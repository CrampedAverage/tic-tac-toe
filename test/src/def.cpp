#include <iostream>
#include "dec.h"
// globally defined
using namespace std;

string board[9] = { " "," "," "," "," "," "," "," "," " };
int player = 1;
int position = 0;

void introduction() 
{
	cout << "Press [Enter] to begin:";
	getchar();  // haults the screen
	cout << "\n";

	cout << "\n";
	cout << "***********\n";
	cout << "Tic-Tac-Toe\n";
	cout << "***********\n";

	cout << "Player 1) X\n";
	cout << "Player 2) O\n";

	cout << "The 3x3 grid is shown below:\n\n";

	cout << "       |       |        \n";
	cout << "   1   |   2   |   3    \n";
	cout << "_______|_______|_______ \n";
	cout << "       |       |        \n";
	cout << "   4   |   5   |   6    \n";
	cout << "_______|_______|_______ \n";
	cout << "       |       |        \n";
	cout << "   7   |   8   |   9    \n";
	cout << "       |       |        \n\n";
}

bool isWinner()
{
	bool winner = false;
	//checking the rows
	if ((board[0] == board[1]) && (board[1] == board[2]) && board[0] != " ")
	{
		winner = true;
	}
	else if ((board[3] == board[4]) && (board[4] == board[5]) && board[3] != " ")
	{
		winner = true;
	}
	else if ((board[6] == board[7]) && (board[7] == board[8]) && board[6] != " ")
	{
		winner = true;
	}

	//checkign the colums
	else if ((board[0] == board[3]) && (board[3] == board[6]) && board[0] != " ")
	{
		winner = true;
	}
	else if ((board[1] == board[4]) && (board[4] == board[7]) && board[1] != " ")
	{
		winner = true;
	}
	else if ((board[2] == board[5]) && (board[5] == board[8]) && board[2] != " ")
	{
		winner = true;
	}

	//checking the diagonals
	else if (((board[0] == board[4]) && (board[4] == board[8]) && board[0] != " "))
	{
		winner = true;
	}
	else if ((board[2] == board[4]) && (board[4] == board[6]) && board[2] != " ")
	{
		winner = true;
	};

	return winner;
}

bool isFilledUp() 
{
	bool filled = true;

	for (int i = 0; i < 9; i++)
	{
		if (board[i] == " ")
		{
			filled = false;
		}
	};

	return filled;
}

void draw()
{
	cout << "       |       |        \n";
	cout << "   " << board[0] << "   |   " << board[1] << "   |   "<< board[2] << "    \n";
	cout << "_______|_______|_______ \n";
	cout << "       |       |        \n";
	cout << "   " << board[3] << "   |   " << board[4] << "   |   " << board[5] << "    \n";
	cout << "_______|_______|_______ \n";
	cout << "       |       |        \n";
	cout << "   " << board[6] << "   |   " << board[7] << "   |   " << board[8] << "    \n";
	cout << "       |       |        \n\n";

}

void setPosition()
{
	cout << "Player: " << player << "'s (Enter: (1-9)";
	while (!(cin >> position))
	{
		cout << "Please enter a valid number 1-9" << endl;
		cin.clear();
		cin.ignore();
	}

	while (board[position - 1] != " ")
	{
		cout << "Oops, that position is already filled \n";
		cout << "Player " << player << "'s Turn (Enter: (1-9)): ";
		cin >> position;
		cout << "\n";
	}
}

void updateBoard() {
	if (player % 2 == 1) 
	{
		board[position - 1] = "X";
	} 
	else
	{
		board[position - 1] = "O";
	}
}

void changePlayer()
{
	if (player == 1) 
	{
		player++;
	}
	else
	{
		player--;
	}
}

void takeTurn()
{
	
	while (!isWinner() && !isFilledUp())
	{
		// invokign the functions
		setPosition();
		updateBoard();
		changePlayer();
		draw();
	}
}

void endGame()
{
	if (isWinner())
	{
		cout << "There is a winner!" << endl;
	}

	else if (isFilledUp())
	{
		cout << "There is a draw!" << endl;
	}
}