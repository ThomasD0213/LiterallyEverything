#include "sort.h"
#include <iostream>
#include <Windows.h>
#include <string>
#include <chrono>
#include <thread>
#include <cmath>

int nScreenWidth = 79;
int nScreenHeight = 40;
const char* menu = "+-----------------------------------------------------------------------------+|                                                                             ||             __  ___  ____ ______ ___  ___  ___ ___ ________  ___            ||X X X X X X (( \\// \\\\ || \\\\| || |// \\\\ ||\\\\//||// \\\\| || |-| //   X X X X X X|+------------>\\\\((   ))||_//  || ((   ))|| \\/ |--|=||  ||  ||((   <-----------+|X X X X X X \\_))\\\\_// || \\\\  ||  \\\\_// ||    |--| ||  ||  || \\\\__ X X X X X X|| X X X X X X X X X X X X X X X X X X X X X X X X X X X X X X X X X X X X X X ||X X X X X X X X 1: Selection Sort 2: Quick Sort 3: Bubble Sort  X X X X X X X|| X X X X X X X X                                               X X X X X X X ||                              By: Thomas Dalgetty                            ||                                                                             |+-----------------------------------------------------------------------------+";
const char* title = "SortoMatic"; //Title of the window
bool called = false; //so that the pre-written UI isn't written over
bool testing = false; //lets the user know the program isn't hung, just working
int size = abs(10); //initial size
SMALL_RECT windowSize = { 0, 0, 79, 40 };

wchar_t *screen = new wchar_t[nScreenWidth*nScreenHeight];
HANDLE hConsole = CreateConsoleScreenBuffer(GENERIC_READ | GENERIC_WRITE, 0, NULL, CONSOLE_TEXTMODE_BUFFER, NULL);
DWORD dwBytesWritten = 0;
/*
TODO BLOCK

make testing respond on the screen
learn how to multithread to do what is stated above
make it to where size can never go below 0


*/

void screenWriter()
{
	WriteConsoleOutputCharacter(hConsole, screen, nScreenWidth * nScreenHeight, { 0,0 }, &dwBytesWritten);
	for (int i = 0; i < 949; i++)
		screen[i] = menu[i];

	int strindex = 0;
	int sizeStrindex = 0;
	std::string str = "Type: None     Time Elapsed: 0 second(s)";
	std::string sizeStr = "Test size: " + std::to_string(size) + " Testing: " + std::to_string(testing);
	for (int i = 949; i < (nScreenWidth * nScreenHeight); i++)
	{

		if (i >= 1027 && i < 1106)
		{
			(!(sizeStrindex >= sizeStr.length())) ? screen[i] = sizeStr[sizeStrindex] : screen[i] = ' ';
			sizeStrindex++;

		}
		else if (!(i > 1106 && i <= 1185))
		{
			screen[i] = ' ';
		}
		else if (!called)
		{
			(!(strindex >= str.length())) ? screen[i] = str[strindex] : screen[i] = ' ';
			strindex++;
		}

	}
}

void keyHandler()
{
	//TODO put the VK-Key Codes into a map so these if statements can become switch

	if (GetAsyncKeyState(0x31)) //1 key
	{
		testing = true;	//TODO make it to where this'll get drawn somehow
		screenWriter();
		std::string str = Sort::testSelectionSort(size);
		int strindex = 0;
		for (int i = 1107; i < 1185; i++)
		{
			if (!(strindex >= str.length()))
				screen[i] = str[strindex];
			else
				screen[i] = ' ';
			strindex++;
		}
		called = true;
	}
	else if (GetAsyncKeyState(0x32)) //2 key
	{
		testing = true;
		std::string str = Sort::testQuickSort(size);
		int strindex = 0;
		for (int i = 1107; i < 1185; i++)
		{
			if (!(strindex >= str.length()))
				screen[i] = str[strindex];
			else
				screen[i] = ' ';
			strindex++;
		}
		called = true;
	}
	else if (GetAsyncKeyState(0x33)) //3 key
	{
		testing = true;
		std::string str = Sort::testBubbleSort(size);
		int strindex = 0;
		for (int i = 1107; i < 1185; i++)
		{
			if (!(strindex >= str.length()))
				screen[i] = str[strindex];
			else
				screen[i] = ' ';
			strindex++;
		}
		called = true;
	}
	else if (GetAsyncKeyState(0x52))  //R key
	{
		std::string reset = "RESET";
		for (int i = 0; i < nScreenWidth * nScreenHeight; i++)
			screen[i] = reset[i % 5];
		called = false;
	}
	else if (GetAsyncKeyState(0x6B)) //VK_ADD
	{
		size += 10;
	}
	else if (GetAsyncKeyState(0x6D)) //VK_SUBTRACT
	{
		size -= 10;
	}
	else if (GetAsyncKeyState(0x6A)) //VK_MULTIPLY
	{
		size += 100;
	}
	else if (GetAsyncKeyState(0x6F)) //VK_DIVIDE
	{
		size -= 100;
	}
	else if (GetAsyncKeyState(0x70)) //VK_F1
	{
		size -= 1000;
	}
	else if (GetAsyncKeyState(0x71)) //VK_F2
	{
		size += 1000;
	}
	testing = false;
}

int main()
{
	auto tp1 = std::chrono::system_clock::now();
	auto tp2 = std::chrono::system_clock::now();
	
	// Create Screen Buffer

	SetConsoleActiveScreenBuffer(hConsole);
	screen[nScreenWidth * nScreenHeight - 1] = '\0';
	SetConsoleTitleA(title);
	SetConsoleWindowInfo(hConsole, TRUE, &windowSize);		
	
	while (true) 
	{
		screenWriter();
		keyHandler();
	}
	
	
}
	


