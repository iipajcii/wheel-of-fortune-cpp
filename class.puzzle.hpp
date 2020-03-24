#ifndef PUZZLE_HPP
#define PUZZLE_HPP

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
		int enterLetter();
		int enterVowel(char c); 
		int enterConsonant(char c);
		void setAnswer(string a);
		void setQuestion(string q);
		void setPuzzle(string q, string a);
		string getQuestion();
		string getAnswer();
		string display();
		string getCache();
		// int lettersFound();
		bool inCache(char c);
		bool isVowel(char c);
	private:

		
		bool isConsonant(char c);
		char   toUpper(char c);
		string toUpper(string s);
		
		
		string question;
		string answer;
		string cache;
};

#endif
