#define _CRT_SECURE_NO_WARNINGS

typedef int bool;
#define true 1;
#define false 0;

#include<stdio.h>
#include<string.h>
#include<errno.h>
#include<malloc.h>

typedef struct Node
{
	int date;
	struct Node* pNext;
}NODE,*PNODE;

//��������
PNODE create_list(void);//��������
void traverse_list(PNODE pHead);//��������
bool is_empty(PNODE pHead);//�ж������Ƿ�Ϊ��
int length_list(PNODE pHead);//��ӡ������
bool insert_list(PNODE pHead,int pos,int val);//��������
bool delete_list(PNODE pHead, int pos,int* pval);//ɾ������
void sort_list(PNODE pHead);//��������