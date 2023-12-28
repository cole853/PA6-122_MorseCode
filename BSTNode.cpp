/*
	Programmer: Cole Clark
	Date: 3/22/2021

		Description: Morse code binary search tree for PA6
*/

#include "BSTNode.h"


//constructor
BSTNode::BSTNode()
{
	character = '\0';
	code = "";
	left = nullptr;
	right = nullptr;
}

BSTNode::BSTNode(char newCharacter, std::string newCode)
{
	character = newCharacter;
	code = newCode;
}

//copy constructor
BSTNode::BSTNode(BSTNode* copy)
{
	character = copy->getCharacter();
	code = copy->getCode();
	left = copy->getLeft();
	right = copy->getRight();
}

//destructor
BSTNode::~BSTNode()
{
	cout << "Inside BSTNode's destructor!" << endl;
}


//getters
char BSTNode::getCharacter()
{
	return character;
}

std::string BSTNode::getCode()
{
	return code;
}

BSTNode* BSTNode::getLeft()
{
	return left;
}

BSTNode* BSTNode::getRight()
{
	return right;
}


//setters
void BSTNode::setCharacter(char& newCharacter)
{
	character = newCharacter;
}

void BSTNode::setCode(std::string& newCode)
{
	code = newCode;
}

void BSTNode::setLeft(BSTNode* newLeft)
{
	left = newLeft;
}

void BSTNode::setRight(BSTNode* newRight)
{
	right = newRight;
}


ifstream& operator>> (ifstream& input, BSTNode& rhs)
{
	char inputChar = '\0';
	std::string inputCode = "";

	input >> inputChar;
	input >> inputCode;

	rhs.setCharacter(inputChar);
	rhs.setCode(inputCode);

	return input;
}