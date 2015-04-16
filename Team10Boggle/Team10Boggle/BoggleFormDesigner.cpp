#include "BoggleForm.h"
using namespace System::Resources;
namespace view{
	/// <summary>
	/// Required method for Designer support - do not modify
	/// the contents of this method with the code editor.
	/// </summary>
	void BoggleForm::InitializeComponent(void)
	{
		this->components = (gcnew System::ComponentModel::Container());
		System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(BoggleForm::typeid));
		this->backgroundWorker1 = (gcnew System::ComponentModel::BackgroundWorker());
		this->checkBoxContainer = (gcnew System::Windows::Forms::TableLayoutPanel());
		this->checkBox17 = (gcnew System::Windows::Forms::CheckBox());
		this->checkBox16 = (gcnew System::Windows::Forms::CheckBox());
		this->checkBox15 = (gcnew System::Windows::Forms::CheckBox());
		this->checkBox14 = (gcnew System::Windows::Forms::CheckBox());
		this->checkBox13 = (gcnew System::Windows::Forms::CheckBox());
		this->checkBox12 = (gcnew System::Windows::Forms::CheckBox());
		this->checkBox11 = (gcnew System::Windows::Forms::CheckBox());
		this->checkBox10 = (gcnew System::Windows::Forms::CheckBox());
		this->checkBox9 = (gcnew System::Windows::Forms::CheckBox());
		this->checkBox8 = (gcnew System::Windows::Forms::CheckBox());
		this->checkBox7 = (gcnew System::Windows::Forms::CheckBox());
		this->checkBox6 = (gcnew System::Windows::Forms::CheckBox());
		this->checkBox5 = (gcnew System::Windows::Forms::CheckBox());
		this->checkBox4 = (gcnew System::Windows::Forms::CheckBox());
		this->checkBox3 = (gcnew System::Windows::Forms::CheckBox());
		this->checkBox2 = (gcnew System::Windows::Forms::CheckBox());
		this->listBox1 = (gcnew System::Windows::Forms::ListBox());
		this->addWordButton = (gcnew System::Windows::Forms::Button());
		this->label1 = (gcnew System::Windows::Forms::Label());
		this->label2 = (gcnew System::Windows::Forms::Label());
		this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
		this->label3 = (gcnew System::Windows::Forms::Label());
		this->columnHeader1 = (gcnew System::Windows::Forms::ColumnHeader());
		this->rotateButton = (gcnew System::Windows::Forms::Button());
		this->label4 = (gcnew System::Windows::Forms::Label());
		this->highScorePanel = (gcnew System::Windows::Forms::Panel());
		this->mainMenuPanelReturnButton = (gcnew System::Windows::Forms::Button());
		this->scoreBoard = (gcnew System::Windows::Forms::ListView());
		this->col1 = (gcnew System::Windows::Forms::ColumnHeader());
		this->col2 = (gcnew System::Windows::Forms::ColumnHeader());
		this->endGamePrompt = (gcnew System::Windows::Forms::Panel());
		this->nameBox = (gcnew System::Windows::Forms::ComboBox());
		this->submitNameButton = (gcnew System::Windows::Forms::Button());
		this->nameLabel = (gcnew System::Windows::Forms::Label());
		this->timeUpLabel = (gcnew System::Windows::Forms::Label());
		this->mainMenuPanel = (gcnew System::Windows::Forms::Panel());
		this->highscoresButton = (gcnew System::Windows::Forms::Button());
		this->startGameButton = (gcnew System::Windows::Forms::Button());
		this->checkBoxContainer->SuspendLayout();
		this->highScorePanel->SuspendLayout();
		this->endGamePrompt->SuspendLayout();
		this->mainMenuPanel->SuspendLayout();
		this->SuspendLayout();
		// 
		// checkBoxContainer
		// 
		this->checkBoxContainer->AutoSize = true;
		this->checkBoxContainer->BackColor = System::Drawing::Color::Silver;
		this->checkBoxContainer->ColumnCount = 4;
		this->checkBoxContainer->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
			25)));
		this->checkBoxContainer->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
			25)));
		this->checkBoxContainer->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
			25)));
		this->checkBoxContainer->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
			25)));
		this->checkBoxContainer->Controls->Add(this->checkBox17, 3, 3);
		this->checkBoxContainer->Controls->Add(this->checkBox16, 2, 3);
		this->checkBoxContainer->Controls->Add(this->checkBox15, 1, 3);
		this->checkBoxContainer->Controls->Add(this->checkBox14, 0, 3);
		this->checkBoxContainer->Controls->Add(this->checkBox13, 3, 2);
		this->checkBoxContainer->Controls->Add(this->checkBox12, 2, 2);
		this->checkBoxContainer->Controls->Add(this->checkBox11, 1, 2);
		this->checkBoxContainer->Controls->Add(this->checkBox10, 0, 2);
		this->checkBoxContainer->Controls->Add(this->checkBox9, 3, 1);
		this->checkBoxContainer->Controls->Add(this->checkBox8, 2, 1);
		this->checkBoxContainer->Controls->Add(this->checkBox7, 1, 1);
		this->checkBoxContainer->Controls->Add(this->checkBox6, 0, 1);
		this->checkBoxContainer->Controls->Add(this->checkBox5, 3, 0);
		this->checkBoxContainer->Controls->Add(this->checkBox4, 2, 0);
		this->checkBoxContainer->Controls->Add(this->checkBox3, 1, 0);
		this->checkBoxContainer->Controls->Add(this->checkBox2, 0, 0);
		this->checkBoxContainer->Location = System::Drawing::Point(14, 13);
		this->checkBoxContainer->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
		this->checkBoxContainer->Name = L"checkBoxContainer";
		this->checkBoxContainer->RowCount = 4;
		this->checkBoxContainer->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 25)));
		this->checkBoxContainer->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 25)));
		this->checkBoxContainer->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 25)));
		this->checkBoxContainer->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 25)));
		this->checkBoxContainer->Size = System::Drawing::Size(260, 244);
		this->checkBoxContainer->TabIndex = 2;
		this->checkBoxContainer->MouseUp += gcnew System::Windows::Forms::MouseEventHandler(this, &BoggleForm::checkBox_MouseUp);
		// 
		// checkBox17
		// 
		this->checkBox17->AllowDrop = true;
		this->checkBox17->Appearance = System::Windows::Forms::Appearance::Button;
		this->checkBox17->BackColor = System::Drawing::Color::White;
		this->checkBox17->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
		this->checkBox17->CausesValidation = false;
		this->checkBox17->Cursor = System::Windows::Forms::Cursors::Hand;
		this->checkBox17->Dock = System::Windows::Forms::DockStyle::Fill;
		this->checkBox17->FlatAppearance->CheckedBackColor = System::Drawing::Color::RoyalBlue;
		this->checkBox17->FlatAppearance->MouseOverBackColor = System::Drawing::Color::RoyalBlue;
		this->checkBox17->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
		this->checkBox17->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Bold));
		this->checkBox17->Location = System::Drawing::Point(201, 189);
		this->checkBox17->Margin = System::Windows::Forms::Padding(6);
		this->checkBox17->Name = L"checkBox17";
		this->checkBox17->Size = System::Drawing::Size(53, 49);
		this->checkBox17->TabIndex = 17;
		this->checkBox17->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
		this->checkBox17->ThreeState = true;
		this->checkBox17->UseVisualStyleBackColor = false;
		this->checkBox17->CheckStateChanged += gcnew System::EventHandler(this, &BoggleForm::checkBox_CheckStateChanged);
		this->checkBox17->Click += gcnew System::EventHandler(this, &BoggleForm::checkBox_Click);
		this->checkBox17->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &BoggleForm::checkBox_MouseDown);
		this->checkBox17->MouseEnter += gcnew System::EventHandler(this, &BoggleForm::checkBox_MouseEnter);
		this->checkBox17->MouseHover += gcnew System::EventHandler(this, &BoggleForm::checkBox_MouseHover);
		this->checkBox17->MouseUp += gcnew System::Windows::Forms::MouseEventHandler(this, &BoggleForm::checkBox_MouseUp);
		// 
		// checkBox16
		// 
		this->checkBox16->AllowDrop = true;
		this->checkBox16->Appearance = System::Windows::Forms::Appearance::Button;
		this->checkBox16->BackColor = System::Drawing::Color::White;
		this->checkBox16->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
		this->checkBox16->CausesValidation = false;
		this->checkBox16->Cursor = System::Windows::Forms::Cursors::Hand;
		this->checkBox16->Dock = System::Windows::Forms::DockStyle::Fill;
		this->checkBox16->FlatAppearance->CheckedBackColor = System::Drawing::Color::RoyalBlue;
		this->checkBox16->FlatAppearance->MouseDownBackColor = System::Drawing::Color::RoyalBlue;
		this->checkBox16->FlatAppearance->MouseOverBackColor = System::Drawing::Color::RoyalBlue;
		this->checkBox16->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
		this->checkBox16->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Bold));
		this->checkBox16->Location = System::Drawing::Point(136, 189);
		this->checkBox16->Margin = System::Windows::Forms::Padding(6);
		this->checkBox16->Name = L"checkBox16";
		this->checkBox16->Size = System::Drawing::Size(53, 49);
		this->checkBox16->TabIndex = 16;
		this->checkBox16->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
		this->checkBox16->ThreeState = true;
		this->checkBox16->UseVisualStyleBackColor = false;
		this->checkBox16->CheckStateChanged += gcnew System::EventHandler(this, &BoggleForm::checkBox_CheckStateChanged);
		this->checkBox16->Click += gcnew System::EventHandler(this, &BoggleForm::checkBox_Click);
		this->checkBox16->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &BoggleForm::checkBox_MouseDown);
		this->checkBox16->MouseEnter += gcnew System::EventHandler(this, &BoggleForm::checkBox_MouseEnter);
		this->checkBox16->MouseHover += gcnew System::EventHandler(this, &BoggleForm::checkBox_MouseHover);
		this->checkBox16->MouseUp += gcnew System::Windows::Forms::MouseEventHandler(this, &BoggleForm::checkBox_MouseUp);
		// 
		// checkBox15
		// 
		this->checkBox15->AllowDrop = true;
		this->checkBox15->Appearance = System::Windows::Forms::Appearance::Button;
		this->checkBox15->BackColor = System::Drawing::Color::White;
		this->checkBox15->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
		this->checkBox15->CausesValidation = false;
		this->checkBox15->Cursor = System::Windows::Forms::Cursors::Hand;
		this->checkBox15->Dock = System::Windows::Forms::DockStyle::Fill;
		this->checkBox15->FlatAppearance->CheckedBackColor = System::Drawing::Color::RoyalBlue;
		this->checkBox15->FlatAppearance->MouseOverBackColor = System::Drawing::Color::RoyalBlue;
		this->checkBox15->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
		this->checkBox15->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Bold));
		this->checkBox15->Location = System::Drawing::Point(71, 189);
		this->checkBox15->Margin = System::Windows::Forms::Padding(6);
		this->checkBox15->Name = L"checkBox15";
		this->checkBox15->Size = System::Drawing::Size(53, 49);
		this->checkBox15->TabIndex = 15;
		this->checkBox15->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
		this->checkBox15->ThreeState = true;
		this->checkBox15->UseVisualStyleBackColor = false;
		this->checkBox15->CheckStateChanged += gcnew System::EventHandler(this, &BoggleForm::checkBox_CheckStateChanged);
		this->checkBox15->Click += gcnew System::EventHandler(this, &BoggleForm::checkBox_Click);
		this->checkBox15->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &BoggleForm::checkBox_MouseDown);
		this->checkBox15->MouseEnter += gcnew System::EventHandler(this, &BoggleForm::checkBox_MouseEnter);
		this->checkBox15->MouseHover += gcnew System::EventHandler(this, &BoggleForm::checkBox_MouseHover);
		this->checkBox15->MouseUp += gcnew System::Windows::Forms::MouseEventHandler(this, &BoggleForm::checkBox_MouseUp);
		// 
		// checkBox14
		// 
		this->checkBox14->AllowDrop = true;
		this->checkBox14->Appearance = System::Windows::Forms::Appearance::Button;
		this->checkBox14->BackColor = System::Drawing::Color::White;
		this->checkBox14->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
		this->checkBox14->CausesValidation = false;
		this->checkBox14->Cursor = System::Windows::Forms::Cursors::Hand;
		this->checkBox14->Dock = System::Windows::Forms::DockStyle::Fill;
		this->checkBox14->FlatAppearance->CheckedBackColor = System::Drawing::Color::RoyalBlue;
		this->checkBox14->FlatAppearance->MouseOverBackColor = System::Drawing::Color::RoyalBlue;
		this->checkBox14->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
		this->checkBox14->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Bold));
		this->checkBox14->Location = System::Drawing::Point(6, 189);
		this->checkBox14->Margin = System::Windows::Forms::Padding(6);
		this->checkBox14->Name = L"checkBox14";
		this->checkBox14->Size = System::Drawing::Size(53, 49);
		this->checkBox14->TabIndex = 14;
		this->checkBox14->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
		this->checkBox14->ThreeState = true;
		this->checkBox14->UseVisualStyleBackColor = false;
		this->checkBox14->CheckStateChanged += gcnew System::EventHandler(this, &BoggleForm::checkBox_CheckStateChanged);
		this->checkBox14->Click += gcnew System::EventHandler(this, &BoggleForm::checkBox_Click);
		this->checkBox14->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &BoggleForm::checkBox_MouseDown);
		this->checkBox14->MouseEnter += gcnew System::EventHandler(this, &BoggleForm::checkBox_MouseEnter);
		this->checkBox14->MouseHover += gcnew System::EventHandler(this, &BoggleForm::checkBox_MouseHover);
		this->checkBox14->MouseUp += gcnew System::Windows::Forms::MouseEventHandler(this, &BoggleForm::checkBox_MouseUp);
		// 
		// checkBox13
		// 
		this->checkBox13->AllowDrop = true;
		this->checkBox13->Appearance = System::Windows::Forms::Appearance::Button;
		this->checkBox13->BackColor = System::Drawing::Color::White;
		this->checkBox13->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
		this->checkBox13->CausesValidation = false;
		this->checkBox13->Cursor = System::Windows::Forms::Cursors::Hand;
		this->checkBox13->Dock = System::Windows::Forms::DockStyle::Fill;
		this->checkBox13->FlatAppearance->CheckedBackColor = System::Drawing::Color::RoyalBlue;
		this->checkBox13->FlatAppearance->MouseOverBackColor = System::Drawing::Color::RoyalBlue;
		this->checkBox13->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
		this->checkBox13->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Bold));
		this->checkBox13->Location = System::Drawing::Point(201, 128);
		this->checkBox13->Margin = System::Windows::Forms::Padding(6);
		this->checkBox13->Name = L"checkBox13";
		this->checkBox13->Size = System::Drawing::Size(53, 49);
		this->checkBox13->TabIndex = 13;
		this->checkBox13->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
		this->checkBox13->ThreeState = true;
		this->checkBox13->UseVisualStyleBackColor = false;
		this->checkBox13->CheckStateChanged += gcnew System::EventHandler(this, &BoggleForm::checkBox_CheckStateChanged);
		this->checkBox13->Click += gcnew System::EventHandler(this, &BoggleForm::checkBox_Click);
		this->checkBox13->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &BoggleForm::checkBox_MouseDown);
		this->checkBox13->MouseEnter += gcnew System::EventHandler(this, &BoggleForm::checkBox_MouseEnter);
		this->checkBox13->MouseHover += gcnew System::EventHandler(this, &BoggleForm::checkBox_MouseHover);
		this->checkBox13->MouseUp += gcnew System::Windows::Forms::MouseEventHandler(this, &BoggleForm::checkBox_MouseUp);
		// 
		// checkBox12
		// 
		this->checkBox12->AllowDrop = true;
		this->checkBox12->Appearance = System::Windows::Forms::Appearance::Button;
		this->checkBox12->BackColor = System::Drawing::Color::White;
		this->checkBox12->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
		this->checkBox12->CausesValidation = false;
		this->checkBox12->Cursor = System::Windows::Forms::Cursors::Hand;
		this->checkBox12->Dock = System::Windows::Forms::DockStyle::Fill;
		this->checkBox12->FlatAppearance->CheckedBackColor = System::Drawing::Color::RoyalBlue;
		this->checkBox12->FlatAppearance->MouseOverBackColor = System::Drawing::Color::RoyalBlue;
		this->checkBox12->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
		this->checkBox12->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Bold));
		this->checkBox12->Location = System::Drawing::Point(136, 128);
		this->checkBox12->Margin = System::Windows::Forms::Padding(6);
		this->checkBox12->Name = L"checkBox12";
		this->checkBox12->Size = System::Drawing::Size(53, 49);
		this->checkBox12->TabIndex = 12;
		this->checkBox12->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
		this->checkBox12->ThreeState = true;
		this->checkBox12->UseVisualStyleBackColor = false;
		this->checkBox12->CheckStateChanged += gcnew System::EventHandler(this, &BoggleForm::checkBox_CheckStateChanged);
		this->checkBox12->Click += gcnew System::EventHandler(this, &BoggleForm::checkBox_Click);
		this->checkBox12->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &BoggleForm::checkBox_MouseDown);
		this->checkBox12->MouseEnter += gcnew System::EventHandler(this, &BoggleForm::checkBox_MouseEnter);
		this->checkBox12->MouseHover += gcnew System::EventHandler(this, &BoggleForm::checkBox_MouseHover);
		this->checkBox12->MouseUp += gcnew System::Windows::Forms::MouseEventHandler(this, &BoggleForm::checkBox_MouseUp);
		// 
		// checkBox11
		// 
		this->checkBox11->AllowDrop = true;
		this->checkBox11->Appearance = System::Windows::Forms::Appearance::Button;
		this->checkBox11->BackColor = System::Drawing::Color::White;
		this->checkBox11->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
		this->checkBox11->CausesValidation = false;
		this->checkBox11->Cursor = System::Windows::Forms::Cursors::Hand;
		this->checkBox11->Dock = System::Windows::Forms::DockStyle::Fill;
		this->checkBox11->FlatAppearance->CheckedBackColor = System::Drawing::Color::RoyalBlue;
		this->checkBox11->FlatAppearance->MouseOverBackColor = System::Drawing::Color::RoyalBlue;
		this->checkBox11->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
		this->checkBox11->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Bold));
		this->checkBox11->Location = System::Drawing::Point(71, 128);
		this->checkBox11->Margin = System::Windows::Forms::Padding(6);
		this->checkBox11->Name = L"checkBox11";
		this->checkBox11->Size = System::Drawing::Size(53, 49);
		this->checkBox11->TabIndex = 11;
		this->checkBox11->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
		this->checkBox11->ThreeState = true;
		this->checkBox11->UseVisualStyleBackColor = false;
		this->checkBox11->CheckStateChanged += gcnew System::EventHandler(this, &BoggleForm::checkBox_CheckStateChanged);
		this->checkBox11->Click += gcnew System::EventHandler(this, &BoggleForm::checkBox_Click);
		this->checkBox11->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &BoggleForm::checkBox_MouseDown);
		this->checkBox11->MouseEnter += gcnew System::EventHandler(this, &BoggleForm::checkBox_MouseEnter);
		this->checkBox11->MouseHover += gcnew System::EventHandler(this, &BoggleForm::checkBox_MouseHover);
		this->checkBox11->MouseUp += gcnew System::Windows::Forms::MouseEventHandler(this, &BoggleForm::checkBox_MouseUp);
		// 
		// checkBox10
		// 
		this->checkBox10->AllowDrop = true;
		this->checkBox10->Appearance = System::Windows::Forms::Appearance::Button;
		this->checkBox10->BackColor = System::Drawing::Color::White;
		this->checkBox10->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
		this->checkBox10->CausesValidation = false;
		this->checkBox10->Cursor = System::Windows::Forms::Cursors::Hand;
		this->checkBox10->Dock = System::Windows::Forms::DockStyle::Fill;
		this->checkBox10->FlatAppearance->CheckedBackColor = System::Drawing::Color::RoyalBlue;
		this->checkBox10->FlatAppearance->MouseOverBackColor = System::Drawing::Color::RoyalBlue;
		this->checkBox10->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
		this->checkBox10->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Bold));
		this->checkBox10->Location = System::Drawing::Point(6, 128);
		this->checkBox10->Margin = System::Windows::Forms::Padding(6);
		this->checkBox10->Name = L"checkBox10";
		this->checkBox10->Size = System::Drawing::Size(53, 49);
		this->checkBox10->TabIndex = 10;
		this->checkBox10->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
		this->checkBox10->ThreeState = true;
		this->checkBox10->UseVisualStyleBackColor = false;
		this->checkBox10->CheckStateChanged += gcnew System::EventHandler(this, &BoggleForm::checkBox_CheckStateChanged);
		this->checkBox10->Click += gcnew System::EventHandler(this, &BoggleForm::checkBox_Click);
		this->checkBox10->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &BoggleForm::checkBox_MouseDown);
		this->checkBox10->MouseEnter += gcnew System::EventHandler(this, &BoggleForm::checkBox_MouseEnter);
		this->checkBox10->MouseHover += gcnew System::EventHandler(this, &BoggleForm::checkBox_MouseHover);
		this->checkBox10->MouseUp += gcnew System::Windows::Forms::MouseEventHandler(this, &BoggleForm::checkBox_MouseUp);
		// 
		// checkBox9
		// 
		this->checkBox9->AllowDrop = true;
		this->checkBox9->Appearance = System::Windows::Forms::Appearance::Button;
		this->checkBox9->BackColor = System::Drawing::Color::White;
		this->checkBox9->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
		this->checkBox9->CausesValidation = false;
		this->checkBox9->Cursor = System::Windows::Forms::Cursors::Hand;
		this->checkBox9->Dock = System::Windows::Forms::DockStyle::Fill;
		this->checkBox9->FlatAppearance->CheckedBackColor = System::Drawing::Color::RoyalBlue;
		this->checkBox9->FlatAppearance->MouseOverBackColor = System::Drawing::Color::RoyalBlue;
		this->checkBox9->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
		this->checkBox9->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Bold));
		this->checkBox9->Location = System::Drawing::Point(201, 67);
		this->checkBox9->Margin = System::Windows::Forms::Padding(6);
		this->checkBox9->Name = L"checkBox9";
		this->checkBox9->Size = System::Drawing::Size(53, 49);
		this->checkBox9->TabIndex = 9;
		this->checkBox9->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
		this->checkBox9->ThreeState = true;
		this->checkBox9->UseVisualStyleBackColor = false;
		this->checkBox9->CheckStateChanged += gcnew System::EventHandler(this, &BoggleForm::checkBox_CheckStateChanged);
		this->checkBox9->Click += gcnew System::EventHandler(this, &BoggleForm::checkBox_Click);
		this->checkBox9->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &BoggleForm::checkBox_MouseDown);
		this->checkBox9->MouseEnter += gcnew System::EventHandler(this, &BoggleForm::checkBox_MouseEnter);
		this->checkBox9->MouseHover += gcnew System::EventHandler(this, &BoggleForm::checkBox_MouseHover);
		this->checkBox9->MouseUp += gcnew System::Windows::Forms::MouseEventHandler(this, &BoggleForm::checkBox_MouseUp);
		// 
		// checkBox8
		// 
		this->checkBox8->AllowDrop = true;
		this->checkBox8->Appearance = System::Windows::Forms::Appearance::Button;
		this->checkBox8->BackColor = System::Drawing::Color::White;
		this->checkBox8->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
		this->checkBox8->CausesValidation = false;
		this->checkBox8->Cursor = System::Windows::Forms::Cursors::Hand;
		this->checkBox8->Dock = System::Windows::Forms::DockStyle::Fill;
		this->checkBox8->FlatAppearance->CheckedBackColor = System::Drawing::Color::RoyalBlue;
		this->checkBox8->FlatAppearance->MouseOverBackColor = System::Drawing::Color::RoyalBlue;
		this->checkBox8->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
		this->checkBox8->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Bold));
		this->checkBox8->Location = System::Drawing::Point(136, 67);
		this->checkBox8->Margin = System::Windows::Forms::Padding(6);
		this->checkBox8->Name = L"checkBox8";
		this->checkBox8->Size = System::Drawing::Size(53, 49);
		this->checkBox8->TabIndex = 8;
		this->checkBox8->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
		this->checkBox8->ThreeState = true;
		this->checkBox8->UseVisualStyleBackColor = false;
		this->checkBox8->CheckStateChanged += gcnew System::EventHandler(this, &BoggleForm::checkBox_CheckStateChanged);
		this->checkBox8->Click += gcnew System::EventHandler(this, &BoggleForm::checkBox_Click);
		this->checkBox8->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &BoggleForm::checkBox_MouseDown);
		this->checkBox8->MouseEnter += gcnew System::EventHandler(this, &BoggleForm::checkBox_MouseEnter);
		this->checkBox8->MouseHover += gcnew System::EventHandler(this, &BoggleForm::checkBox_MouseHover);
		this->checkBox8->MouseUp += gcnew System::Windows::Forms::MouseEventHandler(this, &BoggleForm::checkBox_MouseUp);
		// 
		// checkBox7
		// 
		this->checkBox7->AllowDrop = true;
		this->checkBox7->Appearance = System::Windows::Forms::Appearance::Button;
		this->checkBox7->BackColor = System::Drawing::Color::White;
		this->checkBox7->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
		this->checkBox7->CausesValidation = false;
		this->checkBox7->Cursor = System::Windows::Forms::Cursors::Hand;
		this->checkBox7->Dock = System::Windows::Forms::DockStyle::Fill;
		this->checkBox7->FlatAppearance->CheckedBackColor = System::Drawing::Color::RoyalBlue;
		this->checkBox7->FlatAppearance->MouseOverBackColor = System::Drawing::Color::RoyalBlue;
		this->checkBox7->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
		this->checkBox7->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Bold));
		this->checkBox7->Location = System::Drawing::Point(71, 67);
		this->checkBox7->Margin = System::Windows::Forms::Padding(6);
		this->checkBox7->Name = L"checkBox7";
		this->checkBox7->Size = System::Drawing::Size(53, 49);
		this->checkBox7->TabIndex = 7;
		this->checkBox7->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
		this->checkBox7->ThreeState = true;
		this->checkBox7->UseVisualStyleBackColor = false;
		this->checkBox7->CheckStateChanged += gcnew System::EventHandler(this, &BoggleForm::checkBox_CheckStateChanged);
		this->checkBox7->Click += gcnew System::EventHandler(this, &BoggleForm::checkBox_Click);
		this->checkBox7->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &BoggleForm::checkBox_MouseDown);
		this->checkBox7->MouseEnter += gcnew System::EventHandler(this, &BoggleForm::checkBox_MouseEnter);
		this->checkBox7->MouseHover += gcnew System::EventHandler(this, &BoggleForm::checkBox_MouseHover);
		this->checkBox7->MouseUp += gcnew System::Windows::Forms::MouseEventHandler(this, &BoggleForm::checkBox_MouseUp);
		// 
		// checkBox6
		// 
		this->checkBox6->AllowDrop = true;
		this->checkBox6->Appearance = System::Windows::Forms::Appearance::Button;
		this->checkBox6->BackColor = System::Drawing::Color::White;
		this->checkBox6->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
		this->checkBox6->CausesValidation = false;
		this->checkBox6->Cursor = System::Windows::Forms::Cursors::Hand;
		this->checkBox6->Dock = System::Windows::Forms::DockStyle::Fill;
		this->checkBox6->FlatAppearance->CheckedBackColor = System::Drawing::Color::RoyalBlue;
		this->checkBox6->FlatAppearance->MouseOverBackColor = System::Drawing::Color::RoyalBlue;
		this->checkBox6->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
		this->checkBox6->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Bold));
		this->checkBox6->Location = System::Drawing::Point(6, 67);
		this->checkBox6->Margin = System::Windows::Forms::Padding(6);
		this->checkBox6->Name = L"checkBox6";
		this->checkBox6->Size = System::Drawing::Size(53, 49);
		this->checkBox6->TabIndex = 6;
		this->checkBox6->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
		this->checkBox6->ThreeState = true;
		this->checkBox6->UseVisualStyleBackColor = false;
		this->checkBox6->CheckStateChanged += gcnew System::EventHandler(this, &BoggleForm::checkBox_CheckStateChanged);
		this->checkBox6->Click += gcnew System::EventHandler(this, &BoggleForm::checkBox_Click);
		this->checkBox6->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &BoggleForm::checkBox_MouseDown);
		this->checkBox6->MouseEnter += gcnew System::EventHandler(this, &BoggleForm::checkBox_MouseEnter);
		this->checkBox6->MouseHover += gcnew System::EventHandler(this, &BoggleForm::checkBox_MouseHover);
		this->checkBox6->MouseUp += gcnew System::Windows::Forms::MouseEventHandler(this, &BoggleForm::checkBox_MouseUp);
		// 
		// checkBox5
		// 
		this->checkBox5->AllowDrop = true;
		this->checkBox5->Appearance = System::Windows::Forms::Appearance::Button;
		this->checkBox5->BackColor = System::Drawing::Color::White;
		this->checkBox5->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
		this->checkBox5->CausesValidation = false;
		this->checkBox5->Cursor = System::Windows::Forms::Cursors::Hand;
		this->checkBox5->Dock = System::Windows::Forms::DockStyle::Fill;
		this->checkBox5->FlatAppearance->CheckedBackColor = System::Drawing::Color::RoyalBlue;
		this->checkBox5->FlatAppearance->MouseOverBackColor = System::Drawing::Color::RoyalBlue;
		this->checkBox5->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
		this->checkBox5->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Bold));
		this->checkBox5->Location = System::Drawing::Point(201, 6);
		this->checkBox5->Margin = System::Windows::Forms::Padding(6);
		this->checkBox5->Name = L"checkBox5";
		this->checkBox5->Size = System::Drawing::Size(53, 49);
		this->checkBox5->TabIndex = 5;
		this->checkBox5->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
		this->checkBox5->ThreeState = true;
		this->checkBox5->UseVisualStyleBackColor = false;
		this->checkBox5->CheckStateChanged += gcnew System::EventHandler(this, &BoggleForm::checkBox_CheckStateChanged);
		this->checkBox5->Click += gcnew System::EventHandler(this, &BoggleForm::checkBox_Click);
		this->checkBox5->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &BoggleForm::checkBox_MouseDown);
		this->checkBox5->MouseEnter += gcnew System::EventHandler(this, &BoggleForm::checkBox_MouseEnter);
		this->checkBox5->MouseHover += gcnew System::EventHandler(this, &BoggleForm::checkBox_MouseHover);
		this->checkBox5->MouseUp += gcnew System::Windows::Forms::MouseEventHandler(this, &BoggleForm::checkBox_MouseUp);
		// 
		// checkBox4
		// 
		this->checkBox4->AllowDrop = true;
		this->checkBox4->Appearance = System::Windows::Forms::Appearance::Button;
		this->checkBox4->BackColor = System::Drawing::Color::White;
		this->checkBox4->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
		this->checkBox4->CausesValidation = false;
		this->checkBox4->Cursor = System::Windows::Forms::Cursors::Hand;
		this->checkBox4->Dock = System::Windows::Forms::DockStyle::Fill;
		this->checkBox4->FlatAppearance->CheckedBackColor = System::Drawing::Color::RoyalBlue;
		this->checkBox4->FlatAppearance->MouseOverBackColor = System::Drawing::Color::RoyalBlue;
		this->checkBox4->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
		this->checkBox4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Bold));
		this->checkBox4->Location = System::Drawing::Point(136, 6);
		this->checkBox4->Margin = System::Windows::Forms::Padding(6);
		this->checkBox4->Name = L"checkBox4";
		this->checkBox4->Size = System::Drawing::Size(53, 49);
		this->checkBox4->TabIndex = 4;
		this->checkBox4->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
		this->checkBox4->ThreeState = true;
		this->checkBox4->UseVisualStyleBackColor = false;
		this->checkBox4->CheckStateChanged += gcnew System::EventHandler(this, &BoggleForm::checkBox_CheckStateChanged);
		this->checkBox4->Click += gcnew System::EventHandler(this, &BoggleForm::checkBox_Click);
		this->checkBox4->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &BoggleForm::checkBox_MouseDown);
		this->checkBox4->MouseEnter += gcnew System::EventHandler(this, &BoggleForm::checkBox_MouseEnter);
		this->checkBox4->MouseHover += gcnew System::EventHandler(this, &BoggleForm::checkBox_MouseHover);
		this->checkBox4->MouseUp += gcnew System::Windows::Forms::MouseEventHandler(this, &BoggleForm::checkBox_MouseUp);
		// 
		// checkBox3
		// 
		this->checkBox3->AllowDrop = true;
		this->checkBox3->Appearance = System::Windows::Forms::Appearance::Button;
		this->checkBox3->BackColor = System::Drawing::Color::White;
		this->checkBox3->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
		this->checkBox3->CausesValidation = false;
		this->checkBox3->Cursor = System::Windows::Forms::Cursors::Hand;
		this->checkBox3->Dock = System::Windows::Forms::DockStyle::Fill;
		this->checkBox3->FlatAppearance->CheckedBackColor = System::Drawing::Color::RoyalBlue;
		this->checkBox3->FlatAppearance->MouseOverBackColor = System::Drawing::Color::RoyalBlue;
		this->checkBox3->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
		this->checkBox3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Bold));
		this->checkBox3->Location = System::Drawing::Point(71, 6);
		this->checkBox3->Margin = System::Windows::Forms::Padding(6);
		this->checkBox3->Name = L"checkBox3";
		this->checkBox3->Size = System::Drawing::Size(53, 49);
		this->checkBox3->TabIndex = 3;
		this->checkBox3->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
		this->checkBox3->ThreeState = true;
		this->checkBox3->UseVisualStyleBackColor = false;
		this->checkBox3->CheckStateChanged += gcnew System::EventHandler(this, &BoggleForm::checkBox_CheckStateChanged);
		this->checkBox3->Click += gcnew System::EventHandler(this, &BoggleForm::checkBox_Click);
		this->checkBox3->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &BoggleForm::checkBox_MouseDown);
		this->checkBox3->MouseEnter += gcnew System::EventHandler(this, &BoggleForm::checkBox_MouseEnter);
		this->checkBox3->MouseHover += gcnew System::EventHandler(this, &BoggleForm::checkBox_MouseHover);
		this->checkBox3->MouseUp += gcnew System::Windows::Forms::MouseEventHandler(this, &BoggleForm::checkBox_MouseUp);
		// 
		// checkBox2
		// 
		this->checkBox2->AllowDrop = true;
		this->checkBox2->Appearance = System::Windows::Forms::Appearance::Button;
		this->checkBox2->BackColor = System::Drawing::Color::White;
		this->checkBox2->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
		this->checkBox2->Cursor = System::Windows::Forms::Cursors::Hand;
		this->checkBox2->Dock = System::Windows::Forms::DockStyle::Fill;
		this->checkBox2->FlatAppearance->CheckedBackColor = System::Drawing::Color::RoyalBlue;
		this->checkBox2->FlatAppearance->MouseOverBackColor = System::Drawing::Color::RoyalBlue;
		this->checkBox2->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
		this->checkBox2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Bold));
		this->checkBox2->Location = System::Drawing::Point(6, 6);
		this->checkBox2->Margin = System::Windows::Forms::Padding(6);
		this->checkBox2->Name = L"checkBox2";
		this->checkBox2->Size = System::Drawing::Size(53, 49);
		this->checkBox2->TabIndex = 2;
		this->checkBox2->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
		this->checkBox2->ThreeState = true;
		this->checkBox2->UseVisualStyleBackColor = false;
		this->checkBox2->CheckStateChanged += gcnew System::EventHandler(this, &BoggleForm::checkBox_CheckStateChanged);
		this->checkBox2->Click += gcnew System::EventHandler(this, &BoggleForm::checkBox_Click);
		this->checkBox2->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &BoggleForm::checkBox_MouseDown);
		this->checkBox2->MouseEnter += gcnew System::EventHandler(this, &BoggleForm::checkBox_MouseEnter);
		this->checkBox2->MouseHover += gcnew System::EventHandler(this, &BoggleForm::checkBox_MouseHover);
		this->checkBox2->MouseUp += gcnew System::Windows::Forms::MouseEventHandler(this, &BoggleForm::checkBox_MouseUp);
		// 
		// listBox1
		// 
		this->listBox1->DrawMode = System::Windows::Forms::DrawMode::OwnerDrawFixed;
		this->listBox1->Enabled = false;
		this->listBox1->IntegralHeight = false;
		this->listBox1->Location = System::Drawing::Point(274, 33);
		this->listBox1->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
		this->listBox1->Name = L"listBox1";
		this->listBox1->SelectionMode = System::Windows::Forms::SelectionMode::None;
		this->listBox1->Size = System::Drawing::Size(129, 224);
		this->listBox1->TabIndex = 3;
		this->listBox1->DrawItem += gcnew System::Windows::Forms::DrawItemEventHandler(this, &BoggleForm::listBox1_DrawItem);
		this->listBox1->MouseUp += gcnew System::Windows::Forms::MouseEventHandler(this, &BoggleForm::checkBox_MouseUp);
		// 
		// addWordButton
		// 
		this->addWordButton->BackColor = System::Drawing::Color::White;
		this->addWordButton->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Center;
		this->addWordButton->FlatAppearance->MouseDownBackColor = System::Drawing::Color::LightGray;
		this->addWordButton->FlatAppearance->MouseOverBackColor = System::Drawing::Color::Transparent;
		this->addWordButton->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
		this->addWordButton->Location = System::Drawing::Point(14, 261);
		this->addWordButton->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
		this->addWordButton->Name = L"addWordButton";
		this->addWordButton->Size = System::Drawing::Size(75, 22);
		this->addWordButton->TabIndex = 4;
		this->addWordButton->Text = L"Add";
		this->addWordButton->UseVisualStyleBackColor = false;
		this->addWordButton->Click += gcnew System::EventHandler(this, &BoggleForm::addWordButton_Click);
		this->addWordButton->GotFocus += gcnew System::EventHandler(this, &BoggleForm::button_GotFocus);
		// 
		// label1
		// 
		this->label1->AutoSize = true;
		this->label1->Location = System::Drawing::Point(308, 261);
		this->label1->Name = L"label1";
		this->label1->Size = System::Drawing::Size(38, 13);
		this->label1->TabIndex = 6;
		this->label1->Text = L"Score:";
		// 
		// label2
		// 
		this->label2->AutoSize = true;
		this->label2->Location = System::Drawing::Point(352, 261);
		this->label2->Name = L"label2";
		this->label2->Size = System::Drawing::Size(13, 13);
		this->label2->TabIndex = 7;
		this->label2->Text = L"0";
		// 
		// timer1
		// 
		this->timer1->Enabled = true;
		this->timer1->Interval = 1;
		this->timer1->Tick += gcnew System::EventHandler(this, &BoggleForm::timer1_Tick);
		// 
		// label3
		// 
		this->label3->AutoSize = true;
		this->label3->Location = System::Drawing::Point(308, 274);
		this->label3->Name = L"label3";
		this->label3->Size = System::Drawing::Size(28, 13);
		this->label3->TabIndex = 8;
		this->label3->Text = L"3:00";
		// 
		// rotateButton
		// 
		this->rotateButton->BackColor = System::Drawing::Color::White;
		this->rotateButton->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"rotateButton.BackgroundImage")));
		this->rotateButton->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Center;
		this->rotateButton->FlatAppearance->MouseDownBackColor = System::Drawing::Color::LightGray;
		this->rotateButton->FlatAppearance->MouseOverBackColor = System::Drawing::Color::Transparent;
		this->rotateButton->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
		this->rotateButton->ForeColor = System::Drawing::Color::Black;
		this->rotateButton->Location = System::Drawing::Point(95, 261);
		this->rotateButton->Name = L"rotateButton";
		this->rotateButton->Size = System::Drawing::Size(37, 22);
		this->rotateButton->TabIndex = 9;
		this->rotateButton->TextImageRelation = System::Windows::Forms::TextImageRelation::ImageAboveText;
		this->rotateButton->UseVisualStyleBackColor = false;
		this->rotateButton->Click += gcnew System::EventHandler(this, &BoggleForm::rotateButton_Click);
		this->rotateButton->GotFocus += gcnew System::EventHandler(this, &BoggleForm::button_GotFocus);
		// 
		// label4
		// 
		this->label4->BackColor = System::Drawing::Color::Silver;
		this->label4->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
		this->label4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.75F));
		this->label4->Location = System::Drawing::Point(274, 13);
		this->label4->Name = L"label4";
		this->label4->Size = System::Drawing::Size(129, 20);
		this->label4->TabIndex = 10;
		this->label4->TextAlign = System::Drawing::ContentAlignment::TopCenter;
		// 
		// highScorePanel
		// 
		this->highScorePanel->Controls->Add(this->mainMenuPanelReturnButton);
		this->highScorePanel->Controls->Add(this->scoreBoard);
		this->highScorePanel->Location = System::Drawing::Point(0, 0);
		this->highScorePanel->Name = L"highScorePanel";
		this->highScorePanel->Size = System::Drawing::Size(415, 292);
		this->highScorePanel->TabIndex = 11;
		this->highScorePanel->Visible = false;
		// 
		// mainMenuPanelReturnButton
		// 
		this->mainMenuPanelReturnButton->Location = System::Drawing::Point(328, 261);
		this->mainMenuPanelReturnButton->Name = L"mainMenuPanelReturnButton";
		this->mainMenuPanelReturnButton->Size = System::Drawing::Size(75, 23);
		this->mainMenuPanelReturnButton->TabIndex = 4;
		this->mainMenuPanelReturnButton->Text = L"Main Menu";
		this->mainMenuPanelReturnButton->UseVisualStyleBackColor = true;
		this->mainMenuPanelReturnButton->Click += gcnew System::EventHandler(this, &BoggleForm::mainMenuPanelReturnButton_Click);
		// 
		// scoreBoard
		// 
		this->scoreBoard->Columns->AddRange(gcnew cli::array< System::Windows::Forms::ColumnHeader^  >(2) { this->col1, this->col2 });
		this->scoreBoard->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.25F));
		this->scoreBoard->Location = System::Drawing::Point(95, 32);
		this->scoreBoard->Name = L"scoreBoard";
		this->scoreBoard->Size = System::Drawing::Size(224, 229);
		this->scoreBoard->TabIndex = 3;
		this->scoreBoard->UseCompatibleStateImageBehavior = false;
		this->scoreBoard->View = System::Windows::Forms::View::Details;
		this->scoreBoard->VisibleChanged += gcnew System::EventHandler(this, &BoggleForm::scoreBoard_SizeChanged);
		// 
		// col1
		// 
		this->col1->Tag = L"2";
		this->col1->Text = L"Name";
		// 
		// col2
		// 
		this->col2->Tag = L"2";
		this->col2->Text = L"Score";
		// 
		// endGamePrompt
		// 
		this->endGamePrompt->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
		this->endGamePrompt->Controls->Add(this->nameBox);
		this->endGamePrompt->Controls->Add(this->submitNameButton);
		this->endGamePrompt->Controls->Add(this->nameLabel);
		this->endGamePrompt->Controls->Add(this->timeUpLabel);
		this->endGamePrompt->Location = System::Drawing::Point(107, 96);
		this->endGamePrompt->Name = L"endGamePrompt";
		this->endGamePrompt->Size = System::Drawing::Size(200, 100);
		this->endGamePrompt->TabIndex = 12;
		this->endGamePrompt->Visible = false;
		// 
		// nameBox
		// 
		this->nameBox->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Left | System::Windows::Forms::AnchorStyles::Right));
		this->nameBox->FormattingEnabled = true;
		this->nameBox->Location = System::Drawing::Point(42, 43);
		this->nameBox->Name = L"nameBox";
		this->nameBox->Size = System::Drawing::Size(121, 21);
		this->nameBox->TabIndex = 4;
		this->nameBox->TextChanged += gcnew System::EventHandler(this, &BoggleForm::nameBox_TextChanged);
		// 
		// submitNameButton
		// 
		this->submitNameButton->Anchor = System::Windows::Forms::AnchorStyles::Right;
		this->submitNameButton->Enabled = false;
		this->submitNameButton->Location = System::Drawing::Point(167, 43);
		this->submitNameButton->Name = L"submitNameButton";
		this->submitNameButton->Size = System::Drawing::Size(28, 21);
		this->submitNameButton->TabIndex = 3;
		this->submitNameButton->Text = L"button1";
		this->submitNameButton->UseVisualStyleBackColor = true;
		this->submitNameButton->Click += gcnew System::EventHandler(this, &BoggleForm::submitNameButton_Click);
		// 
		// nameLabel
		// 
		this->nameLabel->Anchor = System::Windows::Forms::AnchorStyles::Left;
		this->nameLabel->AutoSize = true;
		this->nameLabel->Location = System::Drawing::Point(3, 47);
		this->nameLabel->Name = L"nameLabel";
		this->nameLabel->Size = System::Drawing::Size(38, 13);
		this->nameLabel->TabIndex = 1;
		this->nameLabel->Text = L"Name:";
		// 
		// timeUpLabel
		// 
		this->timeUpLabel->Anchor = System::Windows::Forms::AnchorStyles::Top;
		this->timeUpLabel->AutoSize = true;
		this->timeUpLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.25F));
		this->timeUpLabel->Location = System::Drawing::Point(49, 15);
		this->timeUpLabel->Name = L"timeUpLabel";
		this->timeUpLabel->Size = System::Drawing::Size(113, 25);
		this->timeUpLabel->TabIndex = 0;
		this->timeUpLabel->Text = L"Time\'s Up!";
		// 
		// mainMenuPanel
		// 
		this->mainMenuPanel->Controls->Add(this->highscoresButton);
		this->mainMenuPanel->Controls->Add(this->startGameButton);
		this->mainMenuPanel->Dock = System::Windows::Forms::DockStyle::Fill;
		this->mainMenuPanel->Location = System::Drawing::Point(0, 0);
		this->mainMenuPanel->Name = L"mainMenuPanel";
		this->mainMenuPanel->Size = System::Drawing::Size(415, 292);
		this->mainMenuPanel->TabIndex = 13;
		// 
		// highscoresButton
		// 
		this->highscoresButton->Location = System::Drawing::Point(140, 167);
		this->highscoresButton->Name = L"highscoresButton";
		this->highscoresButton->Size = System::Drawing::Size(128, 39);
		this->highscoresButton->TabIndex = 1;
		this->highscoresButton->Text = L"View Highscores";
		this->highscoresButton->UseVisualStyleBackColor = true;
		this->highscoresButton->Click += gcnew System::EventHandler(this, &BoggleForm::highscoresButton_Click);
		// 
		// startGameButton
		// 
		this->startGameButton->Location = System::Drawing::Point(140, 122);
		this->startGameButton->Name = L"startGameButton";
		this->startGameButton->Size = System::Drawing::Size(128, 39);
		this->startGameButton->TabIndex = 0;
		this->startGameButton->Text = L"Start Game";
		this->startGameButton->UseVisualStyleBackColor = true;
		this->startGameButton->Click += gcnew System::EventHandler(this, &BoggleForm::startGameButton_Click);
		// 
		// BoggleForm
		// 
		this->AcceptButton = this->addWordButton;
		this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
		this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
		this->AutoValidate = System::Windows::Forms::AutoValidate::Disable;
		this->ClientSize = System::Drawing::Size(415, 292);
		this->Controls->Add(this->endGamePrompt);
		this->Controls->Add(this->label4);
		this->Controls->Add(this->rotateButton);
		this->Controls->Add(this->label3);
		this->Controls->Add(this->label2);
		this->Controls->Add(this->label1);
		this->Controls->Add(this->addWordButton);
		this->Controls->Add(this->listBox1);
		this->Controls->Add(this->checkBoxContainer);
		this->Controls->Add(this->mainMenuPanel);
		this->Controls->Add(this->highScorePanel);
		this->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
			static_cast<System::Byte>(0)));
		this->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
		this->Name = L"BoggleForm";
		this->Text = L"BoggleForm";
		this->Load += gcnew System::EventHandler(this, &BoggleForm::BoggleForm_Load);
		this->MouseUp += gcnew System::Windows::Forms::MouseEventHandler(this, &BoggleForm::checkBox_MouseUp);
		this->checkBoxContainer->ResumeLayout(false);
		this->highScorePanel->ResumeLayout(false);
		this->endGamePrompt->ResumeLayout(false);
		this->endGamePrompt->PerformLayout();
		this->mainMenuPanel->ResumeLayout(false);
		this->ResumeLayout(false);
		this->PerformLayout();

	}

}