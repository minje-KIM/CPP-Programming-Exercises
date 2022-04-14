#include "minesweeper.h"
#pragma warning(disable:4996)

int main()
{
	int height;		//세로
	int width;		//가로
	int num_mine;

	printf("지뢰 맵의 가로의 길이를 입력해 주세요(최대 80) : ");
	scanf("%d", &width);
	printf("지뢰 맵의 세로의 길이를 입력해 주세요(최대 40) : ");
	scanf("%d", &height);

	printf(" <Mine Sweeper> \n");
	printf(" 매설할 지뢰의 개수를 입력해 주세요 : ");
	scanf("%d", &num_mine);
	playminesweeper(num_mine, width, height);

	return 0;
}