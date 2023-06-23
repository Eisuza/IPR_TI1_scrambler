#pragma once

namespace IPR1TI {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	public ref class Analyze : public System::Windows::Forms::Form
	{
	public:
		Analyze(void)
		{
			InitializeComponent();
		}

	protected:
		~Analyze()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::TextBox^ original;
	protected:
	private: System::Windows::Forms::TextBox^ encrypted;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ label2;

	private:
		String^ original_text = "Символ : Количество\r\n";
		String^ encrypted_text = "Количество : Код : Символ\r\n";

	private:
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(Analyze::typeid));
			this->original = (gcnew System::Windows::Forms::TextBox());
			this->encrypted = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// original
			// 
			this->original->Location = System::Drawing::Point(55, 68);
			this->original->Multiline = true;
			this->original->Name = L"original";
			this->original->ScrollBars = System::Windows::Forms::ScrollBars::Vertical;
			this->original->Size = System::Drawing::Size(250, 580);
			this->original->TabIndex = 0;
			// 
			// encrypted
			// 
			this->encrypted->Location = System::Drawing::Point(372, 68);
			this->encrypted->Multiline = true;
			this->encrypted->Name = L"encrypted";
			this->encrypted->ScrollBars = System::Windows::Forms::ScrollBars::Vertical;
			this->encrypted->Size = System::Drawing::Size(250, 580);
			this->encrypted->TabIndex = 1;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label1->ForeColor = System::Drawing::SystemColors::GrayText;
			this->label1->Location = System::Drawing::Point(51, 32);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(145, 20);
			this->label1->TabIndex = 2;
			this->label1->Text = L"Исходный текст";
			// 
			// label2
			// 
			this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label2->ForeColor = System::Drawing::SystemColors::GrayText;
			this->label2->Location = System::Drawing::Point(368, 32);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(208, 20);
			this->label2->TabIndex = 0;
			this->label2->Text = L"Зашифрованный текст";
			// 
			// Analyze
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"$this.BackgroundImage")));
			this->ClientSize = System::Drawing::Size(684, 761);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->encrypted);
			this->Controls->Add(this->original);
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->MaximumSize = System::Drawing::Size(700, 800);
			this->MinimumSize = System::Drawing::Size(700, 800);
			this->Name = L"Analyze";
			this->Text = L"Analyze";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	public:
		void set_original_statistics(String^ character, int amount) {
			original_text = original_text + character + " : " + amount + "\r\n";
		}
		void show_original_statistics() {
			this->original->Text = original_text;
		}
		void set_encrypted_statistics(int code, String^ symbol, int amount) {
			encrypted_text = encrypted_text + amount + " : " + code + " : " + symbol + "\r\n";
		}
		void show_encrypted_statistics() {
			this->encrypted->Text = encrypted_text;
		}
	};
}
