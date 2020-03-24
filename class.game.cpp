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

int Game::spin()
{
	return wheel.spin();
}

int Game::end()
{
	display.clear();
	display.pause(1);
	display.banner(4);
	display.pause(1);
	return 0;
}

int Game::start()
{
	//Displaying Game Banner;
	display.banner(1);
	display.pause(1);
	display.banner(6);
	display.wait();
	
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

	players.insertPlayerAtHead("Patrick");
	players.insertPlayerAtHead("Dymond");
	players.insertPlayerAtHead("Michael");
	players.insertPlayerAtHead("Brianna");
	players.circular();
	// players.display();

	puzzle.setPuzzle("question","answer");
	// cout << puzzle.display() << "  " << puzzle.getQuestion() << "  " << puzzle.getAnswer() << endl;
	return 0;
}

int Game::action(int choice)
{
	if(choice < 1 || choice > 4)
	{
		int i;
		display.text("Invalid Choice, Please enter again");
		cin >> i;
		action(i);
	}
	else
	{
		switch(choice)
		{
			case 1:
				buyVowel();
			break;
			
			case 2:
			break;
			
			case 3:
			break;
			
			case 4:
				wheel.spin();
			break;
		}
	}
	return 0;
}

void Game::buyVowel()
{
	string a;
	cin >> a;
	if(puzzle.isVowel(a.at(0)))
	{
		if(!puzzle.inCache(a.at(0)))
		{
			puzzle.enterLetter(a.at(0));
		}
		else {
			display.text("Letter Has already been entered; Enter another vowel");
			buyVowel();
		}
		
	}
	else
	{
		display.text("Letter is not a Vowel. Enter a vowel");
		buyVowel();
	}
	
}

int Game::options(Player* p)
{
	int choice = -1;
	display.text("OPTIONS:  [✓ = Available, x = Not Available]");

	(p->balance() >= 250)      ? (display.text("✓ 1. Buy Vowel  [$250]"), choice = 1): (display.text("x 1. Buy Vowel  [$250]"), choice = -1 );
	(wheel.getSpun())          ? (display.text("✓ 2. Pick Consonant"), choice = 2 ): (display.text("x 2. Pick Consonant"), choice = -1);
	(!(puzzle.getCache()=="")) ? (display.text("✓ 3. Solve"), choice = 3) : (display.text("x 3. Solve"), choice = -1);
	(1)/*You can always spin*/ ? (display.text("✓ 4. Spin Wheel\n"), choice = 4) : (display.text("x 4. Spin Wheel\n"), choice = -1);

	display.text("ENTER AN OPTION: ");
	cin >> choice;
	return choice;
}


int Game::round(int round)
{
	display.clear();
	display.displayRound(round);
	display.pause(3);
	// display.clear();
	display.player(players.player());

	display.puzzle(puzzle);
	action(options(players.player()));
	// puzzle.enterLetter();
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

