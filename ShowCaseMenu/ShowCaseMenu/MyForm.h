#pragma once
#include "Launcher.h"

namespace ShowCaseMenu {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;


	/// <summary>
	/// Summary for MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		array<String^>^ imagePath;
		array<Launcher^>^ programs;

	private: System::Windows::Forms::PictureBox^ pictureBox1;
	private: System::Windows::Forms::PictureBox^ pictureBox2;
	private: System::Windows::Forms::PictureBox^ pictureBox3;
	private: System::Windows::Forms::Panel^ pnl_Header;
	private: System::Windows::Forms::Label^ lbl_Title;


	public:



	public:

	public:

	public:
		array<RadioButton^>^ rb_Pages;
		array<Button^>^ btn_Icons;
	public:
		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
			programs = gcnew array<Launcher^>(2);
			imagePath = gcnew array<String^>(4);

			// Iniatialize SlideShow Pictures
			imagePath[0] = "Resources\\SlideShowPics\\1.png";
			imagePath[1] = "Resources\\SlideShowPics\\2.png";
			imagePath[2] = "Resources\\SlideShowPics\\3.png";
			imagePath[3] = "Resources\\SlideShowPics\\4.png";

			SetupSlideShow();

			// Iniatialize programs or applications
			programs[0] = gcnew Launcher("D:\Project\JGuess\JGuess\dist\JGuess.jar", "Games", "JGuess");
			programs[1] = gcnew Launcher("D:\\TeraProject\\TeraBite\\Build\\Windows\\TeraBite.exe", "Games", "TeraBite");
			
			SetupUI();
		}

		void SetupSlideShow() {
			rb_Pages = (gcnew array<RadioButton^>(imagePath->Length));

			for (int i = 0; i < rb_Pages->Length; ++i)
			{
				rb_Pages[i] = gcnew RadioButton();
				this->rb_Pages[i]->AutoSize = true;
				this->rb_Pages[i]->BackgroundImageLayout = System::Windows::Forms::ImageLayout::None;
				this->rb_Pages[i]->CheckAlign = System::Drawing::ContentAlignment::MiddleCenter;
				this->rb_Pages[i]->Checked = false;
				this->rb_Pages[i]->Location = System::Drawing::Point(53, 18);
				this->rb_Pages[i]->Margin = System::Windows::Forms::Padding(3, 3, 15, 3);
				this->rb_Pages[i]->Name = L"rb_Page" + i;
				this->rb_Pages[i]->Size = System::Drawing::Size(14, 13);
				this->rb_Pages[i]->TabIndex = i;
				this->rb_Pages[i]->TabStop = true;
				this->rb_Pages[i]->UseVisualStyleBackColor = true;

				// Add event handler
				rb_Pages[i]->CheckedChanged += gcnew EventHandler(this, &MyForm::RadioButton_CheckedChanged);

				this->flp_PicturesCtrlr->Controls->Add(this->rb_Pages[i]);
			}

			rb_Pages[0]->Checked = true;
		}

		void SetupUI()
		{
			btn_Icons = gcnew array<Button^>(programs->Length);
			// Create buttons or picture boxes for each launcher
			for (int i = 0; i < programs->Length; ++i)
			{
				String^ name = programs[i]->Category;
			//// btn_Icon
			btn_Icons[i] = gcnew Button();
			btn_Icons[i]->Location = System::Drawing::Point(8, 8);
			btn_Icons[i]->Name = L"" + name;
			btn_Icons[i]->Size = System::Drawing::Size(73, 64);
			btn_Icons[i]->TabIndex = i;
			btn_Icons[i]->Text = programs[i]->Description;
			btn_Icons[i]->UseVisualStyleBackColor = true;
			btn_Icons[i]->Click += gcnew EventHandler(this, &MyForm::OnLaunchButtonClick);

			// Add to tab panel
			this->flp_Tab->Controls->Add(this->btn_Icons[i]);
			//// 

			btn_Icons[i]->Tag = programs[i];
			}

		}

		

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}


	private: System::Windows::Forms::FlowLayoutPanel^ flp_SideBar;


	protected:

	private: System::Windows::Forms::SplitContainer^ splitContainer1;
	private: System::Windows::Forms::Button^ btn_Showcase;


	private: System::Windows::Forms::Button^ btn_Games;
	private: System::Windows::Forms::Button^ btn_Application;





	private: System::Windows::Forms::Button^ btn_ShowAll;
	private: System::Windows::Forms::Panel^ pnl_SlideShow;

	private: System::Windows::Forms::FlowLayoutPanel^ flp_Tab;

	private: System::Windows::Forms::FlowLayoutPanel^ flp_PicturesCtrlr;


	private: System::Windows::Forms::PictureBox^ pb_SlideShow;
	private: System::Windows::Forms::Timer^ slideshowTimer;






	private: System::ComponentModel::IContainer^ components;














	protected:

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(MyForm::typeid));
			this->flp_SideBar = (gcnew System::Windows::Forms::FlowLayoutPanel());
			this->btn_Showcase = (gcnew System::Windows::Forms::Button());
			this->btn_Games = (gcnew System::Windows::Forms::Button());
			this->btn_Application = (gcnew System::Windows::Forms::Button());
			this->btn_ShowAll = (gcnew System::Windows::Forms::Button());
			this->splitContainer1 = (gcnew System::Windows::Forms::SplitContainer());
			this->flp_PicturesCtrlr = (gcnew System::Windows::Forms::FlowLayoutPanel());
			this->pnl_SlideShow = (gcnew System::Windows::Forms::Panel());
			this->pb_SlideShow = (gcnew System::Windows::Forms::PictureBox());
			this->flp_Tab = (gcnew System::Windows::Forms::FlowLayoutPanel());
			this->slideshowTimer = (gcnew System::Windows::Forms::Timer(this->components));
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox2 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox3 = (gcnew System::Windows::Forms::PictureBox());
			this->pnl_Header = (gcnew System::Windows::Forms::Panel());
			this->lbl_Title = (gcnew System::Windows::Forms::Label());
			this->flp_SideBar->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->splitContainer1))->BeginInit();
			this->splitContainer1->Panel1->SuspendLayout();
			this->splitContainer1->Panel2->SuspendLayout();
			this->splitContainer1->SuspendLayout();
			this->pnl_SlideShow->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pb_SlideShow))->BeginInit();
			this->flp_Tab->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox3))->BeginInit();
			this->pnl_Header->SuspendLayout();
			this->SuspendLayout();
			// 
			// flp_SideBar
			// 
			this->flp_SideBar->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->flp_SideBar->AutoScroll = true;
			this->flp_SideBar->BackColor = System::Drawing::Color::Lavender;
			this->flp_SideBar->Controls->Add(this->btn_Showcase);
			this->flp_SideBar->Controls->Add(this->btn_Games);
			this->flp_SideBar->Controls->Add(this->btn_Application);
			this->flp_SideBar->Controls->Add(this->btn_ShowAll);
			this->flp_SideBar->FlowDirection = System::Windows::Forms::FlowDirection::TopDown;
			this->flp_SideBar->Location = System::Drawing::Point(32, 38);
			this->flp_SideBar->Name = L"flp_SideBar";
			this->flp_SideBar->Padding = System::Windows::Forms::Padding(5, 0, 0, 0);
			this->flp_SideBar->Size = System::Drawing::Size(202, 324);
			this->flp_SideBar->TabIndex = 3;
			this->flp_SideBar->WrapContents = false;
			// 
			// btn_Showcase
			// 
			this->btn_Showcase->AutoSize = true;
			this->btn_Showcase->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(15)), static_cast<System::Int32>(static_cast<System::Byte>(24)),
				static_cast<System::Int32>(static_cast<System::Byte>(32)));
			this->btn_Showcase->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btn_Showcase->ForeColor = System::Drawing::Color::Lavender;
			this->btn_Showcase->Location = System::Drawing::Point(8, 3);
			this->btn_Showcase->Name = L"btn_Showcase";
			this->btn_Showcase->Size = System::Drawing::Size(187, 60);
			this->btn_Showcase->TabIndex = 0;
			this->btn_Showcase->Text = L"Showcase";
			this->btn_Showcase->UseVisualStyleBackColor = false;
			this->btn_Showcase->Click += gcnew System::EventHandler(this, &MyForm::btn_Showcas_Click);
			// 
			// btn_Games
			// 
			this->btn_Games->AutoSize = true;
			this->btn_Games->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(15)), static_cast<System::Int32>(static_cast<System::Byte>(24)),
				static_cast<System::Int32>(static_cast<System::Byte>(32)));
			this->btn_Games->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btn_Games->ForeColor = System::Drawing::Color::Lavender;
			this->btn_Games->Location = System::Drawing::Point(8, 69);
			this->btn_Games->Name = L"btn_Games";
			this->btn_Games->Size = System::Drawing::Size(187, 60);
			this->btn_Games->TabIndex = 1;
			this->btn_Games->Text = L"Games";
			this->btn_Games->UseVisualStyleBackColor = false;
			this->btn_Games->Click += gcnew System::EventHandler(this, &MyForm::btn_Games_Click);
			// 
			// btn_Application
			// 
			this->btn_Application->AutoSize = true;
			this->btn_Application->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(15)), static_cast<System::Int32>(static_cast<System::Byte>(24)),
				static_cast<System::Int32>(static_cast<System::Byte>(32)));
			this->btn_Application->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btn_Application->ForeColor = System::Drawing::Color::Lavender;
			this->btn_Application->Location = System::Drawing::Point(8, 135);
			this->btn_Application->Name = L"btn_Application";
			this->btn_Application->Size = System::Drawing::Size(187, 60);
			this->btn_Application->TabIndex = 2;
			this->btn_Application->Text = L"Application";
			this->btn_Application->UseVisualStyleBackColor = false;
			this->btn_Application->Click += gcnew System::EventHandler(this, &MyForm::btn_Application_Click);
			// 
			// btn_ShowAll
			// 
			this->btn_ShowAll->AutoSize = true;
			this->btn_ShowAll->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(15)), static_cast<System::Int32>(static_cast<System::Byte>(24)),
				static_cast<System::Int32>(static_cast<System::Byte>(32)));
			this->btn_ShowAll->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btn_ShowAll->ForeColor = System::Drawing::Color::Lavender;
			this->btn_ShowAll->Location = System::Drawing::Point(8, 201);
			this->btn_ShowAll->Name = L"btn_ShowAll";
			this->btn_ShowAll->Size = System::Drawing::Size(187, 60);
			this->btn_ShowAll->TabIndex = 3;
			this->btn_ShowAll->Text = L"Show All";
			this->btn_ShowAll->UseVisualStyleBackColor = false;
			this->btn_ShowAll->Click += gcnew System::EventHandler(this, &MyForm::btn_ShowAll_Click);
			// 
			// splitContainer1
			// 
			this->splitContainer1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->splitContainer1->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(15)), static_cast<System::Int32>(static_cast<System::Byte>(24)),
				static_cast<System::Int32>(static_cast<System::Byte>(32)));
			this->splitContainer1->Location = System::Drawing::Point(0, 136);
			this->splitContainer1->Name = L"splitContainer1";
			// 
			// splitContainer1.Panel1
			// 
			this->splitContainer1->Panel1->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(15)),
				static_cast<System::Int32>(static_cast<System::Byte>(24)), static_cast<System::Int32>(static_cast<System::Byte>(32)));
			this->splitContainer1->Panel1->Controls->Add(this->flp_SideBar);
			this->splitContainer1->Panel1->Padding = System::Windows::Forms::Padding(5, 10, 5, 0);
			// 
			// splitContainer1.Panel2
			// 
			this->splitContainer1->Panel2->BackColor = System::Drawing::SystemColors::ControlDarkDark;
			this->splitContainer1->Panel2->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"splitContainer1.Panel2.BackgroundImage")));
			this->splitContainer1->Panel2->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->splitContainer1->Panel2->Controls->Add(this->flp_PicturesCtrlr);
			this->splitContainer1->Panel2->Controls->Add(this->pnl_SlideShow);
			this->splitContainer1->Panel2->Controls->Add(this->flp_Tab);
			this->splitContainer1->Panel2->Padding = System::Windows::Forms::Padding(25, 15, 0, 0);
			this->splitContainer1->Size = System::Drawing::Size(1273, 460);
			this->splitContainer1->SplitterDistance = 263;
			this->splitContainer1->TabIndex = 1;
			// 
			// flp_PicturesCtrlr
			// 
			this->flp_PicturesCtrlr->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->flp_PicturesCtrlr->AutoScroll = true;
			this->flp_PicturesCtrlr->BackColor = System::Drawing::Color::Lavender;
			this->flp_PicturesCtrlr->Location = System::Drawing::Point(262, 382);
			this->flp_PicturesCtrlr->Name = L"flp_PicturesCtrlr";
			this->flp_PicturesCtrlr->Padding = System::Windows::Forms::Padding(50, 15, 10, 10);
			this->flp_PicturesCtrlr->Size = System::Drawing::Size(465, 45);
			this->flp_PicturesCtrlr->TabIndex = 6;
			// 
			// pnl_SlideShow
			// 
			this->pnl_SlideShow->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->pnl_SlideShow->BackColor = System::Drawing::Color::Lavender;
			this->pnl_SlideShow->Controls->Add(this->pb_SlideShow);
			this->pnl_SlideShow->Location = System::Drawing::Point(44, 29);
			this->pnl_SlideShow->Name = L"pnl_SlideShow";
			this->pnl_SlideShow->Size = System::Drawing::Size(914, 333);
			this->pnl_SlideShow->TabIndex = 5;
			// 
			// pb_SlideShow
			// 
			this->pb_SlideShow->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->pb_SlideShow->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->pb_SlideShow->Location = System::Drawing::Point(16, 10);
			this->pb_SlideShow->Name = L"pb_SlideShow";
			this->pb_SlideShow->Size = System::Drawing::Size(884, 311);
			this->pb_SlideShow->TabIndex = 0;
			this->pb_SlideShow->TabStop = false;
			// 
			// flp_Tab
			// 
			this->flp_Tab->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->flp_Tab->AutoScroll = true;
			this->flp_Tab->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(15)), static_cast<System::Int32>(static_cast<System::Byte>(24)),
				static_cast<System::Int32>(static_cast<System::Byte>(32)));
			this->flp_Tab->Location = System::Drawing::Point(44, 29);
			this->flp_Tab->Name = L"flp_Tab";
			this->flp_Tab->Padding = System::Windows::Forms::Padding(5);
			this->flp_Tab->Size = System::Drawing::Size(914, 333);
			this->flp_Tab->TabIndex = 2;
			// 
			// slideshowTimer
			// 
			this->slideshowTimer->Interval = 5000;
			this->slideshowTimer->Tick += gcnew System::EventHandler(this, &MyForm::timer_Tick);
			// 
			// pictureBox1
			// 
			this->pictureBox1->BackColor = System::Drawing::Color::Transparent;
			this->pictureBox1->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->pictureBox1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox1.Image")));
			this->pictureBox1->Location = System::Drawing::Point(368, -25);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(298, 187);
			this->pictureBox1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->pictureBox1->TabIndex = 2;
			this->pictureBox1->TabStop = false;
			// 
			// pictureBox2
			// 
			this->pictureBox2->BackColor = System::Drawing::Color::Transparent;
			this->pictureBox2->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->pictureBox2->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox2.Image")));
			this->pictureBox2->Location = System::Drawing::Point(591, 12);
			this->pictureBox2->Name = L"pictureBox2";
			this->pictureBox2->Size = System::Drawing::Size(171, 118);
			this->pictureBox2->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pictureBox2->TabIndex = 3;
			this->pictureBox2->TabStop = false;
			// 
			// pictureBox3
			// 
			this->pictureBox3->BackColor = System::Drawing::Color::Transparent;
			this->pictureBox3->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->pictureBox3->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox3.Image")));
			this->pictureBox3->Location = System::Drawing::Point(768, 12);
			this->pictureBox3->Name = L"pictureBox3";
			this->pictureBox3->Size = System::Drawing::Size(123, 106);
			this->pictureBox3->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pictureBox3->TabIndex = 4;
			this->pictureBox3->TabStop = false;
			// 
			// pnl_Header
			// 
			this->pnl_Header->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(15)), static_cast<System::Int32>(static_cast<System::Byte>(24)),
				static_cast<System::Int32>(static_cast<System::Byte>(32)));
			this->pnl_Header->Controls->Add(this->lbl_Title);
			this->pnl_Header->Controls->Add(this->pictureBox3);
			this->pnl_Header->Controls->Add(this->pictureBox2);
			this->pnl_Header->Controls->Add(this->pictureBox1);
			this->pnl_Header->Dock = System::Windows::Forms::DockStyle::Top;
			this->pnl_Header->Location = System::Drawing::Point(0, 0);
			this->pnl_Header->Name = L"pnl_Header";
			this->pnl_Header->Size = System::Drawing::Size(1273, 140);
			this->pnl_Header->TabIndex = 4;
			// 
			// lbl_Title
			// 
			this->lbl_Title->AutoSize = true;
			this->lbl_Title->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->lbl_Title->Font = (gcnew System::Drawing::Font(L"Ravie", 20.25F, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->lbl_Title->ForeColor = System::Drawing::Color::Lavender;
			this->lbl_Title->Location = System::Drawing::Point(12, 12);
			this->lbl_Title->Name = L"lbl_Title";
			this->lbl_Title->Size = System::Drawing::Size(386, 108);
			this->lbl_Title->TabIndex = 5;
			this->lbl_Title->Text = L"ProgatomicX \r\n\r\nProgramming Team";
			// 
			// MyForm
			// 
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Inherit;
			this->ClientSize = System::Drawing::Size(1273, 595);
			this->Controls->Add(this->splitContainer1);
			this->Controls->Add(this->pnl_Header);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
			this->Name = L"MyForm";
			this->SizeGripStyle = System::Windows::Forms::SizeGripStyle::Show;
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Showcase Menu";
			this->WindowState = System::Windows::Forms::FormWindowState::Maximized;
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			this->flp_SideBar->ResumeLayout(false);
			this->flp_SideBar->PerformLayout();
			this->splitContainer1->Panel1->ResumeLayout(false);
			this->splitContainer1->Panel2->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->splitContainer1))->EndInit();
			this->splitContainer1->ResumeLayout(false);
			this->pnl_SlideShow->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pb_SlideShow))->EndInit();
			this->flp_Tab->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox3))->EndInit();
			this->pnl_Header->ResumeLayout(false);
			this->pnl_Header->PerformLayout();
			this->ResumeLayout(false);

		}
#pragma endregion
char iPicture;
int iSlide = 0;

void hideSlideshow() {
	if (pnl_SlideShow->Visible == true) {
		pnl_SlideShow->Visible = false;
		flp_PicturesCtrlr->Visible = false;
	}
}

void showOff() {
	for (int i = 0; i < programs->Length; ++i)
	{
		if (btn_Icons[i]->Visible == false) 
			btn_Icons[i]->Visible = true;
	}
}

void showOff(String^ category) {
	for (int i = 0; i < programs->Length; ++i)
	{
		if (programs[i]->Category == category) {
			btn_Icons[i]->Visible = true;
		}
		else {
			btn_Icons[i]->Visible = false;
		}
	}
}

private: System::Void btn_Showcas_Click(System::Object^ sender, System::EventArgs^ e) {
	if (pnl_SlideShow->Visible == true)
	{
		pnl_SlideShow->Visible = false;
		flp_PicturesCtrlr->Visible = false;
	}
	else{
		pnl_SlideShow->Visible = true;
		flp_PicturesCtrlr->Visible = true;
	}
}

private: System::Void btn_Games_Click(System::Object^ sender, System::EventArgs^ e) {
	hideSlideshow();

	showOff("Games");

}
private: System::Void btn_Application_Click(System::Object^ sender, System::EventArgs^ e) {
	hideSlideshow();
	showOff("Application");
}


private: System::Void btn_ShowAll_Click(System::Object^ sender, System::EventArgs^ e) {
	hideSlideshow();
	showOff();
}

private: System::Void MyForm_Load(System::Object^ sender, System::EventArgs^ e) {
	slideshowTimer->Start();
}

private: System::Void timer_Tick(System::Object^ sender, System::EventArgs^ e) {
	pb_SlideShow->BackgroundImage = Image::FromFile(imagePath[iSlide]);

	rb_Pages[iSlide]->Checked = true;
	iSlide = (iSlide + 1) % imagePath->Length;
	
}
	// RadioButton Event handler method
	private: System::Void RadioButton_CheckedChanged(Object^ sender, EventArgs^ e)
	{
		RadioButton^ radioButton = dynamic_cast<RadioButton^>(sender);
		iSlide = radioButton->TabIndex;

		pb_SlideShow->BackgroundImage = Image::FromFile(imagePath[iSlide]);
	}
		
	private: System::Void OnLaunchButtonClick(Object^ sender, EventArgs^ e)
	{
		// Change cursor to loading cursor
		this->Cursor = Cursors::WaitCursor;
		try {
		Button^ button = dynamic_cast<Button^>(sender);
		if (button != nullptr)
		{
			// Retrieve the ProgramLauncher from the button's Tag property
			Launcher^ launcher = dynamic_cast<Launcher^>(button->Tag);
			if (launcher != nullptr)
			{
				launcher->Launch();
			}
		}
		} catch (Exception^ ex)
		{
			MessageBox::Show("Failed to launch program: " + ex->Message);
		}
		finally
		{
			// Revert the cursor back to the default cursor
			this->Cursor = Cursors::Default;
		}
	}
};
}
