#define _CRT_SECURE_NO_WARNINGS 

#include <stdio.h>

void menu()
{
	printf("#######################\n");
	printf("####1.play   0.exit####\n");
	printf("#######################\n");
}
void test()
{
	int input = 0;
	do
	{
		menu();
		printf("��ѡ�񡪡���");
		scanf_s("%d", input);
		switch(input)
		{
		case 1:
			break;
		case 0:
	        {
			printf("�˳���Ϸ\n");
			break;
		     }
		default:
		    {
			printf("ѡ�����������ѡ�񣡣�");
			break;
            }
		}
	} while (input);
}
int main()
{
	test();
	return 0;
}