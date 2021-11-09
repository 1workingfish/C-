#define _CRT_SECURE_NO_WARNINGS


#include "game.h"
void game()
{
	char mine[ROWS][COLS] = { 0 };
	char show[ROWS][COLS] = { 0 };
	//初始化界面
	//全部是0  row*col
	InitBoard(mine,ROWS,COLS,'0');
	//全部是*  row*col
	InitBoard(show,ROWS,COLS,'*');
	//打印界面  只打印显示的部分
	DisplayBoard(show,ROW,COL);
	//DisplayBoard(mine,ROW,COL);
	//布置雷  随机布置雷
	SetMine(mine, ROW, COL);
	//DisplayBoard(mine, ROW, COL);
	//扫雷
	FineMine(mine, show, ROW, COL);
}
void menu()
{
	printf("###########################\n");
	printf("####1. play   0. exit  ####\n");
	printf("###########################\n");
}
void test()
{
	int input = 0;
	srand((unsigned int)time(NULL));
	do
	{
		menu();
		printf("请选择：》");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			game();
			break;
		case 0:
			printf("退出游戏\n");
			break;
		default:
			printf("选择有误，请重新选择！！\n");
			break;
		}
	} while (input);
}
int main()
{
	test();
	return 0;
}