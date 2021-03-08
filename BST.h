#ifndef __BST_H
#define __BST_H

#include <iostream>
#include <limits>
using namespace std;


/*
 *  Data structure for a single tree node
 */
template <typename T>
struct Node {
public:
	T value;
	Node* left;
	Node* right;

	Node(T val) {
		this->value = val;
		this->left = nullptr;
		this->right = nullptr;
	}

	~Node()
	{
		this->value = 0;
		this->left = nullptr;
		this->right = nullptr;
	}
};

/*
 * Binary Search Tree (BST) class implementation
 */
template <typename T>
class BST {

protected:
	Node<T>* _root;         // Root of the tree nodes

	/* Add new T val to the tree */
	void addHelper(Node<T>* root, T val) {
		if (root->value > val) {
			if (!root->left) {
				root->left = new Node<T>(val);
			}
			else {
				addHelper(root->left, val);
			}
		}
		else {
			if (!root->right) {
				root->right = new Node<T>(val);
			}
			else {
				addHelper(root->right, val);
			}
		}
	}

	/* Print tree out in inorder (A + B) */
	void printInOrderHelper(Node<T>* root) {
		if (!root) return;
		printInOrderHelper(root->left);
		cout << root->value << ' ';
		printInOrderHelper(root->right);
	}

	/* Return number of nodes in tree */
	int nodesCountHelper(Node<T>* root) {
		if (!root) {
			return 0;
		}
		else {
			return 1 + nodesCountHelper(root->left) + nodesCountHelper(root->right);
		}
	}

	/* Return height of tree (root == nullptr -> 0) */
	int heightHelper(Node<T>* root) {
		if (!root) {
			return -1;
		}
		else {
			if (heightHelper(root->left) > heightHelper(root->right))
				return 1 + heightHelper(root->left);
			else
				return 1 + heightHelper(root->right);

			//return 1 + max(heightHelper(root->left), heightHelper(root->right));
		}
	}

	/* Delete a given <T> value from tree */
	bool deleteValueHelper(Node<T>* parent, Node<T>* current, T value) {
		if (!current) return false;
		if (current->value == value) {
			if (current->left == nullptr || current->right == nullptr) {
				Node<T>* temp = current->left;
				if (current->right) temp = current->right;
				if (parent) {
					if (parent->left == current) {
						parent->left = temp;
					}
					else {
						parent->right = temp;
					}
				}
				else {
					this->_root = temp;
				}
			}
			else {
				Node<T>* validSubs = current->right;
				while (validSubs->left) {
					validSubs = validSubs->left;
				}
				T temp = current->value;
				current->value = validSubs->value;
				validSubs->value = temp;
				return deleteValueHelper(current, current->right, temp);
			}
			delete current;
			return true;
		}
		return deleteValueHelper(current, current->left, value) ||
			deleteValueHelper(current, current->right, value);
	}

	/********************************* PUBLIC API *****************************/
public:

	BST() : _root(nullptr) { }               // Basic initialization constructor

	/**
	 * Destructor - Needs to free *all* nodes in the tree
	 * TODO: Implement Destructor
	 */
	//the destructor has been implemented
	~BST() {
		//destructor calls on a recursive helper function
		DestructorHelper(this->_root);
	}

	void DestructorHelper(Node<T>* root_node) {
		if (!root_node)
			return;//the tree has been deleted
		else{
			DestructorHelper(root_node->right);
			DestructorHelper(root_node->left);
			//use the deleteValue helper function
			this->deleteValue(root_node->value);
		}
	}


	/* Public API */
	void add(T val) {
		if (this->_root) {
			this->addHelper(this->_root, val);
		}
		else {
			this->_root = new Node<T>(val);
		}
	}

	void print() {
		printInOrderHelper(this->_root);
	}

	/**
	 * Print the nodes level by level, starting from the root
	 * TODO: Implement printLevelOrder
	 */
	void printLevelOrder() {
		int height = this->height();
		height += 1;
		int i = 1;
		while(i<=height) {
			//prints the nodes one level at a time
			printLevelNodes(i, this->_root);
			cout << endl;
			i++;
		}
	}

	//this function is called in the printLevelOrder function
	void printLevelNodes(int level_num, Node<T>* root_node) {
		if (!root_node)
			return;
		//prints out root node
		if (level_num >= 1) {
			if (level_num == 1)
				cout << root_node->value << " ";
			else{
				level_num--;
				printLevelNodes(level_num, root_node->left);
				printLevelNodes(level_num, root_node->right);
			}
		}
	}


	int nodesCount() {
		return nodesCountHelper(this->_root);
	}

	int height() {
		return heightHelper(this->_root);
	}

	/**
	 * Print the maximum path in this tree
	 * TODO: Implement printMaxPath
	 */
	//calls on findMaxPath
	void printMaxPath() {
		int height = this->height();
		height += 1;
		T* arr = new T[height];
		findMaxPath(0, this->_root, 0, arr, height);
		for (int i = 0; i < height; i++) {
			cout << arr[i] << " ";
		}
	}

	//recursively goes through the tree until the height of the current path is equal to 
	//the height of the tree, and if that's teh case stores the values of the path in
	//array arr[]
	void findMaxPath(int height, Node<T>* root_node, int goal, T arr[], int goal1) {
		if (!root_node) {
			height--;
			goal--;
			return;
		}
		
		if (height == goal) {
			arr[height] = root_node->value;
			if (goal == goal1) {
				return;
			}
		}
			height++;
			goal++;
			findMaxPath(height, root_node->right, goal, arr, goal1);
			findMaxPath(height, root_node->left, goal, arr, goal1);
	}


	bool deleteValue(T value) {
		return this->deleteValueHelper(nullptr, this->_root, value);
	}

	/**
	 * Find if the BST contains the value
	 * TODO: Implement contains
	 */
	
	bool contains(T value) {
		int count = this->nodesCount();
		T* arr = new T[count];
		placeNodesInArray(0, arr, this->_root);
		for (int i = 0; i < count; i++) {
			if (arr[i] == value)
				return true;
		}
		return false;

		delete arr;
	}
	//I used an array as a placeholder for all of the nodes in the tree, 
	//and then searched the array for the value T
	void placeNodesInArray(int count, T arr[], Node<T>* root_node) {
		if (!root_node) 
			return;
		placeNodesInArray(count, arr, root_node->left);
		arr[count]= root_node->value;
		count++;
		placeNodesInArray(count, arr, root_node->right);
	}

};

#endif



