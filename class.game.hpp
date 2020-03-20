#ifndef GAME_HPP
#define GAME_HPP

#include "class.playerll.hpp"
#include "class.wheel.hpp"
#include "class.puzzle.hpp"

#include <iostream>
using namespace std;

class Game
{
	public:
		Game();
		Game(PlayerLL p, Wheel w);
		Game(PlayerLL p, Wheel w, Puzzle z);
		int start();
	private:
		PlayerLL players;
		Wheel wheel;
		Puzzle puzzle;
};

#endif
