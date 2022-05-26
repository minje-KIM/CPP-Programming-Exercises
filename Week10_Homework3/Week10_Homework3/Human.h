#pragma once
#include "Monster.h"
#include <conio.h>
enum Direction { Left = 75, Right = 77, Up = 72, Down = 80 };

class Human : public Monster {
public:
	Human(string n = "미래인류", string i = "♀", int px = 0, int py = 0)
		: Monster(n, i, px, py) {}
	~Human() { cout << " [Human   ]"; }
	int getDirKey() { return _getche() == 224 ? _getche() : 0; }
	void move(int** map, int maxx, int maxy) {
		if (_kbhit()) {
			char ch = getDirKey();
			if (ch == Left) x--;
			else if (ch == Right) x++;
			else if (ch == Up) y--;
			else if (ch == Down) y++;
			else return;
			clip(maxx, maxy);
			eat(map);
		}
	}
};

class Tuman : public Human {

public:
	Tuman(string n = "플레이어", string i = "방", int px = 0, int py = 0)
		: Human(n, i, px, py ) {}
	~Tuman() { cout << " 플레이어 "; }

	void move(int** map, int maxx, int maxy, unsigned char ch)
	{
			if (ch == Left) x--;
			else if (ch == Right) x++;
			else if (ch == Up) y--;
			else if (ch == Down) y++;
			else return;
			clip(maxx, maxy);
			eat(map);
		}


	void moveHuman(int **map, int maxx, int maxy, unsigned char ch)
	{
		if (ch == 'w' || ch == 'W')
			y--;
		else if (ch == 'a' || ch == 'A')
			x--;
		else if (ch == 's' || ch == 'S')
			y++;
		else if (ch == 'd' || ch == 'D')
			x++;
	
		clip(maxx, maxy);
		eat(map);
	}
};