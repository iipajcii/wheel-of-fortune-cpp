main: main.cpp class.player.cpp class.player.hpp
	 g++ class.player.cpp main.cpp -o main

test.node: test.node.cpp class.node.cpp class.node.hpp
	g++ class.node.cpp test.node.cpp -o test_node

test.linkedList:  test.linkedList.cpp class.linkedList.cpp class.linkedList.hpp
	g++ class.node.cpp class.linkedList.cpp test.linkedList.cpp -o test_linkedList
