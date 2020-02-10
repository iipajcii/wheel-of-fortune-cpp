#include "class.linkedList.hpp"

LinkedList::LinkedList()
{

	_head.set("LinkedList Q", "LinkedList A");
};

LinkedList::LinkedList(string ques, string ans)
{
	_head.set(ques, ans);
};

void LinkedList::display()
{
	Node *tmp = &_head;
	cout << tmp->question() << " " << tmp->answer() << endl;
	while(tmp->nextNode() != NULL)
	{
		tmp = tmp->nextNode();
		cout << tmp->question() << " " << tmp->answer() << endl;
	}
};

void LinkedList::insertLast(Node n)
{
	Node *tmp = &_head;
	while(tmp != NULL)
	{
		tmp = tmp->nextNode();
	}
	tmp->setNext(n);
};

void LinkedList::insertFirst(Node n)
{
	Node *tmp = new Node(n);
	tmp->_next = &_head;
	_head = *tmp;
	delete tmp;
};
