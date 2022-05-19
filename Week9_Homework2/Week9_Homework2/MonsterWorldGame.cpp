#include "MonsterWorld.h"
#include "VariousMonsters.h"
#include <time.h>

int main()
{
	srand((unsigned int)time(NULL));
	int w = 16, h = 8;
	MonsterWorld game(w, h);

	game.add(new Smombi("대각스몸비", "β", rand() % w, rand() % h));
	game.add(new Sianshi("슈퍼강시", "∑", rand() % w, rand() % h, true));
	game.add(new Minje("민제몬스터", "∀", rand() % w, rand() % h));

	game.play(500, 10);
	printf("------게임 종료-------------------\n");
	
	return 0;
}