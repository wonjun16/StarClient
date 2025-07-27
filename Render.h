#pragma once
#pragma once

#include "Player.h"

extern char ScreenBuffer[PLAYER_LIMIT_Y][PLAYER_LIMIT_X + 1];

/**
	ScreenBuffer�� ����
*/
void BufferClear(void);

/**
	ScreenBuffer�� ȭ�鿡 ����Ѵ�
*/
void BufferFlip(void);

/**
	ScreenBuffer�� �Է¹��� X, Y��ǥ�� �ƽ�Ű�ڵ带 �ϳ� �Է��Ѵ�
*/
void SpriteDraw(int X, int Y, char Sprite);

/**
	Game ȭ���� �������Ѵ�
*/
void Rendering(void);