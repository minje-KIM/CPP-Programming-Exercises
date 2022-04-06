#pragma warning(disable:4996)
#include "Ranking.h"
#define NUM_MVP 5
static PlayInfo MVP[NUM_MVP];	
static int num_MVP = NUM_MVP;	

static void InitRanking() 
{
	PlayInfo Initial = { "Not ranked", 1000, 1000.0 };
	for (int i = 0; i < num_MVP; i++)
		MVP[i] = Initial;
}

void LoadRanking(const char* fname)
{
	FILE* fp = fopen(fname, "r");
	if (fp == NULL)
		InitRanking();
	else 
	{
		for (int i = 0; i < num_MVP; i++)
			fscanf(fp, "%d%s%lf", &MVP[i].num_moved, MVP[i].name, &MVP[i].time_elapsed);
		fclose(fp);
	}
}

void StoreRanking(const char* fname) 
{
	FILE* fp = fopen(fname, "w");
	if (fp == NULL) return;
	for (int i = 0; i < num_MVP; i++)
		fprintf(fp, "  %4d  %-16s %-5.1f\n", MVP[i].num_moved, MVP[i].name, MVP[i].time_elapsed);
	fclose(fp);
}

void PrintRanking() 
{
	for (int i = 0; i < num_MVP; i++)
		printf("  [%2d위]  %4d  %-16s %5.1f\n", i + 1, MVP[i].num_moved, MVP[i].name, MVP[i].time_elapsed);
}

int AddRanking(int num_moved, double time_elapsed) {
	if (num_moved < MVP[num_MVP - 1].num_moved) {
		int position = num_MVP - 1;
		for (; position > 0; position--) {
			if (num_moved >= MVP[position - 1].num_moved) break;
			MVP[position] = MVP[position - 1];
		}
		MVP[position].num_moved = num_moved;
		MVP[position].time_elapsed = time_elapsed;
		printf(" %d위입니다. 이름을 입력하세요: ", position + 1);
		scanf("%s", MVP[position].name);
		return position + 1;
	}
	return 0;
}