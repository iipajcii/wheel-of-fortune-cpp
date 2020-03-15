#ifndef PLAYERLL_HPP
#define PLAYERLL_HPP
#include "class.playerNode.hpp"

class PlayerLL
{
	public:
		PlayerLL();
		PlayerLL(Player *p)
		void insertFirst(Player* p);
		void deleteNode();
		void insertMiddle(Player* p);
		void insertLast(Player* p);
		void circluar();//Transforms the Linked List into a Circular Linked List
		void uncircular();//Transforms the Linked List into a Circular Linked List
		int count();
		int find(string find);
		void display();

	private:
		Player *_head = NULL;
};

#endif
