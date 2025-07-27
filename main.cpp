#include "data.h"
#include "KeyboardInput.h"
#include "Console.h"
#include "Render.h"
#include "Network.h"

int main()
{
	InitNetwork();
	Initial();

	while (1)
	{
		HandleInput();
		SetSelect();
		Rendering();
		Wait();
		UpdateProcessTime();
	}

	WSACleanup();
	return 0;
}

