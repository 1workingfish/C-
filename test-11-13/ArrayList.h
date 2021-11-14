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
void init_arr(array* parray,int length);//��ʼ��Ԫ�ز�������̬�ռ�
void show_arr(array* parray);//��ӡԪ��
bool is_empty(array* parray);//�ж��Ƿ�Ϊ��
bool is_full(array* parray);//�ж��Ƿ�Ϊ��
bool append_arr(array* parray, int val);//׷��Ԫ��
bool insert_arr(array* parray, int pos, int val);//����Ԫ��
int get(array* parray,int pos);//��ȡԪ��
bool delete_arr(array* parray, int pos,int* val);//ɾ��Ԫ�ز�����ɾ��Ԫ�ص�ֵ
void sort_arr(array* parray);//��������
void inversion_arr(array* parray);//��������