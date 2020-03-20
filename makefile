card:
	g++ class.card.cpp -o card -D UNIT_TEST_CARD;

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

puzzle: class.puzzle.hpp class.puzzle.cpp
	g++ class.puzzle.hpp class.puzzle.cpp -o puzzle -D UNIT_TEST_PUZZLE

test_game: test.game.cpp
	g++ test.game.cpp -o test_game;

game: class.card.cpp class.card.hpp class.game.cpp class.game.hpp class.player.cpp class.player.hpp class.playerll.cpp class.playerll.hpp class.playerNode.cpp class.playerNode.hpp class.puzzle.cpp class.puzzle.hpp class.wheel.cpp class.wheel.hpp
	g++ class.card.cpp class.game.cpp class.player.cpp class.playerll.cpp class.playerNode.cpp class.puzzle.cpp class.wheel.cpp -o game -D UNIT_TEST_GAME

wheel: class.linkedList.cpp class.linkedList.hpp
	g++ class.wheel.cpp class.wheel.hpp -o wheel -D UNIT_TEST_WHEEL
