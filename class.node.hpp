#ifndef CLASS_NODE_HPP
#define CLASS_NODE_HPP

#include <iostream>
#include <string>
using namespace std;

class Node {
	public:
		Node();
		Node(string ques, string ans);
		// Node(Node n);
		string question();
		string answer();
		void set(string ques, string ans);
		void setQuestion(string ques);
		void setAnswer(string ans);
		void setNext(Node n);
		Node*  nextNode();
		void display();

	//private:
		string _ques;
		string _ans;
		Node*  _next;
};

#endif
