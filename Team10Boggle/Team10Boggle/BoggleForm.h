#pragma once
#include "Boggle.h"
#include "BoggleSolver.h"
#include "Die.h"
#include "DieCollection.h"
#include "BoggleForm.h"
#include "PlayerManager.h"
#include "Player.h"

delegate void IterateFunction(int, int);
namespace view{
	using namespace model;

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;

	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Resources;
	using namespace System::Collections::ObjectModel;
	using namespace System::Collections::Specialized;

	/// <summary>
	/// Summary for BoggleForm
	/// </summary>
	enum class Row : int { BELOW = 1, ABOVE = -1, MAX = 4, MIN = 0 };
	enum class Column : int { BEFORE = -1, AFTER = 1, MAX = 4, MIN = 0 };
	public ref class BoggleForm : public System::Windows::Forms::Form
	{
	public:
		BoggleForm();
		void InitializeComponent(void);

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~BoggleForm()
		{
			if (components)
			{
				delete components;
			}
		}

	private: PlayerManager^ playerManager;
			 ResourceManager^ resourceManager;
			 void addNeighborsInColumnBefore(int row, int column, Row neighboringRow);
			 void addNeighborsInColumnAfter(int row, int column, Row neighboringRow);
			 void initializeGameInterface();
			 void initializeStringResources();
			 void generateCheckBoxLetter(int col, int row);
			 void showMainMenu();
			 void showGamePanel();
			 void showHighscorePanel();
			 void showEndGamePanel();
			 void endGame();
			 void changeTimerMinute();
			 DieCollection^ dice;
			 System::Windows::Forms::Button^  rotateButton;
			 System::Windows::Forms::Label^  label4;
			 System::Windows::Forms::Panel^  highScorePanel;
			 System::Windows::Forms::Panel^  mainMenuPanel;
			 System::Windows::Forms::Button^  highscoresButton;
			 System::Windows::Forms::Button^  startGameButton;
			 bool gameRunning;
			 System::Windows::Forms::ListView^  scoreBoard;
			 System::Windows::Forms::ColumnHeader^  col1;
			 System::Windows::Forms::ColumnHeader^  col2;
			 ObservableCollection<String^>^ letters;
			 System::Windows::Forms::MenuStrip^  menuStrip1;
			 System::Windows::Forms::Panel^  endGamePanel;
			 System::Windows::Forms::ListBox^  allPossibleWordBox;
			 System::Windows::Forms::Panel^  gamePanel;
			 System::Windows::Forms::Label^  boggleTitle;
			 System::Windows::Forms::Button^  addWordButton;
			 System::Windows::Forms::Panel^  endGamePrompt;
			 System::Windows::Forms::ComboBox^  nameBox;
			 System::Windows::Forms::Button^  submitNameButton;
			 System::Windows::Forms::Label^  nameLabel;
			 System::Windows::Forms::Label^  timeUpLabel;
			 System::Windows::Forms::Button^  mainMenuPanelReturnButton;
			 System::Windows::Forms::TabControl^  endGameWordTabs;
			 System::Windows::Forms::TabPage^  allWordsTab;
			 System::Windows::Forms::TabPage^  playerWordsTab;
			 System::Windows::Forms::ListBox^  userSubmittedWordBox;
			 System::Windows::Forms::TableLayoutPanel^  checkBoxContainer;
			 System::Windows::Forms::CheckBox^  checkBox17;
			 System::Windows::Forms::CheckBox^  checkBox16;
			 System::Windows::Forms::CheckBox^  checkBox15;
			 System::Windows::Forms::CheckBox^  checkBox14;
			 System::Windows::Forms::CheckBox^  checkBox13;
			 System::Windows::Forms::CheckBox^  checkBox12;
			 System::Windows::Forms::CheckBox^  checkBox11;
			 System::Windows::Forms::CheckBox^  checkBox10;
			 System::Windows::Forms::CheckBox^  checkBox9;
			 System::Windows::Forms::CheckBox^  checkBox8;
			 System::Windows::Forms::CheckBox^  checkBox7;
			 System::Windows::Forms::CheckBox^  checkBox6;
			 System::Windows::Forms::CheckBox^  checkBox5;
			 System::Windows::Forms::CheckBox^  checkBox4;
			 System::Windows::Forms::CheckBox^  checkBox3;
			 System::Windows::Forms::CheckBox^  checkBox2;
			 System::Windows::Forms::Label^  endScoreLabel;
			 System::Windows::Forms::Label^  finalScoreLabel;
			 System::Windows::Forms::Button^  newGameButton;
			 System::Windows::Forms::Button^  mainMenuButton2;
			 int draggedOverBoxCount;
			 CheckBox^ getCheckBox(int column, int row);
			 bool clickedValidCheckedBox(CheckBox^ checkBox);
			 bool allUnchecked;
			 bool mouseDown;
			 bool clickedValidUncheckedBox(CheckBox^ checkBox);
			 void handleChangedCheckState(CheckState checkState, CheckBox^ checkButton);
			 void updateLastBoxChecked();
			 void removeEntry(CheckBox^ checkBox);
			 void refresh();
			 void addEntry(CheckBox^ checkBox);
			 void removeLastLetterFromWord(CheckBox^ checkBox);
			 void addLetterToWord();
			 void calculateNeighborsAt(Row neighboringRow);
			 bool lastBoxCheckedHas(Row neighboringRow);
			 bool lastBoxCheckedHas(Column neighboringColumn);
			 void updateCurrentNeighbors();
			 void setAllBoxesUncheckable();
			 void uncheckAllBoxes();
			 void updateLetters();
			 void iterate(IterateFunction^ func);
			 void addLetter(int row, int column);
			 void changeCheckBoxLetter(int row, int column);
			 void loadNameBoxPlayers();
			 array<String^, 2>^ getBoardArray();
			 bool resizing;
			 Boggle^ boggle;
			 BoggleSolver^ boggleSolver;
			 List<String^>^ missedWords;
			 int second;
			 int minute;
			 CheckBox^ lastBoxChecked;
			 String^ secondString;
			 String^ minuteString;
			 System::ComponentModel::BackgroundWorker^  backgroundWorker1;
			 array<CheckBox^, 2>^ diceButtons;
			 List<CheckBox^>^ checkedBoxes;
			 List<CheckBox^>^ currentNeighbors;
			 System::Windows::Forms::ListBox^  playerWordBank;
			 IterateFunction^ addLetters;
			 System::Windows::Forms::Label^  gamePanelScoreLabel;
			 System::Windows::Forms::Label^  label2;
			 System::Windows::Forms::Timer^  timer1;
			 System::Windows::Forms::Label^  label3;
			 System::Windows::Forms::ColumnHeader^  columnHeader1;
			 System::ComponentModel::IContainer^  components;
			 System::Void checkBox_Click(System::Object^  sender, System::EventArgs^  e);
			 System::Void checkBox_CheckStateChanged(System::Object^  sender, System::EventArgs^  e);
			 System::Void addWordButton_Click(System::Object^  sender, System::EventArgs^  e);
			 System::Void timer1_Tick(System::Object^  sender, System::EventArgs^  e);
			 System::Void checkBox_MouseEnter(System::Object^  sender, System::EventArgs^  e);
			 System::Void checkBox_MouseDown(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e);
			 System::Void checkBox_MouseUp(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e);
			 System::Void checkBox_MouseHover(System::Object^  sender, System::EventArgs^  e);
			 System::Void button_GotFocus(System::Object^  sender, System::EventArgs^  e);
			 System::Void rotateButton_Click(System::Object^  sender, System::EventArgs^  e);
			 System::Void nameBox_TextChanged(System::Object^  sender, System::EventArgs^  e);
			 System::Void submitNameButton_Click(System::Object^  sender, System::EventArgs^  e);
			 System::Void scoreBoard_SizeChanged(System::Object^  sender, System::EventArgs^  e);
			 System::Void startGameButton_Click(System::Object^  sender, System::EventArgs^  e);
			 System::Void highscoresButton_Click(System::Object^  sender, System::EventArgs^  e);
			 System::Void mainMenuPanelReturnButton_Click(System::Object^  sender, System::EventArgs^  e);
			 System::Void newGameButton_Click(System::Object^  sender, System::EventArgs^  e);
	
};

}