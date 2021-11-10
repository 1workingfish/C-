#define _CRT_SECURE_NO_WARNINGS

#include "contact.h"

//��ʼ���ṹ������
void InitContact(struct Contact* ps)
{
	ps->date = (struct PeoInfo*)malloc(3 * sizeof(struct PeoInfo));
	if (ps->date == NULL)
	{
		return;
	}
	ps->size = 0;
	ps->capacity = DEFAULT_SZ;

	LoadContact(ps);
}
//��������
void CheckCapacity(struct Contact* ps);
//��ȡ�ļ�����
void LoadContact(struct Contact* ps)
{
	struct PeoInfo tmp = { 0 };
	FILE* pfread = fopen("contact.dat", "rb");
	if (pfread == NULL)
	{
		printf("%s\n", strerror(errno));
		return;
	}
	while (fread(&tmp, sizeof(struct PeoInfo), 1, pfread))
	{
		CheckCapacity(ps);
		ps->date[ps->size] = tmp;
		ps->size++;
	}
	fclose(pfread);
	pfread = NULL;
}
//���ͨѶ¼����
void CheckCapacity(struct Contact* ps)
{
	if (ps->size == ps->capacity)
	{
		struct PeoInfo* ptr = realloc(ps->date, (ps->capacity + 2) * sizeof(struct PeoInfo));
		if (ptr != NULL)
		{
			ps->date = ptr;
			ps->capacity += 2;
			printf("���ݳɹ�\n");
		}
		else
		{
			printf("����ʧ��\n");
		}

	}
}
void AddContact(struct Contact* ps)
{
	CheckCapacity(ps);


	printf("������������");
	scanf("%s", ps->date[ps->size].name);
	printf("���������䣺");
	scanf("%d", &(ps->date[ps->size].age));
	printf("�������Ա�");
	scanf("%s", ps->date[ps->size].sex);
	printf("������绰��");
	scanf("%s", ps->date[ps->size].tele);
	printf("�������ַ��");
	scanf("%s", ps->date[ps->size].addr);

	ps->size++;
	printf("��ӳɹ�\n");

/*	if (ps->size == MAX)
	{
		printf("ͨѶ¼����\n");
	}
	else
	{
		printf("������������");
		scanf("%s", ps->date[ps->size].name);
		printf("���������䣺");
		scanf("%d", &(ps->date[ps->size].age));
		printf("�������Ա�");
		scanf("%s", ps->date[ps->size].sex);
		printf("������绰��");
		scanf("%s", ps->date[ps->size].tele);
		printf("�������ַ��");
		scanf("%s", ps->date[ps->size].addr);

		ps->size++;
		printf("��ӳɹ�\n");
	}*/	
}
//չʾ����Ԫ�ص���Ϣ
void ShowContact(const struct Contact* ps)
{
	if (ps->size == 0)
	{
		printf("ͨѶ¼Ϊ��\n");
	}
	else
	{
		int i = 0;
		printf("%-20s\t%-4s\t%-5s\t%-12s\t%-30s\n", "����", "����","�Ա�","�绰", "��ַ");
			for (i = 0; i < ps->size; i++)
			{
				printf("%-20s\t%-4d\t%-5s\t%-12s\t%-30s\n",
					ps->date[i].name,
					ps->date[i].age,
					ps->date[i].sex,
					ps->date[i].tele,
					ps->date[i].addr);
			}
	}
	
}
//����Ԫ�ص�λ��
static int Fine_By_Name(char name[MAX_NAME],struct Contact* ps)
{
	int i = 0;
	for (i = 0; i < ps->size; i++)
	{
		if (0 == (strcmp(name, ps->date[i].name)))
		{
			return i;
		}
	}
	return -1;
}
//ɾ��Ԫ��
void DelContact(struct Contact* ps)
{
	char name[MAX_NAME];
	printf("������Ҫɾ��������\n");
	scanf("%s", &name);
	int ret=Fine_By_Name(name,ps);
	if (ret == -1)
	{
		printf("δ�ҵ�������\n");
	}
	else
	{
		int i = 0;
		for (i = ret; i < ps->size-1; i++)
		{
			ps->date[i] = ps->date[i + 1];
		}
		ps->size--;
		printf("ɾ���ɹ�\n");
	}
}
//����Ԫ��
void SearchContact(struct Contact* ps)
{
	char name[MAX_NAME];
	printf("������Ҫ���ҵ�����\n");
	scanf("%s", &name);
	int ret=Fine_By_Name(name, ps);
	if (ret == -1)
	{
		printf("δ�ҵ�������\n");
	}
	else
	{
		printf("%-20s\t%-4s\t%-5s\t%-12s\t%-30s\n", "����", "����", "�Ա�", "�绰", "��ַ");
		printf("%-20s\t%-4d\t%-5s\t%-12s\t%-30s\n",
			ps->date[ret].name,
			ps->date[ret].age,
			ps->date[ret].sex,
			ps->date[ret].tele,
			ps->date[ret].addr);
	}
}
//�޸�Ԫ�ص�����
void ModifyContact(struct Contact* ps)
{
	char name[MAX_NAME];
	printf("������Ҫ�޸��˵�����\n");
	scanf("%s", &name);
	int ret = Fine_By_Name(name, ps);
	if (ret == -1)
	{
		printf("Ҫ�޸��˵�����������\n");
	}
	else
	{
		printf("�������޸ĺ��������");
		scanf("%s", ps->date[ret].name);
		printf("�������޸ĺ�����䣺");
		scanf("%d", &(ps->date[ret].age));
		printf("�������޸ĺ���Ա�");
		scanf("%s", ps->date[ret].sex);
		printf("�������޸ĺ�ĵ绰��");
		scanf("%s", ps->date[ret].tele);
		printf("�������޸ĺ�ĵ�ַ��");
		scanf("%s", ps->date[ret].addr);
	}
}
void SortContact(struct Contact* ps)
{
	int i = 0;
 // int j = 0;
 // for(i = 0 ; i < ps->size ; i++)
 //{
	//     for (j = 0; j < ps->size - i; j++)
	//         {
	//	        int ret = strcmp((ps->date + j).name, ps->date + j + 1.name);
	//	        if (ret == 1)
	//	           {
	//	            	ps->date[ps->size + 1] = ps->date[i];
	//	             	ps->date[i] = ps->date[i + 1];
	//		            ps->date[i + 1] = ps->date[ps->size + 1];
	//	            	memset(ps->date + ps->size + 1, 0, sizeof(ps->date[0]));
	//	            }
	//          }
 //}
	printf("%-20s\t%-4s\t%-5s\t%-12s\t%-30s\n", "����", "����", "�Ա�", "�绰", "��ַ");
	for (i = 0; i < ps->size; i++)
	{
		printf("%-20s\t%-4d\t%-5s\t%-12s\t%-30s\n",
			ps->date[i].name,
			ps->date[i].age,
			ps->date[i].sex,
			ps->date[i].tele,
			ps->date[i].addr);
	}
}
void DestroyContact(struct Contact* ps)
{
	free(ps->date);
	ps->date = NULL;
}
void SaveContact(struct Contact* ps)
{
	FILE* pfwrite = fopen("contact.dat", "wb");
	if (pfwrite == NULL)
	{
		printf("%s\n", strerror(errno));
		return;
	}
	int i = 0;
	for (i = 0; i < ps->size; i++)
	{
		fwrite(&(ps->date[i]), sizeof(struct PeoInfo), 1, pfwrite);
	}
	fclose(pfwrite);
	pfwrite = NULL;
}