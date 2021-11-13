#define _CRT_SECURE_NO_WARNINGS

#include"ArrayList.h"

//void init_arr();初始化数组
//bool append_arr();追加
//bool insert_arr();插入
//bool delete_arr();删除
//int get();获取
//bool is_empty();是否为空
//bool is_full();是否为满
//void sort_arr();排序数组
//void show_arr();打印数组
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
	//	printf("追加成功\n");
	//}
	//else
	//{
	//	printf("追加失败\n");
	//}
	//show_arr(&arr);
	return 0;
}