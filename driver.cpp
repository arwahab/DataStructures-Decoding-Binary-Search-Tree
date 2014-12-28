include "the_tree.h"
#include <iostream>
#include <string>
#include <fstream>
#include <cctype>

// Lab 9 - Data Structures 001
// Abdul Wahab

using namespace std;
BT::BT() {
the_root_node = NULL;
}

BT::~BT() {
}

void BT::insert_code(char the_message, string morse_code) {
/*f(b->letter > letter) Insert(b->left, letter, code);
if (b->letter < letter) Insert(b->right, letter, code);*/
if (!the_root_node) {
insert_code(the_root_node, the_message, morse_code, true);
}
else {
BTNode *node = the_root_node;


//
//cout << b->letter << "\t";
//display_in_order(b->left);
//display_in_order(b->right);
//}





for (string::size_type i = 0; i < morse_code.length(); i++) {
if (morse_code[i] == '.') {
if (!node->left_node) {
if (i == morse_code.length() - 1) {
insert_code(node->left_node, the_message, morse_code.substr(0, i + 1), true);
}
else {
insert_code(node->left_node, the_message, morse_code.substr(0, i + 1), false);


}
}
node = node->left_node;
if (node->left_node) {
if (i == morse_code.length() - 1) {
node->the_message = the_message;

//void display_in_order(BTNode *b)
//{
//	if (b != nullptr)
//	{
//
//		display_in_order(b->left);
//		cout << b->letter << "\t";
//		display_in_order(b->right);
//	}
//}
//
//void display_in_order(){ display_in_order(root); }
//void display_pre_order(){ display_pre_order(root); }
//void display_post_order(BTNode *b)
//{
//	if (b != nullptr)
//	{
//
//		display_post_order(b->left);
//		display_post_order(b->right);
//		cout << b->letter << "\t";
//	}
//}
//
//
//
//
//
//

}
}
if (!node->left_node) {
if (i == morse_code.length() - 1) {
node->the_message = the_message;
}}
}
else if (morse_code[i] == '-') {
if (!node->right_node) {
if (i == morse_code.length() - 1) {
insert_code(node->right_node, the_message, morse_code.substr(0, i + 1), true);
}
else {
insert_code(node->right_node, the_message, morse_code.substr(0, i + 1), false);
}}

//BTNode* search_and_return(BTNode *b, char x)
//{
//	if (b != nullptr)
//	{
//		if (b->letter[0] == x) { return b; }
//		else if (b->letter[0] > x) { search_and_return(b->left, x); }
//		else { search_and_return(b->right, x); }
//	}
//	else return nullptr;
//
node = node->right_node;
if (node->right_node) {
if (i == morse_code.length() - 1) {
node->the_message = the_message;
}}
if (!node->right_node) {
if (i == morse_code.length() - 1) {
node->the_message = the_message;
}}
}
}
}
}

void BT::insert_code(BTNode *&node, char the_message, string morse_code, bool is_last) {
if (is_last) {
node = new BTNode();
node->the_message = the_message;
node->right_node = NULL;
node->left_node = NULL;
node->morse_code = morse_code;
}









if (!is_last) {
node = new BTNode();
node->the_message = '\0';
node->right_node = NULL;
node->left_node = NULL;
node->morse_code = morse_code;
}
}


bool BT::lessThanFour(string::size_type a) {
if (a < 4){
return true;
}else{
return false;
}
}

bool BT::leafNode(BTNode *node) {
if (!node->left_node && !node->right_node) {
return true;
}
else {
return false;
}}
string BT::decode(string the_input, bool added_node) {
string the_output = "";
BTNode *node = the_root_node;
for (string::size_type a = 0; a < the_input.length(); ++a) {
if (the_input[a] == '.') {
if (node->left_node) {
node = node->left_node;
added_node = true;
}
if ((a == the_input.length() - 1 || the_input[a + 1] == ' ') && added_node) {
/*BTNode* search_and_returnString(BTNode *b, string x)
{
if (b != nullptr)
{
if (b->code == x) { cout << b->code << " matches " << x << endl; return b; }
else if (b->code > x) { search_and_returnString(b->left, x); }
else { search_and_returnString(b->right, x); }
}
else return nullptr;
}
};*/
the_output.append(node->the_message);
}
}
if (the_input[a] == ' ') {
node = the_root_node;
added_node = false;
}
if (the_input[a] == '-') {
if (node->right_node) {
node = node->right_node;
added_node = true;
}
if ((a == the_input.length() - 1 || the_input[a + 1] == ' ') && added_node) {
the_output.append(node->the_message);
}}
added_node = false;
}
return the_output;
}
