#ifndef DISPLAY_HPP
#define DISPLAY_HPP
#include "class.player.hpp"
#include "class.puzzle.hpp"
#include "class.card.hpp"
#include <string>
using namespace std;

class Display
{
	public:
		Display();
		void banner(int i);
		void player(Player* p);
		void clear();
		void puzzle(Puzzle p);
		void wait();
		void pause(int i);
		void text(string s);
		void spinning();
		void millipause(int milliseconds);
		void displayRound(int round);
		void card(Card* c);
	private:
};

#endif
