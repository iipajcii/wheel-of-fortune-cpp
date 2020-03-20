#include "class.card.hpp"

Card::Card(){type = SKIP; value = 0;};
Card::Card(Type t, float f){type = t; value = f;};
Card::Card(Type t){type = t; value = 0;};
void  Card::setType(Type t){type = t;};
void  Card::setValue(float v){value = v;};
Type  Card::getType(){return type;};
float Card::getValue() {return value;};

#ifdef UNIT_TEST_CARD
	#include <iostream>
	using namespace std;
	int main()
	{

		Card c1;
		Card *c2 = new Card();

		cout << "...GETTING VALUES OF c1 AND c2..." << endl;
		cout << c1.getValue() << endl;
		cout << c2->getValue() << endl << endl;
		
		cout << "...GETTING TYPES OF c1 AND c2..." << endl;
		cout << c1.getType() << endl;
		cout << c2->getType() << endl << endl;
		
		cout << "...SETTING VALUES OF c1 AND c2..." << endl << endl;
		c1.setValue(4545);
		c2->setValue(9696);

		cout << "...SETTING TYPES  OF c1 AND c2..." << endl << endl;
		c1.setType(BANKRUPT);
		c2->setType(BANKRUPT);

		cout << "...GETTING VALUES OF c1 AND c2..." << endl;
		cout << c1.getValue() << endl;
		cout << c2->getValue() << endl << endl;
		
		cout << "...GETTING TYPES OF c1 AND c2..." << endl;
		cout << c1.getType() << endl;
		cout << c2->getType() << endl << endl;
	}	
#endif
	
