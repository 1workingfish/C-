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

//声明函数
PNODE create_list(void);//创建链表
void traverse_list(PNODE pHead);//遍历链表
bool is_empty(PNODE pHead);//判断链表是否为空
int length_list(PNODE pHead);//打印链表长度
bool insert_list(PNODE pHead,int pos,int val);//插入链表
bool delete_list(PNODE pHead, int pos,int* pval);//删除链表
void sort_list(PNODE pHead);//排序链表