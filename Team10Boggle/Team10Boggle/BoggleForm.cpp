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
		this->InitializeComponent();
		this->boggle = gcnew Boggle();
		this->label2->DataBindings->Add(gcnew Binding("Text", this->boggle, "PlayerScore"));
		this->endScoreLabel->DataBindings->Add(gcnew Binding("Text", this->boggle, "PlayerScore"));
		this->mainMenuPanel->Visible = true;
		this->mainMenuPanel->BringToFront();
	}

	System::Void BoggleForm::newGameButton_Click(System::Object^  sender, System::EventArgs^  e){
		this->boggle = gcnew Boggle();
		this->missedWords = gcnew List<String^>();
		this->listBox1->DataSource = this->boggle->playersWords;
		this->boggle->PlayerScore = 0;
		this->second = 60;
		this->minute = 2;
		this->timer1->Start();
		this->diceButtons = gcnew array<CheckBox^, 2>(4, 4);
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
		this->gamePanel->BringToFront();
		DieCollection^ dice = gcnew DieCollection();
		for each (Player^ player in this->boggle->Players->Players){
			if (!this->nameBox->Items->Contains(player->Name)){
				this->nameBox->Items->Add(player->Name);
			}
		}
		for (int i = 0; i < 4; i++){
			for (int j = 0; j < 4; j++){
				this->diceButtons[i, j] = this->getCheckBox(j, i);
				this->diceButtons[i, j]->Text = dice->getRandomDie()->letter;
				this->diceButtons[i, j]->AutoCheck = false;
			}
		}

	}

	System::Void BoggleForm::getMissedWords() {
		array<String^, 2>^ board = getBoardArray();
		this->boggleSolver = gcnew BoggleSolver(this->boggle->Dictionary, board);
		for each (String^ word in this->boggleSolver->Words) {
			Word^ currWord = gcnew Word(word);
			if (word->Length > 2){
				if (!this->boggle->playersWords->Contains(currWord)) {
					this->missedWords->Add(word);
					word = word->ToLower();
					String^ firstLetter = Char::ToUpper(word->ToCharArray()[0]).ToString();
					word = word->Substring(1, word->Length - 1);
					word = firstLetter + word;
					this->allPossibleWordBox->Items->Add(word);
				}
				else
				{
					word = word->ToLower();

					String^ firstLetter = Char::ToUpper(word->ToCharArray()[0]).ToString();
					word = word->Substring(1, word->Length - 1);
					word = firstLetter + word;
					this->allPossibleWordBox->Items->Add(word);
					this->userSubmittedWordBox->Items->Add(word);
				}
			}
			
		}
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
		this->missedWords = gcnew List<String^>();
		this->listBox1->DataSource = this->boggle->playersWords;
		this->boggle->PlayerScore = 0;
		this->second = 60;
		this->minute = 2;
		this->timer1->Start();
		this->diceButtons = gcnew array<CheckBox^, 2>(4, 4);
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
		this->resizing = false;
		this->mainMenuPanel->Visible = false;
		this->gameRunning = true;
		this->gamePanel->BringToFront();
		DieCollection^ dice = gcnew DieCollection();
		for each (Player^ player in this->boggle->Players->Players){
			if (!this->nameBox->Items->Contains(player->Name)){
				this->nameBox->Items->Add(player->Name);
			}
		}
		for (int i = 0; i < 4; i++){
			for (int j = 0; j < 4; j++){
				this->diceButtons[i, j] = this->getCheckBox(j, i);
				this->diceButtons[i, j]->Text = dice->getRandomDie()->letter;
				this->diceButtons[i, j]->AutoCheck = false;
			}
		}
	}

	System::Void BoggleForm::highscoresButton_Click(System::Object^  sender, System::EventArgs^  e){
		this->mainMenuPanel->Visible = false;
		this->highScorePanel->Visible = true;
		this->highScorePanel->BringToFront();
		this->scoreBoard->Items->Clear();

		for (int i = 0; i < 10 && i < this->boggle->Players->Players->Count; i++){
			ListViewItem^ item = gcnew ListViewItem(gcnew array < String^ > {this->boggle->Players->Players[i]->Name, this->boggle->Players->Players[i]->Score.ToString()});
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
		this->endGamePanel->Visible = true;
		this->endGamePanel->BringToFront();
		this->getMissedWords();
	}

	Void BoggleForm::BoggleForm_Load(Object^  sender, EventArgs^  e) {

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
			checkBox->FlatAppearance->MouseOverBackColor = System::Drawing::Color::LightGray;
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
			checkBox->FlatAppearance->MouseOverBackColor = System::Drawing::Color::LightGray;
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
		if (this->boggle->isDefinedWord(word) && word->length > 2 && !this->boggle->playersWords->Contains(word)){
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
				this->label3->Text = minuteString + ":00";
				this->second = 60;
				minute--;
			}
			else if (minute == 0 && second == 0){
				this->label3->Text = "0:00";
				this->timer1->Stop();
				this->endGamePrompt->Visible = true;
				this->endGamePrompt->BringToFront();
				this->checkBoxContainer->Enabled = false;
				this->addWordButton->Enabled = false;
				this->rotateButton->Enabled = false;
			}
			else {
				this->label3->Text = minuteString + ":" + secondString;
			}
		}
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

	void BoggleForm::updateCheckedBoxesList(){

	}
	void BoggleForm::calculateNeighborsAt(Row neighboringRow){
		TableLayoutPanelCellPosition checkedBoxLocation =
			this->checkBoxContainer->GetPositionFromControl(this->lastBoxChecked);

		int row = checkedBoxLocation.Row;
		int column = checkedBoxLocation.Column;

		if (this->lastBoxCheckedHas(Column::BEFORE)){
			this->currentNeighbors->Add(this->diceButtons[row, column - 1]);
			this->currentNeighbors->Add(this->diceButtons[row + (int)neighboringRow, column]);
			this->currentNeighbors->Add(this->diceButtons[row + (int)neighboringRow, column - 1]);
		}
		if (this->lastBoxCheckedHas(Column::AFTER)){
			this->currentNeighbors->Add(this->diceButtons[row, column + 1]);
			this->currentNeighbors->Add(this->diceButtons[row + (int)neighboringRow, column]);
			this->currentNeighbors->Add(this->diceButtons[row + (int)neighboringRow, column + 1]);
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
