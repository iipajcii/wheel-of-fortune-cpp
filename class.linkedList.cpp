#include "class.linkedList.hpp"
//#define UNIT_TEST_LINKEDLIST

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

void LinkedList::insertMiddle(string ques, string ans)
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
		int entries = count() / 2;
		Node* tmp = _head;
		Node* prev = NULL;
		for(int i = 0; i < entries; i++)
		{
			prev = tmp;
			tmp = tmp->_next;
		};
		prev->_next = n;
		n->_next = tmp;
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

void LinkedList::deleteNode()
{
	     if(_head == NULL)
	{
		cout << "Head is Null" << endl;
		return;
	}

	cout << "Enter Question to delete" << endl;
	string del;
	cin >> del;

	if(_head->_ques == del)
	{
		Node *tmp = _head;
		_head = _head->_next;
		delete tmp;
	}
	else
	{
		Node *tmp = _head;
		Node *prev = tmp;
		while(tmp->_next != NULL)
		{
			prev = tmp;
			tmp = tmp->_next;
			if(tmp->_ques == del)
			{
				prev->_next = tmp->_next;
				delete tmp;
				break;
			}
		}
	}

	
}

	#ifdef UNIT_TEST_LINKEDLIST
	int main()
	{
		LinkedList  ll("Q1","A1");
		ll.insertFirst("Q2","A2");
		ll.insertLast ("Q3","A3");
		ll.insertLast ("Q4","A4");
		ll.insertLast ("Q5","A5");
		
		ll.insertMiddle("M","M");

		cout << "Linked List Node Count: "  << ll.count() << endl << endl;
		ll.find("Q3");
		ll.circluar();
		ll.uncircular();
		ll.display();
		ll.deleteNode();
		ll.display();
		return 0;
	}
	#endif
