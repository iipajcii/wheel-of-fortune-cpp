#include <iostream>
#include <string>

using namespace std;
int word(string ques, string ans);
int main()
{
	string ques, ans, cache, temp;
	cout << "Enter a Question" << endl;
	getline(cin, ques, '\n');

	cout << endl << "Enter the Answer" << endl;
	getline(cin, ans, '\n');

	word("Answer is \"guess me\"",ans);
	return 0;
}

int word(string ques, string ans)
{
	string cache, temp;
	while (true)
	{
		int complete = ans.length(), spaceCount = 0;
		cout << ques << endl;
		cout << "Enter a Letter" << endl;
		cin >> temp;
		cache.append(temp);

		for(int j = ans.length(), i = 0; i < j ; i++)
	     {
			bool dash, space;
			spaceCount = 0;
			for(int k = cache.length(), l = 0; l < k ; l++)
			{	
				dash = true;
				if(cache.at(l) == ans.at(i))
				{
					cout << ans.at(i);
					dash = false;
					break;
				}
				else if(ans.at(i) == ' ')
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
  	cout << "Letters found: " << complete - spaceCount << " of " << ans.length() - spaceCount << endl;
    	if(complete == ans.length()){return 0;}
	}
}
