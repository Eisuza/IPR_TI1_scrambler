#pragma once
#include "Statistics.h"
#include "Analyze.h"

namespace IPR1TI {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	public ref class MainWindow : public System::Windows::Forms::Form
	{
	public:
		MainWindow(void)
		{
			InitializeComponent();
		}
	protected:
		~MainWindow()
		{
			if (components)
			{
				delete components;
			}
		}

	private: System::Windows::Forms::TextBox^ input_text;
	private: System::Windows::Forms::TextBox^ output_text;
	private: System::Windows::Forms::TextBox^ key_text;
	internal: System::Windows::Forms::Button^ btn_input_text;
	private:

	private: System::Windows::Forms::Button^ btn_key_input;
	private: System::Windows::Forms::Button^ btn_output_save;
	private: System::Windows::Forms::Button^ btn_key_save;
	private: System::Windows::Forms::Button^ btn_encrypt;
	private: System::Windows::Forms::Button^ btn_decrypt;
	private: System::Windows::Forms::Button^ btn_clean;
	private: System::Windows::Forms::OpenFileDialog^ openFileDialog1;
	private: System::Windows::Forms::SaveFileDialog^ saveFileDialog1;
	private: System::Windows::Forms::Button^ btn_menu_encrypt;
	private: System::Windows::Forms::Button^ btn_menu_decrypt;
	private: System::Windows::Forms::Button^ btn_input_binary;
	private: System::Windows::Forms::Button^ btn_show_frequency;
	private: System::Windows::Forms::Button^ btn_show_analyze;

	private: 
		String^ FileNameInput = "";
		String^ FileNameKey = "";
		String^ FileNameOutput = "";
		String^ FileNameKeySave = "";
		int alphabet_size = 29;
		int random_values_amount = 900;
		static array <String^>^ alphabet = gcnew array<String^>{ "A", "B", "C", "D", "E", "F", "G", "H", "I", "J", "K", "L", "M", "N",
							"O", "P", "Q", "R", "S", "T", "U", "V", "W", "X", "Y", "Z", ".", ",", " " };
		array<int>^ random_values;
		array<int>^ ch_frequency;
		array<array<int>^>^ table;
		array<int>^ encrypted_message;
		int message_size;
		array<array<int>^>^ decryption_table;
		int decryption_table_size;
		array <String^>^ output_message;
		array<int>^ en_frequency;
		array<array<int>^>^ statistics_table;

	protected:

	private:
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(MainWindow::typeid));
			this->input_text = (gcnew System::Windows::Forms::TextBox());
			this->output_text = (gcnew System::Windows::Forms::TextBox());
			this->key_text = (gcnew System::Windows::Forms::TextBox());
			this->btn_input_text = (gcnew System::Windows::Forms::Button());
			this->btn_key_input = (gcnew System::Windows::Forms::Button());
			this->btn_output_save = (gcnew System::Windows::Forms::Button());
			this->btn_key_save = (gcnew System::Windows::Forms::Button());
			this->btn_encrypt = (gcnew System::Windows::Forms::Button());
			this->btn_decrypt = (gcnew System::Windows::Forms::Button());
			this->btn_clean = (gcnew System::Windows::Forms::Button());
			this->openFileDialog1 = (gcnew System::Windows::Forms::OpenFileDialog());
			this->saveFileDialog1 = (gcnew System::Windows::Forms::SaveFileDialog());
			this->btn_menu_encrypt = (gcnew System::Windows::Forms::Button());
			this->btn_menu_decrypt = (gcnew System::Windows::Forms::Button());
			this->btn_input_binary = (gcnew System::Windows::Forms::Button());
			this->btn_show_frequency = (gcnew System::Windows::Forms::Button());
			this->btn_show_analyze = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// input_text
			// 
			this->input_text->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(250)), static_cast<System::Int32>(static_cast<System::Byte>(247)),
				static_cast<System::Int32>(static_cast<System::Byte>(248)));
			this->input_text->Cursor = System::Windows::Forms::Cursors::IBeam;
			resources->ApplyResources(this->input_text, L"input_text");
			this->input_text->Name = L"input_text";
			// 
			// output_text
			// 
			this->output_text->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(250)), static_cast<System::Int32>(static_cast<System::Byte>(247)),
				static_cast<System::Int32>(static_cast<System::Byte>(248)));
			resources->ApplyResources(this->output_text, L"output_text");
			this->output_text->Name = L"output_text";
			// 
			// key_text
			// 
			this->key_text->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(250)), static_cast<System::Int32>(static_cast<System::Byte>(247)),
				static_cast<System::Int32>(static_cast<System::Byte>(248)));
			resources->ApplyResources(this->key_text, L"key_text");
			this->key_text->Name = L"key_text";
			// 
			// btn_input_text
			// 
			this->btn_input_text->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(156)), static_cast<System::Int32>(static_cast<System::Byte>(64)),
				static_cast<System::Int32>(static_cast<System::Byte>(87)));
			this->btn_input_text->FlatAppearance->BorderSize = 0;
			resources->ApplyResources(this->btn_input_text, L"btn_input_text");
			this->btn_input_text->Name = L"btn_input_text";
			this->btn_input_text->UseVisualStyleBackColor = false;
			this->btn_input_text->Click += gcnew System::EventHandler(this, &MainWindow::btn_input_text_Click);
			// 
			// btn_key_input
			// 
			this->btn_key_input->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(156)), static_cast<System::Int32>(static_cast<System::Byte>(64)),
				static_cast<System::Int32>(static_cast<System::Byte>(87)));
			this->btn_key_input->FlatAppearance->BorderSize = 0;
			resources->ApplyResources(this->btn_key_input, L"btn_key_input");
			this->btn_key_input->Name = L"btn_key_input";
			this->btn_key_input->UseVisualStyleBackColor = false;
			this->btn_key_input->Click += gcnew System::EventHandler(this, &MainWindow::btn_key_input_Click);
			// 
			// btn_output_save
			// 
			this->btn_output_save->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(156)), static_cast<System::Int32>(static_cast<System::Byte>(64)),
				static_cast<System::Int32>(static_cast<System::Byte>(87)));
			this->btn_output_save->FlatAppearance->BorderSize = 0;
			resources->ApplyResources(this->btn_output_save, L"btn_output_save");
			this->btn_output_save->Name = L"btn_output_save";
			this->btn_output_save->UseVisualStyleBackColor = false;
			this->btn_output_save->Click += gcnew System::EventHandler(this, &MainWindow::btn_output_save_Click);
			// 
			// btn_key_save
			// 
			this->btn_key_save->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(156)), static_cast<System::Int32>(static_cast<System::Byte>(64)),
				static_cast<System::Int32>(static_cast<System::Byte>(87)));
			this->btn_key_save->FlatAppearance->BorderSize = 0;
			resources->ApplyResources(this->btn_key_save, L"btn_key_save");
			this->btn_key_save->Name = L"btn_key_save";
			this->btn_key_save->UseVisualStyleBackColor = false;
			this->btn_key_save->Click += gcnew System::EventHandler(this, &MainWindow::btn_key_save_Click);
			// 
			// btn_encrypt
			// 
			this->btn_encrypt->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(156)), static_cast<System::Int32>(static_cast<System::Byte>(64)),
				static_cast<System::Int32>(static_cast<System::Byte>(87)));
			this->btn_encrypt->FlatAppearance->BorderSize = 0;
			resources->ApplyResources(this->btn_encrypt, L"btn_encrypt");
			this->btn_encrypt->Name = L"btn_encrypt";
			this->btn_encrypt->UseVisualStyleBackColor = false;
			this->btn_encrypt->Click += gcnew System::EventHandler(this, &MainWindow::btn_encrypt_Click);
			// 
			// btn_decrypt
			// 
			this->btn_decrypt->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(156)), static_cast<System::Int32>(static_cast<System::Byte>(64)),
				static_cast<System::Int32>(static_cast<System::Byte>(87)));
			this->btn_decrypt->FlatAppearance->BorderSize = 0;
			resources->ApplyResources(this->btn_decrypt, L"btn_decrypt");
			this->btn_decrypt->Name = L"btn_decrypt";
			this->btn_decrypt->UseVisualStyleBackColor = false;
			this->btn_decrypt->Click += gcnew System::EventHandler(this, &MainWindow::btn_decrypt_Click);
			// 
			// btn_clean
			// 
			this->btn_clean->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(156)), static_cast<System::Int32>(static_cast<System::Byte>(64)),
				static_cast<System::Int32>(static_cast<System::Byte>(87)));
			this->btn_clean->Cursor = System::Windows::Forms::Cursors::Hand;
			this->btn_clean->FlatAppearance->BorderSize = 0;
			resources->ApplyResources(this->btn_clean, L"btn_clean");
			this->btn_clean->Name = L"btn_clean";
			this->btn_clean->UseVisualStyleBackColor = false;
			this->btn_clean->Click += gcnew System::EventHandler(this, &MainWindow::btn_clean_Click);
			// 
			// openFileDialog1
			// 
			this->openFileDialog1->FileName = L"openFileDialog1";
			// 
			// btn_menu_encrypt
			// 
			this->btn_menu_encrypt->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(156)),
				static_cast<System::Int32>(static_cast<System::Byte>(64)), static_cast<System::Int32>(static_cast<System::Byte>(87)));
			resources->ApplyResources(this->btn_menu_encrypt, L"btn_menu_encrypt");
			this->btn_menu_encrypt->Name = L"btn_menu_encrypt";
			this->btn_menu_encrypt->UseVisualStyleBackColor = false;
			this->btn_menu_encrypt->Click += gcnew System::EventHandler(this, &MainWindow::btn_menu_encrypt_Click);
			// 
			// btn_menu_decrypt
			// 
			this->btn_menu_decrypt->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(156)),
				static_cast<System::Int32>(static_cast<System::Byte>(64)), static_cast<System::Int32>(static_cast<System::Byte>(87)));
			resources->ApplyResources(this->btn_menu_decrypt, L"btn_menu_decrypt");
			this->btn_menu_decrypt->Name = L"btn_menu_decrypt";
			this->btn_menu_decrypt->UseVisualStyleBackColor = false;
			this->btn_menu_decrypt->Click += gcnew System::EventHandler(this, &MainWindow::btn_menu_decrypt_Click);
			// 
			// btn_input_binary
			// 
			this->btn_input_binary->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(156)),
				static_cast<System::Int32>(static_cast<System::Byte>(64)), static_cast<System::Int32>(static_cast<System::Byte>(87)));
			resources->ApplyResources(this->btn_input_binary, L"btn_input_binary");
			this->btn_input_binary->Name = L"btn_input_binary";
			this->btn_input_binary->UseVisualStyleBackColor = false;
			this->btn_input_binary->Click += gcnew System::EventHandler(this, &MainWindow::btn_input_binary_Click);
			// 
			// btn_show_frequency
			// 
			this->btn_show_frequency->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(156)),
				static_cast<System::Int32>(static_cast<System::Byte>(64)), static_cast<System::Int32>(static_cast<System::Byte>(87)));
			resources->ApplyResources(this->btn_show_frequency, L"btn_show_frequency");
			this->btn_show_frequency->Name = L"btn_show_frequency";
			this->btn_show_frequency->UseVisualStyleBackColor = false;
			this->btn_show_frequency->Click += gcnew System::EventHandler(this, &MainWindow::btn_show_frequency_Click);
			// 
			// btn_show_analyze
			// 
			this->btn_show_analyze->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(156)),
				static_cast<System::Int32>(static_cast<System::Byte>(64)), static_cast<System::Int32>(static_cast<System::Byte>(87)));
			resources->ApplyResources(this->btn_show_analyze, L"btn_show_analyze");
			this->btn_show_analyze->Name = L"btn_show_analyze";
			this->btn_show_analyze->UseVisualStyleBackColor = false;
			this->btn_show_analyze->Click += gcnew System::EventHandler(this, &MainWindow::btn_show_analyze_Click);
			// 
			// MainWindow
			// 
			resources->ApplyResources(this, L"$this");
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(240)), static_cast<System::Int32>(static_cast<System::Byte>(210)),
				static_cast<System::Int32>(static_cast<System::Byte>(220)));
			this->Controls->Add(this->btn_show_analyze);
			this->Controls->Add(this->btn_show_frequency);
			this->Controls->Add(this->btn_input_binary);
			this->Controls->Add(this->btn_menu_decrypt);
			this->Controls->Add(this->btn_menu_encrypt);
			this->Controls->Add(this->btn_clean);
			this->Controls->Add(this->btn_decrypt);
			this->Controls->Add(this->btn_encrypt);
			this->Controls->Add(this->btn_key_save);
			this->Controls->Add(this->btn_output_save);
			this->Controls->Add(this->btn_key_input);
			this->Controls->Add(this->btn_input_text);
			this->Controls->Add(this->key_text);
			this->Controls->Add(this->output_text);
			this->Controls->Add(this->input_text);
			this->ForeColor = System::Drawing::Color::White;
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedDialog;
			this->Name = L"MainWindow";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
		private: System::Void btn_menu_encrypt_Click(System::Object^ sender, System::EventArgs^ e);
		private: System::Void btn_menu_decrypt_Click(System::Object^ sender, System::EventArgs^ e);
		private: System::Void btn_input_text_Click(System::Object^ sender, System::EventArgs^ e);
		private: System::Void btn_input_binary_Click(System::Object^ sender, System::EventArgs^ e);
		private: System::Void btn_key_input_Click(System::Object^ sender, System::EventArgs^ e);
		private: System::Void btn_clean_Click(System::Object^ sender, System::EventArgs^ e);
		private: System::Void btn_encrypt_Click(System::Object^ sender, System::EventArgs^ e);
		private: System::Void btn_decrypt_Click(System::Object^ sender, System::EventArgs^ e);
		private: System::Void btn_key_save_Click(System::Object^ sender, System::EventArgs^ e);
		private: System::Void btn_output_save_Click(System::Object^ sender, System::EventArgs^ e);
		private: System::Void btn_show_frequency_Click(System::Object^ sender, System::EventArgs^ e);
		private: System::Void btn_show_analyze_Click(System::Object^ sender, System::EventArgs^ e);

		private: void input_text_file();
		private: void input_binary_file();
		private: array<int>^ create_random_values();
		private: array<int>^ get_character_frequency();
		private: array<array<int>^>^ create_encryption_table();
		private: void print_key();
		private: array<int>^ encrypt_message();
		private: void print_output_encrypted();
		private: void save_key();
		private: void save_output();
		private: void get_key();
		private: void print_decryption_table();
		private: void sort_statistics_table();
		private: void decrypt_message();
		private: void print_output_decrypted();
		private: void input_diagram();
		private: void get_encryption_frequency();
		private: void output_diagram();
		private: array<array<int>^>^ create_statistics_table();
		private: void set_up_statistics();
	};
}
