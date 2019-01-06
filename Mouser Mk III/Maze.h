#ifndef MAZE_H
#define MAZE_H

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <windows.h>

using namespace std;

class Maze
{
public:
	// -- //
	void HelloWorld()	// Test function for the class.
	{
		cout << "I am Maze, hello world!" << endl
			 << "I load the maze ready for Mouser." << endl << endl;
	}

	// Constructor
	Maze::Maze()	// Default Constructor. Defaults to test mode.
	{
		preset = 0;
	}
	// Services
	void LoadMaze (string Filename)
	{
		if (preset == 0) // Test Mode
		{
			int x;
			int y;
			int i;
			char temp;

			ifstream fin("C:\\Users\\Black Wolf\\Documents\\My Dropbox\\Projects\\Mouser Mk III\\Debug\\maze2.txt", ios::in);

			if (fin.fail() == true)
			{
				cout << "Error occured. Failbit set TRUE. Reading operation was not processed correctly." << endl;
				system ("pause" );
				exit(1);
			}

			if (fin.bad() == true)
			{
				cout << "Error occured. Badbit set TRUE. Reading stream is somehow corrupted, data may be lost." << endl;
				system ("pause" );
				exit(1);
			}

			if (fin.good() == true)
			{
				fin >> size;

				maze.resize(size);
				for (i = 0; i < size; i++)
				{
					maze[i].resize(size);
				}

				for (y = 0; y < size; y++)
				{
					for (x = 0; x < size; x++)
					{
						fin >> temp;
						maze[y][x] = temp;
					}
				}
			}

		}
		if(preset == 1) // User Interactive Mode
		{
			int x;
			int y;
			int i;
			char temp;

			cout << endl << "Please enter the name of the maze you want to open: ";
			cin >> Filename;

			ifstream fin( Filename.c_str() , ios::in);

			
			if (fin.fail() == true)	// First test to ensure the file opened correctly for reading.
			{
				cout << "Error occured. Failbit set TRUE. Reading operation was not processed correctly." << endl;
				system ("pause" );
				exit(1);
			}

			if (fin.bad() == true)	// Second test to see if file opened correctly for reading.
			{
				cout << "Error occured. Badbit set TRUE. Reading stream is somehow corrupted, data may be lost." << endl;
				system ("pause" );
				exit(1);
			}

			if (fin.good() == true)	// All systems go! The maze is resized and the file loaded into it.
			{
				fin >> size;

				maze.resize(size);
				for (i = 0; i < size; i++)
				{
					maze[i].resize(size);
				}

				for (y = 0; y < size; y++)
				{
					for (x = 0; x < size; x++)
					{
						fin >> temp;
						maze[y][x] = temp;
					}
				}
			}
		}
		if (preset == 2) // Command Line Mode
		{
			int x;
			int y;
			int i;
			char temp;

			ifstream fin( Filename.c_str() , ios::in);

			if (fin.fail() == true)	// First test to ensure the file opened correctly for reading.
			{
				cout << "Error occured. Failbit set TRUE. Reading operation was not processed correctly." << endl;
				exit(1);
			}

			if (fin.bad() == true)	// Second test to see if file opened correctly for reading.
			{
				cout << "Error occured. Badbit set TRUE. Reading stream is somehow corrupted, data may be lost." << endl;
				exit(1);
			}

			if (fin.good() == true)	// All systems go! The maze is resized and the file loaded into it.
			{
				fin >> size;

				maze.resize(size);
				for (i = 0; i < size; i++)
				{
					maze[i].resize(size);
				}

				for (y = 0; y < size; y++)
				{
					for (x = 0; x < size; x++)
					{
						fin >> temp;
						maze[y][x] = temp;
					}
				}
			}
		}
	}

	void PrintMaze ()	// The basic printer. Disused as is for diagnostic purposes.
	{
		int x;
		int y;

		cout << endl << "->Printing the maze to screen" << endl;

		for (y = 0; y < size; y++)
		{
			for (x = 0; x < size; x++)
			{
				cout << maze[y][x];
			}
			cout << endl;
		}

		cout << "...Printing complete" << endl;
	}

	// Tools
	int GetSize ()	// Returns the size as read from the top of the file.
	{
		return size;
	}
	void SetChar (char InChar, int y, int x)	// Manually set any character in the maze to any character.
	{
		maze[y][x] = InChar;
	}
	char GetChar (int y, int x)	// Returns the character at a location in the maze.
	{
		return maze[y][x];
	}
	void SetPreset (int PreVal)	// Prests the operational mode of the class.
	{
		preset = PreVal;
	}
	// -- //
private:
	int preset;
	int size;
	vector< vector<char> > maze;
};

#endif