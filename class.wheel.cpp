#include "class.wheel.hpp"
#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;

Wheel::Wheel()
{
	current = head = NULL;
};


Wheel::Wheel(CardNode* c)
{
	current = head = c;
	head->setNextCard(NULL);
}

int Wheel::spin()
{
	srand(time(0));
	int count = 50 + (rand() % 51);
	return count;
}


void Wheel::insertFirst(CardNode* c)
{
	if(head == NULL)
	{
		head = c;
	}
	else
	{
		c->setNextCard(head);
		head = c;
	}
}

void Wheel::insertCardAtHead(Type t, float v)
{
	Card* card = new Card(t, v);
	CardNode* c = new CardNode(card);
	if(head == NULL)
	{
		head = c;
	}
	else
	{
		c->setNextCard(head);
		head = c;
	}
}

void Wheel::insertCardAtHead(Type t)
{
	Card* card = new Card(t, 0);
	CardNode* c = new CardNode(card);
	if(head == NULL)
	{
		head = c;
	}
	else
	{
		c->setNextCard(head);
		head = c;
	}
}


void Wheel::insertMiddle(CardNode* n)
{
	if(head == NULL)
	{
		head = n;
	}
	else
	{
		int entries = count() / 2;
		CardNode* tmp = head;
		CardNode* prev = NULL;
		for(int i = 0; i < entries; i++)
		{
			prev = tmp;
			tmp = tmp->getNextCard();
		};
		prev->setNextCard(n);
		n->setNextCard(tmp);
	}
}

void Wheel::insertLast(CardNode* n)
{
	if(head == NULL)
	{
		head = n;
	}
	else
	{
		CardNode* tmp = head;
		while(tmp->getNextCard() != NULL)
		{
			tmp = tmp->getNextCard();
		};
		tmp->setNextCard(n);
	}
};

int Wheel::count()
{
	CardNode *tmp = head;
	int count = 0;
	while(NULL != tmp)
	{
		tmp = tmp->getNextCard();
		count++;
	}
	return count;
}

int Wheel::find(Type t, float v)
{
	CardNode *tmp = head;
	int count = 0;
	while(NULL != tmp)
	{
		count++;
		if(tmp->getCardType() == t && tmp->getCardValue() == v)
		{
			// cout <<"\"" << t <<"::" << f << "\""<<" found in entry: " << count << endl;
			return count;
		}
		tmp = tmp->getNextCard();
	}
	return -1;
}


void Wheel::display()
{
	CardNode *tmp = head;
	while(NULL != tmp)
	{
		cout << tmp->getCardType() << " :: " << tmp->getCardValue() << endl;
		tmp = tmp->getNextCard();
	}
}

void Wheel::circular()
{
	CardNode *tmp = head;
	while(NULL != tmp->getNextCard())
	{
		tmp = tmp->getNextCard();
	}
	tmp->setNextCard(head);
};

void Wheel::uncircular()
{
	CardNode *tmp = head;
	while(head != tmp->getNextCard())
	{
		tmp = tmp->getNextCard();
	}
	tmp->setNextCard(NULL);
};

int Wheel::deleteCard(Type t, float v)
{
	if(head == NULL)
	{
		return -1;
	}

	if(head->getCardType() == t && head->getCardValue() == v)
	{
		CardNode *tmp = head;
		head = head->getNextCard();
		delete tmp;
		return 0;
	}
	else
	{
		CardNode *tmp = head;
		CardNode *prev = tmp;
		while(tmp->getNextCard() != NULL)
		{
			prev = tmp;
			tmp = tmp->getNextCard();
			if(tmp->getCardType() == t && tmp->getCardValue() == v)
			{
				prev->setNextCard(tmp->getNextCard());
				delete tmp;
				break;
			}
		}
		return 0;
	}
}

	#ifdef UNIT_TEST_WHEEL
	int main()
	{
		Card* c1 = new Card(MONEY,300);
		CardNode* cN1 = new CardNode(c1);
		
		Card* c2 = new Card(MONEY,500);
		CardNode* cN2 = new CardNode(c2);

		
		

		Wheel wheel;
		wheel.insertFirst(cN1);
		wheel.insertLast(cN2);
		wheel.insertCardAtHead(MONEY,600);
		cout << "Wheel Card Count: "  << wheel.count() << endl;
		wheel.circluar();
		wheel.uncircular();
		wheel.display();
		cout << "Test find MONEY::700\n" << wheel.find(MONEY, 700) << endl;
		cout << "Test find MONEY::600\n" << wheel.find(MONEY, 600) << endl;
		cout << "Test find MONEY::300\n" << wheel.find(MONEY, 300) << endl;
		cout << "Test find MONEY::500\n" << wheel.find(MONEY, 500) << endl;
		cout << "Deleting MONEY::500\n" << endl;
		wheel.deleteCard(MONEY, 500);
		wheel.display();
		return 0;
	}
	#endif
