#include "MonsterWorld.h"
#include "VariousMonsters.h"
#include <time.h>

int main()
{
	srand((unsigned int)time(NULL));
	int w = 16, h = 8;
	MonsterWorld game(w, h);

	game.add(new Smombi("�밢������", "��", rand() % w, rand() % h));
	game.add(new Sianshi("���۰���", "��", rand() % w, rand() % h, true));
	game.add(new Minje("��������", "��", rand() % w, rand() % h));

	game.play(500, 10);
	printf("------���� ����-------------------\n");
	
	return 0;
}