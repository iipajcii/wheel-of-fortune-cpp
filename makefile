main: class.card.cpp class.card.hpp class.cardNode.cpp class.cardNode.hpp class.game.cpp class.game.hpp class.player.cpp class.player.hpp class.playerll.cpp class.playerll.hpp class.playerNode.cpp class.playerNode.hpp class.puzzle.cpp class.puzzle.hpp class.wheel.cpp class.wheel.hpp class.display.hpp class.display.cpp main.cpp
	g++ class.card.cpp class.cardNode.cpp class.game.cpp class.player.cpp class.playerll.cpp class.playerNode.cpp class.puzzle.cpp class.wheel.cpp class.display.cpp main.cpp -o main
	clear
	./main

card: class.card.hpp class.card.cpp
	g++ class.card.cpp -o card -D UNIT_TEST_CARD;

cardNode: class.card.hpp class.card.cpp class.cardNode.hpp class.cardNode.cpp
	g++ class.cardNode.cpp class.card.cpp -o cardNode -D UNIT_TEST_CARD_NODE

player: class.player.hpp class.player.cpp
	g++ class.player.cpp -o player -D UNIT_TEST_PLAYER

playerNode: class.player.hpp class.player.cpp class.playerNode.hpp class.playerNode.cpp
	g++ class.playerNode.cpp class.player.cpp -o playerNode -D UNIT_TEST_PLAYER_NODE

playerll: class.player.hpp class.player.cpp class.playerNode.hpp class.playerNode.cpp class.playerll.hpp class.playerll.cpp
	g++ class.playerll.cpp class.playerNode.cpp class.player.cpp -o playerll -D UNIT_TEST_PLAYERLL

puzzle: class.puzzle.hpp class.puzzle.cpp
	g++ class.puzzle.hpp class.puzzle.cpp -o puzzle -D UNIT_TEST_PUZZLE

game: class.card.cpp class.card.hpp class.cardNode.cpp class.cardNode.hpp class.game.cpp class.game.hpp class.player.cpp class.player.hpp class.playerll.cpp class.playerll.hpp class.playerNode.cpp class.playerNode.hpp class.puzzle.cpp class.puzzle.hpp class.wheel.cpp class.wheel.hpp class.display.cpp class.display.hpp
	g++ class.card.cpp class.cardNode.cpp class.game.cpp class.player.cpp class.playerll.cpp class.playerNode.cpp class.puzzle.cpp class.wheel.cpp class.display.cpp -o game -D UNIT_TEST_GAME

wheel: class.cardNode.cpp class.cardNode.hpp class.wheel.cpp class.wheel.hpp class.card.hpp class.card.cpp
	g++ class.wheel.cpp class.cardNode.cpp class.card.cpp -o wheel -D UNIT_TEST_WHEEL


# node: struct.node.hpp
# 	cp struct.node.hpp struct.node.cpp;
#	g++ struct.node.cpp -o node -D UNIT_TEST_NODE;
#	rm struct.node.cpp;

# test_game: test.game.cpp
#	g++ test.game.cpp -o test_game;
