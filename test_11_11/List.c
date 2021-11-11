#define _CRT_SECURE_NO_WARNINGS

#include"List.h"

void InitList(int* arr)
{
	int i = 0;
	for (i = 0; i < MAXSIZE; i++)
	{
		arr[i] = 0;
	}
}
void AddList(int* arr,int* sz)
{
	int a = 0;
	printf("请输入要添加的数字\n");
	scanf("%d", &a);
	if (*sz > MAXSIZE)
	{
		return;
	}
	arr[*sz] = a;
	(*sz)++;
	printf("添加成功\n");
}

void DelList(int* arr,int* sz)
{
	int a = 0;
	printf("请输入要删除的数字\n");
	scanf("%d", &a);
	int i = 0;
	for (i = 0; i < *sz; i++)
	{
		if (arr[i] == a)
		{
			arr[i] = 0;
			int j = 0;
			for (j = i; j < *sz; j++)
			{
				arr[j] = arr[j + 1];
			}
			(*sz)--;
		}
		if (i >= *sz)
		{
			printf("未找到该数字\n");
		}
	}
}
void GetList(int* arr,int* sz)
{
	int a = 0;
	printf("请输入要查找的数字\n");
	scanf("%d", &a);
	int i = 0;
	for (i = 0; i > *sz; i++)
	{
		if (arr[i] == a)
		{
			printf("找到该数字，数字的下标为:%d\n", i);
		}
		if (i >= *sz)
		{
			printf("未找到该数字\n");
		}
	}
}
void ShotList(int* arr,int* sz)
{
	int a = 0;
	printf("请输入要修改的数字\n");
	scanf("%d", &a);
	int i = 0;
	for (i = 0; i < *sz; i++)
	{
		if (arr[i] == a)
		{
			int b = 0;
			printf("请输入修改的数字\n");
			scanf("%d", &b);			
			arr[i] = b;
		}
		if (i >= *sz)
		{
			printf("未找到要修改的数字\n");
		}
	}
}