#ifndef PA2_H
#define PA2_H


#include <algorithm>
#include"AVLTree.h"
#include <iostream>
#include <fstream>
#include<string>
#include<time.h>

#include <iostream>

//the set array function sets up the three arrays so that one is in ascending order, one is
//in decreasing order, and the last is filled randomly with no repeats
void set_arrays(int num, int arr[50]) {
	//sort in increasing order
	if (num == 1) {
		int count = 0;
		for (int i = 1; i < 100; i += 2) {
			arr[count] = i;
			count++;
		}
	}
	//sort in decreasing order
	else if (num == 2) {
		int count = 0;
		for (int i = 99; i >= 1; i -= 2) {
			arr[count] = i;
			count++;
		}
	}
	//random shuffle
	else if(num == 3) {
		int check[50] = { 0 };
		int a = 0;
		for (int i = 0; i < 50; i++) {
			do {
				a = ((rand() % 50));
			} while (check[a] != 0);
			check[a]++;
			arr[i] = (2 * a) + 1;
		}

	}

}


#endif 