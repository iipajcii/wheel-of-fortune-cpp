#include <iostream>
#include <string>
using namespace std;

class Node {
	public:
		Node();
		void display();
		bool empty();
	private:
		string _ques;
		string _ans;
};
