/*
	Programmer: Cole Clark
	Date: 3/22/2021

		Description: Morse code binary search tree for PA6
*/

#include "BST.h"

//constructor
BST::BST()
{
	ifstream infile;
	infile.open("MorseTable.txt");

	BSTNode temp;

	while (infile.good())
	{
		infile >> temp;
		insert(temp);
	}

	infile.close();
}

//inserts one node into the tree
void BST::insert(BSTNode& newData)
{
	insert(root, newData);
}

//inserts one node into the tree
void BST::insert(BSTNode* tree, BSTNode& newData)
{
	BSTNode* newNode = nullptr;

	if (root == nullptr)
	{
		root = new BSTNode;

		char newCharacter = newData.getCharacter();
		std::string newString = newData.getCode();

		root->setCharacter(newCharacter);
		root->setCode(newString);
	}
	else if ((int) newData.getCharacter() < (int)tree->getCharacter() && tree->getLeft() == nullptr)
	{
		newNode = new BSTNode;
		char newCharacter = newData.getCharacter();
		std::string newString = newData.getCode();

		newNode->setCharacter(newCharacter);
		newNode->setCode(newString);

		tree->setLeft(newNode);
	}
	else if ((int) newData.getCharacter() > (int) tree->getCharacter() && tree->getRight() == nullptr)
	{
		newNode = new BSTNode;
		char newCharacter = newData.getCharacter();
		std::string newString = newData.getCode();

		newNode->setCharacter(newCharacter);
		newNode->setCode(newString);

		tree->setRight(newNode);
	}
	else if ((int) newData.getCharacter() < (int) tree->getCharacter())
	{
		insert(tree->getLeft(), newData);
	}
	else if ((int) newData.getCharacter() > (int) tree->getCharacter())
	{
		insert(tree->getRight(), newData);
	}
}

//destructor
BST::~BST()
{
	cout << "Inside BST's destructor! destroying all nodes." << endl;

	destructorHelper(root);
}

void BST::destructorHelper(BSTNode* tree)
{
	if (tree != nullptr)
	{
		destructorHelper(tree->getLeft());
		destructorHelper(tree->getRight());
		delete tree;
	}
}

//getter
BSTNode* BST::getRoot()
{
	return root;
}

//setter
void BST::setRoot(BSTNode* newRoot)
{
	root = newRoot;
}

//prints the tree from left to right
void BST::printTree()
{
	system("cls");
	cout << "Search Tree In Order" << endl << endl;
	printTree(root);
}

//prints the tree from left to right
void BST::printTree(BSTNode* treeRoot)
{
	if (treeRoot != nullptr)
	{
		printTree(treeRoot->getLeft());
		cout << treeRoot->getCharacter() << " " << treeRoot->getCode() << endl;
		printTree(treeRoot->getRight());
	}
}

//searches for a letter input and returns the morse code for that letter
std::string BST::search(char searchCharacter)
{
	std::string result = search(root, searchCharacter);

	return result;
}

//searches for a letter input and returns the morse code for that letter
std::string BST::search(BSTNode* tree, char searchCharacter)
{
	static std::string result;

	if (searchCharacter > tree->getCharacter())
	{
		search(tree->getRight(), searchCharacter);
	}
	else if (searchCharacter < tree->getCharacter())
	{
		search(tree->getLeft(), searchCharacter);
	}
	else if (searchCharacter == tree->getCharacter())
	{
		result = tree->getCode();
	}
	
	return result;
}

//prints the input to the screen and the morse code for that input
void BST::printResult()
{
	ifstream infile;
	infile.open("Convert.txt");
	char temp = '\0';
	std::string tempCode = "";
	char original[100] = "";

	cout << endl << endl << "Original message: " << endl;

	while (infile.good())
	{
		if (original != "")
		{
			tempCode.append("\n");
		}

		infile.getline(original, 100);
		cout << original << endl;

		for (int i = 0; original[i] != '\0'; ++i)
		{
			original[i] = toupper(original[i]);

			if (original[i] == ' ')
			{
				tempCode.append("  ");
			}
			else
			{
				tempCode.append(search(original[i]));
				tempCode.append(" ");
			}
		}
	}

	cout << endl << endl << "Morse code: " << endl << tempCode << endl << endl << endl;

	for (int i = 0; tempCode[i] != '\0'; ++i)
	{
		if (tempCode[i] == '.')
		{
			Beep(600, 250);
		}
		else if (tempCode[i] == '-')
		{
			Beep(600, 750);
		}
		else if (tempCode[i] == ' ')
		{
			Beep(0, 250);
		}
		else if (tempCode[i] == '\n')
		{
			Beep(0, 1000);
		}
	}

	infile.close();
}