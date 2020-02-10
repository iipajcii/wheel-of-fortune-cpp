#ifndef CLASS_LINKEDLIST
#define CLASS_LINKEDLIST

#include "class.node.hpp"

class LinkedList{
	public:
		LinkedList();
		LinkedList(string ques, string ans);
		void display();
		void insertLast(Node n);
		void insertFirst(Node n);
	private:
		Node _head;
};

#endif
