#include "MainWindow.h"
#include <ctime>
#include <iostream>
#include <math.h>

using namespace System;
using namespace System::Windows::Forms;
using namespace System::IO;

[STAThreadAttribute]

int main(array<String^>^ args) {
	Application::SetCompatibleTextRenderingDefault(false);
	Application::EnableVisualStyles();
	IPR1TI::MainWindow window;
	Application::Run(% window);
}

System::Void IPR1TI::MainWindow::btn_menu_encrypt_Click(System::Object^ sender, System::EventArgs^ e)
{
	btn_input_text->Visible = true;
	btn_menu_encrypt->Enabled = false;
	btn_menu_decrypt->Visible = false;
	return System::Void();
}

System::Void IPR1TI::MainWindow::btn_menu_decrypt_Click(System::Object^ sender, System::EventArgs^ e)
{
	btn_input_binary->Visible = true;
	btn_menu_decrypt->Enabled = false;
	btn_menu_encrypt->Visible = false;
	return System::Void();
}

System::Void IPR1TI::MainWindow::btn_input_text_Click(System::Object^ sender, System::EventArgs^ e)
{
	input_text_file();
	input_text->Visible = true;
	btn_encrypt->Visible = true;
	btn_clean->Visible = true;
	return System::Void();
}

System::Void IPR1TI::MainWindow::btn_input_binary_Click(System::Object^ sender, System::EventArgs^ e)
{
	input_binary_file();
	input_text->Visible = true;
	btn_key_input->Visible = true;
	btn_clean->Visible = true;
	return System::Void();
}

System::Void IPR1TI::MainWindow::btn_key_input_Click(System::Object^ sender, System::EventArgs^ e)
{
	get_key();
	print_decryption_table();
	key_text->Visible = true;
	btn_decrypt->Visible = true;
	return System::Void();
}

System::Void IPR1TI::MainWindow::btn_clean_Click(System::Object^ sender, System::EventArgs^ e)
{
	btn_input_text->Visible = false;
	btn_input_text->Enabled = true;
	btn_input_binary->Visible = false;
	btn_input_binary->Enabled = true;
	btn_key_input->Visible = false;
	btn_key_input->Enabled = true;
	btn_encrypt->Visible = false;
	btn_encrypt->Enabled = true;
	btn_decrypt->Visible = false;
	btn_clean->Visible = false;
	btn_key_save->Visible = false;
	btn_output_save->Visible = false;
	input_text->Visible = false;
	key_text->Visible = false;
	output_text->Visible = false;
	btn_show_frequency->Visible = false;
	btn_show_analyze->Visible = false;
	btn_menu_encrypt->Enabled = true;
	btn_menu_decrypt->Enabled = true;
	btn_menu_encrypt->Visible = true;
	btn_menu_decrypt->Visible = true;
	FileNameInput = "";
	FileNameKey = "";
	FileNameOutput = "";
	FileNameKeySave = "";
	return System::Void();
}

System::Void IPR1TI::MainWindow::btn_encrypt_Click(System::Object^ sender, System::EventArgs^ e)
{
	random_values = create_random_values();		//create a new key
	ch_frequency = get_character_frequency();
	table = create_encryption_table();
	statistics_table = create_statistics_table();
	print_key();								//show the key
	encrypted_message = encrypt_message();
	message_size = table[alphabet_size][0];
	print_output_encrypted();

	key_text->Visible = true;
	btn_key_save->Visible = true;
	output_text->Visible = true;
	btn_output_save->Visible = true;
	btn_input_text->Enabled = false;
	btn_encrypt->Enabled = false;
	btn_show_frequency->Visible = true;
	btn_show_analyze->Visible = true;
	return System::Void();
}

System::Void IPR1TI::MainWindow::btn_decrypt_Click(System::Object^ sender, System::EventArgs^ e)
{
	decrypt_message();
	print_output_decrypted();
	output_text->Visible = true;
	return System::Void();
}

System::Void IPR1TI::MainWindow::btn_key_save_Click(System::Object^ sender, System::EventArgs^ e)
{
	save_key();
	return System::Void();
}

System::Void IPR1TI::MainWindow::btn_output_save_Click(System::Object^ sender, System::EventArgs^ e)
{
	save_output();
	return System::Void();
}

System::Void IPR1TI::MainWindow::btn_show_frequency_Click(System::Object^ sender, System::EventArgs^ e)
{
	input_diagram();
	get_encryption_frequency();
	output_diagram();
	return System::Void();
}

System::Void IPR1TI::MainWindow::btn_show_analyze_Click(System::Object^ sender, System::EventArgs^ e)
{
	sort_statistics_table();
	set_up_statistics();
	return System::Void();
}

void IPR1TI::MainWindow::input_text_file()
{
	if (openFileDialog1->ShowDialog() == Windows::Forms::DialogResult::OK) {
		FileNameInput = openFileDialog1->FileName;
	}
	try	{
		StreamReader^ file = File::OpenText(FileNameInput);
		input_text->Text = file->ReadToEnd();
		file->Close();
	}
	catch (Exception^ e) {
		MessageBox::Show(this, "Файл не был загружен или загружен не полностью", "Информация", MessageBoxButtons::OK, MessageBoxIcon::Information);
	}
}

void IPR1TI::MainWindow::input_binary_file()
{
	if (openFileDialog1->ShowDialog() == Windows::Forms::DialogResult::OK) {
		FileNameInput = openFileDialog1->FileName;
	}
	try
	{
		String^ a = "Пробелы использованы для наглядности: \r\n";

		FileStream^ file = gcnew FileStream(FileNameInput, FileMode::Open);
		BinaryReader^ reader = gcnew BinaryReader(file);
		message_size = reader->BaseStream->Length / 4;					//sizeof(int)
		
		for (int i = 0; i < message_size; i++) {
			a = a + reader->ReadInt32() + " ";
		}
		input_text->Text = a;

		file->Close();
	}
	catch (Exception^ e)
	{
		MessageBox::Show(this, "Не получилось открыть файл с ключом", "Информация", MessageBoxButtons::OK, MessageBoxIcon::Information);
	}
}

array<int>^ IPR1TI::MainWindow::create_random_values()
{
	srand(static_cast<unsigned int>(time(0)));
	array<int>^ random_values = gcnew array<int>(random_values_amount);
	for (int i = 0; i < random_values_amount; i++)
		random_values[i] = 0;
	bool used;
	int newRandomValue = 0;
	for (int i = 0; i < random_values_amount;) {
		used = false;
		newRandomValue = (rand() % random_values_amount) + 100;
		for (int j = 0; j < i; j++)	{
			if (random_values[j] == newRandomValue)	{
				used = true;
				break;
			}
		}
		if (used == false) {
			random_values[i] = newRandomValue;
			i++;
		}
	}
	return random_values;
}

array<int>^ IPR1TI::MainWindow::get_character_frequency()
{
	array<int>^ ch_frequency = gcnew array<int>(alphabet_size+1);	// alphabet_size + message size
	for (int i = 0; i <= alphabet_size; i++)
		ch_frequency[i] = 0;
	char character;
	try	{
		StreamReader^ file = File::OpenText(FileNameInput);
		while (file->Peek() > -1) {
			character = file->Read();
			if (character == 32) {						// space
				ch_frequency[alphabet_size - 1] += 1;
				ch_frequency[alphabet_size] += 1;
			}
			else if (character >= 97 && character <= 122) {	// low case
				ch_frequency[character - 97] += 1;
				ch_frequency[alphabet_size] += 1;
			}
			else if (character == 46) {						// dot
				ch_frequency[alphabet_size - 3] += 1;
				ch_frequency[alphabet_size] += 1;
			}
			else if (character >= 65 && character <= 90) {	// up case
				ch_frequency[character - 65] += 1;
				ch_frequency[alphabet_size] += 1;
			}
			else if (character == 44) {						// comma
				ch_frequency[alphabet_size - 2] += 1;
				ch_frequency[alphabet_size] += 1;
			}
		}
	file->Close();
	}
	catch (Exception^ e) {
		MessageBox::Show(this, "Во время подсчетов произошла ошибка", "Информация", MessageBoxButtons::OK, MessageBoxIcon::Information);
	}
	return ch_frequency;
}

array<array<int>^>^ IPR1TI::MainWindow::create_encryption_table()
{
	array<array<int>^>^ table = gcnew array<array<int>^>(alphabet_size+1);
	int random_values_number = 0;
	int cnt_random_values = 0;
	
	for (int i = 0; i < alphabet_size; i++)	{			// create a table
		random_values_number = floor(random_values_amount * ch_frequency[i] / ch_frequency[alphabet_size]);
		if (random_values_number == 0  && ch_frequency[i] != 0)
			random_values_number = 1;
		table[i] = gcnew array<int>(random_values_number+1);
		table[i][0] = random_values_number;
		for (int j = 1; j <= random_values_number; j++) {
			table[i][j] = random_values[cnt_random_values];
			cnt_random_values += 1;
		}
	}
	table[alphabet_size] = gcnew array<int>(1);
	table[alphabet_size][0] = ch_frequency[alphabet_size];
	return table;
}

void IPR1TI::MainWindow::print_key()
{
	String^ a = "";

	for (int i = 0; i < alphabet_size; i++)	{
		a = a + alphabet[i] + ": ";
		for (int j = 1; j <= table[i][0]; j++)
			a = a + table[i][j] + " ";
		a = a + "\r\n";
	}
	key_text->Text = a;
}

array<int>^ IPR1TI::MainWindow::encrypt_message()
{
	array<int>^ encrypted_message = gcnew array<int>(table[alphabet_size][0]);
	try	{
		StreamReader^ file = File::OpenText(FileNameInput);
		char character;
		int code;
		int cnt_message = 0;

		while ((file->Peek() > -1) && (cnt_message < table[alphabet_size][0])) {
			character = file->Read();
			if (character == 32) {							// space
				code = table[alphabet_size - 1][(rand() % table[alphabet_size - 1][0]) + 1];
				encrypted_message[cnt_message] = code;
				cnt_message += 1;
				statistics_table[code - 100][1] = alphabet_size - 1;
				statistics_table[code - 100][2] += 1;
			}
			else if (character >= 97 && character <= 122) {	// low case
				code = table[character - 97][(rand() % table[character - 97][0]) + 1];
				encrypted_message[cnt_message] = code;
				cnt_message += 1;
				statistics_table[code - 100][1] = character - 97;
				statistics_table[code - 100][2] += 1;
			}
			else if (character == 46) {						// dot
				code = table[alphabet_size - 3][(rand() % table[alphabet_size - 3][0]) + 1];
				encrypted_message[cnt_message] = code;
				cnt_message += 1;
				statistics_table[code - 100][1] = alphabet_size - 3;
				statistics_table[code - 100][2] += 1;
			}
			else if (character >= 65 && character <= 90) {	// up case
				code = table[character - 65][(rand() % table[character - 65][0]) + 1];
				encrypted_message[cnt_message] = code;
				cnt_message += 1;
				statistics_table[code - 100][1] = character - 65;
				statistics_table[code - 100][2] += 1;
			}
			else if (character == 44) {						// comma
				code = table[alphabet_size - 2][(rand() % table[alphabet_size - 2][0]) + 1];
				encrypted_message[cnt_message] = code;
				cnt_message += 1;
				statistics_table[code - 100][1] = alphabet_size - 2;
				statistics_table[code - 100][2] += 1;
			}
		}
		file->Close();
	}
	catch (Exception^ e) {
		MessageBox::Show(this, "Во время шифрования возникла ошибка", "Информация", MessageBoxButtons::OK, MessageBoxIcon::Information);
	}
	return encrypted_message;
}

void IPR1TI::MainWindow::print_output_encrypted()
{
	String^ a = "Пробелы использованы для наглядности: \r\n";
	for (int i = 0; i < message_size; i++) {
		a = a + encrypted_message[i] + " ";
	}
	output_text->Text = a;
}

void IPR1TI::MainWindow::save_key()
{
	if (saveFileDialog1->ShowDialog() == Windows::Forms::DialogResult::OK)	{
		FileNameKeySave = saveFileDialog1->FileName;
	}
	try	{
		FileStream^ file = gcnew FileStream(FileNameKeySave, FileMode::Create);
		BinaryWriter^ writer = gcnew BinaryWriter(file);
		for (int i = 0; i < alphabet_size; i++) {
			writer->Write(table[i][0]);
			for (int j = 1; j <= table[i][0]; j++) {
				writer->Write(table[i][j]);
			}
		}
		file->Close();
	}
	catch (Exception^ e)	{
		MessageBox::Show(this, "Файл не был сохранен", "Информация", MessageBoxButtons::OK, MessageBoxIcon::Information);
	}
}

void IPR1TI::MainWindow::save_output()
{
	if (saveFileDialog1->ShowDialog() == Windows::Forms::DialogResult::OK) {
		FileNameOutput = saveFileDialog1->FileName;
	}
	try {
		FileStream^ file = gcnew FileStream(FileNameOutput, FileMode::Create);
		BinaryWriter^ writer = gcnew BinaryWriter(file);
		for (int i = 0; i < table[alphabet_size][0]; i++) {
			writer->Write(encrypted_message[i]);
		}
		file->Close();
	}
	catch (Exception^ e) {
		MessageBox::Show(this, "Файл не был сохранен", "Информация", MessageBoxButtons::OK, MessageBoxIcon::Information);
	}
}

void IPR1TI::MainWindow::get_key()
{
	if (openFileDialog1->ShowDialog() == Windows::Forms::DialogResult::OK)
	{
		FileNameKey = openFileDialog1->FileName;
	}
	try
	{
		FileStream^ file = gcnew FileStream(FileNameKey, FileMode::Open);
		BinaryReader^ reader = gcnew BinaryReader(file);
		decryption_table = gcnew array<array<int>^>(random_values_amount);
		int amount = 0;
		int code = 0;
		decryption_table_size = 0;
		for (int i = 0; i < alphabet_size; i++) {
			amount = reader->ReadInt32();			// amount of codes for 1 letter
			for (int j = 0; j < amount; j++) {
				decryption_table[decryption_table_size] = gcnew array<int>(2);	// for each code 2 column
				code = reader->ReadInt32();			// amount of codes for 1 letter
				decryption_table[decryption_table_size][0] = code;
				decryption_table[decryption_table_size][1] = i;
				decryption_table_size += 1;
			}
		}
		file->Close();
	}
	catch (Exception^ e)
	{
		MessageBox::Show(this, "Не получилось открыть файл с ключом", "Информация", MessageBoxButtons::OK, MessageBoxIcon::Information);
	}
}

void IPR1TI::MainWindow::print_decryption_table()
{
	String^ a = "";
	for (int i = 0; i < decryption_table_size;) {
		a = a + alphabet[decryption_table[i][1]] + ": " + decryption_table[i][0] + " ";
		while ((i < decryption_table_size-1) && (decryption_table[i][1] == decryption_table[i + 1][1])) {
			a = a + decryption_table[i+1][0] + " ";
			i++;
		}
		a = a + "\r\n";
		i++;
	}
	key_text->Text = a;
}

void IPR1TI::MainWindow::sort_statistics_table()
{
	int flg = 0, temp0 = 0, temp1 = 0, temp2 = 0;
	for (int gap = random_values_amount/2; gap > 0; gap /= 2) {
		do {
			flg = 0;
			for (int i = 0, j = gap; j < random_values_amount; i++, j++) {
				if (statistics_table[i][2] > statistics_table[j][2]) {
					temp0 = statistics_table[j][0];
					temp1 = statistics_table[j][1];
					temp2 = statistics_table[j][2];
					statistics_table[j][0] = statistics_table[i][0];
					statistics_table[j][1] = statistics_table[i][1];
					statistics_table[j][2] = statistics_table[i][2];
					statistics_table[i][0] = temp0;
					statistics_table[i][1] = temp1;
					statistics_table[i][2] = temp2;
					flg = 1;
				}
			}
		} while (flg);
	}
}

void IPR1TI::MainWindow::decrypt_message()
{
	int code;

	FileStream^ file = gcnew FileStream(FileNameInput, FileMode::Open);
	BinaryReader^ reader = gcnew BinaryReader(file);
	message_size = reader->BaseStream->Length / 4;					//sizeof(int)
	output_message = gcnew array<String^>(message_size);
	for (int i = 0; i < message_size; i++){
		code = reader->ReadInt32();
		for (int j = 0; j < decryption_table_size; j++) {
			if (code == decryption_table[j][0]) {
		output_message[i] = alphabet[decryption_table[j][1]];
			}
		}
	}
	file->Close();
}

void IPR1TI::MainWindow::print_output_decrypted(){
	String^ a = "";
	for (int i = 0; i < message_size; i++) {
		a = a + output_message[i];
	}
	output_text->Text = a;
}

void IPR1TI::MainWindow::input_diagram()
{
	Statistics^ StatisticWindow = gcnew Statistics();
	StatisticWindow->Show();
	StatisticWindow->clear_input_diagram();
	for (int i = 0; i < alphabet_size; i++)
	{
		StatisticWindow->set_input_frequency(alphabet[i], ch_frequency[i]);
	}
	StatisticWindow->set_input_diagram_visible();
}

void IPR1TI::MainWindow::get_encryption_frequency()
{
	en_frequency = gcnew array<int>(random_values_amount);
	for (int i = 0; i < random_values_amount; i++) {
		en_frequency[i] = 0;
	}
	for (int i = 0; i < table[alphabet_size][0]; i++) {
		en_frequency[encrypted_message[i] - 100] += 1;
	}
}

void IPR1TI::MainWindow::output_diagram()
{
	Statistics^ StatisticWindow = gcnew Statistics();
	StatisticWindow->Show();
	StatisticWindow->clear_encryption_diagram();
	for (int i = 0; i < random_values_amount; i++)
	{
		if (en_frequency[i] != 0)
			StatisticWindow->set_encryption_frequency(i + 100, en_frequency[i]);
	}
	StatisticWindow->set_encryption_diagram_visible();
}

array<array<int>^>^ IPR1TI::MainWindow::create_statistics_table()
{
	array<array<int>^>^ statistics_table = gcnew array<array<int>^>(random_values_amount);
	for (int i = 0; i < random_values_amount; i++) {
		statistics_table[i] = gcnew array<int>(3);
		statistics_table[i][0] = i + 100;		//code for encryption
		statistics_table[i][1] = 0;				//character
		statistics_table[i][2] = 0;				//code frequency in message
	}
	return statistics_table;
}

void IPR1TI::MainWindow::set_up_statistics()
{
	Analyze^ AnalyzeWindow = gcnew Analyze();
	AnalyzeWindow->Show();
	for (int i = 0; i < alphabet_size; i++)
	{
		AnalyzeWindow->set_original_statistics(alphabet[i], ch_frequency[i]);
	}
	AnalyzeWindow->show_original_statistics();

	for (int i = 0; i < random_values_amount; i++)
	{
		if (statistics_table[i][2] > 0) {
			AnalyzeWindow->set_encrypted_statistics(statistics_table[i][0], alphabet[statistics_table[i][1]], statistics_table[i][2]);
		}
	}
	AnalyzeWindow->show_encrypted_statistics();
}
