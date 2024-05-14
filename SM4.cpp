#include "SM4.h"

using namespace SM4_Consts;

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
	string ascii_string;
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
		char hex_char[3] = {};
		snprintf(hex_char, 3, "%02x", text[i]);
		ss << hex_char;
	}

	ofstream out("HEX_INPUT.txt");
	out << ss.str();
	out.close();

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
// Функція заміни Т
DWORD T(DWORD x, E_Encrypt_Mode is_encrypt) {
	// 1. SBox()
	BYTE q[4] = {};
	DWORD tau = 0;
	for (BYTE n = 0, j = 0; n <= 24 && j < 4; n += 8, j++) {
		q[j] = (BYTE)((x >> n) & 0xFF);
		q[j] = SBox[q[j]];
		tau ^= q[j] << n;
	}

	// 2. L(tau)
	if (is_encrypt == EEM_Encrypt)
		return tau ^ C_SHL(tau, 2) ^ C_SHL(tau, 10) ^ C_SHL(tau, 18) ^ C_SHL(tau, 24);
	else
		return tau ^ C_SHL(tau, 13) ^ C_SHL(tau, 23);
}
//=========================================================================================================
// Генерація раундових ключів
void Key_Expansion(DWORD MK[], DWORD rk[]) {
	DWORD K[4] = {};
	K[0] = MK[0] ^ FK[0];
	K[1] = MK[1] ^ FK[1];
	K[2] = MK[2] ^ FK[2];
	K[3] = MK[3] ^ FK[3];

	for (BYTE i = 0; i < 32; i++) {
		rk[i] = K[0] ^ T(K[1] ^ K[2] ^ K[3] ^ CK[i], EEM_Decrypt);

		K[0] = K[1];
		K[1] = K[2];
		K[2] = K[3];
		K[3] = rk[i];
	}
}
//=========================================================================================================
// Раунд шифрування блоку
void SM4_Block(DWORD X[], DWORD rk[], E_Encrypt_Mode is_encrypt) {
	DWORD Xtemp = 0;
	for (BYTE i = 0; i < 32; i++) {
		if (is_encrypt == EEM_Encrypt)
			Xtemp = X[0] ^ T(X[1] ^ X[2] ^ X[3] ^ rk[i], EEM_Encrypt);
		else
			Xtemp = X[0] ^ T(X[1] ^ X[2] ^ X[3] ^ rk[31 - i], EEM_Encrypt);
		X[0] = X[1];
		X[1] = X[2];
		X[2] = X[3];
		X[3] = Xtemp;
	}
}
//=========================================================================================================
// Функція виконання алгоритму SM4 із заміром часу виконання
void SM4Process(String^ path_initialtext, String^ path_finaltext, E_Encrypt_Mode encrypt_mode, DWORD MK[]) {
	FileStream^ initialtext_fs = gcnew FileStream(path_initialtext, FileMode::Open, FileAccess::Read);
	StreamReader^ initialtext_sr = gcnew StreamReader(initialtext_fs);
	
	string initialtext = Input_from_File(initialtext_sr);
	fill_text(initialtext);
	
	string initialtext_hex = translate_text_to_hex(initialtext);
	
	// Обчислення кількості блоків, на які ділиться текст повідомлення
	DWORD block_count = (DWORD)initialtext_hex.length() / (HEX_DWORD_BLOCK_SIZE * 4);
	DWORD X[4] = {}, rk[32];

	initialtext_sr->Close();
	initialtext_fs->Close();

	string finaltext_hex;

	// 1. Замір часу генерації ключів
	Key_Expansion(MK, rk);
		
	// 2. Замір часу шифрування блоку
	for (size_t i = 0; i < block_count; i++) {
		take_hex_value_for_dword(X, initialtext_hex, i * 32);
		SM4_Block(X, rk, encrypt_mode);
		save_finaltext_dword(X, finaltext_hex);
	}

	// Вивід кінцевого тексту

	// 1. У hex-вигляді
	ofstream out("HEX_OUTPUT.txt");
	out << finaltext_hex;
	out.close();

	// 2. У строковому вигляді
	FileStream^ finaltext_fs = gcnew FileStream(path_finaltext, FileMode::Create, FileAccess::Write);
	StreamWriter^ finaltext_sw = gcnew StreamWriter(finaltext_fs);

	String^ finaltext = gcnew String(translate_hex_to_text(finaltext_hex).c_str());	
	finaltext_sw->WriteLine(finaltext);
	
	finaltext_sw->Close();
	finaltext_fs->Close();
}
//=========================================================================================================