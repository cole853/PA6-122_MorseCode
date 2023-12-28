/*
	Programmer: Cole Clark
	Date: 3/22/2021

		Description: Morse code binary search tree for PA6
*/


#pragma once

#include "BSTNode.h"

#include <string>
#include <windows.h>

using std::toupper;

class BST
{
public:

	//constructor
	BST();

	//destructor
	~BST();

	//getter
	BSTNode* getRoot();

	//setter
	void setRoot(BSTNode* newRoot);

	//prints the tree from left to right
	void printTree();

	//prints the input to the screen and the morse code for that input
	void printResult();

	//searches for a letter input and returns the morse code for that letter
	std::string search(char searchCharacter);


private:

	//inserts one node into the tree
	void insert(BSTNode& newData);

	//inserts one node into the tree
	void insert(BSTNode* tree, BSTNode& newData);

	//destroys all nodes in the list
	void destructorHelper(BSTNode* tree);

	void printTree(BSTNode* treeRoot);

	std::string search(BSTNode* tree, char searchCharacter);

	BSTNode* root;

};