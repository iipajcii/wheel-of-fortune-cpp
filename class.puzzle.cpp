#include "class.puzzle.hpp"

Puzzle::Puzzle()
{
	question = answer = cache = "";
}

Puzzle::Puzzle(string ques, string ans)
{
	question = toUpper(ques);
	answer = toUpper(ans);
}

string Puzzle::getQuestion()
{
	return question;
}

string Puzzle::getAnswer()
{
	return answer;
}

void Puzzle::setQuestion(string q)
{
	question = toUpper(q);
}

void Puzzle::setAnswer(string a)
{
	answer = toUpper(a);
}

void Puzzle::setPuzzle(string q, string a)
{
	question = toUpper(q);
	answer = toUpper(a);
}

int Puzzle::enterLetter(char c)
{
	c = toUpper(c);
	cache.append(&c);
	return 0;	
}

int Puzzle::enterLetter()
{
	char c;
	string buffer;
	cin >> buffer;
	c = buffer.at(0);
	c = toUpper(c);
	cache.append(&c);
	return 0;	
}

int Puzzle::enterVowel(char c)
{
	c = toUpper(c);
	if(isVowel(c))
	{
		cache.append(&c);
		return 0;
	}
	return -1;
} 

int Puzzle::enterConsonant(char c)
{
	c = toUpper(c);
	if(isConsonant(c))
	{
		cache.append(&c);
		return 0;
	}
	return -1;
}

bool Puzzle::isVowel(char c)
{
	c = toUpper(c);
	switch(c)
	{
		case 'A':
		case 'E':
		case 'I':
		case 'O':
		case 'U':
			return true;
	}
	return false;
}

bool Puzzle::isConsonant(char c)
{
	return !isVowel(c);
}

/*
	Note: Function used in enterVowel() and enterConsonant()
*/
string Puzzle::toUpper(string s)
{
	string str = "";
	int count = s.length();
	for(int i = 0; i < count; i++)
	{
		char c = s.at(i);
  		if(c <='z' && c >='a')
  		{
  			c -= 32;
  		}
  		str += c;
  	}
    return str;
}

char Puzzle::toUpper(char c)
{
	if(c <='z' && c >='a')
	{
		c -= 32;
	}
	return c;
}


bool Puzzle::inCache(char c)
{
	c = toUpper(c);
	for(int counter = 0, count = cache.length(); counter < count; counter++)
	{
		if(c == cache.at(counter))
		{return true;}
	}
	return false;
}


string Puzzle::display()
{
	string str = "";
	if (cache == "")
	{
		int complete = answer.length();
		for (int i = 0; i < complete; i++)
		{
			if(answer.at(i) == ' '){str += "  ";}
			else {str += "_ ";}
			if(i == complete - 1){/*cout << endl;*/}
		}
		return str;
	}
	else
	{
		int complete = answer.length(), spaceCount = 0;
		for(int j = answer.length(), i = 0; i < j ; i++)
	    {
			bool dash, space;
			spaceCount = 0;
			for(int k = cache.length(), l = 0; l < k ; l++)
			{	
				dash = true;
				if(cache.at(l) == answer.at(i))
				{
					str += answer.at(i);
					dash = false;
					break;
				}
				else if(answer.at(i) == ' ')
				{
					//Above block of code does not handle spaces, this block 
					str += "  ";
					dash = false;
					space = true;
					break;
				}
			}
			if(dash == true){complete--; str += "_ ";}
			if(space == true){spaceCount++;}
			if( i == j - 1){/*cout << endl;*/}
		}
		return str;
	}
	
}

string Puzzle::getCache()
{
	return cache;
}

// int Puzzle::lettersFound()
// {
// 	int letters = 0;
// 	int counter1 = 0;
// 	int counter2 = 0;
// 	int count1 = answer.length();
// 	int count2 = cache.length();
// 	cout << "Answer Length: " << count1 << endl;
// 	cout << "Cache  Length: " << count2 << endl;
// 	cout << "" << getCache() << endl;
// 	while(counter1 != count1 -1)
// 	{
// 		cout << counter1 << "  " << counter2 << endl;
// 		if(answer.at(counter1) == cache.at(counter2))
// 		{
// 			letters++;
// 			cout << letters << endl;
// 			counter1++;
// 			counter2 = 0;
// 		}
// 		else
// 		{
// 			counter2++;
// 		}
// 	}
// 	return letters;	
// }


int Puzzle::play()
{
	string temp = cache = "";
	int complete = answer.length();
	for (int i = 0; i < complete; i++)
	{
		if(answer.at(i) == ' '){cout << "  ";}
		else {cout << "_ ";}
		if(i == complete - 1){cout << endl;}
	}

	while (true)
	{
		int complete = answer.length(), spaceCount = 0;
		cout << question << endl;
		cout << "Enter a Letter" << endl;
		cin >> temp;
		cout << endl;
		
		cache.append(temp);

		for(int j = answer.length(), i = 0; i < j ; i++)
	     {
			bool dash, space;
			spaceCount = 0;
			for(int k = cache.length(), l = 0; l < k ; l++)
			{	
				dash = true;
				if(cache.at(l) == answer.at(i))
				{
					cout << answer.at(i);
					dash = false;
					break;
				}
				else if(answer.at(i) == ' ')
				{
					//Above block of code does not handle spaces, this block 
					cout << "  ";
					dash = false;
					space = true;
					break;
				}
			}
			if(dash == true){complete--; cout << "_ ";}
			if(space == true){spaceCount++;}
			if( i == j - 1){cout << endl;}
    	}
  		cout << "Letters found: " << complete - spaceCount << " of " << answer.length() - spaceCount << endl << endl;
    	if(complete == answer.length()){return 0;}
	}
}


#ifdef UNIT_TEST_PUZZLE
	int main()
	{
		Puzzle p1;
		Puzzle p2("Question","Answer");
		Puzzle* p3 = new Puzzle();
		Puzzle* p4 = new Puzzle("Question","Answer");

		cout << p2.getQuestion() << endl << p2.getAnswer() << endl;
		// cout << p2.enterVowel('A') << endl;
		// // cout << p2.enterVowel('e') << endl;
		// cout << p2.enterVowel('i') << endl;
		// cout << p2.enterVowel('o') << endl;
		// cout << p2.enterVowel('u') << endl;
		
		// cout << p2.enterConsonant('l') << endl;
		// cout << p2.enterConsonant('f') << endl;
		// cout << p2.enterConsonant('u') << endl;
		cout << p2.display() << endl;
		p2.enterLetter('n');
		cout << p2.display() << endl;
		p2.enterLetter('a');
		cout << p2.display() << endl;
		p2.enterLetter('s');
		cout << p2.display() << endl;
		p2.enterLetter('W');
		cout << p2.display() << endl;
		p2.enterLetter('E');
		cout << p2.display() << endl;
		p2.enterLetter('r');
		cout << p2.display() << endl;
		cout << p2.display() << endl;
		cout << p2.display() << endl;
		// p2.inCache('7');
		// p2.play();
		// p4->play();


		return 0;
	}
#endif
