#include "BoggleForm.h"
#include "DieCollection.h"
#include "Boggle.h"
#include "Word.h"
#include <vector>
#include <mmsystem.h>
#include <Windows.h>
#pragma comment(lib, "winmm.lib")
using namespace System::Windows::Input;
using namespace std;
using namespace model;
using namespace System::Threading;
namespace view{

	BoggleForm::BoggleForm(){
		this->InitializeComponent();
		this->boggle = gcnew Boggle();
		this->listBox1->DataSource = this->boggle->playersWords;
		this->label2->DataBindings->Add(gcnew Binding("Text", this->boggle, "PlayerScore"));
		this->second = 60;
		this->minute = 2;
		this->diceButtons = gcnew array<CheckBox^, 2>(4, 4);
		this->checkedBoxes = gcnew List<CheckBox^>();
		this->currentNeighbors = gcnew List<CheckBox^>();
		this->lastBoxChecked = gcnew CheckBox();
		this->allUnchecked = true;
		this->mouseDown = false;
		this->draggedOverBoxCount = 0;
		
	}

	System::Void BoggleForm::BoggleForm_Load(System::Object^  sender, System::EventArgs^  e) {
		DieCollection^ dice = gcnew DieCollection();

		for (int i = 0; i < 4; i++){
			for (int j = 0; j < 4; j++){
				this->diceButtons[i, j] = this->getCheckBox(j, i);
				this->diceButtons[i, j]->Text = dice->getRandomDie()->letter;
				this->diceButtons[i, j]->AutoCheck = false;
			}
		}
	}

	System::Void BoggleForm::checkBox_Click(System::Object^ sender, System::EventArgs^  e){
		CheckBox^ checkBox = static_cast<CheckBox^>(sender);

		if (this->clickedValidUncheckedBox(checkBox)){
			PlaySound(L"check.wav", NULL, SND_FILENAME | SND_ASYNC);
			checkBox->FlatAppearance->MouseOverBackColor = System::Drawing::Color::RoyalBlue;
			checkBox->CheckState = CheckState::Checked;
		}
		else if (this->clickedValidCheckedBox(checkBox)){
			PlaySound(L"check.wav", NULL, SND_FILENAME | SND_ASYNC);
			checkBox->FlatAppearance->MouseOverBackColor = System::Drawing::Color::LightGray;
			checkBox->CheckState = CheckState::Unchecked;
		}

		this->allUnchecked = (this->checkedBoxes->Count == 0);

	}


	System::Void BoggleForm::checkBox_MouseEnter(System::Object^  sender, System::EventArgs^  e){
		this->checkBox_MouseHover(sender, e);
		if (mouseDown){
			this->checkBox_Click(sender, e);
			this->draggedOverBoxCount++;
		}

	}

	System::Void BoggleForm::checkBox_MouseDown(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e){
		mouseDown = true;
		CheckBox^ checkBox = static_cast<CheckBox^>(sender);

		this->checkBox_Click(sender, e);
		checkBox->Capture = false;
	}

	System::Void BoggleForm::checkBox_MouseUp(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e){
		if (this->draggedOverBoxCount > 0){
			this->button1_Click(button1, e);
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
			checkBox->FlatAppearance->MouseOverBackColor = System::Drawing::Color::RoyalBlue;
		}
	}
	System::Void BoggleForm::button1_Click(System::Object^  sender, System::EventArgs^  e){
		Word^ word = gcnew Word(this->textBox1->Text);
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
		}
		else {
			this->label3->Text = minuteString + ":" + secondString;
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
		this->textBox1->Text += this->lastBoxChecked->Text->ToUpper();
	}

	void BoggleForm::removeLastLetterFromWord(CheckBox^ checkBox){

		this->textBox1->Text = this->textBox1->Text->Replace(checkBox->Text->ToUpper(), "");
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

