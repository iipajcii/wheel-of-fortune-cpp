#include <iostream>
#include "class.player.hpp"

using namespace std;

enum catagory{ PERSON = 1, PLACE = 2, THING = 3, PHRASE = 4};
catagory CATAGORY;

int main()
{
	Player Player1;
	cout << "Player Name: "<< Player1.name() << endl;
	cout << "End" << endl << endl;
	return 0;
}
