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
	int boob[ROW][ROW] = { 0 };//����
	char board[ROW][ROW] = { 0 };//����
	
	initboard(boob,board,ROW);//��ʼ������
	prboard(board,ROW);//��ӡ����
    //prboard(boob,ROW);//��
	int x = 1;
	int y = 1;
	while (x&&y)
	{
		y =choose(boob, board, ROW);//ɨ��
		x = judge(board, ROW);//�жϻ�ʤ
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
			printf("�˳���Ϸ");
			break;
		default:
			printf("���������������\n");
			break;
		}
	} while (a);

	return 0;
}