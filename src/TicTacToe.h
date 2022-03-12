#pragma once

class TicTacToe {
private:
	char Board[3][3]; // O for Player 1, X for Player 2
	bool GameOver; // tells whether game is over or not
	void ResetBoard(); // print all values in board according to index
	void PrintBoard(); // print board
	bool BoardIsFull(); // returns true while board is full
	void InputPlayerOne(); // get input from player 1
	void InputPlayerTwo(); // get input from player 2
	void Result(); // displays result
public:
	void Run(); // executes game
};