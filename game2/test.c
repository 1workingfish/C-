#define _CRT_SECURE_NO_WARNINGS


#include "game.h"
void game()
{
	char mine[ROWS][COLS] = { 0 };
	char show[ROWS][COLS] = { 0 };
	//��ʼ������
	//ȫ����0  row*col
	InitBoard(mine,ROWS,COLS,'0');
	//ȫ����*  row*col
	InitBoard(show,ROWS,COLS,'*');
	//��ӡ����  ֻ��ӡ��ʾ�Ĳ���
	DisplayBoard(show,ROW,COL);
	//DisplayBoard(mine,ROW,COL);
	//������  ���������
	SetMine(mine, ROW, COL);
	//DisplayBoard(mine, ROW, COL);
	//ɨ��
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
		printf("��ѡ�񣺡�");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			game();
			break;
		case 0:
			printf("�˳���Ϸ\n");
			break;
		default:
			printf("ѡ������������ѡ�񣡣�\n");
			break;
		}
	} while (input);
}
int main()
{
	test();
	return 0;
}