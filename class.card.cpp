#include <iostream>
#include "class.card.hpp"

using namespace std;


Card::Card(){type = SKIP; value = 0;};
void  Card::setType(Type t){type = t;};
void  Card::setValue(float v){value = v;};
Type  Card::getType(){return type;};
float Card::getValue() {return value;};

#ifdef UNIT_TEST_CARD

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
	
