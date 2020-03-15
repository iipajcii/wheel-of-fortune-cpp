#include "class.playerll.hpp"

PlayerLL::PlayerLL()
{
	_head = NULL;
}

PlayerLL::PlayerLL(PlayerNode *p)
{
	_head = p;
}

void PlayerLL::insertFirst(PlayerNode *p)
{
	if(_head == NULL)
	{
		_head = p;
	}
	else
	{
		p->setNextPlayer(_head);
		_head = p;
	}
}

void PlayerLL::display()
{
	int counter = 1;
	PlayerNode *tmp = _head;
	while(NULL != tmp)
	{
		cout <<"Player"<< counter <<"->";
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
