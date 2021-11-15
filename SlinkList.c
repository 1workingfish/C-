#define _CRT_SECURE_NO_WARNINGS

#include"SlinkList.h"

PNODE create_list(void)
{
	int len;
	int i = 0;
	int val;
	PNODE pHead = (PNODE)malloc(sizeof(NODE));
	if (pHead == NULL)
	{
		printf("%s\n", strerror(errno));
	}
	PNODE ptail = pHead;
	ptail->pNext = NULL;
	printf("请输入要创建的节点个数\n");
	scanf("%d",&len);
	for (i = 0; i < len; i++)
	{
		printf("请输入第%d个节点的值\n", i + 1);
		scanf("%d",&val);
		PNODE pNew = (PNODE)malloc(sizeof(NODE));
		if (pNew == NULL)
		{
			printf("%s\n", strerror(errno));
		}
		pNew->date = val;
		ptail->pNext = pNew;
		pNew->pNext = NULL;
		ptail = pNew;
	}
	return pHead;
}

void traverse_list(PNODE pHead)
{
	PNODE p = pHead->pNext;
	while (p != NULL)
	{
		printf("%d ", p->date);
		p = p->pNext;
	}
	printf("\n");
}

bool is_empty(PNODE pHead)
{
	if (pHead->pNext == NULL)
	{
		return true;
	}
	else
	{
		return false;
	}
}

int length_list(PNODE pHead)
{
	PNODE p = pHead->pNext;
	int i = 0;
	while (p != NULL)
	{
		i++;
		p = p->pNext;
	}
	return i;
}

bool insert_list(PNODE pHead,int pos,int val)
{
	PNODE p = pHead->pNext;
	int i = 0;
	for (i = 0; i < pos; i++)
	{
		p = p->pNext;
	}
	PNODE pNew = (PNODE)malloc(sizeof(NODE));
	if (pNew == NULL)
	{
		printf("%s\n", strerror(errno));
		return false;
	}
	PNODE pn = p->pNext;
	p->pNext = pNew;
	pNew->date = val;
	pNew->pNext = pn;
	return true;
}

bool delete_list(PNODE pHead, int pos)
{
	PNODE p = pHead->pNext;
	int i = 0;
	for (i = 0; i < pos - 1; i++)
	{
		p = p->pNext;
	}
	PNODE pd = p->pNext;
	p->pNext = pd->pNext;
	return true;
}

void sort_list(PNODE pHead)
{
	int i = 0;
	int j = 0;
	int tmp = 0;
	PNODE p ;
	PNODE q ;
	for (i = 0, p = pHead->pNext; i < length_list(pHead)-1; i++, p = p->pNext)
	{
		for (j = i + 1, q = p->pNext; j < length_list(pHead); j++, q = q->pNext)
		{	
			if (p->date > q->date)
			{
				tmp = p->date;
				p->date = q->date;
				q->date = tmp;
			}	
		}	
	}
}