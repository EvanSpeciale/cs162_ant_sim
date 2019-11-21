/******************************************************************************
* Name: Evan Speciale
* Date: July 7, 2019
* Description:	Implementation of Ant class member functions. 
******************************************************************************/
#include <iostream>
#include "Ant.hpp"
using std::cin;
using std::cout;
using std::endl;

//default constructor initializes key variables, leaves the rest to the user via
//the menu function
Ant::Ant()
{
	antOrientation = 'u';
	orientCounter = 0;
	
	//fills the orientation array with the possible orientations; the orientCounter
	//then cycles through the orientations based on the sim rules.
	orientations[0] = 'u';
	orientations[1] = 'r';
	orientations[2] = 'd';
	orientations[3] = 'l';
	
	antSpaceColor = 0;		//0 for white, 1 for black.
}

//SET FUNCTIONS for all variables set by the user via the menu function
void Ant::setBoardHeight(int newHeight)
{
	boardHeight = newHeight;
}
void Ant::setBoardWidth(int newWidth)
{
	boardWidth = newWidth;
}
void Ant::setSteps(int newSteps)
{
	steps = newSteps;
}
void Ant::setAntRow(int newRow)
{
	antRow = newRow;
}
void Ant::setAntCol(int newCol)
{
	antCol = newCol;
}
void Ant::setAntOrientation(char newOrientation)
{
	antOrientation = newOrientation;
}
//END SET FUNCTIONS

//checks if the ant is in an edge row or column and if the ant is facing said
//row or column. If so, returns true. If not, returns false.
bool Ant::facingWall()
{
	if (antRow == 0 && antOrientation == 'u')
	{
		return true;
	}
	else if (antRow == boardHeight-1 && antOrientation == 'd')
	{
		return true;
	}
	else if (antCol == 0 && antOrientation == 'l')
	{
		return true;
	}
	else if (antCol == boardWidth-1 && antOrientation == 'r')
	{
		return true;
	}
	else
	{
		return false;
	}
}

//Main simulation function. Dynamically allocates memory for 2D array of the
//size specified by the user. The board is filled with ' ' chars to represent
//white spaces. Then, the for-loop executes each step, checking the color of
//the space the ant is on, turning the ant, and changing the color of the space.
//If the ant is facing a wall, and therefore going to step out of bounds, the
//ant is turned around to take its next step. The ant then steps one space
//forward based on its orientation. The ant's space color is recorded, the ant
//symbol is placed, the board is printed, the color space replaced on the board,
//and the screen is cleared for the next step.

void Ant::antSimulation()
{
	//dynamically allocates memory for a 2D array of chars to hold board status
	char **board = new char*[boardHeight];
	for (int i = 0; i < boardHeight; i++)
	{
		board[i] = new char[boardWidth];
	}

	//fills board with ' ' chars to represent white space
	for (int i = 0; i < boardHeight; i++)
	{
		for (int j = 0; j < boardWidth; j++)
		{
			board[i][j] = ' ';
		}
	}

	for (int i = 0; i < steps; i++)
	{
		
		//Based on the square color, the loop increments or decrements the
		//orientation counter, adjusts orientation, and changes space color
		//for each step entered by the user
		if (board[antRow][antCol] != '#')
		{
			orientCounter += 1;
			antOrientation = orientations[orientCounter % 4];
			board[antRow][antCol] = '#';
			
		}
		else if (board[antRow][antCol] == '#')
		{
			orientCounter += 3;
			antOrientation = orientations[orientCounter % 4];
			board[antRow][antCol] = ' ';
		}
		
		//checks if ant is about to step out of bounds. If so, turns the ant 180 degrees.
		if (facingWall() == true)
		{
			orientCounter += 2;
			antOrientation = orientations[orientCounter % 4];
		}
		
		//based on ant's orientation, moves ant one space forward
		if (antOrientation == 'u')
		{
			antRow -= 1;
		}
		else if (antOrientation == 'r')
		{
			antCol += 1;
		}
		else if (antOrientation == 'd')
		{
			antRow += 1;
		}
		else if (antOrientation == 'l')
		{
			antCol -= 1;
		}

		//records the ant's space color before placing the ant symbol on the board
		if (board[antRow][antCol] == '#')
		{
			antSpaceColor = 1;
		}
		else if (board[antRow][antCol] == ' ')
		{
			antSpaceColor = 0;
		}

		//places '*' symbol at the ant's location after all steps complete
		board[antRow][antCol] = '*';

		//prints the resulting board to the console
		for (int i = 0; i < boardWidth + 2; i++)
		{
			cout << "-";
		}
		cout << endl;
		for (int i = 0; i < boardHeight; i++)
		{
			cout << "|";
			for (int j = 0; j < boardWidth; j++)
			{
				cout << board[i][j];
			}
			cout << "|" << endl;
		}
		for (int i = 0; i < boardWidth + 2; i++)
		{
			cout << "-";
		}
		cout << endl;
		cout << "Step: " << i + 1 << endl;

		//replaces ant symbol with space color recorded above printing code
		if (antSpaceColor == 1)
		{
			board[antRow][antCol] = '#';
		}
		else if (antSpaceColor == 0)
		{
			board[antRow][antCol] = ' ';
		}		
	}
	

	//frees memory allocated for dynamic 2D array
	for (int i = 0; i < boardHeight; i++)
	{
		delete[] board[i];
	}
	delete[] board;
	board = NULL;
}
