#include "Ranking.h"
extern int PlayFifteenPuzzle();

int main()
{
	LoadRanking("ranking.bin");
	int rank = PlayFifteenPuzzle();
	PrintRanking();
	StoreRanking("ranking.bin");

	return 0;
}