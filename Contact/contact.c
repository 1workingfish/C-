#define _CRT_SECURE_NO_WARNINGS

#include "contact.h"

//初始化结构体内容
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
//声明函数
void CheckCapacity(struct Contact* ps);
//读取文件内容
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
//添加通讯录内容
void CheckCapacity(struct Contact* ps)
{
	if (ps->size == ps->capacity)
	{
		struct PeoInfo* ptr = realloc(ps->date, (ps->capacity + 2) * sizeof(struct PeoInfo));
		if (ptr != NULL)
		{
			ps->date = ptr;
			ps->capacity += 2;
			printf("增容成功\n");
		}
		else
		{
			printf("增容失败\n");
		}

	}
}
void AddContact(struct Contact* ps)
{
	CheckCapacity(ps);


	printf("请输入姓名：");
	scanf("%s", ps->date[ps->size].name);
	printf("请输入年龄：");
	scanf("%d", &(ps->date[ps->size].age));
	printf("请输入性别：");
	scanf("%s", ps->date[ps->size].sex);
	printf("请输入电话：");
	scanf("%s", ps->date[ps->size].tele);
	printf("请输入地址：");
	scanf("%s", ps->date[ps->size].addr);

	ps->size++;
	printf("添加成功\n");

/*	if (ps->size == MAX)
	{
		printf("通讯录已满\n");
	}
	else
	{
		printf("请输入姓名：");
		scanf("%s", ps->date[ps->size].name);
		printf("请输入年龄：");
		scanf("%d", &(ps->date[ps->size].age));
		printf("请输入性别：");
		scanf("%s", ps->date[ps->size].sex);
		printf("请输入电话：");
		scanf("%s", ps->date[ps->size].tele);
		printf("请输入地址：");
		scanf("%s", ps->date[ps->size].addr);

		ps->size++;
		printf("添加成功\n");
	}*/	
}
//展示所有元素的信息
void ShowContact(const struct Contact* ps)
{
	if (ps->size == 0)
	{
		printf("通讯录为空\n");
	}
	else
	{
		int i = 0;
		printf("%-20s\t%-4s\t%-5s\t%-12s\t%-30s\n", "姓名", "年龄","性别","电话", "地址");
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
//查找元素的位置
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
//删除元素
void DelContact(struct Contact* ps)
{
	char name[MAX_NAME];
	printf("请输入要删除的名字\n");
	scanf("%s", &name);
	int ret=Fine_By_Name(name,ps);
	if (ret == -1)
	{
		printf("未找到该名字\n");
	}
	else
	{
		int i = 0;
		for (i = ret; i < ps->size-1; i++)
		{
			ps->date[i] = ps->date[i + 1];
		}
		ps->size--;
		printf("删除成功\n");
	}
}
//查找元素
void SearchContact(struct Contact* ps)
{
	char name[MAX_NAME];
	printf("请输入要查找的名字\n");
	scanf("%s", &name);
	int ret=Fine_By_Name(name, ps);
	if (ret == -1)
	{
		printf("未找到该名字\n");
	}
	else
	{
		printf("%-20s\t%-4s\t%-5s\t%-12s\t%-30s\n", "姓名", "年龄", "性别", "电话", "地址");
		printf("%-20s\t%-4d\t%-5s\t%-12s\t%-30s\n",
			ps->date[ret].name,
			ps->date[ret].age,
			ps->date[ret].sex,
			ps->date[ret].tele,
			ps->date[ret].addr);
	}
}
//修改元素的内容
void ModifyContact(struct Contact* ps)
{
	char name[MAX_NAME];
	printf("请输入要修改人的姓名\n");
	scanf("%s", &name);
	int ret = Fine_By_Name(name, ps);
	if (ret == -1)
	{
		printf("要修改人的姓名不存在\n");
	}
	else
	{
		printf("请输入修改后的姓名：");
		scanf("%s", ps->date[ret].name);
		printf("请输入修改后的年龄：");
		scanf("%d", &(ps->date[ret].age));
		printf("请输入修改后的性别：");
		scanf("%s", ps->date[ret].sex);
		printf("请输入修改后的电话：");
		scanf("%s", ps->date[ret].tele);
		printf("请输入修改后的地址：");
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
	printf("%-20s\t%-4s\t%-5s\t%-12s\t%-30s\n", "姓名", "年龄", "性别", "电话", "地址");
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