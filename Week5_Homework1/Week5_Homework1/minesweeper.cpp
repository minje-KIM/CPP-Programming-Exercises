#include "minesweeper.h"
#define DIM 9

enum labeltype {empty = 0, bomb = 9};
enum masktype {hide = 0, open, flag};

static int minemap_mask[DIM][DIM];
static int minemap_label[DIM][DIM];
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
		if (label(x, y) == 0) // ���� 0 �̱� ������ ������ �͵鵵 �Ǵ�.
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

static int getbombcount()  // ��ũ�� ����� ����
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
	printf("   �߰�:%2d   ��ü:%2d\n", getbombcount(), num_bomb);
	printf("   ����������\n");
	for (int y = 0; y < num_y; y++) {
		printf("%2c ", 'A' + y);
		for (int x = 0; x < num_x; x++) {
			if (mask(x, y) == hide)	printf("��");		
			else if (mask(x, y) == flag) printf("��");	
			else {									
				if (isbomb(x, y)) printf("��");		
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
	printf("\n����(P)��(A-I)��(1-9)\n �Է� --> ");
	bool isbomb = false;

	y = toupper(_getch()) - 'A';
	if (y == 'P' - 'A')
	{
		isbomb = true;
		y = toupper(_getch()) - 'A';
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

void playminesweeper(int total)
{
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
		printf("\n ���� : ���ڰ� �����Ͽ����ϴ�!\n\n");
	else printf("\n ���� : ���ڸ� ���� ã�ҽ��ϴ�\n\n");
}