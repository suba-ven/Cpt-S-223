#ifndef AVLNODE_H
#define AVLNODE_H


template <typename T>
class AVLNode
{
private:
	T data;
	AVLNode* left_ptr;
	AVLNode* right_ptr;
	int height;
public:
	// (5 pts) necessary constructors for your implementation, destructor
	AVLNode(T new_data) {
		left_ptr = nullptr;
		right_ptr = nullptr;
		height = 0;
		data = new_data;
	}

	AVLNode() {
		left_ptr = nullptr;
		right_ptr = nullptr;
		height = 0;
	}

	~AVLNode() {
		delete this;
	}

	//accessor and mutator functions for height variable
	void set_height(int node_height) {
		height = node_height;
	}

	int get_height() {
		if (this != NULL)
			return height;
		else
			return -1;
	}

	//accessor and mutator functions for data variable
	T get_data() {
		return data;
	}

	void set_data(T new_data) {
		data = new_data;
	}

	//accessor and mutator functions for right and left node pointers
	AVLNode<T>*& get_left_ptr(AVLNode<T>*& ref_node) {
		return (ref_node)->left_ptr;
	}

	AVLNode<T>*& get_right_ptr(AVLNode<T>*& ref_node) {
		return (ref_node)->right_ptr;
	}

	void set_left_ptr(AVLNode<T>* new_left) {
		left_ptr = new_left;
	}

	void set_right_ptr(AVLNode<T>* new_right) {
		right_ptr = new_right;
	}
};

#endif