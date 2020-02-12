#ifndef NODE_HPP
#define NODE_HPP
//#define UNIT_TEST_NODE //Copy file to cpp to test

#include <iostream>
#include <string>
using namespace std;

struct node
{
	string _ques;
	string _ans;
	struct node * _next;
} typedef Node;


	#ifdef UNIT_TEST_NODE
	int main()
	{
		struct node n1;
		Node n2;

		n1._ques = "n1 declared";
		n2._ques = "n2 declared";

		cout << n1._ques << endl;
		cout << n2._ques << endl;
		return 0;
	}
	#endif
#endif
