#include "minesweeper.h"
#pragma warning(disable:4996)

int main()
{
	int num_mine;
	printf(" <Mine Sweeper> \n");
	printf(" �ż��� ������ ������ �Է��� �ּ��� : ");
	scanf("%d", &num_mine);
	playminesweeper(num_mine);

	return 0;
}