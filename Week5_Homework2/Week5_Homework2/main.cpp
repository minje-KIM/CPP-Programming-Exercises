#include "minesweeper.h"
#pragma warning(disable:4996)

int main()
{
	int height;		//����
	int width;		//����
	int num_mine;

	printf("���� ���� ������ ���̸� �Է��� �ּ���(�ִ� 80) : ");
	scanf("%d", &width);
	printf("���� ���� ������ ���̸� �Է��� �ּ���(�ִ� 40) : ");
	scanf("%d", &height);

	printf(" <Mine Sweeper> \n");
	printf(" �ż��� ������ ������ �Է��� �ּ��� : ");
	scanf("%d", &num_mine);
	playminesweeper(num_mine, width, height);

	return 0;
}