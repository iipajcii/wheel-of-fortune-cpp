#include "class.linkedList.hpp"
#define UNIT_TEST_LINKEDLIST // Copy file to .cpp extension and compile to use unit test

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

int LinkedList::count()
{
	Node *tmp = _head;
	int count = 0;
	while(NULL != tmp)
	{
		tmp = tmp->_next;
		count++;
	}
	return count;
}

int LinkedList::find(string find)
{
	Node *tmp = _head;
	int count = 0;
	while(NULL != tmp)
	{
		count++;
		if(tmp->_ques == find)
		{
			cout <<"\"" << find << "\""<<" found in entry: " << count << endl;
			return count;
		}
		tmp = tmp->_next;
	}
	return -1;
}


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
		LinkedList  ll("Q1","A1");
		ll.insertFirst("Q2","A2");
		ll.insertLast ("Q3","A3");
		ll.insertLast ("Q4","A4");

		cout << "Linked List Node Count: "  << ll.count() << endl << endl;
		ll.find("Q3");
		ll.circluar();
		ll.uncircular();
		ll.display();
		return 0;
	}
	#endif
