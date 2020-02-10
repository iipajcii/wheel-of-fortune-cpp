#include "class.linkedList.hpp"

int main()
{
	Node n1("What is the World's Largest Lake", "Duhkno");
	Node n2("What is the World's Largest City", "Havena");

	LinkedList ll(n1);

	ll.display();
	ll.insertLast(n2);
	ll.display();
	
}
