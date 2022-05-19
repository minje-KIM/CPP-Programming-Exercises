#pragma once
#include "Monster.h"
#include <time.h>

class Zombie : public Monster {
public:
	Zombie(string n = "ÇãÁ¢Á»ºñ", string i = "¡×", int x = 0, int y = 0)
		: Monster(n, i, x, y) {}
	~Zombie() { cout << " Zombie"; }
};

class Vampire : public Monster {
public:
	Vampire(string n = "¹ìÆÄÀÌ¾î", string i = "¡Ú", int x = 0, int y = 0)
		: Monster(n, i, x, y) {}
	~Vampire() { cout << " Vampire"; }

	void move(int** map, int maxx, int maxy) {
		int dir = rand() % 4;
		if (dir == 0) x--;
		else if (dir == 1) x++;
		else if (dir == 2) y--;
		else y++;
		clip(maxx, maxy);
		eat(map);
	}
};

class KGhost : public Monster {
public:
	KGhost(string n = "Ã³³à±Í½Å", string i = "¢¾", int x = 0, int y = 0)
		: Monster(n, i, x, y) {}
	~KGhost() { cout << " KGhost"; }

	void move(int** map, int maxx, int maxy) {
		x = rand() % maxx;
		y = rand() % maxy;
		clip(maxx, maxy);
		eat(map);
	}
};

class Jiangshi : public Monster {
protected:
	bool	bHori;
public:
	Jiangshi(string n = "´ë·ú°­½Ã", string i = "¡ê", int x = 0, int y = 0, bool bH = true)
		: Monster(n, i, x, y), bHori(bH) {}
	~Jiangshi() { cout << " Jiangshi"; }

	void move(int** map, int maxx, int maxy) {
		int dir = rand() % 2;
		int jump = rand() % 2 + 1;
		if (bHori) x += ((dir == 0) ? -jump : jump);
		else y += ((dir == 0) ? -jump : jump);
		clip(maxx, maxy);
		eat(map);
	}
};

class Smombi : public Monster
{
public:
	Smombi(string n = "½º¸öºñ", string i = "¥â", int x = 0, int y = 0)
		:Monster(n, i, x, y) {}
	~Smombi() { cout << " Smombi "; }

	void move(int** map, int maxx, int maxy)
	{
		int dir = rand() % 4;
		if (dir == 0)
		{
			x--;
			y--;
		}
		else if (dir == 1)
		{
			x--;
			y++;
		}
		else if (dir == 2)
		{
			x++;
			y--;
		}
		else
		{
			x++;
			y++;
		}
		clip(maxx, maxy);
		eat(map);
	}
};

class Sianshi : public Jiangshi
{
	int timer = 0;


public:
	Sianshi(string n = "¼öÆÛ °­½Ã", string i = "¢²", int x = 0, int y = 0, bool bH = true)
		: Jiangshi(n, i, x, y) 
	{
		bHori = bH;
	}
	~Sianshi() { cout << " Sianshi "; }

	void move(int** map, int maxx, int maxy) 
	{
		int dir = rand() % 2;
		int jump = rand() % 2 + 1;

		if (bHori)
		{
			x += ((dir == 0) ? -jump : jump);
			if (timer == 10)
			{
				timer = 0;
				bHori = false;
			}
			else timer += 1;
		}

		else
		{
			y += ((dir == 0) ? -jump : jump);
			if (timer == 10)
			{
				timer = 0;
				bHori = true;
			}
			else timer += 1;

		}
		clip(maxx, maxy);
		eat(map);
	}
		

};

class Minje : public Vampire
{
public:
	Minje(string n = "¹ÎÁ¦¸ó½ºÅÍ", string i = "¢£", int x = 0, int y = 0)
		: Vampire(n, i, x, y) {}
	~Minje() { cout << " Minje "; }

	void move(int** map, int maxx, int maxy)
	{
		int dir = rand() % 4;
		if (dir == 0)
		{
			x = x - 1;
			y = y - 3;
		}
		else if (dir == 1)
		{
			x = x - 1;
			y = y + 3;
		}
		else if (dir == 2)
		{
			x = x + 1;
			y = y - 3;
		}
		else
		{
			x = x + 1;
			y = y + 3;
		}
		clip(maxx, maxy);
		eat(map);
	}
};
