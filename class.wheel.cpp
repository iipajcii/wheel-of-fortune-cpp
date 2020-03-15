#include "class.wheel.hpp"
//#define UNIT_TEST_WHEEL

Wheel::Wheel()
{
	_head = NULL;
};

Wheel::Wheel(string q, string a)
{
	_head = new Node;
	_head->_ques = q;
	_head->_ans = a;
	_head->_next = NULL;
};

void Wheel::insertFirst(string ques, string ans)
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

void Wheel::insertMiddle(string ques, string ans)
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

void Wheel::insertLast(string ques, string ans)
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

int Wheel::count()
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

int Wheel::find(string find)
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


void Wheel::display()
{
	Node *tmp = _head;
	while(NULL != tmp)
	{
		cout << tmp->_ques << " :: " << tmp->_ans << endl;
		tmp = tmp->_next;
	}
};

void Wheel::circluar()
{
	Node *tmp = _head;
	while(NULL != tmp->_next)
	{
		tmp = tmp->_next;
	}
	tmp->_next = _head;
};

void Wheel::uncircular()
{
	Node *tmp = _head;
	while(_head != tmp->_next)
	{
		tmp = tmp->_next;
	}
	tmp->_next = NULL;
};

void Wheel::deleteNode()
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

	#ifdef UNIT_TEST_WHEEL
	int main()
	{
		Wheel  ll("Q1","A1");
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
