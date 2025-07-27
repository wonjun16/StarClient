#include "Network.h"
#include <stdio.h>
#include "data.h"
#include "Player.h"

SOCKET sock;
FD_SET rset;
timeval timeout = { 0, 0 };

int Curplayers = 1;

void ErrQuit(const char* message)
{
	printf("Error : %s\n", message);
	WSACleanup();
	exit(1);
}

void ErrDispaly(const char* message)
{
	printf("Error : %s\n", message);
}

void InitNetwork(void)
{
	WSADATA wsa;
	WSAStartup(MAKEWORD(2, 2), &wsa);

	sock = socket(AF_INET, SOCK_STREAM, 0);
	if (sock == INVALID_SOCKET) ErrQuit("socket()");

	WCHAR ipStr[INET_ADDRSTRLEN];
	printf("접속할 IP를 입력하세요 : ");
	wscanf_s(L"%ws", ipStr, _countof(ipStr));

	SOCKADDR_IN sockaddr;
	memset(&sockaddr, 0, sizeof(sockaddr));
	sockaddr.sin_family = AF_INET;
	if (InetPton(AF_INET, ipStr, &(sockaddr.sin_addr)) != 1) ErrQuit("InetPton()");
	sockaddr.sin_port = htons(PORT);

	WCHAR ipOut[INET_ADDRSTRLEN];
	if (InetNtop(AF_INET, &(sockaddr.sin_addr), ipOut, INET_ADDRSTRLEN) == NULL) ErrQuit("InetNtop()");
	int connret = connect(sock, (SOCKADDR*)&sockaddr, sizeof(sockaddr));
	if (connret == SOCKET_ERROR) ErrQuit("connect()");

	u_long nonBlocking = 1;
	int ret = ioctlsocket(sock, FIONBIO, &nonBlocking);
	if (ret == SOCKET_ERROR) ErrQuit("ioctlsocket()");
}

void SetSelect(void)
{
	FD_ZERO(&rset);
	FD_SET(sock, &rset);

	int retval;
	retval = select(0, &rset, NULL, NULL, &timeout);
	if (retval == SOCKET_ERROR) ErrQuit("select()");

	if (FD_ISSET(sock, &rset))
	{
		char recvbuf[1600];
		int recvret = recv(sock, recvbuf, sizeof(recvbuf), 0);
		if (recvret == SOCKET_ERROR)
		{
			ErrQuit("recv()");
		}
		if (recvret == 0)
		{
			closesocket(sock);
			WSACleanup();
			exit(1);
		}

		int index = 0;
		while (recvret > index * 16)
		{
			char* packet = recvbuf + index * 16;
			int* type = (int*)packet;

			switch (*type)
			{
			case 0:
			{
				stAllocID* allocID = (stAllocID*)packet;
				player.ID = allocID->_ID;
				break;
			}

			case 1:
			{
				stCreateStar* createStar = (stCreateStar*)packet;

				if (player.ID == createStar->_ID)
				{
					player.Sprite = '*';
					player.PosX = createStar->_X;
					player.PosY = createStar->_Y;
				}
				else
				{
					Player* p = new Player();
					p->ID = createStar->_ID;
					p->Sprite = '*';
					p->PosX = createStar->_X;
					p->PosY = createStar->_Y;
					others.push_back(p);
					Curplayers++;
				}

				break;
			}

			case 2:
			{
				stDeleteStar* deletestar = (stDeleteStar*)packet;

				for (auto i = others.begin(); i != others.end(); i++)
				{
					if ((*i)->ID == deletestar->_ID)
					{
						delete (*i);
						others.erase(i);
						Curplayers--;
						break;
					}
				}
				break;
			}

			case 3:
			{
				stMove* move = (stMove*)packet;

				for (auto i = others.begin(); i != others.end(); i++)
				{
					if ((*i)->ID == move->_ID)
					{
						(*i)->PosX = move->_X;
						(*i)->PosY = move->_Y;
						break;
					}
				}
				break;
			}

			default:
				break;
			}
			index++;
		}
	}
}

void SendMsg(void)
{
	stMove movepacket;
	movepacket._ID = player.ID;
	movepacket._Type = 3;
	movepacket._X = (int)player.PosX;
	movepacket._Y = (int)player.PosY;
	int sendlen = send(sock, (char*)&movepacket, sizeof(movepacket), 0);
	if (sendlen == SOCKET_ERROR)
	{
		ErrQuit("send()");
	}
}