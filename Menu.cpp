/******************************************************************************
* Name: Evan Speciale
* Date: July 7, 2019
* Description: Implementation of the menu function. Offers user to begin sim or
*		       quit. If the user begins the sim, they are prompted to enter the
*			   size of the board, the ant's starting location, and the number
*			   of steps. The function then calls to the antSimulation member
*			   function and then recursively calls the menu function until the
*			   user chooses to quit.
******************************************************************************/
#include <iostream>
#include "Menu.hpp"
#include "Ant.hpp"
using std::cin;
using std::cout;
using std::endl;

void menu()
{
	int choice;
	do
	{
		cout << "Welcome to Langton Ant Simulator 2k19" << endl
			<< "##################*##################" << endl
			<< "1 - Begin Simulation" << endl
			<< "2 - Quit Program" << endl
			<< "Enter Selection: ";
		cin >> choice;
	} while (choice != 1 && choice != 2);		//continues asking user for input until they enter 1 or 2
	
	switch (choice)
	{
		case 1:
		{
			Ant userAnt;						//creates instance of Ant class
			int newBoardHeight,					//series of user-input parameters for simulation
				newBoardWidth,
				newRow,
				newCol,
				newSteps;
			
			cout << "Enter board height: " << endl;
			cin >> newBoardHeight;
			userAnt.setBoardHeight(newBoardHeight);		//calls to set functions for Ant class

			cout << "Enter board width: " << endl;
			cin >> newBoardWidth;
			userAnt.setBoardWidth(newBoardWidth);

			cout << "Enter the Ant's starting column: " << endl;
			cin >> newRow;
			userAnt.setAntRow(newRow-1);

			cout << "Enter the Ant's starting row: " << endl;
			cin >> newCol;
			userAnt.setAntCol(newCol-1);

			cout << "Enter the number of steps you want the Ant to take: "
				<< endl;
			cin >> newSteps;
			userAnt.setSteps(newSteps);

			userAnt.antSimulation();				//calls to simulation Ant member function

			menu();									//recursively calls to menu until the user selects "quit"
			
			break;
		}
		case 2:
		{
			cout << "Goodbye!" << endl;
			break;
		}
	}
}