#include "class.puzzle.hpp"

Puzzle::Puzzle()
{
	question = "";
	answer = "";	
}

Puzzle::Puzzle(string ques, string ans)
{
	question = toUpper(ques);
	answer = toUpper(ans);
}


int Puzzle::play()
{
	string cache, temp;
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

#ifdef UNIT_TEST_PUZZLE
	int main()
	{
		Puzzle p1;
		Puzzle p2("Question","Answer");
		Puzzle* p3 = new Puzzle();
		Puzzle* p4 = new Puzzle("Question","Answer");

		p2.play();
		p4->play();
		return 0;
	}
#endif
