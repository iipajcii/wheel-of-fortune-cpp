#ifndef WHEEL_HPP
#define WHEEL_HPP
#include "class.cardNode.hpp"
#include <cstddef> //In order to import the 'NULL' keyword that is usually added in <iostream>

class Wheel
{
	public:
		Wheel();
		Wheel(CardNode* c);
		void insertFirst(CardNode* c);
		void insertCardAtHead(Type t, float v);
		void insertCardAtHead(Type t);
		int deleteCard(Type t, float v);
		void insertMiddle(CardNode* c);
		void insertLast(CardNode* c);
		void circular();//Transforms the Linked List into a Circular Linked List
		void uncircular();//Transforms the Linked List into a Circular Linked List
		int count();
		int spin();
		int find(Type t, float v);
		void display();
		
	private:
		CardNode* head = NULL;
		CardNode* current;
};

#endif
