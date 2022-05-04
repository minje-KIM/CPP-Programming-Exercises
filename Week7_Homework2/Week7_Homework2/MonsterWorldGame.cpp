#include "MonsterWorld.h"
#include <time.h>
int main()
{
	srand((unsigned int)time(NULL));
	int w = 16, h = 8;

	MonsterWorld game(w, h);
	game.add(Monster("����", "��", rand() % w, rand() % h));
	game.add(Monster("������", "��", rand() % w, rand() % h));
	game.add(Monster("���״�", "��", rand() % w, rand() % h));
	game.add(Monster("��Ʈ", "��", rand() % w, rand() % h));
	game.play(500, 10);
	printf("------���� ����-------------------\n");
	return 0;
}