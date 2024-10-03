#define _CRT_SECURE_NO_WARNINGS
#include"game2.h"
void initboard(char boob[ROW][ROW], char board[ROW][ROW],int row)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < row; j++)
		{
			boob[i][j] = '0';
		}
	}

	for (i = 1; i < row-1; i++)
	{
		for (j = 1; j < row-1; j++)
		{
			board[i][j] = '*';
		}
	}
	//设置雷的个数
	for (i = 0; i < BOOB; i++)
	{
		int x = rand() % (row-1);
		int y = rand() % (row-1);
		if (x > 0 && y > 0 )
		{
			if (boob[x][y] == '0')
				boob[x][y] = '1';
			else
				i--;
		}
		else
			i--;
	}
}


void prboard(char board[ROW][ROW],int row)
{
	system("cls");
	int i = 0;
	int j = 0;
	printf("--------扫雷-------\n");
	for (j = 0; j < row - 1; j++)
	{
		printf("%d ", j);
	}
	printf("\n");

	for (i = 1; i < row - 1; i++)
	{
		printf("%d ", i);
		for (j = 1; j < row - 1; j++)
		{
			printf("%c ", board[i][j]);
		}
		printf("\n");
	}
}

int check(char boob[ROW][ROW],int x, int y)
{
	return(
		boob[x+1][y-1]+ boob[x+1][y] + 
		boob[x+1][y+1]+boob[x][y-1] + 
		boob[x][y+1] + boob[x-1][y-1] + 
		boob[x-1][y] + boob[x-1][y+1] - 8*'0'
		);
}

void unfold(char boob[ROW][ROW],char board[ROW][ROW],int x, int y)
{
	board[x][y] = ' ';
	int num = 0;
	/*if (board[x - 1][y] != ' '&& x - 1 < ROW-1 && x - 1>0)
	{
		num = check(boob, x - 1, y);
		if (num != 0)
			board[x - 1][y] = num + '0';
		else
			unfold(boob,board, x - 1, y);
	}

	if (board[x + 1][y] != ' ' && x + 1 < ROW-1 && x + 1 > 0)
	{
		num = check(boob, x + 1, y);
		if (num != 0)
			board[x + 1][y] = num + '0';
		else
			unfold(boob, board, x + 1, y);
	}

	if (board[x][y - 1] != ' ' && y - 1 < ROW-1 && y - 1 >0)
	{
		num = check(boob, x , y - 1);
		if (num != 0)
			board[x][y - 1] = num + '0';
		else
			unfold(boob, board, x , y -1 );
	}

	if (board[x][y + 1] != ' ' && y + 1 < ROW-1 && y + 1 > 0)
	{
		num = check(boob, x , y + 1);
		if (num != 0)
			board[x][y + 1] = num + '0';
		else
			unfold(boob, board, x , y + 1);
	}*/

	int i = 0;
	int j = 0;
	for (i = x - 1; i < x + 2 && i < ROW ; i++)
	{
		for (j = y - 1; j < y + 2 && j < ROW; j++)
		{
			if (board[i][j] != ' ' &&  i < ROW - 1 &&  i > 0 && j < ROW - 1 && j > 0)
			{
				int num = check(boob, i, j);
				if (num == 0)
				{
					board[i][j] = ' ';
					unfold(boob, board, i, j);
				}
				else
					board[i][j] = num + '0';
			}
		}
	}
}


int choose(char boob[ROW][ROW], char board[ROW][ROW],int row)
{
	printf("请扫雷》");
	int x = 0;
	int y = 0;
		scanf_s("%d %d", &x, &y);
		if (board[x][y] != '*')
		{
			printf("已排查过，请重新输入》");
		}
		else 
		{
			if (boob[x][y] == '1')
			{
				prboard(boob, ROW);
				printf("以上是雷位↑\n");
				printf("你在(%d %d)被炸死了！！！\n",x,y);
				return 0;
			}
			else
			{
				int num = check(boob, x, y);
				if (num != 0)
				{
					board[x][y] = num + '0';
					prboard(board, ROW);
				}
				else
				{
					unfold(boob, board, x, y);
					prboard(board, ROW);
				}
				return 1;
			}
		}
}

int judge(char board[ROW][ROW], int x)
{
	int num = 0;
	int i = 0;
	int j = 0;
	for (i = 1; i < x - 1; i++)
	{
		for (j = 1; j < x - 1; j++)
		{
			if (board[i][j] == '*')
				num++;
		}
	}
	if (num == 10)
	{
		printf("恭喜，扫雷成功！！！\n");
		return 0;
	}
	else
		return 1;
}