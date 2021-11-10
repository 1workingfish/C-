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

//����ͨѶ¼����
struct PeoInfo
{
	char name[MAX_NAME];
	int age;
	char sex[MAX_SEX];
	char tele[MAX_TELE];
	char addr[MAX_ADDR];
};
//��ʼ��ͨѶ¼
struct Contact
{
	struct PeoInfo *date;
	int size;
	int capacity;
};
//��������
void InitContact(struct Contact* ps);
//���ͨѶ¼Ԫ����Ϣ
void AddContact(struct Contact* ps);
//չʾͨѶ¼Ԫ����Ϣ
void ShowContact(const struct Contact* ps);
//ɾ��ͨѶ¼Ԫ����Ϣ
void DelContact(struct Contact* ps);
//����ͨѶ¼Ԫ����Ϣ
void SearchContact(struct Contact* ps);
//�޸�ͨѶ¼Ԫ����Ϣ
void ModifyContact(struct Contact* ps);
//����ͨѶ¼Ԫ����Ϣ
//void SortContact(struct Contact* ps);
//�ͷſռ�
void DestroyContact(struct Contact* ps);
//�����ļ�����ͨѶ¼Ԫ����Ϣ
void SaveContact(struct Contact* ps);
//��ȡ�ļ���ͨѶ¼��Ԫ����Ϣ
void LoadContact(struct Contact* ps);