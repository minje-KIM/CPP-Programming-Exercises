#include "Ranking.h"
extern int PlayFifteenPuzzle();

int main()
{
	LoadRanking("ranking.txt");
	int rank = PlayFifteenPuzzle();
	PrintRanking();
	StoreRanking("ranking.txt");

	return 0;
}