#include "class.node.hpp"

int main()
{
	Node n1, n2("Question", "Answer");
	// Node n3(n2);
	n1.display();
	n2.display();
	cout << n2.nextNode();
	return 0;
}
