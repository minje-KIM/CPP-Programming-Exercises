#include "Ranking.h"
#include <windows.h>	
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <time.h>

#define DIM	4	// 퍼즐의 크기

enum Direction { Left = 75, Right = 77, Up = 72, Down = 80 };
static int DirKey[4] = { Left, Right, Up, Down };
static int map[DIM][DIM];	
static int x, y;		// 빈 칸의 좌표 표현
static int num_moved;		// 이동한 횟수
static clock_t time_start;	

static void init() 
{
	for (int i = 0; i < DIM * DIM - 1; i++)
		map[i / DIM][i % DIM] = i + 1;
	map[DIM - 1][DIM - 1] = 0;
	x = DIM - 1; y = DIM - 1;

	srand(time(NULL));	// 난수를 발생시킵니다.
	time_start = clock();	
	num_moved = 0;		
}

static void display() 
{
	system("cls");
	printf("\t15-Puzzle\n\t");
	printf("--------------\n\t");
	for (int row = 0; row < DIM; row++) {
		for (int col = 0; col < DIM; col++) {
			if (map[row][col] > 0)
				printf("%3d", map[row][col]);
			else printf("   ");
		}
		printf("\n\t");
	}
	printf("--------------\n\t");
	clock_t	t1 = clock();
	double d = (double)(t1 - time_start) / CLOCKS_PER_SEC;
	printf("\n\t이동 횟수 :%6d\n\t소요 시간 :%6.1f\n\n", num_moved, d);
}

static bool move(int dir)
{
	if (dir == Right && x > 0) 
	{		
		map[y][x] = map[y][x - 1];
		map[y][--x] = 0;
	}
	else if (dir == Left && x < DIM - 1) 
	{	
		map[y][x] = map[y][x + 1];
		map[y][++x] = 0;
	}
	else if (dir == Up && y < DIM - 1) 
	{		
		map[y][x] = map[y + 1][x];
		map[++y][x] = 0;
	}
	else if (dir == Down && y > 0) 
	{		
		map[y][x] = map[y - 1][x];
		map[--y][x] = 0;
	}
	else return false;

	num_moved++;
	return true;
}

static void shuffle(int num_shuffle) {
	for (int i = 0; i < num_shuffle; i++) {
		int key = DirKey[rand() % 4];
		if (move(key) == false) { i--; continue; }
		display();
		Sleep(50);
	}
}

static bool isDone() 
{
	for (int row = 0; row < DIM; row++) {
		for (int col = 0; col < DIM; col++) {
			if (map[row][col] != row * DIM + col + 1)
				return (row == DIM - 1) && (col == DIM - 1);
		}
	}
	return true;
}

static int getDirKey() { return _getche() == 224 ? _getche() : 0; }

int PlayFifteenPuzzle() 
{
	init();
	display();
	PrintRanking();
	printf("\n 퍼즐을 섞으려면 enter를 누르세요.");
	_getche();
	shuffle(100);			
	printf("\n Game Start!!!!");
	_getche();

	num_moved = 0;			
	time_start = clock();		
	while (!isDone()) 
	{		
		move(getDirKey());	
		display();		
	}

	clock_t	t1 = clock();		
	double d = (double)(t1 - time_start) / CLOCKS_PER_SEC;
	return AddRanking(num_moved, d);	
}