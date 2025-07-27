#pragma once
#include <list>

#define PLAYER_LIMIT_X 81
#define PLAYER_LIMIT_Y 24

struct Player
{
	int ID;

	char Sprite;

	double PosX;
	double PosY;
};

enum Direction
{
	Left = 0,
	Right,
	Up,
	Down
};

extern Player player;
extern std::list<Player*> others;

void PlayerMove(Direction Dir);