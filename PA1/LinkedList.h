#pragma once
#include "PA1.h"

template <class A, class B>
class LinkedList {

private:
	A command_name;
	B description;
	Node <A,B> *head_ptr;
	int size;


public:

	LinkedList<A,B>() {
		head_ptr = nullptr;
		size = 0;
	}

	~LinkedList<A, B>() {
		Node <string, string>* current = head_ptr;
		
		while (current != nullptr) {
			Node <string, string>* prev = current;
			current = current->getNext();
			delete prev;
		}
	}

	Node <string, string>* getHead() {
		return head_ptr;
	}


	void insertAtFront(A val, B val2) {
		Node <string, string> *current = head_ptr;
		Node <string, string> *newNode = (Node <string, string>*)malloc(sizeof(Node <string, string>*));
		//Node<string, string> bnode(val, val2);
		//*newNode = bnode;
		newNode = new Node <string, string>(val, val2);
		newNode->setNext(head_ptr);
		//newNode->setCommand(bnode.getCommand());
		//newNode->setDesc(bnode.getDesc());
		this->head_ptr = newNode;
		size++;
	}

	void removeNode(A val) {
		Node <string, string>* current = head_ptr;
		Node <string, string>* prev = head_ptr;
		int count = 0;
		while (current != nullptr) {
			if ((current->getCommand()).compare(val) == 0){
				if (count == 0) {
					head_ptr = current->getNext();
				}
				else {
					prev->setNext(current->getNext());
				}
			}
			current = current->getNext();
				if (count > 0) {
					prev = prev->getNext();
				}
				count++;
		}

		delete current;
	}

	void printList() {
		Node <string, string> *current = head_ptr;
		while (current != nullptr) {

			cout << current->getCommand() << endl;;
			current = current->getNext();
		}
	}

	void printToFile(fstream dataFile) {
		Node <string, string>* current = head_ptr;
		while (current != nullptr) {

			dataFile << current->getCommand()<<",\""<< current->getDesc() <<"\""<< endl;
			current = current->getNext();
		}
		dataFile.close();
	}

	Node<string, string> findNode(int position) {
		Node <string, string>* current = head_ptr;
		int count = 1;
		while (current != nullptr) {
			if (count == position) {
				return *current;
			}
			count++;
			current = current->getNext();
			
		}
		Node <string, string> extraNode;
		return extraNode;
	}

	bool find_duplicate(string newCommand) {
		Node <string, string>* current = head_ptr;
		while (current != nullptr) {
			if (((current->getCommand()).compare(newCommand))==0) {
				return true;
			}
			current = current->getNext();
		}
		return false;
	}

};



