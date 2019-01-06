#include <string>
#include <iostream>
#include <iomanip>
#include <Windows.h>
using namespace std;

class DISP{
	public:
		// All entries are static to avoid having to have an instance of the class to be able to acess the functions.
		static void DISP::printRed(string output, bool intense)
	{
		HANDLE hout;
		hout = GetStdHandle(STD_OUTPUT_HANDLE);

		if(intense)
		{
			SetConsoleTextAttribute(hout, BACKGROUND_RED | BACKGROUND_INTENSITY);
		}
		else
		{
			SetConsoleTextAttribute(hout, BACKGROUND_RED);
		}

		cout << output;

		SetConsoleTextAttribute(hout,FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
	}
		static void DISP::printGreen(string output, bool intense)
	{
		HANDLE hout;
		hout = GetStdHandle(STD_OUTPUT_HANDLE);

		if(intense)
		{
			SetConsoleTextAttribute(hout, BACKGROUND_GREEN | BACKGROUND_INTENSITY);
		}
		else
		{
			SetConsoleTextAttribute(hout, BACKGROUND_GREEN);
		}

		cout << output;

		SetConsoleTextAttribute(hout,FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
	}
		static void DISP::printNegative(string output, bool intense)
	{
		HANDLE hout;
		hout = GetStdHandle(STD_OUTPUT_HANDLE);

		if(intense)
		{
			SetConsoleTextAttribute(hout,BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE | BACKGROUND_INTENSITY);
		}
		else
		{
			SetConsoleTextAttribute(hout,BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE);
		}

		cout << output;

		SetConsoleTextAttribute(hout,FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
	}
		static void DISP::printYellow(string output, bool intense)
	{
		HANDLE hout;
		hout = GetStdHandle(STD_OUTPUT_HANDLE);

		if(intense)
		{
			SetConsoleTextAttribute(hout, BACKGROUND_GREEN | BACKGROUND_RED | BACKGROUND_INTENSITY);
		}
		else
		{
			SetConsoleTextAttribute(hout, BACKGROUND_GREEN | BACKGROUND_RED );
		}

		cout << output;

		SetConsoleTextAttribute(hout,FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
	}

	private:
		// No private variables needed.
};
	/*
	static void DISP::printCyan(string output, bool intense)
	{
		HANDLE hout;
		hout = GetStdHandle(STD_OUTPUT_HANDLE);

		if(intense)
		{
			SetConsoleTextAttribute(hout, BACKGROUND_GREEN | BACKGROUND_BLUE | BACKGROUND_INTENSITY);
		}
		else
		{
			SetConsoleTextAttribute(hout, BACKGROUND_GREEN | BACKGROUND_BLUE );
		}

		cout << output;

		SetConsoleTextAttribute(hout,FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
	}
	static void DISP::printBlue(string output, bool intense)
	{
		HANDLE hout;
		hout = GetStdHandle(STD_OUTPUT_HANDLE);

		if(intense)
		{
			SetConsoleTextAttribute(hout, BACKGROUND_BLUE | BACKGROUND_INTENSITY);
		}
		else
		{
			SetConsoleTextAttribute(hout, BACKGROUND_BLUE);
		}

		cout << output;

		SetConsoleTextAttribute(hout,FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
	}
	*/