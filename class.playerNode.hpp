#ifndef PLAYER_NODE_HPP
#define PLAYER_NODE_HPP
#include "class.player.hpp"

class PlayerNode{
	public:
		PlayerNode();
		PlayerNode(Player* p);
		PlayerNode(Player* p, PlayerNode* n);

		Player* getPlayer();
		PlayerNode* getNextPlayer();
		void setPlayer(Player* p);
		void setNextPlayer(PlayerNode* p);


	private:
		Player* player;
		PlayerNode* nextPlayer;
};

#endif
