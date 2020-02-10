#include "class.linkedList.hpp"

LinkedList::LinkedList()
{
	//_node = new Node();
	//_next_node = NULL;
};

LinkedList::LinkedList(Node n)
{
	_node = n;
}

void LinkedList::display() //Displays all the nodes in the linked list
{
	
	if(!_node.empty())
	{
		_node.display();
	}

	Node *tmp = nextNode();
	while(NULL != tmp)
	{
		cout << "->";
		tmp->display();
		tmp = tmp->nextNode();
	}
};

void LinkedList::insertLast(Node n) //Insert node at the end of List 
{
	// Node *tmp = _node.nextNode();
	// while(*tmp != NULL)
	// {
	// 	tmp = _node.nextNode();
	// }
	//tmp->nextNode() = new Node(n);
};


void LinkedList::insertFirst(Node n) //Insert node at the beginning of List 
{
};

Node* LinkedList::nextNode()
{
	return _node.nextNode();
};

bool LinkedList::empty()
{
	if(_node.empty()){return true;}
	else {return false;}
}
