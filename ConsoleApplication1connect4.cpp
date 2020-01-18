// ConsoleApplication1connect4.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <conio.h>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

using namespace std;
int fillstat[6][7]; //stores filled/empty  status of blocks
int pcheck[6][7];  //stores which player's token is filled in a block
char p1[10] = " |  X  |"; //player 1's token
char p2[10] = " |  O  |"; //player 2's token
int player;   //represents which player's chance is going on
int win = 0;   //win flag. 0:no winner, 1:player 1 winner, 2:player 2 winner
char player1name[30];
char player2name[30];
void fill(char c);  //func to fill blocks
void execute();

void rules()               //Display rules
{
	
	cout << "\t\t\t\tRULES:\n";
	cout << "To win Connect Four, all you have to do is connect four of your colored checker pieces in a row, much the same as tic tac toe. This can be done horizontally, vertically or diagonally. Each player will drop in one checker piece at a time. This will give you a chance to either build your row, or stop your opponent from getting four in a row.The game is over either when you or your friend reaches four in a row, or when all forty two slots are filled, ending in a stalemate.";
	cout << "\n\n";
	cout << "Press any button to continue: ";
	_getch();
	system("cls");
	cout << "\t\t\t\tCONNECT 4\n\n";

}
void dispboard()
{
	system("cls");
	char blank[10] = " |     |";
	cout << "\t\t\t\tCONNECT 4\n\n";
	for (char i = 'A'; i <= 'G'; i++)
	{
		cout << "\t" << i;
	}
	for (int j = 0; j < 6; j++)
	{
		cout << "\n\n\n   " << j + 1;
		for (int k = 0; k < 7; k++)
		{
			if (fillstat[j][k] == 0)        //checks and display blank blocks
				cout << blank;
			else
			{
				if (pcheck[j][k] == 2)    //checks which block belongs to which player and display X / O accordingly
					cout << p2;
				else
					cout << p1;

			}

		}
	}

}

int isfull(char c) //checks if the column is full or not
{
	int a;
	switch (tolower(c))
	{
	case 'a': a = 0; break;
	case 'b': a = 1; break;
	case 'c': a = 2; break;
	case 'd': a = 3; break;
	case 'e': a = 4; break;
	case 'f': a = 5; break;
	case 'g': a = 6; break;
	}
	if (fillstat[0][a] == 1)
		return 1;
	else
		return 0;
}
void fill(char c)
{
	switch (tolower(c))
	{
	case 'a':for (int z0 = 5; z0 >= 0; z0--)      //stacks tokens in columns from bottom
	{
		if (fillstat[z0][0] == 0)
		{
			fillstat[z0][0] = 1;
			if (player == 1)                //assigns player number to blocks
				pcheck[z0][0] = 1;
			else
				pcheck[z0][0] = 2;
			break;
		}

	}
			break;
	case 'b':for (int z1 = 5; z1 >= 0; z1--)
	{
		if (fillstat[z1][1] == 0)
		{
			fillstat[z1][1] = 1;
			if (player == 1)
				pcheck[z1][1] = 1;
			else
				pcheck[z1][1] = 2;
			break;
		}
	}
			break;
	case 'c':for (int z2 = 5; z2 >= 0; z2--)
	{
		if (fillstat[z2][2] == 0)
		{
			fillstat[z2][2] = 1;
			if (player == 1)
				pcheck[z2][2] = 1;
			else
				pcheck[z2][2] = 2;
			break;
		}
	}
			break;
	case 'd':for (int z3 = 5; z3 >= 0; z3--)
	{
		if (fillstat[z3][3] == 0)
		{
			fillstat[z3][3] = 1;
			if (player == 1)
				pcheck[z3][3] = 1;
			else
				pcheck[z3][3] = 2;
			break;
		}
	}
			break;
	case 'e':for (int z4 = 5; z4 >= 0; z4--)
	{
		if (fillstat[z4][4] == 0)
		{
			fillstat[z4][4] = 1;
			if (player == 1)
				pcheck[z4][4] = 1;
			else
				pcheck[z4][4] = 2;
			break;
		}
	}
			break;
	case 'f':for (int z5 = 5; z5 >= 0; z5--)
	{
		if (fillstat[z5][5] == 0)
		{
			fillstat[z5][5] = 1;
			if (player == 1)
				pcheck[z5][5] = 1;
			else
				pcheck[z5][5] = 2;
			break;
		}
	}
			break;
	case 'g':for (int z6 = 5; z6 >= 0; z6--)
	{
		if (fillstat[z6][6] == 0)
		{
			fillstat[z6][6] = 1;
			if (player == 1)
				pcheck[z6][6] = 1;
			else
				pcheck[z6][6] = 2;
			break;
		}
	}
			break;
	default:cout << "Invalid column";
	}

}

void wincheck()
{
	for (int i = 5; i >= 0; i--)
	{
		for (int j = 6; j >= 0; j--)
		{
			if (fillstat[i][j] == 1)     //checks only filled blocks
			{
				if ((pcheck[i][j] == pcheck[i][j + 1]) && (pcheck[i][j] == pcheck[i][j + 2]) && (pcheck[i][j] == pcheck[i][j + 3]) || ((pcheck[i][j] == pcheck[i - 1][j]) && (pcheck[i][j] == pcheck[i - 2][j]) && (pcheck[i][j] == pcheck[i - 3][j])))   //Horizontal and vertical check
				{
					if (pcheck[i][j] == 1)
					{
						win = 1;
						i = j = -1; break;  //breaks both loops and doesnt check further
					}
					if (pcheck[i][j] == 2)
					{
						win = 2;
						i = j = -1; break;
					}
				}
				if ((pcheck[i][j] == pcheck[i - 1][j + 1]) && (pcheck[i][j] == pcheck[i - 2][j + 2]) && (pcheck[i][j] == pcheck[i - 3][j + 3]) || ((pcheck[i][j] == pcheck[i - 1][j - 1]) && (pcheck[i][j] == pcheck[i - 2][j - 2]) && (pcheck[i][j] == pcheck[i - 3][j - 3])))   //right and left diagonal check
				{
					if (pcheck[i][j] == 1)
					{
						win = 1;
						i = j = -1; break;  //breaks both loops and doesnt check further
					}
					if (pcheck[i][j] == 2)
					{
						win = 2;
						i = j = -1; break;
					}
				}
			}
		}
	}
}

void player_change()
{
	player = (player % 2) + 1;    //if player=1, updates value to 1+1=2 ; if player =2, updates value to 0+1=1
}

void execute()
{
	char col;
	do
	{	if(player==1)
			cout << "\n" << player1name << ", Enter column(A-G): ";
		if(player==2)
			cout << "\n" << player2name << ", Enter column(A-G): ";
		cin >> col;
		if ((col >= 'a' && col <= 'g') || (col >= 'A' && col <= 'G'))
		{
			if (isfull(col) == 1) //if the column is full, the player has to enter the column again
			{
				cout << "Column " << (char)toupper(col) << " is full. Try again."; //toupper returns integer, so char is typecasted
				continue;
			}
			fill(col);
			dispboard();
			wincheck();
			player_change();
		}
		else
		{
			cout << "Invalid input. Try again!";
			continue;
		}
	} while (win == 0);
	if(win==1)
		cout << "\n\nCONGRATULATIONS!!! \n " << player1name << " WON THE GAME!!!";
	else
		cout << "\n\nCONGRATULATIONS!!! \n " << player2name << " WON THE GAME!!!";
}

void getnames()
{
	cout << "Enter name for Player 1: ";
	gets_s(player1name);
	cout << "Enter name for Player 2: ";
	gets_s(player2name);
}
int main()
{
	system("cls");
	char f[5];
	player = 1;
	cout << "\t\t\t\tCONNECT 4\n\n";
	getnames();
	system("cls");
	cout << "\t\t\t\tCONNECT 4\n\n";
	cout << "Do you want to read the rules(Yes/No)?";
	gets_s(f);
	if ((_strcmpi(f, "yes") == 0) || (_strcmpi(f, "y") == 0))
	{
		rules();
	}
	else
	{
		system("cls");
		cout << "\t\t\t\tCONNECT 4\n\n";
	}
	dispboard();
	execute();
	_getch();
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
