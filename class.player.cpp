#include "class.player.hpp"

Player::Player()
{
     money = 0;
     turns = 3;
}

float Player::balance()
{
     return money;
}

void Player::deposit (float m)
{
     money += m;
}

int Player::getTurns()
{
	return turns;
}

void Player::decrementTurns()
{
	turns = turns - 1;
}


#ifdef UNIT_TEST_PLAYER
	#include <iostream>
	using namespace std;
	int main()
	{
		//Declaring Object
		Player Player1;
		Player1.deposit(500);
		cout << Player1.balance() << endl;

		//Using Pointer
		Player *Player2 = new Player();
		Player2->deposit(400);
		cout << Player2->balance() << endl;
		
		return 0;
	}
#endif
