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
	//Displaying Game Banner;
	display.banner(1);
	
	//Inserting Cards into Wheel
	wheel.insertCardAtHead(MONEY,900);
	wheel.insertCardAtHead(MONEY,500);
	wheel.insertCardAtHead(MONEY,650);
	wheel.insertCardAtHead(MONEY,500);
	wheel.insertCardAtHead(MONEY,800);
	wheel.insertCardAtHead(SKIP);
	wheel.insertCardAtHead(MONEY, 700);
	wheel.insertCardAtHead(MONEY, 850);
	wheel.insertCardAtHead(MONEY, 650);
	wheel.insertCardAtHead(BANKRUPT);
	wheel.insertCardAtHead(MONEY, 600);
	wheel.insertCardAtHead(MONEY, 500);
	wheel.insertCardAtHead(MONEY, 550);
	wheel.insertCardAtHead(MONEY, 600);
	wheel.insertCardAtHead(BANKRUPT);
	wheel.insertCardAtHead(MONEY, 700);
	wheel.insertCardAtHead(MONEY, 500);
	wheel.insertCardAtHead(MONEY, 650);
	wheel.insertCardAtHead(MONEY, 600);
	wheel.insertCardAtHead(MONEY, 700);
	wheel.insertCardAtHead(MONEY, 600);
	wheel.insertCardAtHead(SKIP);
	wheel.insertCardAtHead(MONEY, 2500);
	wheel.insertCardAtHead(BANKRUPT);
	wheel.circular();


	// wheel.display();
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

