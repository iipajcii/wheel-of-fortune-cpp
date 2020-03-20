#include "class.card.hpp"

Card::Card(){type = SKIP; value = 0;};
void  Card::setType(Card::Type t){type = t;};
void  Card::setValue(float v){value = v;};
Card::Type  Card::getType(){return type;};
float Card::getValue() {return value;};

#ifdef UNIT_TEST_CARD
	#include <iostream>
	using namespace std;
	int main()
	{

		Card *c1 = new Card();
		Card c2;
		
		cout << c2.getValue() << endl;
		cout << c1->getValue() << endl;

		//c1.setType(BANKRUPT);
		c1->setValue(400);

		///cout << c1.getType() << endl;
	     cout << c1->getValue() << endl;
	}	
#endif
	
