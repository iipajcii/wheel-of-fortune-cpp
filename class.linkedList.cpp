#include "class.linkedList.hpp"

LinkedList::LinkedList()
{
	//_node = new Node();
	_next_node = NULL;
};

void LinkedList::display() //Displays all the nodes in the linked list
{
	
	if(!_node.empty())
	{
		_node.display();
	}
	LinkedList *tmp = nextNode();
	while(NULL != tmp)
	{
		cout << "->";
		tmp->display();
		tmp = tmp->nextNode();
	}
	
};

void LinkedList::insertLast(Node n) //Insert node at the end of List 
{
	while(nextNode() != NULL)
	{
		Linkedlist *tmp = nextNode();
		if(tmp->nextNode() == NULL){(tmp->nextNode)._node = n}
	}
	
};


void LinkedList::insertFirst(Node n) //Insert node at the beginning of List 
{
};

LinkedList* LinkedList::nextNode()
{
	return _next_node;
};
