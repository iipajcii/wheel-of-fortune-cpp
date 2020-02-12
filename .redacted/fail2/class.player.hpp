#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>
using namespace std;
class Player {
	public:
		Player();
		string name();
		string id();

	private:
		string _name;
		string _id;
		float  _total;
};

#endif
