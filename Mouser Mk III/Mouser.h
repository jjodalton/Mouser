#ifndef MOUSER_H
#define MOUSER_H

#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <windows.h>
#include "Maze.h"
#include "Display.h"

using namespace std;

class Mouser
{
public:
	// -- //
	void HelloWorld()	// Test Function
	{
		cout << "I am Mouser, hello world!" << endl
			 << "I solve the maze for you." << endl << endl;
	}
	// Constructor
	Mouser::Mouser(Maze maze)	// Default consturctor. Cannot be constructed without a maze to be passed in. Defaults to test mode.
	{
		preset = 0;
		Sy = -1;
		Sx = -1;
		privMaze = maze;
	}
	// Services
	void PrintMaze() // The petty printer, contains all the conditional output formatting.
	{
		int x;
		int y;
		string temp;

		cout << endl << "->Printing the maze to screen" << endl;

		for (y = 0; y < privMaze.GetSize(); y++)
		{
			for (x = 0; x < privMaze.GetSize(); x++)
			{
				if (privMaze.GetChar(y,x) == 'x')
				{
					temp = privMaze.GetChar(y,x);
					DISP::printNegative(temp, false);
				}
				if (privMaze.GetChar(y,x) == 'p')
				{
					cout << privMaze.GetChar(y,x);
				}
				if (privMaze.GetChar(y,x) == 'g')
				{
					temp = privMaze.GetChar(y,x);
					DISP::printYellow(temp, true);
				}
				if (privMaze.GetChar(y,x) == 'S')
				{
					temp = privMaze.GetChar(y,x);
					DISP::printYellow(temp, true);
				}
				if (privMaze.GetChar(y,x) == '@')
				{
					temp = privMaze.GetChar(y,x);
					DISP::printGreen(temp, false);
				}
				if (privMaze.GetChar(y,x) == 'B')
				{
					temp = privMaze.GetChar(y,x);
					DISP::printRed(temp, false);
				}		
			}
			cout << endl;
		}

		cout << "...Printing complete" << endl << endl;
	}

	void SetStart(int y, int x) // Deals with the various cases for setting the start location.
	{
		if (preset == 0) // Test Mode. Blindly sets the location based on what is passed in.
		{
			Sy = y;
			Sx = x;

			privMaze.SetChar('S',Sy,Sx);
		}

		if (preset == 1) // User Interactive Mode
		{
		int y;
		int x;

		cout << "Please enter the x co-ordinate to start at: ";
		cin >> x;
		cout << "Please enter the y co-ordinate to start at: ";
		cin >> y;

		Sy = y;
		Sx = x;

		if ( x < 0 || x > (privMaze.GetSize() - 1) || y < 0 || y > (privMaze.GetSize() - 1) - 1 ) // Check for start out of bounds.
		{
			cout << endl << "Starting co-ordinates entered are not valid." << endl;
			cout << "Unable to outside the maze" << endl;
			cout << endl << "End of Line." << endl;
			system ("pause" );
			exit (1);
		}

		if( privMaze.GetChar(Sy,Sx) == 'x' ) // Check for start in a wall.
		{
			cout << endl << "Starting co-ordinates entered are not valid." << endl;
			cout << "Unable to start in wall" << endl;
			cout << endl << "End of Line." << endl;
			system ("pause" );
			exit (1);
		}

		if( privMaze.GetChar(Sy,Sx) == 'g' ) // Checxk for start on goal.
		{
			cout << endl << "Starting co-ordinates entered are not valid." << endl;
			cout << "Unable to start at goal." << endl;
			cout << endl << "End of Line." << endl;
			system ("pause" );
			exit (1);
		}

		privMaze.SetChar('S',Sy,Sx);
		}

		if (preset == 2) // Command Line Mode
		{
			Sy = y;
			Sx = x;

		if ( x < 0 || x > (privMaze.GetSize() - 1) || y < 0 || y > (privMaze.GetSize() - 1) - 1 ) // Check for start out of bounds.
		{
			cout << endl << "Starting co-ordinates entered are not valid." << endl;
			cout << "Unable to outside the maze" << endl;
			cout << endl << "End of Line." << endl;
			system ("pause" );
			exit (1);
		}

		if( privMaze.GetChar(Sy,Sx) == 'x' ) // Check for start in a wall.
		{
			cout << endl << "Starting co-ordinates entered are not valid." << endl;
			cout << "Unable to start in wall" << endl;
			cout << endl << "End of Line." << endl;
			system ("pause" );
			exit (1);
		}

		if( privMaze.GetChar(Sy,Sx) == 'g' ) // Checxk for start on goal.
		{
			cout << endl << "Starting co-ordinates entered are not valid." << endl;
			cout << "Unable to start at goal." << endl;
			cout << endl << "End of Line." << endl;
			system ("pause" );
			exit (1);
		}

			privMaze.SetChar('S',Sy,Sx);
		}


	}
	int SolveMaze(int y, int x)
	{
		/*
		Symbols
		'p' = open
		'x' = blocked
		'S' = start
		'g' = goal
		'@' = solution path
		'B' = bad path
		*/

		// If x,y is the goal, return true.
		if ( privMaze.GetChar(y,x) == 'g' ) 
		{
			return 1;
		}

		// If x,y is not open, return false.
		if ( privMaze.GetChar(y,x) != 'p' && privMaze.GetChar(y,x) != 'S' ) 
		{
			return 0;
		}

		// Mark x,y part of solution path. Do not touch Start point.
		if ( privMaze.GetChar(y,x) != 'S')
		{
			privMaze.SetChar('@',y,x);
		}
	 
	    // If SolveMaze North of x,y is true, return true.
	    if ( this->SolveMaze(y - 1, x) == 1 ) 
		{
			return 1;
		}
	 
	    // If SolveMaze East of x,y is true, return true.
	    if ( this->SolveMaze(y, x + 1) == 1 ) 
		{
			return 1;
		}
	 
	    // If SolveMaze South of x,y is true, return true.
	    if ( this->SolveMaze(y + 1, x) == 1 ) 
		{
			return 1;
		}
	 
	    // If SolveMaze West of x,y is true, return true.
	    if ( this->SolveMaze(y, x - 1) == 1 ) 
		{
			return 1;
		}
	 
	    // Set x,y as bad path. Do not touch Start point.
		if ( privMaze.GetChar(y,x) != 'S')
		{
			privMaze.SetChar('B',y,x);
		}
	 
	    return 0;
	}



	// Tools
	int GetSy() // Returns the currently set yStart value.
	{
		return Sy;
	}
	int GetSx()	// Returns the currently set xStart value.
	{
		return Sx;
	}
	void SetSy(int y) // Sets the yStart value.
	{
		Sy = y;
	}
	void SetSx(int x)	// Sets the xStart value.
	{
		Sx = x;
	}
	void SetPreset(int PreVal)	// Sets the variable which indicates the preset mode of operation.
	{
		preset = PreVal;
	}
	void OutputSolution () // Will contain the code to write the solution to a file...at some point.
	{
		// Print Solution to a File
	}
	// -- //
private:
	int preset;
	int Sy;
	int Sx;
	Maze privMaze;
};

#endif