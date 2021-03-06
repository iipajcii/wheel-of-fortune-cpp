#ifndef GAME_HPP
#define GAME_HPP

#include "class.playerll.hpp"
#include "class.wheel.hpp"
#include "class.puzzle.hpp"
#include "class.display.hpp"

#include <iostream>
using namespace std;

class Game
{
	public:
		Game();
		Game(PlayerLL p, Wheel w);
		Game(PlayerLL p, Wheel w, Puzzle z);
		int start();
		int spin();
		int end();
		int options(Player* p);
		int action(int i);
		void buyVowel();
		void pickConsonant();
		void solvePuzzle();
		int round(int round);
		Display display;
		
	private:
		PlayerLL players;
		Wheel wheel;
		Puzzle puzzle;
};

#endif
