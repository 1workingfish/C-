#define _CRT_SECURE_NO_WARNINGS

#include"List.h"
void menu()
{
	printf("###############################\n");
	printf("#####  1.add        2.del  ####\n");
	printf("#####  3.get        4.shot#####\n");
	printf("###############################\n");
}
enum list
{
	exit,
	add,
	del,
	get,
	shot,
	size
};
int main()
{
	int arr[MAXSIZE] = {0};
	int input = 0;
	InitList(arr);
	int sz = 0;
	do
	{
		menu();
		printf("请输入操作选项\n");
		scanf("%d", &input);
		switch(input)
		{
		case add:
			AddList(arr,&sz);
			break;
		case del:
			DelList(arr,&sz);
			break;
		case get:
			GetList(arr,&sz);
			break;
		case shot:
			ShotList(arr,&sz);
			break;
		case size:
			printf("%d\n",sz);
			break;
		case exit:
			break;
		default:
			printf("请重新选择\n");
			break;
		}
	} while (input);
	return 0;
}