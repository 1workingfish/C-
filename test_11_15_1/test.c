#define _CRT_SECURE_NO_WARNINGS

#include"SlinkList.h" 

int main()
{
	PNODE pHead = NULL;
	pHead = create_list();
	traverse_list(pHead);
	int i = is_empty(pHead);
	if (i == 1)
	{
		printf("链表为空\n");
	}
	else
	{
		printf("链表不为空\n");
	}
	/*insert_list(pHead, 2, 5);
	traverse_list(pHead);
	sort_list(pHead);
	delete_list(pHead, 4);
	traverse_list(pHead);*/
	return 0;
}

