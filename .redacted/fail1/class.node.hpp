#include <iostream>
#include <string>
using namespace std;

class Node {
	public:
		Node();
		Node(string ques, string ans);
		void display();
		bool empty();
		Node* nextNode();
	private:
		string _ques;
		string _ans;
		Node*  _next;
};
