#ifndef LINKEDLIST_HPP
#define LINKEDLIST_HPP
#define UNIT_TEST_LINKEDLIST // Copy file to .cpp extension and compile to use unit test

#include "struct.node.hpp"

class LinkedList
{
	public:
		LinkedList();
		LinkedList(string q, string a);
		void insertFirst(string ques, string ans);
		void insertLast(string ques, string ans);
		void circluar();//Transforms the Linked List into a Circular Linked List
		void uncircular();//Transforms the Linked List into a Circular Linked List
		void display();
	private:
		Node *_head = NULL;
};

LinkedList::LinkedList()
{
	_head = NULL;
};

LinkedList::LinkedList(string q, string a)
{
	_head = new Node;
	_head->_ques = q;
	_head->_ans = a;
	_head->_next = NULL;
};

void LinkedList::insertFirst(string ques, string ans)
{
	Node *n = new Node;
	n->_ques = ques;
	n->_ans = ans;
	n->_next = NULL;

	if(_head == NULL)
	{
		_head = n;
	}
	else
	{
		n->_next= _head;
		_head = n;
	}
};

void LinkedList::insertLast(string ques, string ans)
{
	Node *n = new Node;
	n->_ques = ques;
	n->_ans = ans;
	n->_next = NULL;

	if(_head == NULL)
	{
		_head = n;
	}
	else
	{
		Node* tmp = _head;
		while(tmp->_next != NULL)
		{
			tmp = tmp->_next;
		};
		tmp->_next = n;
	}
};

void LinkedList::display()
{
	Node *tmp = _head;
	// /*1*/cout << _head->_ques << " :: " << _head->_ans << endl;
	// /*2*/cout << _head->_next->_ques << " :: " << _head->_next->_ans << endl;
	// /*3*/cout << _head->_next->_next->_ques << " :: " << _head->_next->_next->_ans << endl;
	// /*4*/cout << _head->_next->_next->_next->_ques << " :: " << _head->_next->_next->_next->_ans << endl;
	// /*5*/cout << _head->_next->_next->_next->_next->_ques << " :: " << _head->_next->_next->_next->_next->_ans << endl;
	// /*6*/cout << _head->_next->_next->_next->_next->_next->_ques << " :: " << _head->_next->_next->_next->_next->_next->_ans << endl;

	while(NULL != tmp)
	{
		cout << tmp->_ques << " :: " << tmp->_ans << endl;
		tmp = tmp->_next;
	}
};

void LinkedList::circluar()
{
	Node *tmp = _head;
	while(NULL != tmp->_next)
	{
		tmp = tmp->_next;
	}
	tmp->_next = _head;
};

void LinkedList::uncircular()
{
	Node *tmp = _head;
	while(_head != tmp->_next)
	{
		tmp = tmp->_next;
	}
	tmp->_next = NULL;
};

	#ifdef UNIT_TEST_LINKEDLIST
	int main()
	{
		LinkedList  ll("Question1","Answer1");
		ll.insertFirst("Question2","Answer2");
		ll.insertFirst("Question3","Answer3");
		ll.insertFirst("Question4","Answer4");
		ll.insertFirst("Question5","Answer5");
		ll.insertLast ("Question6","Answer6");
		ll.insertLast ("Question7","Answer7");
		ll.insertLast ("Question8","Answer8");
		ll.insertLast ("Question9","Answer9");
		ll.insertLast ("Question10","Answer10");

		ll.circluar();
		ll.uncircular();
		ll.display();
		return 0;
	}
	#endif

#endif
