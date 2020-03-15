game: test.game.cpp
	g++ test.game.cpp -o game;

player: class.player.hpp class.player.cpp
	g++ class.player.cpp -o player -D UNIT_TEST_PLAYER

ll: class.linkedList.cpp class.linkedList.hpp
	g++ class.linkedList.cpp class.linkedList.hpp -o ll -D UNIT_TEST_LINKEDLIST

node: 
	cp struct.node.hpp struct.node.cpp;
	g++ struct.node.cpp -o node -D UNIT_TEST_NODE;
	rm struct.node.cpp;

card:
	g++ class.card.cpp -o card -D UNIT_TEST_CARD;
