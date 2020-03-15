enum Type{BANKRUPT = -1, SKIP = 0, MONEY = 1};

class Card 
{
	public:
		Card();
		void  setType(Type t);
		void  setValue(float v);
		Type  getType();
		float getValue();

	private:
		enum Type type;
		float value;
};
