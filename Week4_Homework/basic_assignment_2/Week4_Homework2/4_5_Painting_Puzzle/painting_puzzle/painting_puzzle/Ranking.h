#pragma once
#include <cstdio>

struct PlayInfo {
	char	name[200];	// 플레이어의 이름
	int		num_moved;		// 퍼즐을 움직인 횟수
	double	time_elapsed;	// 퍼즐을 푸는데 걸린 시간
};
extern void LoadRanking(const char* filename);
extern void StoreRanking(const char* filename);
extern void PrintRanking();
extern int AddRanking(int num_moved, double time_elapsed);