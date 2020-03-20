#include "class.game.hpp"
#include "class.display.hpp"

Game::Game()
{
	PlayerLL p;
	Wheel w;
	Puzzle z;
	Display d;

	players = p;
	display = d;
	wheel = w;
	puzzle = z;
}

Game::Game(PlayerLL p, Wheel w)
{
	Puzzle z;
	Display d;

	puzzle = z;
	display = d;
	players = p;
	wheel = w;
}

Game::Game(PlayerLL p, Wheel w, Puzzle z)
{
	Display d;

	display = d;
	players = p;
	wheel = w;
	puzzle = z;
}


int Game::start()
{
	display.banner(1);
	Card* c1 = new Card(BANKRUPT);
	Card* c2 = new Card(SKIP);
	Card* c3 = new Card(MONEY, 505);
	Card* c4 = new Card(MONEY, 202);

	CardNode* cN1 = new CardNode(c1);
	CardNode* cN2 = new CardNode(c2);
	CardNode* cN3 = new CardNode(c3);
	CardNode* cN4 = new CardNode(c4);

	wheel.insertFirst(cN1);
	wheel.insertFirst(cN2);
	wheel.insertFirst(cN3);
	wheel.insertFirst(cN4);
	wheel.display();
	return 0;
}

#ifdef UNIT_TEST_GAME
	int main()
	{
		Game game;
		game.start();
		return 0;
	}
#endif

