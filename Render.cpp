#include "Render.h"
#include "Network.h"
#include <Windows.h>
#include <stdio.h>
#include "Console.h"

char ScreenBuffer[PLAYER_LIMIT_Y][PLAYER_LIMIT_X + 1];

void BufferClear(void)
{
	memset(ScreenBuffer, ' ', (PLAYER_LIMIT_X + 1) * PLAYER_LIMIT_Y);

	for (int i = 0; i < PLAYER_LIMIT_Y; i++)
	{
		ScreenBuffer[i][PLAYER_LIMIT_X] = '\0';
	}
}

void BufferFlip(void)
{
	for (int i = 0; i < PLAYER_LIMIT_Y; i++)
	{
		MoveCursor(0, i);
		printf(ScreenBuffer[i]);
	}
}

void SpriteDraw(int X, int Y, char Sprite)
{
	if (X < 0 || Y < 0 || X >= PLAYER_LIMIT_X || Y >= PLAYER_LIMIT_Y) return;

	ScreenBuffer[Y][X] = Sprite;
}

void Rendering(void)
{
	BufferClear();

	SpriteDraw((int)player.PosX, (int)player.PosY, player.Sprite);

	for (auto i : others)
	{
		SpriteDraw((int)i->PosX, (int)i->PosY, i->Sprite);
	}

	BufferFlip();
}