#ifndef AVLTREE_H
#define AVLTREE_H


#include"AVLNode.h"

template <typename T>
class AVLTree
{
private:
	int size;
	//(5 pts) a pointer to the root AVLNode
	AVLNode<T>* rootnode;

public:
	//5 pts) necessary constructors for your implementation, destructor
	//constructor
	AVLTree(T root_value) {
		rootnode = new AVLNode<T> (root_value);
		size = 1;
	}

	//destructor

	~AVLTree() {
		destroySubTree(rootnode);
	}

	//helper function for destructor
	void destroySubTree(AVLNode<T>* nodePtr)
	{
		//recursiely destroys the nodes from the root_node of the subtree
		if (nodePtr)
		{
			if (nodePtr->get_left_ptr(nodePtr))
				destroySubTree(nodePtr->get_left_ptr(nodePtr));
			if (nodePtr->get_right_ptr(nodePtr))
				destroySubTree(nodePtr->get_right_ptr(nodePtr));
			delete nodePtr;
		}
	}

	//accessor function, return rootnode
	AVLNode<T>* get_root() {
		return rootnode;
	}

	//(5 pts) height() – returns the height of the tree 
	/* modified from heightHelper function in MA2 */
	int heightOfTree(AVLNode<T>* node) {
		if (!node) {
			return -1;
		}
		else {
			if (heightOfTree(node->get_left_ptr(node)) > heightOfTree(node->get_right_ptr(node)))
				return 1 + heightOfTree(node->get_left_ptr(node));
			else
				return 1 + heightOfTree(node->get_right_ptr(node));
		}
	}


	//(20 pts) insert() – inserts a value(type T) into the tree – must abide by AVL balancing properties
	void insertNode(T value)
	{
		AVLNode<T>* newNode = nullptr;	// Pointer to a new node.

		// Create a new node and store num in it.
		newNode = new AVLNode<T>(value);
		//set left and right
		insert(newNode, rootnode);
	}

	//modified from 'AVL Tree Implentation' shown in lecture
	void insert(AVLNode<T>*& newNode, AVLNode<T>* &root_node) {
		
		if (root_node == nullptr) {
			root_node = newNode;
			size++;
		}

		else if (newNode->get_data() < (root_node->get_data())) {
			insert(newNode, root_node->get_left_ptr(root_node));

			if (heightOfTree(root_node->get_left_ptr(root_node)) - heightOfTree(root_node->get_right_ptr(root_node)) == 2) {
				if (newNode->get_data() < (root_node->get_left_ptr(root_node)->get_data()))
					rotation_cases(1, root_node);
				else
					rotation_cases(3, root_node);
			}

		}
		else if (newNode->get_data() > (root_node->get_data())) {
			insert(newNode, root_node->get_right_ptr(root_node));

			if (heightOfTree(root_node->get_right_ptr(root_node)) - heightOfTree(root_node->get_left_ptr(root_node)) == 2) {
				if (newNode->get_data() > (root_node->get_right_ptr(root_node)->get_data()))
					rotation_cases(2, root_node);
				else
					rotation_cases(4, root_node);
			}
		}

		root_node->set_height(heightOfTree(root_node));

	}
	//modified from 'AVL Tree Implementation' shown in lecture
	void rotation_cases(int num, AVLNode<T>* &newnode){
		if (num == 1) {
			//case 1 corresponds to rotation with left child
			AVLNode<T>* left_node = newnode->get_left_ptr(newnode);
			newnode->set_left_ptr(left_node->get_right_ptr(left_node));
			left_node->set_right_ptr(newnode);
			newnode->set_height(std::max(heightOfTree(newnode->get_left_ptr(newnode)), heightOfTree(newnode->get_right_ptr(newnode))) + 1);
			left_node->set_height(std::max(heightOfTree(left_node->get_left_ptr(left_node)), newnode->get_height()) + 1);
			
			newnode = left_node;
		}
		else if (num == 2) {
			//case 2 corresponds with rotation with right child
			AVLNode<T>* right_node = newnode->get_right_ptr(newnode);
			newnode->set_right_ptr(right_node->get_left_ptr(right_node));
			right_node->set_left_ptr(newnode);
			newnode->set_height(std::max(heightOfTree(newnode->get_left_ptr(newnode)), heightOfTree(newnode->get_right_ptr(newnode))) + 1);
			right_node->set_height(std::max(heightOfTree(right_node->get_right_ptr(right_node)), newnode->get_height()) + 1);
			
			newnode = right_node;
		}

		else if (num == 3) {
			//case 3 = double rotation, left child
			rotation_cases(2, newnode->get_left_ptr(newnode));
			rotation_cases(1, newnode);
		}
		else if (num == 4) {
			//case 4 = double rotation, right child
			rotation_cases(1, newnode->get_right_ptr(newnode));
			rotation_cases(2, newnode);
		}
	}

	//(5 pts) contains() - given a value(type T), returns 1 if it is in the tree; 0 otherwise.
	int contains(T value, AVLNode<T>* nodePtr) {
		if (nodePtr != nullptr) {
			if (nodePtr->get_data() == value)
				return 1;

			else if (nodePtr->get_data() > value)
				return contains(value, nodePtr->get_left_ptr(nodePtr));

			else if (nodePtr->get_data() < value)
				return contains(value, nodePtr->get_right_ptr(nodePtr));

		}
		else
			return 0;
	}
	

	//(10 pts) validate() – returns 1 if this tree is a balanced tree; 0 otherwise.
	//Recall this: height of left and right subtrees at every node in a AVL tree differ by at most 1.
	int validate(AVLNode<T>* nodePtr) {

		if (nodePtr != nullptr) {
			//checks if unbalanced, returns 0
			if ((((heightOfTree(nodePtr->get_left_ptr(nodePtr))) - (heightOfTree(nodePtr->get_right_ptr(nodePtr)))) > 1) || (((heightOfTree(nodePtr->get_left_ptr(nodePtr))) - (heightOfTree(nodePtr->get_right_ptr(nodePtr)))) < -1))
				return 0;
			return validate(nodePtr->get_left_ptr(nodePtr));
			return validate(nodePtr->get_right_ptr(nodePtr));
		}
		else
			return 1;
	}

};

#endif