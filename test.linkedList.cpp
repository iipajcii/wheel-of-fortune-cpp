#include "class.linkedList.hpp"

int main()
{
	LinkedList ll;
	Node ll1("Sitter", "Gratter");
	Node ll2("2Sitter", "2Gratter");
	//ll.display();
	ll.insertFirst(ll1);
	ll.insertFirst(ll2);
	ll.display();
	return 0;
}
