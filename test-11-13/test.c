#define _CRT_SECURE_NO_WARNINGS

#include"ArrayList.h"

//void init_arr();��ʼ������
//bool append_arr();׷��
//bool insert_arr();����
//bool delete_arr();ɾ��
//int get();��ȡ
//bool is_empty();�Ƿ�Ϊ��
//bool is_full();�Ƿ�Ϊ��
//void sort_arr();��������
//void show_arr();��ӡ����
//void inversion_arr();
int main()
{
	struct Array arr;
	init_arr(&arr, 6);

	append_arr(&arr, 1);
	append_arr(&arr, 5);
	append_arr(&arr, 62);
	append_arr(&arr, 56);
	append_arr(&arr, 2);
	insert_arr(&arr, 3, 78);
	//printf("%d\n", arr.cnt);
	//show_arr(&arr);
	sort_arr(&arr);
	show_arr(&arr);
	//if (i == 1)
	//{
	//	printf("׷�ӳɹ�\n");
	//}
	//else
	//{
	//	printf("׷��ʧ��\n");
	//}
	//show_arr(&arr);
	return 0;
}