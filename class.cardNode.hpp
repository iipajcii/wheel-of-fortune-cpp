#ifndef CARD_NODE_HPP
#define CARD_NODE_HPP
#include "class.card.hpp"

class CardNode{
	public:
		CardNode();
		CardNode(Card* p);
		CardNode(Card* p, CardNode* n);

		Card* getCard();
		CardNode* getNextCard();
		void setCard(Card* p);
		void setNextCard(CardNode* p);

		Type getCardType();
		void setCardType(Type t);
		void setCardValue(float f);
		float getCardValue();
		
	private:
		Card* card;
		CardNode* nextCard;
};

#endif
