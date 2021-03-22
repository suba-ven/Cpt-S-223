#include "PA2.h"

int main()
{	
	
	srand(time(NULL));
	//the data structures I decided to use were three arrays
	int decreasing[50] = { 0 };
	int ascending[50] = { 0 };
	int random[50] = { 0 };

	//this function populates the arrays in the correct orders
	set_arrays(1, ascending);
	set_arrays(2, decreasing);
	set_arrays(3, random);

	
	//Create three AVL trees and insert the three data sequences into three AVL trees, separately.
	//So each AVL tree will have 50 nodes.
	AVLTree<int>* ascen_tree = new AVLTree<int>(ascending[0]);
	for (int i = 1; i < 50; i++) {
		ascen_tree->insertNode(ascending[i]);
	}

	AVLTree<int>* dec_tree = new AVLTree<int>(decreasing[0]);
	for (int i = 1; i < 50; i++) {
		dec_tree->insertNode(decreasing[i]);
	}

	AVLTree<int>* random_tree = new AVLTree<int>(random[0]);
	for (int i = 1; i < 50; i++) {
		random_tree->insertNode(random[i]);
	}

	//Print the height of each AVL tree. (hint: what is the expected output ? )
	//The expected output for height should be around log base 2 of 50, or between 5 and 6
	std::cout << "The height of the first tree (from the ascending array) is: " << ascen_tree->get_root()->get_height()<<std::endl;
	std::cout << "The height of the second tree (from the decreasing array) is: " << dec_tree->get_root()->get_height() << std::endl;
	std::cout << "The height of the third tree (from the shuffled array) is: " << random_tree->get_root()->get_height() << std::endl<<std::endl;

	// Print the result of validate() for each AVL tree
	std::cout << "Result from 'validate' for first tree: " << ascen_tree->validate(ascen_tree->get_root()) << std::endl;
	std::cout << "Result from 'validate' for second tree: " << dec_tree->validate(dec_tree->get_root()) << std::endl;
	std::cout << "Result from 'validate' for third tree: " << random_tree->validate(random_tree->get_root()) << std::endl << std::endl;

	//For each AVL tree, loop over Number 1 – 100 and call contains() function for each number.
	//For odd number, contains() should return 1; for even number, it should return 0. 
	//If the result is not as expected, your code should print “My AVL tree implementation is wrong”.
	std::cout << "Test of contains on first tree" << std::endl;
	for (int i = 1; i <= 100; i++) {
		std::cout << "Value: " << i << "\tResult from contains: " << ascen_tree->contains(i, ascen_tree->get_root()) << std::endl;
	}

	std::cout <<std::endl<< "Test of contains on second tree" << std::endl;
	for (int i = 1; i <= 100; i++) {
		std::cout << "Value: " << i << "\tResult from contains: " << dec_tree->contains(i, dec_tree->get_root()) << std::endl;
	}

	std::cout << std::endl << "Test of contains on third tree" << std::endl;
	for (int i = 1; i <= 100; i++) {
		std::cout << "Value: " << i << "\tResult from contains: " << random_tree->contains(i, random_tree->get_root()) << std::endl;
	}

	return 0;
}
