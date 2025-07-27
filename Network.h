#pragma once
#pragma comment(lib, "ws2_32")
#include <WinSock2.h>
#include <WS2tcpip.h>

#define PORT 3000

extern int Curplayers;

extern SOCKET sock;
extern FD_SET rset;
extern timeval timeout;

void ErrQuit(const char* message);
void ErrDispaly(const char* message);
void InitNetwork(void);
void SetSelect(void);
void SendMsg(void);