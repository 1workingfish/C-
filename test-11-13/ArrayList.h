#pragma once

#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>

typedef int bool;

#define true 1
#define false 0


typedef struct Array
{
	int* pbase;//������Ԫ�صĵ�ַ
	int len;//�����������ɵ����Ԫ�صĸ���
	int cnt;//��ǰ������ЧԪ�صĸ���
}array;

//��������
void init_arr(array* parray,int length);
void show_arr(array* parray);
bool is_empty(array* parray);
bool is_full(array* parray);
bool append_arr(array* parray, int val);
bool insert_arr(array* parray, int pos, int val);
int get(array* parray,int pos);
bool delete_arr(array* parray, int pos);
void sort_arr(array* parray);