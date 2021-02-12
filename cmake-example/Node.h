#pragma once
#include "PA1.h"

//node template class 
template <class A, class B>
class Node {
private:
	Node<A, B>* pnext;
	A command_name;
	B description;

public:

	Node<A, B> (){
		command_name = "";
		description = "";
		pnext = NULL;
	}

	Node<A, B>(A comm, B desc) {
		command_name = comm;
		description = desc;
		pnext = NULL;
	}

	

	Node<A,B>* getNext() {
		return this->pnext;
	}


	void setNext(Node<A, B>* next) {
		this->pnext = next;
	}

	A getCommand() {
		return this->command_name;
	}

	void setCommand(A &val) {
		this->command_name = val;
	}

	void setDesc(B &value) {
		this->description = value;
	}

	B getDesc() {
		return this->description;
	}

	



};