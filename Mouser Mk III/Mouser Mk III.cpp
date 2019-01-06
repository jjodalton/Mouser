/* 
 *Name: Jeremy Dalton
 *Group: 9
 *Program: Mouser the Maze Solver
 *Status: Curiously Functional
*/

#include <iomanip>
#include <string>
#include <windows.h>
#include "Mouser.h"
#include "Maze.h"

using namespace std;

void main (int argc, char* argv[])
{
	int i = 0, yStart = 0, xStart = 0, Out  = 0;
	string File;
	Maze maze;
// -- //

	cout << "Mouser-Maze Solver v3 RC1" << endl << endl;

// -- //
	if(argc == 1) // User interactive mode
	{
		cout << "...no command line arguments passed" << endl;
		cout << "->Entering user interactive mode" << endl;

		File = " ";

		maze.SetPreset(1);	// Presetting Maze to user interactive mode and and loading the fiel specified in.
		maze.LoadMaze(File);	// Empty string passed in as a variable is required but not used in this mode.

		Mouser mouser(maze);	// Constructing Mouser from Maze.
		mouser.PrintMaze();	// Priting the maze that was loaded.

		mouser.SetPreset(1);	// Presetting Mouser to user interactive mode.
		mouser.SetStart(yStart, xStart);	// variables required but are actually set within function.
		mouser.PrintMaze();	// Printing the maze with the start location in place.

		Out = mouser.SolveMaze(mouser.GetSy(),mouser.GetSx()); // Solving the maze and returning a value for sucess or failure.
		if (Out == 1)
		{
			cout << "Mouser found a solution!" << endl;
		}
		if (Out == 0)
		{
			cout << "Mouser was unable to find a solution" << endl;
		}

		mouser.PrintMaze();	// Printing the final state of the maze be it sucess or failure.
		system ("pause" );	// System Pause for user to confirm so it will execute properly outside of Visual Studio.
		exit(0);	// Exiting on sucessful execution.
	}
// -- //
    if (argc > 2 && argc < 7) // Bad arguments / not enough arguments to Command Line Mode
	{
		cout << "Insufficient or erroneous command line arguments" << endl;
        cout << "Usage is -f <filename.txt> -y <Y Start> -x <X Start>" << endl << endl;

		system ("pause" );
		exit(1);	// Exiting on generic execution failure.
    } 
// -- //
	if (argc == 7) // Command Line Mode
	{
        for (i = 1; i < argc; i++) 
		{
            if (i + 1 != argc)
			{
                if ( string(argv[i] ) == "-f") // Looking -f with filename to follow.
				{
					File =  argv[i + 1];
                } 
				if ( string(argv[i] ) == "-y") // Looking for -y with yStart to follow.
				{
                    yStart = atoi( argv[i + 1] );
                } 
				if ( string(argv[i] ) == "-x") // looking for -x with xStart to follow. 
				{
                    xStart = atoi( argv[i + 1] );
                }
			}
		}

		maze.SetPreset(2);	// Presetting ready to recieve the filename to be loaded.
		maze.LoadMaze(File);	// Loading the file specified.

		Mouser mouser(maze);	// Constructing Mouser from the loaded Maze.
		mouser.PrintMaze();	// Prints it to the console - slightly redundant.

		mouser.SetPreset(2);	// Presetting Mouser to recieve the start co-ordinates.
		mouser.SetStart(yStart, xStart);	// Setting the start location.
		mouser.PrintMaze();	// Printing before start - slightly redundant.

		Out = mouser.SolveMaze(mouser.GetSy(),mouser.GetSx());	// Solving the maze and returning a value for sucess or failure.
		if (Out == 1)
		{
			cout << "Mouser found a solution!" << endl;
		}
		if (Out == 0)
		{
			cout << "Mouser was unable to find a solution" << endl;	
		}

		mouser.PrintMaze();	// Printing maze final state.
		system ("pause" );
		exit(0);	// Exiting on sucessful execution.
	}
}