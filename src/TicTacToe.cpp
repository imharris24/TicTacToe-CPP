#include "TicTacToe.h"

#include<iostream>
#include<conio.h>
using namespace std;

void TicTacToe::ResetBoard() {
	char Index = '1';
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			Board[i][j] = Index;
			Index += 1;
		}
	}
	GameOver = false;
}
void TicTacToe::PrintValues() {
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			cout << Board[i][j] << "   ";
		}
		cout << "\n";
	}
}
void TicTacToe::PrintBoard() {
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			cout << " " << Board[i][j] << " ";
			if (j == 0 || j == 1) {
				cout << "|";
			}
		}
		if (i == 0 || i == 1) {
			cout << "\n-----------\n";
		}
		else {
			cout << "\n";
		}
	}
}
bool TicTacToe::BoardIsFull() {
	if ((Board[0][0] == 'X' || Board[0][0] == 'O') && (Board[0][1] == 'X' || Board[0][1] == 'O') && (Board[0][1] == 'X' || Board[0][2] == 'O') && (Board[1][0] == 'X' || Board[1][0] == 'O') && (Board[1][1] == 'X' || Board[1][1] == 'O') && (Board[1][2] == 'X' || Board[1][2] == 'O') && (Board[2][0] == 'X' || Board[2][0] == 'O') && (Board[2][1] == 'X' || Board[2][1] == 'O') && (Board[2][2] == 'X' || Board[2][2] == 'O')) {
		return true;
	}
	else return false;
}
void TicTacToe::InputPlayerOne() {
	char Index;
	while (true) {
		if (!GameOver) {
			Index = '\0';
			cout << "Input Player 1: ";
			Index = _getche();
			cout << "\n";
			for (int i = 0; i < 3; i++) {
				for (int j = 0; j < 3; j++) {
					if (Board[i][j] == Index) {
						Board[i][j] = 'O';
						return;
					}
				}
			}
			cout << "\nInvalid Input\n";
		}
		else {
			return;
		}
	}
}
void TicTacToe::InputPlayerTwo() {
	char Index;
	while (true) {
		if (!GameOver) {
			Index = '\0';
			cout << "Input Player 2: ";
			Index = _getche();
			cout << "\n";
			for (int i = 0; i < 3; i++) {
				for (int j = 0; j < 3; j++) {
					if (Board[i][j] == Index) {
						Board[i][j] = 'X';
						return;
					}
				}
			}
			cout << "\nInvalid Input\n";
		}
		else {
			return;
		}
	}
}
void TicTacToe::Result() {
	if ((Board[0][0] == 'O' && Board[0][1] == 'O' && Board[0][2] == 'O') || (Board[1][0] == 'O' && Board[1][1] == 'O' && Board[1][2] == 'O') || (Board[2][0] == 'O' && Board[2][1] == 'O' && Board[2][2] == 'O') || (Board[0][0] == 'O' && Board[1][0] == 'O' && Board[2][0] == 'O') || (Board[0][1] == 'O' && Board[1][1] == 'O' && Board[2][1] == 'O') || (Board[0][2] == 'O' && Board[1][2] == 'O' && Board[2][2] == 'O') || (Board[0][0] == 'O' && Board[1][1] == 'O' && Board[2][2] == 'O') || (Board[0][2] == 'O' && Board[1][1] == 'O' && Board[2][0] == 'O')) {
		system("cls");
		PrintBoard();
		cout << "\nPlayer 1 WINS\n";
		GameOver = true;
	}
	else if ((Board[0][0] == 'X' && Board[0][1] == 'X' && Board[0][2] == 'X') || (Board[1][0] == 'X' && Board[1][1] == 'X' && Board[1][2] == 'X') || (Board[2][0] == 'X' && Board[2][1] == 'X' && Board[2][2] == 'X') || (Board[0][0] == 'X' && Board[1][0] == 'X' && Board[2][0] == 'X') || (Board[0][1] == 'X' && Board[1][1] == 'X' && Board[2][1] == 'X') || (Board[0][2] == 'X' && Board[1][2] == 'X' && Board[2][2] == 'X') || (Board[0][0] == 'X' && Board[1][1] == 'X' && Board[2][2] == 'X') || (Board[0][2] == 'X' && Board[1][1] == 'X' && Board[2][0] == 'X')) {
		system("cls");
		PrintBoard();
		cout << "\nPlayer 2 WINS\n";
		GameOver = true;
	}
}
void TicTacToe::Run() {
	char Option = '\0';
	bool Swapper = true;
	while (true) {
		system("cls");
		cout << "\n\t TIC-TAC-TOE\n";
		cout << "\t1. Start Game\n";
		cout << "\t2. Exit\n";
		cout << "\t   Option: ";
		Option = _getche();
		cout << "\n";
		switch (Option) {
		case '1':
			ResetBoard();
			while (!BoardIsFull() && !GameOver) {
				if (!GameOver) {
					system("cls");
					PrintBoard();
					Result();
					if (Swapper) {
						InputPlayerOne();
						Swapper = false;
					}
					else {
						InputPlayerTwo();
						Swapper = true;
					}
					if (GameOver == true && BoardIsFull() == true) {
						system("cls");
						PrintBoard();
						cout << "\nIts a DRAW\n";
						system("pause");
						break;
					}
				}
				else {
					system("pause");
					break;
				}
			}
			break;
		case '2':
			exit(-1);
			break;
		default:
			break;
		}
	}
}