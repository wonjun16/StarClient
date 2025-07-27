#pragma once

#define FRAME_SEC		20

extern unsigned long DeltaTime;
extern unsigned long ProcessTime;

/**
	�ܼ� ��� ���� �غ� �۾�
*/
void InitConsole(void);

/**
	�ܼ� ȭ���� Ŀ���� X, Y��ǥ�� �̵���Ų��
*/
void MoveCursor(int PosX, int PosY);

/**
	Ÿ�̸� �ʱ�ȭ
*/
void InitTimer(void);

/**
	���� ���� �� ��� �ʱ�ȭ �۾��� �����Ѵ�
*/
void Initial(void);

/**
	ProcessTime�� ������Ʈ �Ѵ�
*/
void UpdateProcessTime(void);

/**
	FRAME_SEC ���� �� ���� �ð��� �ɷ��� ��� ���� �����ӱ��� ����
*/
void Wait(void);