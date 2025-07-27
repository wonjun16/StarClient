#pragma once

#define FRAME_SEC		20

extern unsigned long DeltaTime;
extern unsigned long ProcessTime;

/**
	콘솔 제어를 위한 준비 작업
*/
void InitConsole(void);

/**
	콘솔 화면의 커서를 X, Y좌표로 이동시킨다
*/
void MoveCursor(int PosX, int PosY);

/**
	타이머 초기화
*/
void InitTimer(void);

/**
	루프 시작 전 모든 초기화 작업을 수행한다
*/
void Initial(void);

/**
	ProcessTime을 업데이트 한다
*/
void UpdateProcessTime(void);

/**
	FRAME_SEC 보다 더 적은 시간이 걸렸을 경우 다음 프레임까지 쉰다
*/
void Wait(void);