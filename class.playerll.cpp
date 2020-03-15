#include "class.Playerll.hpp"
//#define UNIT_TEST_Playerll

/*
class PlayerLL
{
	public:
		PlayerLL();

		void insertFirst(Player* p);
		void deleteNode();
		void insertMiddle(Player* p);
		void insertLast(Player* p);
		void circluar();//Transforms the Linked List into a Circular Linked List
		void uncircular();//Transforms the Linked List into a Circular Linked List
		int count();
		int find(string find);
		void display();

	private:
		Player *_head = NULL;
};

*/

Playerll::Playerll()
{
	_head = NULL;
};

Playerll::Playerll(Player *p)
{
	_head = p;
	_head->_next = NULL;
};

void Playerll::insertFirst(string ques, string ans)
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

void Playerll::insertMiddle(string ques, string ans)
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

void Playerll::insertLast(string ques, string ans)
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

int Playerll::count()
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

int Playerll::find(string find)
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


void Playerll::display()
{
	Node *tmp = _head;
	while(NULL != tmp)
	{
		cout << tmp->_ques << " :: " << tmp->_ans << endl;
		tmp = tmp->_next;
	}
};

void Playerll::circluar()
{
	Node *tmp = _head;
	while(NULL != tmp->_next)
	{
		tmp = tmp->_next;
	}
	tmp->_next = _head;
};

void Playerll::uncircular()
{
	Node *tmp = _head;
	while(_head != tmp->_next)
	{
		tmp = tmp->_next;
	}
	tmp->_next = NULL;
};

void Playerll::deleteNode()
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

	#ifdef UNIT_TEST_Playerll
	int main()
	{
		return 0;
	}
	#endif
