#include "class.playerll.hpp"

PlayerLL::PlayerLL()
{
	head = current = NULL;
}

PlayerLL::PlayerLL(PlayerNode *p)
{
	head = current = p;
}

void PlayerLL::insertFirst(PlayerNode *p)
{
	if(head == NULL)
	{
		head = p;
	}
	else
	{
		p->setNextPlayer(head);
		head = p;
	}
}

void PlayerLL::circular()
{
	PlayerNode *tmp = head;
	while(NULL != tmp->getNextPlayer())
	{
		tmp = tmp->getNextPlayer();
	}
	tmp->setNextPlayer(head);
};

void PlayerLL::uncircular()
{
	PlayerNode *tmp = head;
	while(head != tmp->getNextPlayer())
	{
		tmp = tmp->getNextPlayer();
	}
	tmp->setNextPlayer(NULL);
};

void PlayerLL::insertMiddle(PlayerNode* p)
{
	if(head == NULL)
	{
		head = p;
	}
	else
	{
		int entries = count() / 2;
		PlayerNode* tmp = head;
		PlayerNode* prev = NULL;
		for(int i = 0; i < entries; i++)
		{
			prev = tmp;
			tmp = tmp->getNextPlayer();
		};
		prev->setNextPlayer(p);
		p->setNextPlayer(tmp);
	}
}

void PlayerLL::insertPlayerAtHead(string n)
{
	insertPlayerAtHead(n, 0);
}


void PlayerLL::insertPlayerAtHead(string n, float v)
{
	Player* player = new Player(n, v);
	PlayerNode* p = new PlayerNode(player);
	if(head == NULL)
	{
		head = p;
	}
	else
	{
		p->setNextPlayer(head);
		head = p;
	}
}


int PlayerLL::deletePlayer(string n)
{
	if(head == NULL)
	{
		return -1;
	}

	if(head->getPlayer()->getName() == n)
	{
		PlayerNode *tmp = head;
		head = head->getNextPlayer();
		delete tmp;
		return 0;
	}
	else
	{
		PlayerNode *tmp = head;
		PlayerNode *prev = tmp;
		while(tmp->getNextPlayer() != NULL)
		{
			prev = tmp;
			tmp = tmp->getNextPlayer();
			if(tmp->getPlayer()->getName() == n)
			{
				prev->setNextPlayer(tmp->getNextPlayer());
				delete tmp;
				break;
			}
		}
		return 0;
	}
}

int PlayerLL::find(string n)
{
	PlayerNode *tmp = head;
	int count = 0;
	while(NULL != tmp)
	{
		count++;
		if(tmp->getPlayer()->getName() == n)
		{
			return count;
		}
		tmp = tmp->getNextPlayer();
	}
	return -1;
}

void PlayerLL::insertLast(PlayerNode* p)
{
	if(head == NULL)
	{
		head = p;
	}
	else
	{
		PlayerNode* tmp = head;
		while(tmp->getNextPlayer() != NULL)
		{
			tmp = tmp->getNextPlayer();
		};
		tmp->setNextPlayer(p);
	}
};



int PlayerLL::count()
{
	PlayerNode *tmp = head;
	int count = 0;
	while(NULL != tmp)
	{
		tmp = tmp->getNextPlayer();
		count++;
	}
	return count;
}

void PlayerLL::display()
{
	int counter = 1;
	PlayerNode *tmp = head;
	while(NULL != tmp)
	{
		cout << tmp->getPlayer()->getName() << "->";
		tmp = tmp->getNextPlayer();
		counter++;
	}
	cout << "NULL" << endl;
}

	#ifdef UNIT_TEST_PLAYERLL
	int main()
	{
		PlayerNode pN1;
		PlayerNode pN2;
		PlayerNode pN3;

		PlayerLL pll;
		pll.insertFirst(&pN1);
		pll.insertFirst(&pN2);
		pll.insertFirst(&pN3);
		pll.display();

		return 0;
	}
	#endif
