#ifndef CARD_HPP
#define CARD_HPP

enum Type {BANKRUPT = -1, SKIP = 0, MONEY = 1};

class Card 
{
	public:
  		Card();
  		Card(Type t, float f);
  		Card(Type t);
		void  setType(Type t);
		void  setValue(float v);
		Type  getType();
		float getValue();

	private:
		float value;
		Type type;
};

#endif
