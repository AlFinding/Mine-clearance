#define _CRT_SECURE_NO_WARNINGS
#include"game2.h"

void menu()
{
	printf("****************************\n");
	printf("***********1.play***********\n");
	printf("***********2.quit***********\n");
	printf("****************************\n");
}

void game()
{
	int boob[ROW][ROW] = { 0 };//雷盘
	char board[ROW][ROW] = { 0 };//视盘
	
	initboard(boob,board,ROW);//初始化棋盘
	prboard(board,ROW);//打印棋盘
    //prboard(boob,ROW);//答案
	int x = 1;
	int y = 1;
	while (x&&y)
	{
		y =choose(boob, board, ROW);//扫雷
		x = judge(board, ROW);//判断获胜
	}
}


int main()
{
	srand((unsigned int)time(NULL));
	int a = 0;
	do
	{
		menu();
		scanf_s("%d", &a);
		switch (a)
		{
		case 1:
			game();
			break;
		case 0:
			printf("退出游戏");
			break;
		default:
			printf("输入错误，重新输入\n");
			break;
		}
	} while (a);

	return 0;
}