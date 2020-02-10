#include "class.node.hpp"

Node::Node()
{
	_ques = "*Empty Question*";
	_ans  = "*Empty Answer*"; 
	_next = NULL;
};

Node::Node(string ques, string ans)
{
	_ques = ques;
	_ans  = ans; 
	_next = NULL;
};


void Node::display()
{
	cout << "Question: " << _ques << endl;
	cout << "Answer  : " << _ans  << endl;
};

bool Node::empty()
{
	if(_ques == "" && _ans == ""){return true;}
	else {return false;}
}

Node* Node::nextNode()
{
	return _next;
}

