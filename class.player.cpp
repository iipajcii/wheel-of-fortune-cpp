#include "class.player.hpp"
Player::Player():_name("")
{
	cout << "New Player Created" << endl;
}

string Player::name()
{
	return _name;
}

string Player::id()
{
	return _id;
}
