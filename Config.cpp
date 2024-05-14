#include "Config.h"

//=========================================================================================================
// Внесення всього тексту у рядок (враховуючи переноси рядка)
string Input_from_File(StreamReader^ sr) {
	string str;
	int ch;
	while ((ch = sr->Read()) != -1)
		str += (char)ch;
    return str;
}
//=========================================================================================================
// Внесення всього тексту у рядок (враховуючи переноси рядка)
string Input_from_File(ifstream& in) {
    string str;
    char c;
    while (in.get(c))
        str += c;
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
	for (BYTE i = 0, k = i / 4; i < MK_textbox->Text->Length; i++) {
		MK[k] = (MK[k] << 8) | MK_textbox->Text[i];
		if (i == MK_textbox->Text->Length - 1)
			MK[k] <<= BIN_DWORD_BLOCK_SIZE - MK_textbox->Text->Length % 4 * 8;
	}
}
//=========================================================================================================
