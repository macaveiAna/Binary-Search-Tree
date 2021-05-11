//===================================================================
// @file:		BST.h
// @author:     Ana Macavei
// @version:    1.0
//
//  Demonstrates: The class use of a template Binary Search Tree 
//	which includes all the functions and their implementations.
//====================================================================

#ifndef BST_H
#define BST_H

#include <iostream>
#include <string>

//create tree nodes structure
template<typename type>
struct Node {
	type data;
	Node<type>* left;
	Node<type>* right;
};

template<typename type>
class BST {
public:
	/**------------------------------------------------
	* Constructor
	*/
	BST();

	/**------------------------------------------------
	* Destructor
	*/
	~BST();

	/**------------------------------------------------
	* insert - A function that inserts insertItem in the
	* binary search tree.
	*
	* Postcondition: If there is no node in the binary tree
	* that has the same info as insertItem, a node with the
	* data insertItem is created and inserted in the binary
	* search tree.
	*
	* @param insertItem
	*/
	void insert(const type& insertItem);

	/**------------------------------------------------------------
	* removeAll - A function that destroys the whole tree.
	* To implement this I use the function destroy(listed in private)
	* and pass the root node of the binary tree to the function
	* destroy.
	*/
	void removeAll();

	/**-------------------------------------------------------
	* printPreOrder - A function where the node is processed
	* before its children. Must be used when copying a tree.
	*/
	void printPreOrder() const;

	/**-----------------------------------------------------------
	* printInOrder - A function where the left child is processed,
	* then the node, then the right child is processed.
	* Typically used when searching or printing a tree.
	*/
	void printInOrder() const;

	/**--------------------------------------------------------
	* printPostOrder - A function where the node is processed
	* after its children. Must be used when deleting a tree.
	*/
	void printPostOrder() const;


	/**--------------------------------------------------------------
	* deleteNode - A function to delete deleteItem from the binary
	* search tree.
	*
	* Postcondition: if a node with the same data as deleteItem is
	* found, it is deleted from the binary search tree. If the binary
	* search tree is empty or deleteItem is not in the binary tree, a
	* message is printed.
	*
	* @param deletItem
	*
	*/
	void deleteNode(const type& deleteItem);

	/**-----------------------------------------------------------
	* copy - A function that is a copy of the original tree
	*/
	BST<type>* copy() const;


protected:
	Node<type>* root;

private:
	/*Node<type>* root;*/

	/**------------------------------------------------------------
	* printInOrderR - A function that prints the tree InOrder.
	* Processes left child, node, then right child.
	*
	* @param node, level
	*/
	void printInOrderR(Node<type>* node, int level = 0) const;

	/**------------------------------------------------------------------
	* printPreOrderR - A function that prints the tree in PreOrder.
	* Processes the node first, then the children.
	*
	* @param node
	*/
	void printPreOrderR(Node<type>* node, int level = 0) const;

	/**---------------------------------------------------------------
	* printPostOrderR - A function that prints the tree in PostOrder.
	* Processes the children first, then the node.
	*
	* @param node
	*/
	void printPostOrderR(Node<type>* node, int level = 0) const;

	/**------------------------------------------------
	* destroy - A function that destroys the tree.
	* if the node is not equal to null, then destroy
	* the left subtree, then the right subtree, then
	* the node itself.
	*
	* @param node
	*/
	void destroy(Node<type>*& node);


	/**---------------------------------------------------------------------
	* removeFromTree - A function that deletes the node that node points to,
	* which is deleted from the binary search tree.
	*
	* Postcondition: The node to which node points is deleted.
	*
	* @param node
	*/
	void deleteFromTree(Node<type>*& node);

	/**---------------------------------------------------------------------
	* copyTree - A function that makes a copy of the binary tree where
	* otherTreeRoot points to.
	* 
	* Postcondition: The pointer copiedTreeRoot points to the root of the
	* copied binary tree.
	*
	* @param copiedTreeRoot, otherTreeRoot
	*/
	void copyTree(BST<std::string>* newTree, Node<type>* originalTree) const;

};

//class implementation of a template Binary Search Tree 

template <typename type>
BST<type>::BST() {
	root = nullptr;
}

template <typename type>
BST<type>::~BST() {
	removeAll();
}

template<typename type>
void BST<type>::printInOrder() const {
	std::cout << "\nInOrder: ";
	//prints the list inOrder alphabetically and pass the root node of the binary tree to the function.
	printInOrderR(root);
	if (root == nullptr) {//if the root is null then it will print out "Empty List"
		std::cout << "Empty list";
	}
}

template <typename type>
void BST<type>::printPreOrder() const {
	std::cout << "\nPreOrder: ";
	//prints the list preOrder and passes the root node of the binary tree to the function.
	printPreOrderR(root);
	if (root == nullptr) {
		std::cout << "Empty list";
	}
}

template<typename type>
void BST<type>::printPostOrder() const {
	std::cout << "\nPostOrder: ";
	printPostOrderR(root);//prints the list in postOrder and passes the root node to the function
	if (root == nullptr) {
		std::cout << "Empty list\n";
	}
}


template<typename type>
void BST<type>::printInOrderR(Node<type>* node, int level) const {
	if (node == nullptr) {//checks to see if null
		return;
	}
	printInOrderR(node->left, level + 1);//processes left child first
	std::cout << node->data << "(" << level << ")" << ' ';//then the node as well as the level
	printInOrderR(node->right, level + 1);//then the right child

}

template<typename type>
void BST<type>::printPreOrderR(Node<type>* node, int level) const {
	if (node == nullptr) {
		return;
	}
	std::cout << node->data << "(" << level << ")" << ' ';//processes the node first as well as the level
	printPreOrderR(node->left, level + 1);//then the left child
	printPreOrderR(node->right, level + 1);//then the right child
}

template<typename type>
void BST<type>::printPostOrderR(Node<type>* node, int level) const {
	if (node == nullptr) {
		return;
	}
	printPostOrderR(node->left, level + 1);//processes the left child first
	printPostOrderR(node->right, level + 1);//then the right child
	std::cout << node->data << "(" << level << ")" << ' ';//then the node as well as the level
}



template<typename type>
void BST<type>::insert(const type& insertItem) {
	Node<type>* current; //pointer to traverse the tree
	Node<type>* trailCurrent = nullptr; //pointer behind current
	Node<type>* newNode; //pointer to create the node

	//build and initialize new node
	newNode = new Node<type>;
	newNode->data = insertItem;//copy insertItem into the new node
	newNode->left = nullptr;//Setting left of the new node to nullptr
	newNode->right = nullptr;//setting right of the new node to nullptr

	//empty tree?
	if (root == nullptr)
		root = newNode;
	else {
		current = root;
		//search the binary tree
		while (current != nullptr) {

			trailCurrent = current;

			if (current->data == insertItem) {//if the current->data is the same as the insertItem
				std::cout << "Error: Cannot insert duplicate." << std::endl;//print error message
				return;//exit
			}
			else if (current->data > insertItem)//if current->data is greater than the insertItem
				current = current->left;//follow left of current
			else
				current = current->right;//follow right of current
		}
		//trail now points to the node that will be the parent.
		if (trailCurrent->data > insertItem)
			trailCurrent->left = newNode;//make the new node the left child of trailCurrent
		else
			trailCurrent->right = newNode;//make the new node the right child of trailCurrent
	}
}

template<typename type>
void BST<type>::removeAll() {

	destroy(root);
}

template<typename type>
void BST<type>::destroy(Node<type>*& node) {

	if (node != nullptr) {//if the node is not null (full tree)
		destroy(node->left);//first destroy left subtree
		destroy(node->right);//then destroy right subtree
		delete node; //using delete operator to delete the node
		node = nullptr;//setting node to null.
	}
}

/*
 * Handle special cases
 * 1. Node is leaf (has no children)
 * 2. Node has only one child
 * 3. Node has two children
 */
template<typename type>
void BST<type>::deleteFromTree(Node<type>*& node) {

	Node<type>* current;//pointer to traverse the tree
	Node<type>* trailCurrent;//pointer behind current
	Node<type>* temp; //pointer to delete the node

	if (node == nullptr)
		std::cout << "Error: The node to be deleted doesn't exist." << std::endl;
	//no children
	else if (node->left == nullptr && node->right == nullptr) {

		temp = node;
		node = nullptr;
		delete temp;
	}
	//only one child; left or right
	else if (node->left == nullptr) {

		temp = node;
		node = temp->right;
		delete temp;
	}
	else if (node->right == nullptr) {

		temp = node;
		node = temp->left;
		delete temp;
	}

	//two children. This node can't be removed, so we replace it's data
	//with data from a node that can be removed.

	else {

		//find node with replacement data (and parent)
		//go left once, then right until we hit null.
		current = node->left;
		trailCurrent = nullptr;

		while (current->right != nullptr) {
			
			trailCurrent = current;
			current = current->right;
		}
		
		//replace our data with replacement data and delete the node that the
		//replacement data came from
		node->data = current->data;

		if (trailCurrent == nullptr)//current did not move
									
			node->left = current->left;//current == node->left; adjust node
		else //replacement node came from further down
			trailCurrent->right = current->left;

		delete current;
	}

}

template<typename type>
void BST<type>::deleteNode(const type& deleteItem) {
	
	// find the node to delete, when complete, current will point to the node to delete
	// and parent will point to the parent of that node.

	Node<type>* current;
	Node<type>* trailCurrent;//pointer behind current
	bool found = false;

	if (root == nullptr)
		std::cout << "Empty tree! Can't delete." << std::endl;
	else {
		current = root;
		trailCurrent = root;

		while (current != nullptr && !found) {
			if (current->data == deleteItem)
				found = true;
			else {
				trailCurrent = current;
				if (current->data > deleteItem)
					current = current->left;
				else
					current = current->right;
			}
		}
		// If it was found, pass a reference to the pointer pointing to the node to the 
		// removeFromTree function (so that pointer can be modified). This reference will be to root or 
		// the parent node’s left or right pointer.

		if (current == nullptr)
			std::cout << "The item is not in the tree." << std::endl;
		else if (found) {
			if (current == root)
				deleteFromTree(root); //removeFromTree may modify this pointer
			else if (trailCurrent->data > deleteItem)
				deleteFromTree(trailCurrent->left);//removeFromTree may modify this pointer
			else
				deleteFromTree(trailCurrent->right);//removeFromTree may modify this pointer
		}
		else
			std::cout << "The item is not in the tree." << std::endl;
	}

	std::cout << "\n\nDeleting: " << deleteItem; //this outputs Deleting with whatever item I am deleting.

}

template<typename type>
void BST<type>::copyTree(BST<std::string>* newTree, Node<type>* originalTree) const{

	if (originalTree == nullptr)
		return;
	else{
	newTree->insert(originalTree->data);//inserting the originalTree data into the newTree
		copyTree(newTree, originalTree->left);// copy originalTree's left child
		copyTree(newTree, originalTree->right);//copy originalTree's right child
	}
}

template<typename type>
BST<type>* BST<type>::copy() const{

	BST<type>* newTree = new BST();//create new tree
	copyTree(newTree, root);//call copyTree to copy data of the originalTree into the newTree
	return newTree;
}

#endif
