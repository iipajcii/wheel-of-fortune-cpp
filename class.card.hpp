#ifndef CARD_HPP
#define CARD_HPP

class Card 
{
	enum Type{BANKRUPT = -1, SKIP = 0, MONEY = 1};

	public:
  		Card();
		void  setType(Card::Type t);
		void  setValue(float v);
		Card::Type  getType();
		float getValue();

	private:
		float value;
		Card::Type type;
};

#endif
