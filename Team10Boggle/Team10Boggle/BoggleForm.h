#pragma once
#include "Boggle.h"
#include "Die.h"
#include "DieCollection.h"

using namespace model;

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Resources;

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

	private:
		ResourceManager^ resourceManager;
		int draggedOverBoxCount;
		CheckBox^ getCheckBox(int column, int row);
		bool clickedValidCheckedBox(CheckBox^ checkBox);
		bool allUnchecked;
		bool mouseDown;
		bool clickedValidUncheckedBox(CheckBox^ checkBox);
		void handleChangedCheckState(CheckState checkState, CheckBox^ checkButton);
		void updateCheckedBoxesList();
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
		Boggle^ boggle;
		int second;
		int minute;
		CheckBox^ lastBoxChecked;
		String^ secondString;
		String^ minuteString;
		System::ComponentModel::BackgroundWorker^  backgroundWorker1;
		array<CheckBox^, 2>^ diceButtons;
		List<CheckBox^>^ checkedBoxes;
		List<CheckBox^>^ currentNeighbors;
	private: System::Windows::Forms::TableLayoutPanel^  checkBoxContainer;


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
			 System::Windows::Forms::ListBox^  listBox1;
			 System::Windows::Forms::Button^  button1;
			 System::Windows::Forms::TextBox^  textBox1;
			 System::Windows::Forms::Label^  label1;
			 System::Windows::Forms::Label^  label2;
			 System::Windows::Forms::Timer^  timer1;
			 System::Windows::Forms::Label^  label3;
			 System::Windows::Forms::ColumnHeader^  columnHeader1;
			 System::ComponentModel::IContainer^  components;
			 System::Void BoggleForm_Load(System::Object^  sender, System::EventArgs^  e);
			 System::Void checkBox_Click(System::Object^  sender, System::EventArgs^  e);
			 System::Void checkBox_CheckStateChanged(System::Object^  sender, System::EventArgs^  e);
			 System::Void button1_Click(System::Object^  sender, System::EventArgs^  e);
			 System::Void timer1_Tick(System::Object^  sender, System::EventArgs^  e);
			 System::Void checkBox_MouseEnter(System::Object^  sender, System::EventArgs^  e);
			 System::Void checkBox_MouseDown(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e);
			 System::Void checkBox_MouseUp(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e);
			 System::Void checkBox_MouseHover(System::Object^  sender, System::EventArgs^  e);

	};

