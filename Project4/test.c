#define _CRT_SECURE_NO_WARNINGS

#include <assert.h>
#include<stdio.h>
void* my_memcpy(void* dest, const void* src, size_t count)
{
	char* ret = dest;
	assert(dest != NULL);
	assert(src != NULL);

	while (count--)
	{
		*(char*)dest = *(char*)src;
		++(char*)dest;
		++(char*)src;

	}
	return ret;
}
// void* my_memcpy_byte(void* dst, const void* src, int n)
//{
//     if (dst == NULL || src == NULL || n <= 0)
//         return NULL;
//
//     char* pdst = (char*)dst;
//     char* psrc = (char*)src;
//
//    if (pdst > psrc && pdst < psrc + n)
//     {
//        pdst = pdst + n - 1;
//        psrc = psrc + n - 1;
//        while (n--)
//            * pdst-- = *psrc--;
//     }
//     else
//     {
//         while (n--)
//             * pdst++ = *psrc++;
//     }
//     return dst;
//}
int main()
{
	//strlen �����ַ����ĳ���
	//strstr �������ַ���
	//strcat ׷���ַ���
	//strcmp �ַ����ıȽ�
	//strcpy �����ַ���
	//strtok �ָ��ַ���
	//strncpy ����һ�����ȵ��ַ���
	//strncmp �Ƚ�һ�����ȵ��ַ���
	//strncat ׷��һ�����ȵ��ַ���
	//memcpy �����ڴ�����������
	//memmove ����ʤ���ڴ���ص�����
	//memcmp �Ƚ��ڴ�����������
	//memset �ڴ�����
	

	int arr1[] = { 1,2,3,4,5 };
	int arr2[10] = { 0 };
	my_memcpy(arr2, arr1, sizeof(arr1));
    int i = 0;
    int sz = sizeof(arr2) / sizeof(arr2[0]);
    for(i=0;i<sz;i++)
    {
        printf("%d\n", arr2[i]);
    }

	return 0;
}