#include <iostream>
#include "class.player.hpp"
//#define UNIT_TEST_PLAYER
using namespace std;

float Player::balance ()
{
     // cout << name << " Money: " << balance << endl;
     return money;
};

void Player::deposit (float n)
{
     money += n;
}

Player::Player()
{
     money = 0;
     //name = "Player";
}

#ifdef UNIT_TEST_PLAYER
	int main()
	{
		//Declaring Object
		Player Player1;
		Player1.deposit(400);
		cout << Player1.balance() << endl;

		//Using Pointer
		Player *Player2 = new Player();
		Player2->deposit(400);
		cout << Player2->balance() << endl;
		
		return 0;
	}
#endif
