#define _CRT_SECURE_NO_WARNINGS

#include "contact.h"

void meun()
{
	printf("*********************************\n");
	printf("****  1.add       2.del      ****\n");
	printf("****  3.search    4.modify   ****\n");
	printf("****  5.show      6.sort     ****\n");
	printf("****  7.save      0.exit     ****\n");
	printf("*********************************\n");
}
enum en
{
	EXIT,
	ADD,
	DEL,
	SEARCH,
	MODIFY,
	SHOW,
	SORT,
	SAVE
};
int main()
{
	//创建通讯录容量为1000
	struct Contact con;
	//初始化通讯录
	InitContact(&con);

	int input = 0;
	do 
	{
		meun();
		printf("请输入->");
		scanf("%d", &input);
		switch (input)
		{
		case ADD:
			AddContact(&con);
			break;		
		case DEL:
			DelContact(&con);
			break;
		case SEARCH:
			SearchContact(&con);
			break;
		case MODIFY:
			ModifyContact(&con);
			break;
		case SHOW:
			ShowContact(&con);
			break;
		case SORT:
			//SortContact(&con);
			break;
		case SAVE:
			SaveContact(&con);
			break;
		case EXIT:
			SaveContact(&con);
			DestroyContact(&con);
			printf("退出通讯录\n");
			break;
		default:
			printf("输入信息有误，请重新输入\n");
		}
	} while (input);
	return 0;
}