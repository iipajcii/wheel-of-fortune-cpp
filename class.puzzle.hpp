#include <iostream>
#include <string>
using namespace std;

class Puzzle
{
	public:
		Puzzle();
		Puzzle(string ques, string ans);
		int play();
		void getQuestion();
		void getAnswer();

	private:
		string question;
		string answer;
		string toUpper(string s);
};
