#include "class.playerNode.hpp"
#include <cstddef>

PlayerNode::PlayerNode()
{
	nextPlayer = NULL;
}

PlayerNode::PlayerNode(Player* p)
{
	player = p;
	nextPlayer = NULL;
}

PlayerNode::PlayerNode(Player* p, PlayerNode* n)
{
	player = p;
	nextPlayer = n;	
}

Player*  PlayerNode::getPlayer()
{
	return player;
}

PlayerNode* PlayerNode::getNextPlayer()
{
	return nextPlayer;
}

void PlayerNode::setPlayer(Player* p)
{
	player = p;
}

void PlayerNode::setNextPlayer(PlayerNode* p)
{
	nextPlayer = p;
}

#ifdef UNIT_TEST_PLAYER_NODE
	#include <iostream>
	using namespace std;
	int main()
	{
		//Declaring Players
		Player* p1 = new Player();
		Player* p2 = new Player();
		Player* p3 = new Player();


		//Declaring PlayerNodes
		PlayerNode* pN1 = new PlayerNode();
		PlayerNode* pN2 = new PlayerNode(p2);
		PlayerNode* pN3 = new PlayerNode(p3);

		//Setting Player Nodes
		pN1->setPlayer(p1);
		pN1->setNextPlayer(pN2);
		pN2->setNextPlayer(pN3);

		//Setting Deposit
		pN1->getPlayer()->deposit(500);
		pN1->getPlayer()->deposit(700);
		pN2->getPlayer()->deposit(560);
		pN2->getPlayer()->deposit(790);		
		

		PlayerNode* temp = pN1;
		temp->setNextPlayer(pN1);

		cout << "p1 Balance is: " <<  pN1->getPlayer()->balance() << endl;
		cout << "p2 Balance is: " <<  pN2->getPlayer()->balance() << endl;
		cout << "p3 Balance is: " << temp->getPlayer()->balance() << endl;
		
		cout << "temp Balance is:            " << temp->getPlayer()->balance() << endl;
		cout << "temp.nextPlayer Balance is: " << temp->getNextPlayer()->getNextPlayer()->getPlayer()->balance() << endl;

		return 0;
	}
#endif
