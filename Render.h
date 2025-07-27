#pragma once
#pragma once

#include "Player.h"

extern char ScreenBuffer[PLAYER_LIMIT_Y][PLAYER_LIMIT_X + 1];

/**
	ScreenBuffer를 비운다
*/
void BufferClear(void);

/**
	ScreenBuffer를 화면에 출력한다
*/
void BufferFlip(void);

/**
	ScreenBuffer의 입력받은 X, Y좌표에 아스키코드를 하나 입력한다
*/
void SpriteDraw(int X, int Y, char Sprite);

/**
	Game 화면을 렌더링한다
*/
void Rendering(void);