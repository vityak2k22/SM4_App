#include "SM4.h"

using namespace SM4_Consts;

//=========================================================================================================
// Функція заміни Т
DWORD T(DWORD x, E_Encrypt_Mode is_encrypt, E_Demo_Mode is_demo_mode) {
	if (is_demo_mode)
		make_demonstration_note("\n\tT function:\n");
	
	// 1. SBox()
	BYTE q[4] = {};
	DWORD tau = 0;

	if (is_demo_mode)
		make_demonstration_note("\t1) S-box:\n");
	
	for (BYTE n = 0, j = 0; n <= 24 && j < 4; n += 8, j++) {
		q[j] = (BYTE)((x >> n) & 0xFF);
		
		if (is_demo_mode)
			make_demonstration_note("\t\'%02X\' = \'%02X\'\n", q[j], SBox[q[j]]);

		q[j] = SBox[q[j]];
		tau ^= q[j] << n;
	}
	if (is_demo_mode)
		make_demonstration_note("\tS-box result: Tau = %08X\n", tau);

	// 2. L(tau)
	if (is_encrypt == EEM_Encrypt) {
		if (is_demo_mode)
			make_demonstration_note("\t2) L(tau): Tau xor (Tau <<< 2) xor (Tau <<< 10) xor (Tau <<< 18) xor (Tau <<< 24) = \n"
									"\t   = %08X xor (%08X <<< 2) xor (%08X <<< 10) xor (%08X <<< 18) xor (%08X <<< 24) = %08X\n",
									tau, tau, tau, tau, tau, tau ^ C_SHL(tau, 2) ^ C_SHL(tau, 10) ^ C_SHL(tau, 18) ^ C_SHL(tau, 24));
		
		return tau ^ C_SHL(tau, 2) ^ C_SHL(tau, 10) ^ C_SHL(tau, 18) ^ C_SHL(tau, 24);
	}
	else {
		if (is_demo_mode)
			make_demonstration_note("\t2) L(tau): Tau xor (Tau <<< 13) xor (Tau <<< 23) = %08X xor (%08X <<< 13) xor (%08X <<< 23) = %08X\n",
								tau, tau, tau, tau ^ C_SHL(tau, 13) ^ C_SHL(tau, 23));
		
		return tau ^ C_SHL(tau, 13) ^ C_SHL(tau, 23);
	}
}
//=========================================================================================================
// Генерація раундових ключів
void Key_Expansion(DWORD MK[], DWORD rk[], E_Demo_Mode is_demo_mode) {
	if (is_demo_mode)
		make_demonstration_note("===============================================================Key Expansion===============================================================\n"
								"MK = %08X %08X %08X %08X;\n", MK[0], MK[1], MK[2], MK[3]);

	DWORD K[4] = {};
	K[0] = MK[0] ^ FK[0];
	K[1] = MK[1] ^ FK[1];
	K[2] = MK[2] ^ FK[2];
	K[3] = MK[3] ^ FK[3];

	if (is_demo_mode)
		make_demonstration_note("\nK[0] = MK[0] xor FK[0] = %08X xor %08X = %08X\n"
								"K[1] = MK[1] xor FK[1] = %08X xor %08X = %08X\n"
								"K[2] = MK[2] xor FK[2] = %08X xor %08X = %08X\n"
								"K[3] = MK[3] xor FK[3] = %08X xor %08X = %08X\n", 
								MK[0], FK[0], K[0],
								MK[1], FK[1], K[1], 
								MK[2], FK[2], K[2], 
								MK[3], FK[3], K[3]);

	for (BYTE i = 0; i < 32; i++) {
		rk[i] = K[0] ^ T(K[1] ^ K[2] ^ K[3] ^ CK[i], EEM_Decrypt, is_demo_mode);

		if (is_demo_mode)
			make_demonstration_note("\nrk[%d] = K[0] xor T'( K[1] xor K[2] xor K[3] xor CK[%d] ) = "
									"%08X xor T'(%08X xor %08X xor %08X xor %08X) = \n"
									"      = %08X xor T'(%08X) = %08X\n",
									i, i, K[0], K[1], K[2], K[3], CK[i], K[0], K[1] ^ K[2] ^ K[3] ^ CK[i], rk[i]);

		K[0] = K[1];
		K[1] = K[2];
		K[2] = K[3];
		K[3] = rk[i];
	}
}
//=========================================================================================================
// Раунд шифрування блоку
void SM4_Block(DWORD X[], DWORD rk[], E_Encrypt_Mode is_encrypt, E_Demo_Mode is_demo_mode) {
	if (is_demo_mode)
		make_demonstration_note("\n\n============================================================SM4 Block Operation============================================================\n\n");
	
	DWORD Xtemp = 0;
	for (BYTE i = 0; i < 32; i++) {
		if (is_encrypt == EEM_Encrypt)
			Xtemp = X[0] ^ T(X[1] ^ X[2] ^ X[3] ^ rk[i], EEM_Encrypt, is_demo_mode);
		else
			Xtemp = X[0] ^ T(X[1] ^ X[2] ^ X[3] ^ rk[31 - i], EEM_Encrypt, is_demo_mode);
		
		if (is_demo_mode) {
			if (i == 31)
				make_demonstration_note("\n~~~~X Result: ");
			make_demonstration_note("\nX[%d] = X[%d] xor T(X[%d] xor X[%d] xor X[%d] xor rk[%d]) = %08X xor T(%08X xor %08X xor %08X xor %08X) =\n"
									"      = %08X xor T(%08X) = %08X\n",
									i+4, i, i+1, i+2, i+3, is_encrypt ? i : 31 - i,
									X[0], X[1], X[2], X[3], rk[is_encrypt ? i : 31 - i],
									X[0], X[1] ^ X[2] ^ X[3] ^ rk[is_encrypt ? i : 31 - i], Xtemp);
		}

		X[0] = X[1];
		X[1] = X[2];
		X[2] = X[3];
		X[3] = Xtemp;
	}
}
//=========================================================================================================
// Функція виконання алгоритму SM4 із заміром часу виконання
void SM4Process(String^ path_initialtext, String^ path_finaltext, E_Encrypt_Mode encrypt_mode, DWORD MK[], E_Demo_Mode demo_mode) {
	ifstream in((LPCWSTR)Marshal::StringToHGlobalUni(path_initialtext).ToPointer(), ios::binary);
	string initialtext = Input_from_File(in);
	if (encrypt_mode == EEM_Encrypt)
		fill_text(initialtext);
	in.close();

	string initialtext_hex = translate_text_to_hex(initialtext);

	ofstream out("HEX_INPUT.txt");
	out << initialtext_hex;
	out.close();
	
	// Обчислення кількості блоків, на які ділиться текст повідомлення
	DWORD block_count = (DWORD)initialtext_hex.length() / (HEX_DWORD_BLOCK_SIZE * 4);
	DWORD X[4] = {}, rk[32];

	string finaltext_hex;

	// 1. Замір часу генерації ключів
	Key_Expansion(MK, rk, demo_mode);
		
	// 2. Замір часу шифрування блоку
	for (size_t i = 0; i < block_count; i++) {
		take_hex_value_for_dword(X, initialtext_hex, i * 32);
		i == 0 ? SM4_Block(X, rk, encrypt_mode, demo_mode) : SM4_Block(X, rk, encrypt_mode, EDM_Disabled);
		save_finaltext_dword(X, finaltext_hex);
	}

	// Вивід кінцевого тексту
	// 1. У hex-вигляді
	ofstream hex_out("HEX_OUTPUT.txt");
	hex_out << finaltext_hex;
	hex_out.close();

	// 2. У строковому вигляді
	out.open((LPCWSTR)Marshal::StringToHGlobalUni(path_finaltext).ToPointer(), ios::binary);
	string finaltext = translate_hex_to_text(finaltext_hex);
	if (encrypt_mode == EEM_Decrypt) {
		size_t last_non_null = finaltext.find_last_not_of('\0');
		finaltext.erase(last_non_null + 1);
	}
	out << finaltext;
	out.close();
}
//=========================================================================================================