#ifndef PLAYER_HPP
#define PLAYER_HPP

class Player{
	public:
		Player();
		float balance ();
		void deposit (float n);
		int getTurns();
		void decrementTurns();

	private:
		float money;
		int turns;
};

#endif
