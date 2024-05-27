#include "Config.h"

//=========================================================================================================
// Внесення всього тексту у рядок (враховуючи переноси рядка)
string Input_from_File(ifstream& in) {
	string str;
	int c;
	while ((c = in.get()) != EOF)
		str += (char)c;
	return str;
}
//=========================================================================================================
// Відкриття файлу через вікно OpenFileDialog
void open_file_dialog_for_textbox(TextBox^ textbox) {
	OpenFileDialog^ ofd = gcnew OpenFileDialog;
	ofd->Filter = "All files (*.*) | *.*";
	if (ofd->ShowDialog() == System::Windows::Forms::DialogResult::OK)
		textbox->Text = ofd->FileName;
}
//=========================================================================================================
// Перетворення введенного ключа в 16-байтовий масив
void convert_string_to_dword_for_MK(TextBox^ MK_textbox, DWORD MK[]) {
	for (BYTE i = 0, k = 0; i < MK_textbox->Text->Length; i++, k = i / 4) {
		MK[k] = (MK[k] << 8) | MK_textbox->Text[i];
		if (i == MK_textbox->Text->Length - 1)
			MK[k] <<= BIN_DWORD_BLOCK_SIZE - MK_textbox->Text->Length % 4 * 8;
	}
}
//=========================================================================================================
// Заповнення останнього блоку тексту нулями
void fill_text(string& text) {
	BYTE init_length_mod = text.length() % (HEX_DWORD_BLOCK_SIZE * 2);
	DWORD zero_count = init_length_mod ? HEX_DWORD_BLOCK_SIZE * 2 - init_length_mod : 0;
	text.insert(text.end(), zero_count, 0);
}
//=========================================================================================================
// Конвертація та зберігання тексту у символьному вигляді у файл
string translate_hex_to_text(string& hex_text) {
	string ascii_string = "";
	for (size_t i = 0; i < hex_text.length(); i += 2) {
		string byte_string = hex_text.substr(i, 2);
		char byte = (char)strtol(byte_string.c_str(), NULL, 16);
		ascii_string.push_back(byte);
	}
	return ascii_string;
}
//=========================================================================================================
// Конвертація та зберігання тексту у шістнадцятковому вигляді у файл
string translate_text_to_hex(string& text) {
	stringstream ss;
	for (size_t i = 0; i < text.length(); i++) {
		char hex_char[3];
		snprintf(hex_char, 3, "%02x", (BYTE)text[i]);
		ss << hex_char;
	}

	return ss.str();
}
//=========================================================================================================
// Функція, яка бере шістнадцяткове значення з рядка та присвоює (X0, X1, X2, Х3)
void take_hex_value_for_dword(DWORD X[], string& hex_text, size_t index) {
	for (BYTE n = 0; n < 4; n++) {
		DWORD value = 0;
		for (size_t j = 0; j < HEX_DWORD_BLOCK_SIZE; j++) {
			char hex_char = hex_text[index + j + (size_t)n * 8];
			if (hex_char >= '0' && hex_char <= '9')
				value = (value << 4) | (hex_char - '0');
			else if (hex_char >= 'A' && hex_char <= 'F')
				value = (value << 4) | (hex_char - 'A' + 10);
			else if (hex_char >= 'a' && hex_char <= 'f')
				value = (value << 4) | (hex_char - 'a' + 10);
		}
		X[n] = value;
	}
}
//=========================================================================================================
// Функція, яка зберігає результат шифрування у finaltext
void save_finaltext_dword(DWORD X[], string& finaltext_hex) {
	stringstream ss;
	char X_value[9] = {};
	for (BYTE j = 0; j < 4; j++) {
		snprintf(X_value, 9, "%08x", X[3 - j]);
		ss << X_value;
	}

	string X_hex_string = ss.str();
	finaltext_hex += X_hex_string;
}
//=========================================================================================================
void make_demonstration_note(const wchar_t* format, ...) {
	FILE* demo_file = fopen(DEMO_FILE_PATH, "a");

	va_list args;
	va_start(args, format);
	vfwprintf(demo_file, format, args);
	va_end(args);

	fclose(demo_file);
}
//=========================================================================================================