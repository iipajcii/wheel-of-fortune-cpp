#include "class.game.hpp"

Game::Game()
{
	PlayerLL p;
	Wheel w;
	Puzzle z;

	players = p;
	wheel = w;
	puzzle = z;
}

Game::Game(PlayerLL p, Wheel w)
{
	players = p;
	wheel = w;
}

Game::Game(PlayerLL p, Wheel w, Puzzle z)
{
	players = p;
	wheel = w;
	puzzle = z;
}


int Game::start()
{
	cout << "Game Start" << endl;
	cout << "Game Over " << endl;
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

