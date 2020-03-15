card:
	g++ class.card.cpp -o card -D UNIT_TEST_CARD;

game: test.game.cpp
	g++ test.game.cpp -o game;

node: struct.node.hpp
	cp struct.node.hpp struct.node.cpp;
	g++ struct.node.cpp -o node -D UNIT_TEST_NODE;
	rm struct.node.cpp;

player: class.player.hpp class.player.cpp
	g++ class.player.cpp -o player -D UNIT_TEST_PLAYER

playerNode: class.player.hpp class.player.cpp class.playerNode.hpp class.playerNode.cpp
	g++ class.playerNode.cpp class.player.cpp -o playerNode -D UNIT_TEST_PLAYER_NODE

playerll: class.player.hpp class.player.cpp class.playerNode.hpp class.playerNode.cpp class.playerll.hpp class.playerll.cpp
	g++ class.playerll.cpp class.playerNode.cpp class.player.cpp -o playerll -D UNIT_TEST_PLAYERLL

wheel: class.linkedList.cpp class.linkedList.hpp
	g++ class.wheel.cpp class.wheel.hpp -o wheel -D UNIT_TEST_WHEEL
