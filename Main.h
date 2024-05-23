#pragma once
#include "SM4.h"

namespace SM4App {
	/// <summary>
	/// Summary for Main
	/// </summary>
	public ref class Main : public System::Windows::Forms::Form
	{
	public:
		Main(void)
		{
			InitializeComponent();
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~Main()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ startButton;
	private: System::Windows::Forms::Label^ Intro;
	private: System::Windows::Forms::TextBox^ initialtextTextBox;
	private: System::Windows::Forms::Label^ initextLabel;
	private: System::Windows::Forms::RadioButton^ cryptionRadioButton;
	private: System::Windows::Forms::Label^ finaltextLabel;
	private: System::Windows::Forms::TextBox^ finaltextTextBox;
	private: System::Windows::Forms::Label^ modeLabel;
	private: System::Windows::Forms::RadioButton^ decryptionRadioButton;
	private: System::Windows::Forms::Label^ mkLabel;
	private: System::Windows::Forms::TextBox^ mkTextBox;
	private: System::Windows::Forms::Button^ initialtextOpenFileButton;
	private: System::Windows::Forms::Button^ finaltextOpenFileButton;
	private: System::Windows::Forms::StatusStrip^ statusStrip;
	private: System::Windows::Forms::ToolStripStatusLabel^ statusLabel;


	protected:
		LPCWSTR setting_ini_path = L".//settings.ini";
	private: System::Windows::Forms::CheckBox^ demoCheckBox;
	private: System::Windows::Forms::CheckBox^ settingsiniCheckBox;

	private: System::Windows::Forms::Label^ keyexplainLabel;




	protected:

	private:
		/// <summary>
		/// ReqMainred designer variable.
		/// </summary>
		System::ComponentModel::Container^ components;


#pragma region Windows Form Designer generated code
		/// <summary>
		/// ReqMainred method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			System::Windows::Forms::Button^ lookmkButton;
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(Main::typeid));
			this->startButton = (gcnew System::Windows::Forms::Button());
			this->Intro = (gcnew System::Windows::Forms::Label());
			this->initialtextTextBox = (gcnew System::Windows::Forms::TextBox());
			this->initextLabel = (gcnew System::Windows::Forms::Label());
			this->cryptionRadioButton = (gcnew System::Windows::Forms::RadioButton());
			this->finaltextLabel = (gcnew System::Windows::Forms::Label());
			this->finaltextTextBox = (gcnew System::Windows::Forms::TextBox());
			this->modeLabel = (gcnew System::Windows::Forms::Label());
			this->decryptionRadioButton = (gcnew System::Windows::Forms::RadioButton());
			this->mkLabel = (gcnew System::Windows::Forms::Label());
			this->mkTextBox = (gcnew System::Windows::Forms::TextBox());
			this->initialtextOpenFileButton = (gcnew System::Windows::Forms::Button());
			this->finaltextOpenFileButton = (gcnew System::Windows::Forms::Button());
			this->statusStrip = (gcnew System::Windows::Forms::StatusStrip());
			this->statusLabel = (gcnew System::Windows::Forms::ToolStripStatusLabel());
			this->demoCheckBox = (gcnew System::Windows::Forms::CheckBox());
			this->settingsiniCheckBox = (gcnew System::Windows::Forms::CheckBox());
			this->keyexplainLabel = (gcnew System::Windows::Forms::Label());
			lookmkButton = (gcnew System::Windows::Forms::Button());
			this->statusStrip->SuspendLayout();
			this->SuspendLayout();
			// 
			// lookmkButton
			// 
			lookmkButton->Location = System::Drawing::Point(450, 232);
			lookmkButton->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			lookmkButton->Name = L"lookmkButton";
			lookmkButton->Size = System::Drawing::Size(63, 27);
			lookmkButton->TabIndex = 19;
			lookmkButton->Text = L"Look";
			lookmkButton->UseVisualStyleBackColor = true;
			lookmkButton->Click += gcnew System::EventHandler(this, &Main::lookmkButton_Click);
			// 
			// startButton
			// 
			this->startButton->Cursor = System::Windows::Forms::Cursors::Hand;
			this->startButton->Enabled = false;
			this->startButton->Font = (gcnew System::Drawing::Font(L"Arial Narrow", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->startButton->Location = System::Drawing::Point(15, 288);
			this->startButton->Margin = System::Windows::Forms::Padding(4);
			this->startButton->Name = L"startButton";
			this->startButton->Size = System::Drawing::Size(694, 49);
			this->startButton->TabIndex = 0;
			this->startButton->Text = L"Start SM4";
			this->startButton->UseVisualStyleBackColor = true;
			this->startButton->Click += gcnew System::EventHandler(this, &Main::startButton_Click);
			// 
			// Intro
			// 
			this->Intro->AutoSize = true;
			this->Intro->Font = (gcnew System::Drawing::Font(L"Arial Narrow", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->Intro->Location = System::Drawing::Point(243, 9);
			this->Intro->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->Intro->Name = L"Intro";
			this->Intro->Size = System::Drawing::Size(247, 29);
			this->Intro->TabIndex = 2;
			this->Intro->Text = L"SM4 Demo (for only *.txt)";
			this->Intro->TextAlign = System::Drawing::ContentAlignment::TopCenter;
			// 
			// initialtextTextBox
			// 
			this->initialtextTextBox->Location = System::Drawing::Point(124, 70);
			this->initialtextTextBox->Margin = System::Windows::Forms::Padding(4);
			this->initialtextTextBox->Name = L"initialtextTextBox";
			this->initialtextTextBox->Size = System::Drawing::Size(515, 22);
			this->initialtextTextBox->TabIndex = 3;
			this->initialtextTextBox->TextChanged += gcnew System::EventHandler(this, &Main::initialtextTextBox_TextChanged);
			// 
			// initextLabel
			// 
			this->initextLabel->AutoSize = true;
			this->initextLabel->Location = System::Drawing::Point(12, 74);
			this->initextLabel->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->initextLabel->Name = L"initextLabel";
			this->initextLabel->Size = System::Drawing::Size(94, 16);
			this->initextLabel->TabIndex = 4;
			this->initextLabel->Text = L"Initialtext (path)";
			// 
			// cryptionRadioButton
			// 
			this->cryptionRadioButton->AutoSize = true;
			this->cryptionRadioButton->Checked = true;
			this->cryptionRadioButton->Location = System::Drawing::Point(124, 182);
			this->cryptionRadioButton->Margin = System::Windows::Forms::Padding(4);
			this->cryptionRadioButton->Name = L"cryptionRadioButton";
			this->cryptionRadioButton->Size = System::Drawing::Size(114, 25);
			this->cryptionRadioButton->TabIndex = 6;
			this->cryptionRadioButton->TabStop = true;
			this->cryptionRadioButton->Text = L"Encryption";
			this->cryptionRadioButton->UseVisualStyleBackColor = true;
			// 
			// finaltextLabel
			// 
			this->finaltextLabel->AutoSize = true;
			this->finaltextLabel->Location = System::Drawing::Point(11, 130);
			this->finaltextLabel->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->finaltextLabel->Name = L"finaltextLabel";
			this->finaltextLabel->Size = System::Drawing::Size(93, 16);
			this->finaltextLabel->TabIndex = 7;
			this->finaltextLabel->Text = L"Finaltext (path)";
			// 
			// finaltextTextBox
			// 
			this->finaltextTextBox->Location = System::Drawing::Point(124, 127);
			this->finaltextTextBox->Margin = System::Windows::Forms::Padding(4);
			this->finaltextTextBox->Name = L"finaltextTextBox";
			this->finaltextTextBox->Size = System::Drawing::Size(515, 22);
			this->finaltextTextBox->TabIndex = 8;
			this->finaltextTextBox->TextChanged += gcnew System::EventHandler(this, &Main::finaltextTextBox_TextChanged);
			// 
			// modeLabel
			// 
			this->modeLabel->AutoSize = true;
			this->modeLabel->Location = System::Drawing::Point(11, 185);
			this->modeLabel->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->modeLabel->Name = L"modeLabel";
			this->modeLabel->Size = System::Drawing::Size(42, 16);
			this->modeLabel->TabIndex = 9;
			this->modeLabel->Text = L"Mode";
			// 
			// decryptionRadioButton
			// 
			this->decryptionRadioButton->AutoSize = true;
			this->decryptionRadioButton->Location = System::Drawing::Point(288, 182);
			this->decryptionRadioButton->Margin = System::Windows::Forms::Padding(4);
			this->decryptionRadioButton->Name = L"decryptionRadioButton";
			this->decryptionRadioButton->Size = System::Drawing::Size(93, 20);
			this->decryptionRadioButton->TabIndex = 10;
			this->decryptionRadioButton->Text = L"Decryption";
			this->decryptionRadioButton->UseVisualStyleBackColor = true;
			// 
			// mkLabel
			// 
			this->mkLabel->AutoSize = true;
			this->mkLabel->Location = System::Drawing::Point(11, 239);
			this->mkLabel->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->mkLabel->Name = L"mkLabel";
			this->mkLabel->Size = System::Drawing::Size(35, 16);
			this->mkLabel->TabIndex = 11;
			this->mkLabel->Text = L"Key*";
			// 
			// mkTextBox
			// 
			this->mkTextBox->Location = System::Drawing::Point(124, 234);
			this->mkTextBox->Margin = System::Windows::Forms::Padding(4);
			this->mkTextBox->Name = L"mkTextBox";
			this->mkTextBox->PasswordChar = '*';
			this->mkTextBox->Size = System::Drawing::Size(319, 22);
			this->mkTextBox->TabIndex = 12;
			this->mkTextBox->TextChanged += gcnew System::EventHandler(this, &Main::mkTextBox_TextChanged);
			this->mkTextBox->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &Main::mkTextBox_KeyPress);
			// 
			// initialtextOpenFileButton
			// 
			this->initialtextOpenFileButton->Location = System::Drawing::Point(646, 68);
			this->initialtextOpenFileButton->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->initialtextOpenFileButton->Name = L"initialtextOpenFileButton";
			this->initialtextOpenFileButton->Size = System::Drawing::Size(63, 27);
			this->initialtextOpenFileButton->TabIndex = 16;
			this->initialtextOpenFileButton->Text = L"Open";
			this->initialtextOpenFileButton->UseVisualStyleBackColor = true;
			this->initialtextOpenFileButton->Click += gcnew System::EventHandler(this, &Main::initialtextOpenFileButton_Click);
			// 
			// finaltextOpenFileButton
			// 
			this->finaltextOpenFileButton->Location = System::Drawing::Point(646, 125);
			this->finaltextOpenFileButton->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->finaltextOpenFileButton->Name = L"finaltextOpenFileButton";
			this->finaltextOpenFileButton->Size = System::Drawing::Size(63, 27);
			this->finaltextOpenFileButton->TabIndex = 17;
			this->finaltextOpenFileButton->Text = L"Open";
			this->finaltextOpenFileButton->UseVisualStyleBackColor = true;
			this->finaltextOpenFileButton->Click += gcnew System::EventHandler(this, &Main::finaltextOpenFileButton_Click);
			// 
			// statusStrip
			// 
			this->statusStrip->ImageScalingSize = System::Drawing::Size(20, 20);
			this->statusStrip->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) { this->statusLabel });
			this->statusStrip->Location = System::Drawing::Point(0, 348);
			this->statusStrip->Name = L"statusStrip";
			this->statusStrip->Padding = System::Windows::Forms::Padding(1, 0, 13, 0);
			this->statusStrip->Size = System::Drawing::Size(721, 26);
			this->statusStrip->SizingGrip = false;
			this->statusStrip->TabIndex = 18;
			this->statusStrip->Text = L"statusStrip1";
			// 
			// statusLabel
			// 
			this->statusLabel->Name = L"statusLabel";
			this->statusLabel->Size = System::Drawing::Size(243, 20);
			this->statusLabel->Text = L"Enter the required data in the fields";
			// 
			// demoCheckBox
			// 
			this->demoCheckBox->AutoSize = true;
			this->demoCheckBox->Location = System::Drawing::Point(524, 234);
			this->demoCheckBox->Margin = System::Windows::Forms::Padding(4);
			this->demoCheckBox->Name = L"demoCheckBox";
			this->demoCheckBox->Size = System::Drawing::Size(179, 20);
			this->demoCheckBox->TabIndex = 20;
			this->demoCheckBox->Text = L"with Demonstration Mode";
			this->demoCheckBox->UseVisualStyleBackColor = true;
			// 
			// settingsiniCheckBox
			// 
			this->settingsiniCheckBox->AutoSize = true;
			this->settingsiniCheckBox->Location = System::Drawing::Point(524, 261);
			this->settingsiniCheckBox->Name = L"settingsiniCheckBox";
			this->settingsiniCheckBox->Size = System::Drawing::Size(168, 20);
			this->settingsiniCheckBox->TabIndex = 21;
			this->settingsiniCheckBox->Text = L"generate settings.ini file";
			this->settingsiniCheckBox->UseVisualStyleBackColor = true;
			// 
			// keyexplainLabel
			// 
			this->keyexplainLabel->AutoSize = true;
			this->keyexplainLabel->Location = System::Drawing::Point(121, 264);
			this->keyexplainLabel->Name = L"keyexplainLabel";
			this->keyexplainLabel->Size = System::Drawing::Size(124, 16);
			this->keyexplainLabel->TabIndex = 22;
			this->keyexplainLabel->Text = L"*up to 16 characters";
			// 
			// Main
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(721, 374);
			this->Controls->Add(this->keyexplainLabel);
			this->Controls->Add(this->settingsiniCheckBox);
			this->Controls->Add(this->demoCheckBox);
			this->Controls->Add(lookmkButton);
			this->Controls->Add(this->statusStrip);
			this->Controls->Add(this->finaltextOpenFileButton);
			this->Controls->Add(this->initialtextOpenFileButton);
			this->Controls->Add(this->mkTextBox);
			this->Controls->Add(this->mkLabel);
			this->Controls->Add(this->decryptionRadioButton);
			this->Controls->Add(this->modeLabel);
			this->Controls->Add(this->finaltextTextBox);
			this->Controls->Add(this->finaltextLabel);
			this->Controls->Add(this->cryptionRadioButton);
			this->Controls->Add(this->initextLabel);
			this->Controls->Add(this->initialtextTextBox);
			this->Controls->Add(this->Intro);
			this->Controls->Add(this->startButton);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedDialog;
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->Margin = System::Windows::Forms::Padding(4);
			this->Name = L"Main";
			this->Text = L"SM4 Demo";
			this->Load += gcnew System::EventHandler(this, &Main::Main_Load);
			this->statusStrip->ResumeLayout(false);
			this->statusStrip->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
//=========================================================================================================
	private: void check_textboxes() {
		if (initialtextTextBox->Text != "" && finaltextTextBox->Text != "" && mkTextBox->Text != "")
			startButton->Enabled = true;
	}
//=========================================================================================================
	private: void save_new_settingsfile() {
		auto initialtext_path = Marshal::StringToHGlobalUni(initialtextTextBox->Text);
		auto finaltext_path = Marshal::StringToHGlobalUni(finaltextTextBox->Text);
		auto mk_path = Marshal::StringToHGlobalUni(mkTextBox->Text);

		WritePrivateProfileString(L"Main", L"initialtext", (LPCWSTR)initialtext_path.ToPointer(), setting_ini_path);
		WritePrivateProfileString(L"Main", L"finaltext", (LPCWSTR)finaltext_path.ToPointer(), setting_ini_path);
		WritePrivateProfileString(L"Main", L"MK", (LPCWSTR)mk_path.ToPointer(), setting_ini_path);

		Marshal::FreeHGlobal(initialtext_path);
		Marshal::FreeHGlobal(finaltext_path);
		Marshal::FreeHGlobal(mk_path);
	}
//=========================================================================================================
	private: System::Void Main_Load(System::Object^ sender, System::EventArgs^ e) {
		FileInfo^ save_file = gcnew FileInfo(gcnew String(setting_ini_path));
		if (save_file->Exists) {
			const WORD SIZE = 256;
			TCHAR buffer[SIZE] = {};

			GetPrivateProfileString(L"Main", L"initialtext", L"", buffer, SIZE, setting_ini_path);
			initialtextTextBox->Text = gcnew String(buffer);
			GetPrivateProfileString(L"Main", L"finaltext", L"", buffer, SIZE, setting_ini_path);
			finaltextTextBox->Text = gcnew String(buffer);
			GetPrivateProfileString(L"Main", L"MK", L"", buffer, SIZE, setting_ini_path);
			mkTextBox->Text = gcnew String(buffer);
		}
	}

	private: System::Void initialtextOpenFileButton_Click(System::Object^ sender, System::EventArgs^ e) {
		open_file_dialog_for_textbox(initialtextTextBox);
	}
	private: System::Void finaltextOpenFileButton_Click(System::Object^ sender, System::EventArgs^ e) {
		open_file_dialog_for_textbox(finaltextTextBox);
	}


//=========================================================================================================
	private: System::Void startButton_Click(System::Object^ sender, System::EventArgs^ e) {
		statusLabel->Text = "Data initializating. . .";
		String^ path_initialtext = initialtextTextBox->Text;
		String^ path_finaltext = finaltextTextBox->Text;

		File^ file_path;
		if (file_path->Exists(path_initialtext)) {
			E_Encrypt_Mode encrypt_mode = (E_Encrypt_Mode)cryptionRadioButton->Checked;
			E_Demo_Mode demo_mode = (E_Demo_Mode)demoCheckBox->Checked;
			DWORD MK[4] = {};
			convert_string_to_dword_for_MK(mkTextBox, MK);
			
			statusLabel->Text = "SM4 process is working. . .";
			SM4Process(path_initialtext, path_finaltext, encrypt_mode, MK, demo_mode);
			statusLabel->Text = "Done! Result saved in " + finaltextTextBox->Text;

			if (settingsiniCheckBox->Checked)
				save_new_settingsfile();
		}
		else
			statusLabel->Text = "Invalid paths to initialtext file";
	}
//=========================================================================================================
///
///
///
///


private: System::Void initialtextTextBox_TextChanged(System::Object^ sender, System::EventArgs^ e) {
	check_textboxes();
}
private: System::Void finaltextTextBox_TextChanged(System::Object^ sender, System::EventArgs^ e) {
	check_textboxes();
}
private: System::Void mkTextBox_TextChanged(System::Object^ sender, System::EventArgs^ e) {
	check_textboxes();
}

private: System::Void lookmkButton_Click(System::Object^ sender, System::EventArgs^ e) {
	mkTextBox->PasswordChar = mkTextBox->PasswordChar ? '\0' : PASS_CHAR;
}
private: System::Void mkTextBox_KeyPress(System::Object^ sender, System::Windows::Forms::KeyPressEventArgs^ e) {
	e->Handled = mkTextBox->Text->Length >= MK_MAXLENGTH;
	if (e->KeyChar == (char)Keys::Back)
		e->Handled = false;
}
};
}