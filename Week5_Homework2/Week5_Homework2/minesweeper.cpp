#include "minesweeper.h"
#define DIM 9

enum labeltype {empty = 0, bomb = 9};
enum masktype {hide = 0, open, flag};

static int minemap_mask[40][80];
static int minemap_label[40][80];
static int num_x = DIM, num_y = DIM;
static int num_bomb = DIM;

inline int& mask(int x, int y) { return minemap_mask[y][x]; }
inline int& label(int x, int y) { return minemap_label[y][x]; }
inline bool isvalid(int x, int y) { return (x >= 0 && x < num_x && y >= 0 && y < num_y); }
inline bool isbomb(int x, int y) { return isvalid(x, y) && label(x, y) == bomb; }
inline bool isempty(int x, int y) { return isvalid(x, y) && label(x, y) == empty; }

static void dig(int x, int y)
{
	if (isvalid(x, y) && mask(x, y) != open)
	{
		mask(x, y) = open;
		if (label(x, y) == 0) // 값이 0 이기 때문에 주위의 것들도 판다.
		{
			dig(x-1, y-1);
			dig(x-1, y);
			dig(x-1, y+1);
			dig(x, y-1);
			dig(x, y+1);
			dig(x+1, y-1);
			dig(x+1, y);
			dig(x+1 , y+1);
		}
	}
}

static void mark(int x, int y)
{
	if (isvalid(x, y) && mask(x, y) == hide)
		mask(x, y) = flag;
}

static int getbombcount()  // 마크한 깃발의 개수
{
	int count = 0;
	for (int y = 0; y < num_y; y++)
	{
		for (int x = 0; x < num_x; x++)
		{
			if (mask(x, y) == flag) count++;
		}
	}
	return count;
}

static void print()
{
	system("cls");
	printf("   발견:%2d   전체:%2d\n", getbombcount(), num_bomb);
	printf("\n   ");
	for (int x = 0; x < num_x; x++)
	{
		printf("%2d", x + 1);
	}
	printf("\n");

	for (int y = 0; y < num_y; y++) {
		printf("%2d ", y+1);
		for (int x = 0; x < num_x; x++) 
		{
			if (mask(x, y) == hide)	printf("□");		
			else if (mask(x, y) == flag) printf("¤");	
			else {									
				if (isbomb(x, y)) printf("※");		
				else if (isempty(x, y)) printf("  ");	
				else printf("%2d", label(x, y));		
			}
		}
		printf("\n");
	}
}

static int count_num_bombs(int x, int y)
{
	int count = 0;
	for (int yy = y - 1; yy <= y + 1; yy++)
	{
		for (int xx = x - 1; xx <= x + 1; xx++)
		{
			if (isvalid(xx, yy) && label(xx, yy) == bomb)
			{
				count++;
			}
		}
	}
	return count;
}

static void init(int total = 9)
{
	srand((unsigned int)time(NULL));
	for (int y = 0; y < num_y; y++)
		for (int x = 0; x < num_x; x++) 
		{			
			mask(x, y) = hide;
			label(x, y) = 0;
		}

	num_bomb = total;

	for (int i = 0; i < num_bomb; i++) 
	{
		int x, y;
		do {
			x = rand() % num_x;
			y = rand() % num_y;
		} while (label(x, y) != empty);
		label(x, y) = bomb;
	}

	for (int y = 0; y < num_y; y++)			
		for (int x = 0; x < num_x; x++)
			if (label(x, y) == empty)
				label(x, y) = count_num_bombs(x, y);

}

static bool getpos(int& x, int& y)
{
	printf("\n지뢰(P)행()열()\n 입력 --> ");
	bool isbomb = false;

	y = toupper(_getche()) - '1';
	if (y == 'P' - '1')
	{
		isbomb = true;
		y = _getch() - '1';
	}

	x = _getch() - '1';
	return isbomb;
}

static int checkdone()
{
	int count = 0;
	for (int y = 0; y < num_y; y++)
	{
		for (int x = 0; x < num_x; x++)
		{
			if (mask(x, y) != open) count++;
			else if (isbomb(x, y)) return -1;
		}
	}
	return (count == num_bomb) ? 1 : 0;
}

void playminesweeper(int total, int width, int height)
{
	num_x = width;
	num_y = height;
	int x, y, status;
	init(total);
	do {
		print();
		bool isbomb = getpos(x, y);
		if (isbomb) mark(x, y);
		else dig(x, y);
		status = checkdone();
	} while (status == 0);

	print();
	if (status < 0)
		printf("\n 실패 : 지뢰가 폭발하였습니다!\n\n");
	else printf("\n 성공 : 지뢰를 전부 찾았습니다\n\n");
}