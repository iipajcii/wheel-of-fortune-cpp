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

void Game::solvePuzzle()
{
	string answer = puzzle.getAnswer();
	char buffer[100];
	display.text("YOU HAVE 30 SECONDS TO SOLVE THE PUZZLE!");
	display.text(puzzle.display() + "\n");
	display.pause(30);
	cin >> buffer;
	string attempt = buffer;
	if(puzzle.toUpper(attempt) == answer)
	{
		display.text("Correct");
	}
	else
	{
		display.text("Incorrect");
		display.text(puzzle.toUpper(attempt));
		display.text(answer);
	}
	display.pause(60);
	display.text(attempt);
	display.text(answer);
	
	// if()
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
	display.millipause(2);
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

void Game::pickConsonant()
{
	string a;
	cin >> a;
	if(puzzle.isConsonant(a.at(0)))
	{
		if(!puzzle.inCache(a.at(0)))
		{
			puzzle.enterLetter(a.at(0));
			players.player()->deposit(wheel.card()->getValue() * puzzle.letterCount(a.at(0)));
		}
		else {
			display.text("Letter Has already been entered; Enter another vowel");
			pickConsonant();
		}
		
	}
	else
	{
		display.text("Letter is not a Consonant. Enter a Consonant");
		pickConsonant();
	}
}

/*
	This function is reliant on int Game::options(Player*) for input to decide what actions a player can and cannot do
*/
int Game::action(int choice)
{
	cout << "Choice: " << choice << endl;
	bool loop = true;
	while(loop)
	{
		loop = false;
		switch(choice)
		{
			case 1:	// 1. Buy Vowel
				if(players.player()->balance() >= 250)
				{
					buyVowel();
				}
				else
				{
					display.text("Unavailable Option, please enter again");
					display.text("1");
					cin >> choice;
					loop = true;
				}
			break;

			case 2: // 2. Pick Consonant
				if (wheel.getSpun())
				{
					pickConsonant();
				}
				else
				{
					display.text("Unavailable Option, please enter again");
					display.text("2");
					cin >> choice;
					loop = true;
				}
			break;

			case 3: // 3. Solve
				if(!(puzzle.getCache()==""))
				{
					solvePuzzle();
				}
				else
				{
					display.text("Unavailable Option, please enter again");
					display.text("3");
					cin >> choice;
					loop = true;
				}
			break;

			case 4: // 4. Spin Wheel
				if(true)
				{
					wheel.spin();
					display.spinning();
					display.card(wheel.card());
					display.text("Hit Enter to continue");
					// display.pause(3);
					display.wait();
					// game.decide();
					
				}
				else
				{
					display.text("Unavailable Option, please enter again");
					display.text("4");
					cin >> choice;
					loop = true;
				}
			break;
			default:
				display.text("Unavailable Option, please enter again");
				display.text("default");
				cin >> choice;
				loop = true;
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
			players.player()->setMoney(players.player()->balance() - 250);
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
	int choice;
	display.text("OPTIONS:  [✓ = Available, x = Not Available]");

	(p->balance() >= 250)      ? (display.text("✓ 1. Buy Vowel  [$250]")):(display.text("x 1. Buy Vowel  [$250]"));
	(wheel.getSpun())          ? (display.text("✓ 2. Pick Consonant")): (display.text("x 2. Pick Consonant"));
	(!(puzzle.getCache()=="")) ? (display.text("✓ 3. Solve")) : (display.text("x 3. Solve"));
	(1)/*You can always spin*/ ? (display.text("✓ 4. Spin Wheel\n")) : (display.text("x 4. Spin Wheel\n"));

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
	display.card(wheel.card());
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

