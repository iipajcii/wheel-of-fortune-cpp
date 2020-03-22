#ifndef DISPLAY_HPP
#define DISPLAY_HPP
#include <string>
using namespace std;

class Display
{
	public:
		Display();
		void banner(int i);
		void clear();
		void wait();
		void pause(int i);
		void text(string s);
		void displayRound(int round);
	private:
};

#endif
