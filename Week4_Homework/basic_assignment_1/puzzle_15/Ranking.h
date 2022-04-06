#pragma once
#include <cstdio>

struct PlayInfo {
	char	name[200];	// �÷��̾��� �̸�
	int		num_moved;		// ������ ������ Ƚ��
	double	time_elapsed;	// ������ Ǫ�µ� �ɸ� �ð�
};
extern void LoadRanking(const char* filename);
extern void StoreRanking(const char* filename);
extern void PrintRanking();
extern int AddRanking(int num_moved, double time_elapsed);