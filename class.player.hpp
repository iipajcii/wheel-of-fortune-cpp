#ifndef PLAYER_HPP
#define PLAYER_HPP

class Player{
	public:
		Player();
		float balance ();
		void deposit (float n);

	private:
		float money;
};

#endif
