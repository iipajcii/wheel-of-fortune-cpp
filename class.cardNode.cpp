#include "class.cardNode.hpp"
#include <cstddef> //In order to import the 'NULL' keyword that is usually added in <iostream>

CardNode::CardNode()
{
	nextCard = NULL;
}

CardNode::CardNode(Card* p)
{
	card = p;
	nextCard = NULL;
}

CardNode::CardNode(Card* p, CardNode* n)
{
	card = p;
	nextCard = n;	
}

Card*  CardNode::getCard()
{
	return card;
}

CardNode* CardNode::getNextCard()
{
	return nextCard;
}

void CardNode::setCard(Card* p)
{
	card = p;
}

void CardNode::setNextCard(CardNode* p)
{
	nextCard = p;
}

Type CardNode::getCardType()
{
	return card->getType();
}

void CardNode::setCardType(Type t)
{
	card->setType(t);
}

float CardNode::getCardValue()
{
	return card->getValue();
}

void CardNode::setCardValue(float f)
{
	card->setValue(f);
}


#ifdef UNIT_TEST_CARD_NODE
	#include <iostream>
	using namespace std;
	int main()
	{
		//Declaring Cards
		Card  c1;
		Card* c2 = new Card();
		Card  c3;
		Card* c4 = new Card();

		CardNode cN1(&c1);
		CardNode cN2(c2);
		CardNode* cN3 = new CardNode(&c3);
		CardNode* cN4 = new CardNode(c4);
		
		//Testing Functionality of CardNode Class
		cout << "...GETTING VALUES OF cN1, cN2, cN3, cN4..." << endl;
		cout << cN2.getCardValue() << endl;
		cout << cN1.getCardValue() << endl;
		cout << cN3->getCardValue() << endl;
		cout << cN4->getCardValue() << endl;

		cout << "...GETTING TYPES OF cN1, cN2, cN3, cN4..." << endl;
		cout << cN1.getCardType() << endl;
		cout << cN2.getCardType() << endl;
		cout << cN3->getCardType() << endl;
		cout << cN4->getCardType() << endl << endl;

		cout << "...SETTING VALUES OF cN1, cN2, cN3, cN4..." << endl;
		cN1.setCardValue(123);
		cN2.setCardValue(456);
		cN3->setCardValue(789);
		cN4->setCardValue(101112);

		cout << "...SETTING TYPES OF cN1, cN2, cN3, cN4..." << endl << endl;
		cN1.setCardType(BANKRUPT);
		cN2.setCardType(BANKRUPT);
		cN3->setCardType(SKIP);
		cN4->setCardType(MONEY);

		cout << "...GETTING TYPES OF cN1, cN2, cN3, cN4..." << endl;
		cout << cN1.getCard()->getType() << endl;
		cout << cN2.getCard()->getType() << endl;
		cout << cN3->getCard()->getType() << endl;
		cout << cN4->getCard()->getType() << endl;

		cout << "...GETTING VALUES OF cN1, cN2, cN3, cN4..." << endl;
		cout << cN1.getCard()->getValue() << endl;
		cout << cN2.getCard()->getValue() << endl;
		cout << cN3->getCard()->getValue() << endl;
		cout << cN4->getCard()->getValue() << endl;

		return 0;
	}
#endif
