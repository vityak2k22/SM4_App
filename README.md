SM4 App is a demo program that can encrypt and decrypt files in any format. It can be used as a tutorial as well as a complete file encryption program.

# Using technologies for program design
The program was designed in the C++ programming language using CLI tools and Windows API data types. The graphical interface for the program was implemented using the Windows Forms tool.
# Program description
## GUI description

<img src="for%20README/sm4%20app%20img.jpg" alt="drawing" width="500"/>

The SM4 Demo program interface consists of the following elements:
 - **initialtext (path) text field**. This field contains the path to the file. In SM4 Demo, initialtext is a file at the beginning of the algorithm, which, depending on the selected encryption or decryption mode, can be plaintext or ciphertext. The path can be entered manually or you can use the file selection using the Open button;
 - **finaltext (path) text field**. The final text is the message after the algorithm has run. Depending on the selected mode, it can be ciphertext or plaintext. Like the initialtext, the path can also be entered manually or you can use the file selection with the Open button;

> [!NOTE]
> SM4 Demo allows you to write the same path into the initaltext and finaltext text fields. When the button _Start SM4_ is pressed, the entire contents of initialtext are completely unloaded into RAM, passed through the algorithm and stored in finaltext. So if you specify the same path into the initaltext and finaltext text fields, the result will eventually be saved in the initialtext file. This works both for encryption and decryption.

 - **Mode switch**. It allows you to select the algorithm mode;
 - **Key text field**. In this field, you enter the key that is used during the algorithm operation. By default, it is masked, but to check the correctness of the entered key, you can use the Look button, which shows the contents of the key. The text field itself has a character limit of 16 bytes;
 - **_with Demonstration mode_ checkbox**. If it's checked program generate file which shows intermediate steps of SM4 algorithm like T-function working, Key Expansion and Encryption process of _**first** initialtext block_;
 - **_generate settings.ini file_ checkbox**. If it's checked program generate _settings.ini_ file which a last input data stores after the algorithm is executed for the next quick start of the program;
 - **_Start SM4_ button**. When you press it, the input data is processed and the encryption algorithm runs.
 - **status bar**. It displays the status of the program. During the processing of the entered data, before and after the algorithm starts, it may contain the following messages:
   + _“Enter the required data in the fields”_ - enter the required data in the fields;
   + _“Invalid paths to initialtext file”_ - incorrectly entered initialtext file path;
   + _“SM4 process is working. . .”_ - the input data has been processed and the SM4 algorithm is working;
   + _“Done! Result saved in \<finaltext path\>”_ - the algorithm has successfully completed its work.

## Operation description
**After entering all the input data and clicking the Start SM4 button**, the program starts by checking the correctness of the entered fields. If they are correct, the following steps are performed.
1. Converting the Key-string into an array of four-byte unsigned integers. It is a byte-by-byte input of each byte of the string into the array. If the entered string is less than the maximum allowable length of 16 bytes, then after entering all significant bytes, zeros are written to the end of the array.
2. **Run the algorithm**. The program algorithm is divided into the following components:
   - **_initialization of the initialtext_**. Zero characters ('\0') are written to the end of the initial text to divide the message into 128-bit blocks;
   - **_representation of the initialtext_** in hexadecimal and its saving in the file “HEX_INPUT.txt”;
   - **_Key Expansion_ from the _Key_**;
   - **_encryption process_**. Blocks from the source text string converted to hexadecimal format are assigned to the block that undergoes the encryption process. The result is stored in the final text string in hexadecimal format;
   - the resulting string is **_saved_** in the file “HEX_OUTPUT.txt” and **_presented_** in character form in the finaltext file.
3. **Display** the successful execution of the algorithm in the status bar with the message “Done!”.
4. **Saving** the input data in the _settings.ini_ initialization file (if _generate settings.ini file_ checkbox is checked). The format of the ini file is a list of *key=value* parameters (see Figure).

<img src="for%20README/settings%20ini%20img.jpg" alt="drawing" width="400"/>

## Demonstration mode
During Demonstration mode program generates notes in Demonstration.txt file. This file consists of the following parts:
- **Header**. It contains date and time of algorithm start, initialtext and finaltext paths and selected encryption mode;
- **Key Expansion section**. It contains round keys calculaion process;
- **SM4 Block operation section**. It contains first block of initialtext calculaion process.

Specified sections consists of the T-function section and main calculation section. T-function section contains S-box (non-linear byte substitution) and L (linear substitusion) operations.
Demonstration.txt format is shown in Figure.

<img src="for%20README/demonstration%20txt.jpg" alt="drawing" width="800"/>

>[!IMPORTANT]
>During Demonstration mode program doesn't erase old notes in Demonstration.txt - it attends new notes to the end of the file. This was done so that previous results could be compared to the current one.

# Example

## Encryption process example
Input data:
- **initialtext (path)**: a file with the path “D:\Victor\cppProjects\SM4 App\x64\Debug\PLAINTEXT.txt”;
- **finaltext (path)**: a file with the path “D:\Victor\cppProjects\SM4 App\x64\Debug\FINALTEXT.txt”;
- **Mode**: Encrypt;
- **Key**: test_one.

**SM4 Demo Operation:**

<img src="for%20README/example%20sm4%20app.jpg" alt="drawing" width="500"/>

<img src="for%20README/example%20initialtext.jpg" alt="drawing" width="400"/>

<img src="for%20README/example%20hex%20input.jpg" alt="drawing" width="400"/>

<img src="for%20README/example%20hex%20output.jpg" alt="drawing" width="400"/>

<img src="for%20README/example%20finaltext.jpg" alt="drawing" width="500"/>

<img src="for%20README/example%20settings%20ini.jpg" alt="drawing" width="400"/>

<img src="for%20README/example%20demonstration.jpg" alt="drawing" width="600"/>

## Decryption process example
Input data:
- **initialtext (path)**: a file with the path “D:\Victor\cppProjects\SM4 App\x64\Debug\FINALTEXT.txt”;
- **finaltext (path)**: a file with the path “D:\Victor\cppProjects\SM4 App\x64\Debug\FINALTEXT.txt”;
- **Mode**: Decrypt;
- **Key**: test_one.

<img src="for%20README/decrypt%20example%20sm4%20app.jpg" alt="drawing" width="500"/>

<img src="for%20README/decrypt%20example%20initialtext.jpg" alt="drawing" width="500"/>

<img src="for%20README/decrypt%20example%20hex%20input.jpg" alt="drawing" width="400"/>

<img src="for%20README/decrypt%20example%20hex%20output.jpg" alt="drawing" width="400"/>

<img src="for%20README/decrypt%20example%20finaltext.jpg" alt="drawing" width="400"/>

<img src="for%20README/decrypt%20example%20settings%20ini.jpg" alt="drawing" width="400"/>

<img src="for%20README/decrypt%20example%20demonstration.jpg" alt="drawing" width="600"/>
