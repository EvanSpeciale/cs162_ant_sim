/******************************************************************************
* Name: Evan Speciale
* Date: July 7, 2019
* Description:  Declares Ant class. Creates private member variables for
*				simulation parameters (board size, ant location, ant
*				orientation). Creates public member functions including a
*				default member constructor, set functions for most parameters,
*				the main simulation function, and one bool-returning function
*				to determine edge cases.
******************************************************************************/
#ifndef ANT_HPP
#define ANT_HPP

class Ant
{
	private:
		int boardHeight,
			boardWidth,
			antRow,
			antCol,
			orientCounter,
			antSpaceColor;
		char antOrientation;	//u,r,d,l for up, right, down, and left
		char orientations[4];	//array holds possible orientations which orientCounter cycles through
		int steps;

	public:
		Ant();
		
		//set functions
		void setBoardHeight(int);
		void setBoardWidth(int);
		void setSteps(int);
		void setAntRow(int);
		void setAntCol(int);
		void setAntOrientation(char);
		
		bool facingWall();
		
		void antSimulation();

};

#endif	//ANT_HPP
