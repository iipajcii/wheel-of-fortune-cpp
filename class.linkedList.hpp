#ifndef LINKEDLIST_HPP
#define LINKEDLIST_HPP
#include "struct.node.hpp"

class LinkedList
{
	public:
		LinkedList();
		LinkedList(string q, string a);
		void insertFirst(string ques, string ans);
		void deleteNode();
		void insertMiddle(string ques, string ans);
		void insertLast(string ques, string ans);
		void circluar();//Transforms the Linked List into a Circular Linked List
		void uncircular();//Transforms the Linked List into a Circular Linked List
		int count();
		int find(string find);
		void display();
	private:
		Node *_head = NULL;
};

#endif
