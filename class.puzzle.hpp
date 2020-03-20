#include <iostream>
#include <string>
using namespace std;

class Puzzle
{
	public:
		Puzzle();
		Puzzle(string ques, string ans);
		int play();
		int enterLetter(char c);
		int enterVowel(char c); 
		int enterConsonant(char c);
		void setAnswer(string a);
		void setQuestion(string q);
		string getQuestion();
		string getAnswer();
		string display();
		// int lettersFound();

	private:
		bool isVowel(char c);
		bool isConsonant(char c);
		char   toUpper(char c);
		string toUpper(string s);
		string getCache();
		
		string question;
		string answer;
		string cache;
};
