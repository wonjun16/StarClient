#include "KeyboardInput.h"
#include <conio.h>
#include <Windows.h>
#include "Player.h"

bool GetKeyboardInput(int Key)
{
	SHORT Pressed;
	Pressed = GetAsyncKeyState(Key);
	if (Pressed & 0x8001) return true;
	return false;
}

void HandleInput(void)
{
	if (GetKeyboardInput(VK_LEFT))
	{
		PlayerMove(Direction::Left);
	}
	if (GetKeyboardInput(VK_RIGHT))
	{
		PlayerMove(Direction::Right);
	}
	if (GetKeyboardInput(VK_DOWN))
	{
		PlayerMove(Direction::Down);
	}
	if (GetKeyboardInput(VK_UP))
	{
		PlayerMove(Direction::Up);
	}
}