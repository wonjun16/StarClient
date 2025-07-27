#include "Player.h"
#include "Network.h"
#include <Windows.h>
#include "Console.h"

Player player;
std::list<Player*> others;

void PlayerMove(Direction Dir)
{
	double MoveSpeed = DeltaTime / 30.0;
	int lastX = (int)player.PosX, lastY = (int)player.PosY;
	switch (Dir)
	{
	case Left:
		player.PosX = max(0, player.PosX - MoveSpeed * 1.3);
		break;
	case Right:
		player.PosX = min(PLAYER_LIMIT_X - 1, player.PosX + MoveSpeed * 1.3);
		break;
	case Up:
		player.PosY = max(0, player.PosY - MoveSpeed * 0.8);
		break;
	case Down:
		player.PosY = min(PLAYER_LIMIT_Y - 1, player.PosY + MoveSpeed * 0.8);
		break;
	default:
		break;
	}
	if (lastX != (int)player.PosX || lastY != (int)player.PosY)
	{
		SendMsg();
	}
}
