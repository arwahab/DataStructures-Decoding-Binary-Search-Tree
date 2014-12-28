#include "the_tree.h"
#include <iostream>
#include <cctype>
#include <string>
#include <fstream>


// Lab 9 - Data Structures 001
// Abdul Wahab

using namespace std;
string inputtedText() {
string theText;
cout << "Type in the morse code for decoding: " << endl;
getline(cin, theText);
return theText;
}
//cout << "Enter your original message to encode: ";
//getline(cin, message);
//int line = message.length();
//
//for (int i = 0; i < line; i++)
//{
//	message[i] = toupper(message[i]);
//	char c = message[i];
//	if (c == ' ')
//		cout << "/ ";
//	tree.Encode(c);
//}
//cout << endl;


bool checkerString(string the_input) {
if (!the_input.size()) {
cout << "Type in the morse code for decoding: " << endl;
return false;
}
for (string::size_type a = 0; a < the_input.length(); ++a) {
if (the_input[a] != '.' && the_input[a] != '-' && the_input[a] != ' ') {
return false;
}}
return true;
}
//cout << "Enter your Morse code";
//cin.getline(morse_code, 100, '*');
//char* token = strtok(morse_code, "/");
//while (token != NULL)
//{
//	cout << endl << "Decoding: " << token << endl;
//	string new_code = token;
//	tree.Decode(new_code);
//	token = strtok(NULL, "/");
//}
//cout << "Continue: ";
//cin >> reply; cin.ignore(); cout << endl;
//		}while (reply == 'y');
//
//
//
//		return 0;
//}
string caseLow(string lower) {
	for (string::size_type i = 0; i < lower.length(); i++) {
		tolower(lower[i]);
	}
	return lower;
}

int main() {
ifstream file_read;
string entered_code;
string text;
string lowerCaseText;
BT tree;
bool node_added = false;

file_read.open("morse-code.txt");
if (!file_read) {
cout << "Unable to open the file: morse-code.txt" << endl;
}
else {
tree.insert_code('0', "*");
while (getline(file_read, entered_code)) {
tree.insert_code(entered_code[0], entered_code.substr(2, entered_code.length() - 2));
}
text = inputtedText();
lowerCaseText = caseLow(text);
while (!checkerString(lowerCaseText)) {
text = inputtedText();
lowerCaseText = caseLow(text);
}
file_read.close();
cout << "The decoded text is " << tree.decode(text, node_added) << endl;
}
system("pause");
return 0;
}
