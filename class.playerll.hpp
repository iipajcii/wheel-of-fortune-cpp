#ifndef PLAYERLL_HPP
#define PLAYERLL_HPP
#include "class.playerNode.hpp"
#include <iostream>
using namespace std;

class PlayerLL
{
	public:
		PlayerLL();
		PlayerLL(PlayerNode *p);
		void insertFirst(PlayerNode* p);
		// void deleteNode();
		// void insertMiddle(PlayerNode* p);
		// void insertLast(PlayerNode* p);
		// void circluar();//Transforms the Linked List into a Circular Linked List
		// void uncircular();//Transforms the Linked List into a Circular Linked List
		// int count();
		// int find(string find);
		void display();

	private:
		PlayerNode *_head = NULL;
};

#endif
