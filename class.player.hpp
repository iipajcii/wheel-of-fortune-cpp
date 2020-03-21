#ifndef PLAYER_HPP
#define PLAYER_HPP
#include <string>
using namespace std;

class Player{
	public:
		Player();
		Player(string n, float m);
		float balance ();
		void deposit (float n);
		int getTurns();
		string getName();
		void setName(string n);
		void decrementTurns();

	private:
		float money;
		int turns;
		string name;
};

#endif
