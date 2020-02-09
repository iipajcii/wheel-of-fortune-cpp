#include <iostream>
#include "class.player.hpp"

using namespace std;

int main()
{
	//Player *Player1 = new Player();
	Player Player1;
	//Player1->deposit(400);
	Player1.deposit(400);
	//cout << Player1->balance() << endl;
	cout << Player1.balance() << endl;
	return 0;
}
