#pragma once

#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>

typedef int bool;

#define true 1
#define false 0


typedef struct Array
{
	int* pbase;//数组首元素的地址
	int len;//数组所能容纳的最大元素的个数
	int cnt;//当前数组有效元素的个数
}array;

//声明函数
void init_arr(array* parray,int length);//初始化元素并创建动态空间
void show_arr(array* parray);//打印元素
bool is_empty(array* parray);//判断是否为空
bool is_full(array* parray);//判断是否为满
bool append_arr(array* parray, int val);//追加元素
bool insert_arr(array* parray, int pos, int val);//插入元素
int get(array* parray,int pos);//获取元素
bool delete_arr(array* parray, int pos,int* val);//删除元素并返回删除元素的值
void sort_arr(array* parray);//排序数组
void inversion_arr(array* parray);//逆序数组