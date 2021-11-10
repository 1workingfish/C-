#pragma once

//#define MAX 1000
#define DEFAULT_SZ 3

#define MAX_NAME 20
#define MAX_SEX 5
#define MAX_ADDR 12
#define MAX_TELE 30

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include<errno.h>

//定义通讯录内容
struct PeoInfo
{
	char name[MAX_NAME];
	int age;
	char sex[MAX_SEX];
	char tele[MAX_TELE];
	char addr[MAX_ADDR];
};
//初始化通讯录
struct Contact
{
	struct PeoInfo *date;
	int size;
	int capacity;
};
//声明函数
void InitContact(struct Contact* ps);
//添加通讯录元素信息
void AddContact(struct Contact* ps);
//展示通讯录元素信息
void ShowContact(const struct Contact* ps);
//删除通讯录元素信息
void DelContact(struct Contact* ps);
//查找通讯录元素信息
void SearchContact(struct Contact* ps);
//修改通讯录元素信息
void ModifyContact(struct Contact* ps);
//排序通讯录元素信息
//void SortContact(struct Contact* ps);
//释放空间
void DestroyContact(struct Contact* ps);
//利用文件保存通讯录元素信息
void SaveContact(struct Contact* ps);
//读取文件中通讯录的元素信息
void LoadContact(struct Contact* ps);