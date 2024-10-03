#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>//standard input and output
#include<time.h>
#include<stdlib.h>//standard library
#define ROW 11
#define BOOB 10

void initboard(char a[ROW][ROW],char board[ROW][ROW],int row);

void prboard(char board[ROW][ROW],int row);

int choose(char a[ROW][ROW], char b[ROW][ROW],int row);

int check(int x, int y);

void unfold(char boob[ROW][ROW], char board[ROW][ROW], int x, int y);

int judge(char boob[ROW][ROW], int x);