#include <string>
#include <fstream>
#include <cctype>
#include <iostream>
#ifndef THE_TREE_H
#define THE_TREE_H

// Lab 9 - Data Structures 001
// Abdul Wahab

using namespace std;

class BT {

private:
	struct BTNode {
	string morse_code;
	string the_message;
	BTNode *left_node;
	BTNode *right_node;
}; BTNode *the_root_node;

public:
	 BT();
	~BT();
	void insert_code(char the_message, string morse_code);
	void insert_code(BTNode *&new_node, char the_message, string morse_code, bool is_last);
	bool leafNode(BTNode *node);
	/*string encode(const string& entered_text, fixed_node);*/
	string decode(string the_input, bool added_node );
	bool lessThanFour(string::size_type a);
};
#endif
