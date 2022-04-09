#include "minesweeper.h"
#pragma warning(disable:4996)

int main()
{
	int num_mine;
	printf(" <Mine Sweeper> \n");
	printf(" 매설할 지뢰의 개수를 입력해 주세요 : ");
	scanf("%d", &num_mine);
	playminesweeper(num_mine);

	return 0;
}