#pragma once
#include "Canvas.h"
#define DIM 40

class Monster {
	string name, icon;	// ���� �̸��� ȭ�� ��¿� ������
	int x, y, nItem;		// ���� ��ġ�� ���� ������ ��
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
	Monster(string n = "������", string i = "��", int px = 0, int py = 0)
		: name(n), icon(i), x(px), y(py), nItem(0), nEnergy(100), nMonster(1000) {}
	~Monster() { cout << "\t" << name << icon << " �������ϴ�~~~\n"; }

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
		cout << "��ü ������ ��: " << nMonster <<  endl;
		if (nMonster == 3)
		{
			cout << "���� �� ���� �׾����ϴ�!" << endl;
		}
		else if (nMonster == 2)
		{
			cout << "���� �� ���� �׾����ϴ�!" << endl;
		}
		else if (nMonster == 1)
		{
			cout << "���� �� ���� �׾����ϴ�!" << endl;
		}

	}


};