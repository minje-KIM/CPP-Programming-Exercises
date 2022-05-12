#pragma once
#include "Canvas.h"
#define DIM 40

class Monster {
	string name, icon;	// 몬스터 이름과 화면 출력용 아이콘
	int x, y, nItem;		// 현재 위치와 먹은 아이템 수
	int nEnergy;
	int nMonster;

	void clip(int maxx, int maxy) {
		if (x < 0) x = 0;
		if (x >= maxx) x = maxx - 1;
		if (y < 0) y = 0;
		if (y >= maxy) y = maxy - 1;
	}
	void eat(int** map) {
		if (map[y][x] == 1)
		{
			map[y][x] = 0;
			nEnergy += 8;
			nItem++;
		}
		else
		{
			if (nEnergy != 0)
			{
				nEnergy -= 1;
			}
		}
	}
public:
	Monster(string n = "나괴물", string i = "※", int px = 0, int py = 0)
		: name(n), icon(i), x(px), y(py), nItem(0), nEnergy(100), nMonster(1000) {}
	~Monster() { cout << "\t" << name << icon << " 물러갑니다~~~\n"; }

	void clone(Monster* new1)
	{
		name = new1->name;
		icon = new1->icon;
		x = new1->x;
		y = new1->y;
		nItem = new1->nItem; 
		nEnergy = new1->nEnergy;
	}

	void draw(Canvas &canvas) { canvas.draw(x, y, icon); }
	void move(int** map, int maxx, int maxy) {
		switch (rand() % 8) {
		case 0: y--; break;
		case 1: x++; y--; break;
		case 2: x++; break;
		case 3: x++; y++; break;
		case 4: y++; break;
		case 5: x--; y++; break;
		case 6: x--; break;
		case 7: x--; y--; break;
		}
		clip(maxx, maxy);
		eat(map);
	}
	void print() { cout << "\t" << name << icon << ":" << nItem << " E:" << nEnergy << endl; }

	int getEnergy()
	{
		return nEnergy;
	}

	void printCount(int new_nMonster)
	{
		nMonster = new_nMonster;
		cout << "전체 몬스터의 수: " << nMonster <<  endl;
		if (nMonster == 3)
		{
			cout << "몬스터 한 마리 죽었습니다!" << endl;
		}
		else if (nMonster == 2)
		{
			cout << "몬스터 두 마리 죽었습니다!" << endl;
		}
		else if (nMonster == 1)
		{
			cout << "몬스터 세 마리 죽었습니다!" << endl;
		}

	}


};