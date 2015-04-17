#include "BoggleForm.h"
#include "DieCollection.h"
#include "Boggle.h"
#include "Word.h"
#include "FileIO.h"
#include <mmsystem.h>
#include <Windows.h>
#pragma comment(lib, "winmm.lib")
using namespace model;
using namespace System::Windows::Input;
using namespace System::IO;
using namespace std;
using namespace fileio;
using namespace System::Threading;
using namespace System::Resources;

namespace view{
	BoggleForm::BoggleForm(){
		this->initializeGameInterface();
		this->initializeStringResources();
		this->showMainMenu();
		this->gameRunning = false;
	}

	void BoggleForm::initializeGameInterface(){
		this->InitializeComponent();
		this->resourceManager = gcnew Resources::ResourceManager(L"view.Strings", this->GetType()->Assembly);
		this->dice = gcnew DieCollection();
		this->diceButtons = gcnew array<CheckBox^, 2>(4, 4);	
		this->iterate(gcnew IterateFunction(this, &BoggleForm::generateCheckBoxLetter));
		this->boggle = gcnew Boggle(this->getBoardArray());
		this->label2->DataBindings->Add(gcnew Binding("Text", this->boggle, "PlayerScore"));
		this->endScoreLabel->DataBindings->Add(gcnew Binding("Text", this->boggle, "PlayerScore"));
		this->missedWords = gcnew List<String^>();
		this->playerWordBank->DataSource = this->boggle->PlayersWords;
		this->allPossibleWordBox->DataSource = this->boggle->AllPossibleWords;
		this->userSubmittedWordBox->DataSource = this->boggle->PlayersWords;
		this->boggle->PlayerScore = 0;
		this->second = 60;
		this->minute = 2;
		this->checkedBoxes = gcnew List<CheckBox^>();
		this->currentNeighbors = gcnew List<CheckBox^>();
		this->lastBoxChecked = gcnew CheckBox();
		this->allUnchecked = true;
		this->mouseDown = false;
		this->draggedOverBoxCount = 0;
		this->playerManager = gcnew PlayerManager();
		this->letters = gcnew ObservableCollection<String^>();
		this->rotateButton->GotFocus += gcnew EventHandler(this, &BoggleForm::button_GotFocus);
		this->addWordButton->GotFocus += gcnew EventHandler(this, &BoggleForm::button_GotFocus);
		this->showGamePanel();
	}

	void BoggleForm::loadNameBoxPlayers(){
		for each (Player^ player in this->boggle->Players->Players){
			if (!this->nameBox->Items->Contains(player->Name)){
				this->nameBox->Items->Add(player->Name);
			}
		}
	}

	void BoggleForm::showMainMenu(){
		this->mainMenuPanel->Visible = true;
		this->mainMenuPanel->BringToFront();
	}
	void BoggleForm::showGamePanel(){
		this->gamePanel->BringToFront();
		this->gamePanel->Visible = true;
		this->gamePanel->Enabled = true;
	}
	void BoggleForm::initializeStringResources(){
		this->startGameButton->Text = this->resourceManager->GetString(L"StartGame");
		this->highscoresButton->Text = this->resourceManager->GetString(L"Highscores");
		this->boggleTitle->Text = this->resourceManager->GetString(L"BoggleTitle");
		this->addWordButton->Text = this->resourceManager->GetString(L"Add");
		this->submitNameButton->Text = this->resourceManager->GetString(L"Ok");
		this->nameLabel->Text = this->resourceManager->GetString(L"Name");
		this->gamePanelScoreLabel->Text = this->resourceManager->GetString(L"Score");
		this->endScoreLabel->Text = this->resourceManager->GetString(L"EndScore");
		this->allWordsTab->Text = this->resourceManager->GetString(L"AllWords");
		this->playerWordsTab->Text = this->resourceManager->GetString(L"YourWords");
		this->timeUpLabel->Text = this->resourceManager->GetString(L"TimesUp");
	}

	void BoggleForm::generateCheckBoxLetter(int col, int row){
		this->diceButtons[col, row] = this->getCheckBox(row, col);
		this->diceButtons[col, row]->Text = this->dice->getRandomDie()->letter;
		this->diceButtons[col, row]->AutoCheck = false;
	}

	System::Void BoggleForm::newGameButton_Click(System::Object^  sender, System::EventArgs^  e){
		this->initializeGameInterface();
		this->gameRunning = true;
		this->timer1->Start();
	}

	System::Void BoggleForm::nameBox_TextChanged(System::Object^  sender, System::EventArgs^  e){
		if (this->nameBox->Text == String::Empty){
			this->submitNameButton->Enabled = false;
		}
		else {
			this->submitNameButton->Enabled = true;
		}
	}

	System::Void BoggleForm::scoreBoard_SizeChanged(System::Object^  sender, System::EventArgs^  e) {
		ListView^ listView = static_cast<ListView^>(sender);
		if (listView != nullptr)
		{
			float totalColumnWidth = 0;
			int c = listView->Columns->Count;

			for (int i = 0; i < listView->Columns->Count; i++){
				totalColumnWidth += Convert::ToInt32(listView->Columns[i]->Tag);
			}
			for (int i = 0; i < listView->Columns->Count; i++)
			{
				float colPercentage = (Convert::ToInt32(listView->Columns[i]->Tag) / totalColumnWidth);
				listView->Columns[i]->Width = (int)(colPercentage * listView->ClientRectangle.Width);
			}
		}
	}
	System::Void BoggleForm::startGameButton_Click(System::Object^  sender, System::EventArgs^  e){
		this->initializeGameInterface();
		this->gameRunning = true;
		this->timer1->Start();
	}

	void BoggleForm::showHighscorePanel(){
		this->highScorePanel->Visible = true;
		this->highScorePanel->BringToFront();
	}
	System::Void BoggleForm::highscoresButton_Click(System::Object^  sender, System::EventArgs^  e){
		this->showHighscorePanel();
		this->scoreBoard->Items->Clear();

		for (int i = 0; i < 10 && i < this->boggle->Players->Players->Count; i++){
			ListViewItem^ item = gcnew ListViewItem(gcnew array < String^ > {this->boggle->Players->Players[i]->Name, 
													this->boggle->Players->Players[i]->Score.ToString()});
			this->scoreBoard->Items->Add(item);
		}

	}

	System::Void BoggleForm::mainMenuPanelReturnButton_Click(System::Object^  sender, System::EventArgs^  e){
		this->mainMenuPanel->Visible = true;
		this->mainMenuPanel->BringToFront();
		this->scoreBoard->Items->Clear();
	}
	System::Void BoggleForm::submitNameButton_Click(System::Object^  sender, System::EventArgs^  e){
		this->boggle->Players->addPlayer(this->nameBox->Text, this->boggle->PlayerScore);
		FileIO^ fileio = gcnew FileIO();
		this->boggle->sortPlayersByScore();
		fileio->savePlayers(this->boggle->Players->Players);
		this->endGamePrompt->Visible = false;
		this->showEndGamePanel();
	}

	void BoggleForm::showEndGamePanel(){
		this->endGamePanel->Visible = true;
		this->endGamePanel->BringToFront();
	}
	array<String^, 2>^ BoggleForm::getBoardArray() {
		array<String^, 2>^ board = gcnew array<String^, 2>(4, 4);
		for (int i = 0; i < 4; i++){
			for (int j = 0; j < 4; j++){
				board[i, j] = this->diceButtons[i, j]->Text;
			}
		}
		return board;
	}

	System::Void BoggleForm::checkBox_Click(System::Object^ sender, System::EventArgs^  e){
		CheckBox^ checkBox = static_cast<CheckBox^>(sender);

		if (this->clickedValidUncheckedBox(checkBox)){
			PlaySound(L"check.wav", NULL, SND_FILENAME | SND_ASYNC);
			checkBox->FlatAppearance->MouseOverBackColor = System::Drawing::Color::DimGray;
			checkBox->CheckState = CheckState::Checked;
		}
		else if (this->clickedValidCheckedBox(checkBox)){
			PlaySound(L"check.wav", NULL, SND_FILENAME | SND_ASYNC);
			checkBox->FlatAppearance->MouseOverBackColor = System::Drawing::Color::DimGray;
			checkBox->CheckState = CheckState::Unchecked;
		}

		this->allUnchecked = (this->checkedBoxes->Count == 0);
		this->AcceptButton->NotifyDefault(false);
	}


	System::Void BoggleForm::checkBox_MouseEnter(System::Object^  sender, System::EventArgs^  e){
		this->checkBox_MouseHover(sender, e);
		if (mouseDown){
			this->checkBox_Click(sender, e);
			this->draggedOverBoxCount++;
		}

	}

	System::Void BoggleForm::button_GotFocus(System::Object^ sender, System::EventArgs^ e){
		static_cast<Button^>(sender)->NotifyDefault(false);
	}

	System::Void BoggleForm::checkBox_MouseDown(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e){
		mouseDown = true;
		CheckBox^ checkBox = static_cast<CheckBox^>(sender);

		this->checkBox_Click(sender, e);
		checkBox->Capture = false;
	}

	System::Void BoggleForm::checkBox_MouseUp(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e){
		if (this->draggedOverBoxCount > 0){
			this->addWordButton_Click(addWordButton, e);
			this->draggedOverBoxCount = 0;
		}

		mouseDown = false;
	}
	System::Void BoggleForm::checkBox_MouseHover(System::Object^  sender, System::EventArgs^  e){
		CheckBox^ checkBox = static_cast<CheckBox^>(sender);

		if (this->currentNeighbors->Count != 0 && !this->currentNeighbors->Contains(checkBox) && checkBox != this->lastBoxChecked){
			checkBox->FlatAppearance->MouseOverBackColor = System::Drawing::Color::DimGray;
		}
		else
		{
			checkBox->FlatAppearance->MouseOverBackColor = System::Drawing::Color::DimGray;
		}
	}
	System::Void BoggleForm::rotateButton_Click(System::Object^  sender, System::EventArgs^  e){
		this->iterate(gcnew IterateFunction(this, &BoggleForm::addLetter));
		this->iterate(gcnew IterateFunction(this, &BoggleForm::changeCheckBoxLetter));
	}

	void BoggleForm::changeCheckBoxLetter(int row, int column){
		this->getCheckBox(row, column)->Text = letters[0];
		this->letters->RemoveAt(0);
	}
	void BoggleForm::updateLetters(){

	}
	void BoggleForm::iterate(IterateFunction^ func){
		for (int i = 0; i < 4; i++){
			for (int j = 0; j < 4; j++){
				func(i, j);
			}
		}
	}
	void BoggleForm::addLetter(int row, int column){
		this->letters->Add(this->diceButtons[row, 3 - column]->Text);
	}

	System::Void BoggleForm::addWordButton_Click(System::Object^  sender, System::EventArgs^  e){
		Word^ word = gcnew Word(this->label4->Text);
		if (this->boggle->isDefinedWord(word) && word->length > 2 && !this->boggle->PlayersWords->Contains(word)){
			this->boggle->addWord(word);
			this->boggle->scoreWord(word);
			PlaySound(L"correct.wav", NULL, SND_FILENAME | SND_ASYNC);
		}
		else {
			PlaySound(L"wrong.wav", NULL, SND_FILENAME | SND_ASYNC);
		}

		this->uncheckAllBoxes();
		this->setAllBoxesUncheckable();
		this->currentNeighbors->Clear();
	}

	System::Void BoggleForm::checkBox_CheckStateChanged(System::Object^  sender, System::EventArgs^  e){
		CheckBox^ checkBox = static_cast<CheckBox^>(sender);
		this->handleChangedCheckState(checkBox->CheckState, checkBox);
	}

	System::Void BoggleForm::timer1_Tick(System::Object^  sender, System::EventArgs^  e) {
		if (this->gameRunning){
			this->second--;

			this->secondString = Convert::ToString(second);
			this->minuteString = Convert::ToString(minute);

			if (this->second < 10 && this->second != 0){
				this->label3->Text = minuteString + ":0" + secondString;
			}
			else if (this->second == 0 && this->minute != 0){
				this->changeTimerMinute();
			}
			else if (minute == 0 && second == 0){
				this->endGame();
			}
			else {
				this->label3->Text = minuteString + ":" + secondString;
			}
		}
	}
	void BoggleForm::changeTimerMinute(){
		this->label3->Text = minuteString + ":00";
		this->second = 60;
		this->minute--;
	}
	void BoggleForm::endGame(){
		this->label3->Text = "0:00";
		this->timer1->Stop();
		this->gameRunning = false;
		this->loadNameBoxPlayers();
		this->endGamePrompt->Visible = true;
		this->checkBoxContainer->Enabled = false;
		this->addWordButton->Enabled = false;
		this->rotateButton->Enabled = false;
	}
	bool BoggleForm::clickedValidCheckedBox(CheckBox^ checkBox){
		return (checkBox->Checked && this->lastBoxChecked == checkBox);
	}

	bool BoggleForm::clickedValidUncheckedBox(CheckBox^ checkBox){
		if (this->allUnchecked){
			return true;
		}

		return (!checkBox->Checked && this->currentNeighbors->Contains(checkBox));
	}
	void BoggleForm::refresh(){
		this->setAllBoxesUncheckable();
		this->updateCurrentNeighbors();
	}
	void BoggleForm::addEntry(CheckBox^ checkBox){
		this->checkedBoxes->Add(checkBox);
		this->updateLastBoxChecked();
		this->addLetterToWord();
	}
	void BoggleForm::removeEntry(CheckBox^ checkBox){
		this->checkedBoxes->Remove(checkBox);
		this->updateLastBoxChecked();
		this->removeLastLetterFromWord(checkBox);
	}

	void BoggleForm::handleChangedCheckState(CheckState checkState, CheckBox^ checkBox){
		switch (checkState){
		case CheckState::Unchecked: this->removeEntry(checkBox); this->refresh(); break;
		case CheckState::Checked: this->addEntry(checkBox); this->refresh(); break;
		default: break;
		}
	}

	void BoggleForm::addLetterToWord(){
		this->label4->Text += this->lastBoxChecked->Text->ToUpper();
	}

	void BoggleForm::removeLastLetterFromWord(CheckBox^ checkBox){
		this->label4->Text = this->label4->Text->Replace(checkBox->Text->ToUpper(), "");
	}

	void BoggleForm::updateLastBoxChecked(){
		if (this->checkedBoxes->Count != 0){
			this->lastBoxChecked = this->checkedBoxes[this->checkedBoxes->Count - 1];
		}
	}
	void BoggleForm::addNeighborsInColumnBefore(int row, int column, Row neighboringRow){
		this->currentNeighbors->Add(this->diceButtons[row, column - 1]);
		this->currentNeighbors->Add(this->diceButtons[row + (int)neighboringRow, column]);
		this->currentNeighbors->Add(this->diceButtons[row + (int)neighboringRow, column - 1]);
	}
	void BoggleForm::addNeighborsInColumnAfter(int row, int column, Row neighboringRow){
		this->currentNeighbors->Add(this->diceButtons[row, column + 1]);
		this->currentNeighbors->Add(this->diceButtons[row + (int)neighboringRow, column]);
		this->currentNeighbors->Add(this->diceButtons[row + (int)neighboringRow, column + 1]);
	}
	void BoggleForm::calculateNeighborsAt(Row neighboringRow){
		TableLayoutPanelCellPosition checkedBoxLocation =
			this->checkBoxContainer->GetPositionFromControl(this->lastBoxChecked);

		int row = checkedBoxLocation.Row;
		int column = checkedBoxLocation.Column;

		if (this->lastBoxCheckedHas(Column::BEFORE)){
			this->addNeighborsInColumnBefore(row, column, neighboringRow);
		}
		if (this->lastBoxCheckedHas(Column::AFTER)){
			addNeighborsInColumnAfter(row, column, neighboringRow);
		}
	}

	CheckBox^ BoggleForm::getCheckBox(int column, int row){
		return static_cast<CheckBox^>(this->checkBoxContainer->GetControlFromPosition(column, row));
	}

	bool BoggleForm::lastBoxCheckedHas(Row neighboringRow){
		TableLayoutPanelCellPosition checkedBoxPosition = this->checkBoxContainer->GetPositionFromControl(this->lastBoxChecked);
		int row = checkedBoxPosition.Row;

		switch (neighboringRow){
		case Row::ABOVE: return (row - 1 >= (int)Row::MIN);
		case Row::BELOW: return (row + 1 < (int)Row::MAX);
		}
	}

	bool BoggleForm::lastBoxCheckedHas(Column neighboringColumn){
		TableLayoutPanelCellPosition checkedBoxPosition = this->checkBoxContainer->GetPositionFromControl(this->lastBoxChecked);
		int column = checkedBoxPosition.Column;

		switch (neighboringColumn){
		case Column::AFTER: return (column + 1 < (int)Column::MAX);
		case Column::BEFORE: return (column - 1 >= (int)Column::MIN);
		}
	}

	void BoggleForm::updateCurrentNeighbors(){
		this->currentNeighbors->Clear();
		if (this->lastBoxCheckedHas(Row::BELOW)){
			this->calculateNeighborsAt(Row::BELOW);
		}
		if (this->lastBoxCheckedHas(Row::ABOVE)){
			this->calculateNeighborsAt(Row::ABOVE);
		}
	}

	void BoggleForm::uncheckAllBoxes(){
		for (int i = 0; i < 4; i++){
			for (int j = 0; j < 4; j++){
				this->diceButtons[i, j]->CheckState = CheckState::Unchecked;
			}
		}

		this->allUnchecked = true;
	}
	void BoggleForm::setAllBoxesUncheckable(){
		for each(CheckBox^ checkBox in this->diceButtons){
			checkBox->AutoCheck = false;
		}
	}

}
