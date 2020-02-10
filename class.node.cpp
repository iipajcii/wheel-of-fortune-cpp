#include "class.node.hpp"

Node::Node()
{
	_ques = "*Empty*";
	_ans  = "*Empty*";
	_next = NULL;
};

Node::Node(string ques, string ans)
{
	_ques = ques;
	_ans = ans;
	_next = NULL;
};

void Node::set(string ques, string ans)
{
	_ques = ques;
	_ans  = ans;
};

void Node::setQuestion(string ques)
{
	_ques = ques;
};

void Node::setAnswer(string ans)
{
	_ans = ans;
};

// Node::Node(Node n)
// {
// 	_ques = n.question();
// 	_ans = n.answer();
// 	_next = nextNode();
// };

string Node::question(){return _ques;};
string Node::answer(){return _ans;};
Node*  Node::nextNode(){return _next;};
void  Node::setNext(Node n){_next = &n;};
void Node::display()
{
	cout << "Question: " << _ques << endl << "Answer: "<< _ans << endl;
}
