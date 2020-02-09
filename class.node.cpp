#include "class.node.hpp"

Node::Node()
{
	_ques = "*Empty Question*";
	_ans  = "*Empty Answer*"; 
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
