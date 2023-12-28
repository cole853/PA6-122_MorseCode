/*
	Programmer: Cole Clark
	Date: 3/22/2021

		Description: Morse code binary search tree for PA6
*/


#pragma once

#include <iostream>
#include <fstream>

using std::ifstream;
using std::cout;
using std::endl;
using std::ostream;

class BSTNode
{
public:

	//constructor
	BSTNode();

	BSTNode(char newCharacter, std::string newCode);

	//copy constructor
	BSTNode(BSTNode* copy);

	//destructor
	~BSTNode();


	//getters
	char getCharacter();

	std::string getCode();

	BSTNode* getLeft();

	BSTNode* getRight();


	//setters
	void setCharacter(char &newCharacter);

	void setCode(std::string& newCode);

	void setLeft(BSTNode* newLeft);

	void setRight(BSTNode* newRight);

private:

	char character;
	std::string code;
	BSTNode* left;
	BSTNode* right;

};

ifstream& operator>> (ifstream& input, BSTNode& rhs);