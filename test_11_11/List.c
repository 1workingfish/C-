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
	printf("������Ҫ��ӵ�����\n");
	scanf("%d", &a);
	if (*sz > MAXSIZE)
	{
		return;
	}
	arr[*sz] = a;
	(*sz)++;
	printf("��ӳɹ�\n");
}

void DelList(int* arr,int* sz)
{
	int a = 0;
	printf("������Ҫɾ��������\n");
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
			printf("δ�ҵ�������\n");
		}
	}
}
void GetList(int* arr,int* sz)
{
	int a = 0;
	printf("������Ҫ���ҵ�����\n");
	scanf("%d", &a);
	int i = 0;
	for (i = 0; i > *sz; i++)
	{
		if (arr[i] == a)
		{
			printf("�ҵ������֣����ֵ��±�Ϊ:%d\n", i);
		}
		if (i >= *sz)
		{
			printf("δ�ҵ�������\n");
		}
	}
}
void ShotList(int* arr,int* sz)
{
	int a = 0;
	printf("������Ҫ�޸ĵ�����\n");
	scanf("%d", &a);
	int i = 0;
	for (i = 0; i < *sz; i++)
	{
		if (arr[i] == a)
		{
			int b = 0;
			printf("�������޸ĵ�����\n");
			scanf("%d", &b);			
			arr[i] = b;
		}
		if (i >= *sz)
		{
			printf("δ�ҵ�Ҫ�޸ĵ�����\n");
		}
	}
}