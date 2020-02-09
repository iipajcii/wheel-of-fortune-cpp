#include "class.node.hpp"

class LinkedList {
	public:
		LinkedList();   //Linked List Default Constructor
		void display(); //Displays all the nodes in the linked list
		void insertFirst(Node n); //Insert node at the beginning of List 
		void insertLast(Node n); //Insert node at the end of List 
		LinkedList* nextNode();

	private:
		Node _node;
		LinkedList* _next_node;
};
