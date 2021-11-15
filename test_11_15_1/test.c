#define _CRT_SECURE_NO_WARNINGS

#include"SlinkList.h" 

int main()
{
	PNODE pHead = NULL;
	pHead = create_list();
	traverse_list(pHead);

	sort_list(pHead);
	traverse_list(pHead);
	return 0;
}

