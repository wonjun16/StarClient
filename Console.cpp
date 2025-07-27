#include <Windows.h>
#include <mmsystem.h>
#include "Console.h"
#include <stdio.h>
#include "Player.h"

#pragma comment(lib, "winmm.lib")

HANDLE ConsoleHandle;

unsigned long ProcessTime;
unsigned long DeltaTime = FRAME_SEC;

void InitConsole(void)
{
	char ConsoleSize[50];
	snprintf(ConsoleSize, sizeof(ConsoleSize), "%s%d%s%d", "mode con: cols=", PLAYER_LIMIT_X, " lines=", PLAYER_LIMIT_Y);
	system(ConsoleSize);

	CONSOLE_CURSOR_INFO ConsoleCursor;

	ConsoleCursor.bVisible = false;
	ConsoleCursor.dwSize = 1;

	ConsoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorInfo(ConsoleHandle, &ConsoleCursor);
}

void MoveCursor(int PosX, int PosY)
{
	COORD Coord;
	Coord.X = PosX;
	Coord.Y = PosY;

	SetConsoleCursorPosition(ConsoleHandle, Coord);
}

void InitTimer(void)
{
	timeBeginPeriod(1);
	ProcessTime = timeGetTime();
}

void Initial(void)
{
	InitConsole();
	InitTimer();
}

void UpdateProcessTime(void)
{
	ProcessTime += DeltaTime;
}

void Wait(void)
{
	DWORD CurTime = timeGetTime();
	int Diff = CurTime - ProcessTime;

	if (Diff < FRAME_SEC)
	{
		Sleep(FRAME_SEC - Diff);
	}
}