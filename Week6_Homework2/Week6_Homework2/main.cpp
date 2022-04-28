#include "Hangman.h"
#include "MyDic.h"
#include <cstdlib>
#include <string>

int main()
{
	srand(time(NULL));
	Hangman game;
	MyDic hello;

	hello.load("example.txt");

	int random_num = rand() % 8;
	game.play(hello.getEng(random_num));

	
	cout << endl << "���ܾ� : " << hello.getEng(random_num) << endl;
	cout << "�ѱ� ���� : " << hello.getKor(random_num) << endl;

	return 0;
}