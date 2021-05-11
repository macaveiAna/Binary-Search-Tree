//=================================================================
// @file:		BST.cpp
// @author:     Ana Macavei
// @version:    1.0
//
//  Demonstrates: This file contains the 'main' which tests the 
//	functions that are needed from BST.h
//================================================================

#include <iostream>
#include "BST.h"

int main() {
	//Part 1
	std::cout << "cs260, A5-Binary Trees\n" << "Author: Ana Macavei\n";

	//creating a binary search tree of strings
	BST<std::string>* name = new BST<std::string>;
	
	name->insert("Jynx");
	name->insert("Charmander");
	name->insert("Snorlax");
	name->insert("Diglett");
	name->insert("Kakuna");
	name->insert("Meowth");
	name->insert("Pikachu");
	name->insert("Blastoise");
	name->insert("Squirtle");
	name->insert("Ivysaur");
	name->insert("Bulbasaur");
	name->insert("Abra");

	name->printInOrder();
	name->printPreOrder();
	name->printPostOrder();

	//Part 2 copy the tree
	BST<std::string>* copyTree = name->copy();
	
	name->deleteNode("Squirtle");
	name->printInOrder();

	name->deleteNode("Meowth");
	name->printInOrder();

	name->deleteNode("Blastoise");
	name->printInOrder();

	name->deleteNode("Jynx");
	name->printInOrder();
	std::cout << '\n';

	//printing the copy of the tree
	copyTree->printInOrder();
	copyTree->printPreOrder();
	copyTree->printPostOrder();
	std::cout << '\n';

	//remove all nodes in the original tree
	copyTree->removeAll();

	//reprint the original tree (should print nothing)
	copyTree->printInOrder();
	copyTree->printPreOrder();
	copyTree->printPostOrder();

}


