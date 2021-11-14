#define _CRT_SECURE_NO_WARNINGS

#include "ArrayList.h"

void init_arr(array* parray, int length)
{
	int* base = (int*)malloc(sizeof(int) * length);
	if (base != NULL)
	{
		parray->pbase = base;
	}
	parray->len = length;
	parray->cnt = 0;
}
void show_arr(array* parray)
{
	if (is_empty(parray) == 0)
	{
		printf("Êı×éÎª¿Õ\n");
	}
	else
	{
		int i = 0;
		for (i = 0; i < parray->cnt; i++)
		{
			printf("%d ", parray->pbase[i]);
		}
		printf("\n");
	}
}
bool is_empty(array* parray)
{
	if (parray->cnt == 0)
	{
		return false;
	}
	else
	{
		return true;
	}
}
bool is_full(array* parray)
{
	if (parray->cnt == parray->len)
	{
		return true;
	}
	else
	{
		return false;
	}
}
bool append_arr(array* parray, int val)
{
	if (is_full(parray) != 0)
	{
		return false;
	}
	else
	{
		parray->pbase[parray->cnt] = val;
		(parray->cnt)++;
		return true;
	}
}

bool insert_arr(array* parray, int pos, int val)
{
	if (is_full(parray))
	{
		return false;
	}
	if (pos<1 || pos>parray->cnt + 1)
	{
		return false;
	}
	int i = 0;
	for (i = parray->cnt; i > pos - 1; i--)
	{
		parray->pbase[i] = parray->pbase[i - 1];
	}
	parray->pbase[pos] = val;
	(parray->cnt)++;
	return true;
}

int get(array* parray,int pos)
{
	int i = 0;
	i = parray->pbase[pos + 1];
	return i;
}

bool delete_arr(array* parray, int pos,int* val)
{
	if (is_empty(parray) == 1)
	{
		return false;
	}
	if (pos<1 || pos>parray->cnt)
	{
		return false;
	}
	*val = parray->pbase[pos - 1];
	int i = 0;
	for (i = pos - 1; i < parray->cnt; i++)
	{
		parray->pbase[i] = parray->pbase[i + 1];
	}
	parray->pbase[parray->cnt] = 0;
	(parray->cnt)--;
	return true;
}

void sort_arr(array* parray)
{
	int i = 0;
	for (i = 0; i < parray->cnt - 1; i++)
	{
		int j = 0;
		for (j = i + 1; j < parray->cnt; j++)
		{
			if ((parray->pbase[i]) > (parray->pbase[j]))
			{
				int tmp = 0;
				tmp = parray->pbase[i];
				parray->pbase[i] = parray->pbase[j];
				parray->pbase[j] = tmp;
			}
		}
	}
}
void inversion_arr(array* parray)
{
	int i = 0;
	int j = parray->cnt - 1;
	int tmp = 0;
	while (i < j)
	{
		tmp = parray->pbase[i];
		parray->pbase[i] = parray->pbase[j];
		parray->pbase[j] = tmp;
		i++;
		j--;
	}
}