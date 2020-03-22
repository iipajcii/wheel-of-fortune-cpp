#include "class.game.hpp"
int main()
{
	//make a display object to save the first banner. No need to start a whole new game just in case the player selects exit;
	Game game;
	game.start();
	for(int round = 1; round < 4; round++)
	{
		game.round(round);
	}
	return 0;
}
