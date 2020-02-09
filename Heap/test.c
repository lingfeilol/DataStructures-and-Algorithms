#include "Heap.h"


int main()
{
	Heap hp;
	int arr[] = { 1, 8, 5, 3, 4, 9, 7, 2, 0, 6 };
	int len = sizeof(arr) / sizeof(int);
	HeapCreate(&hp, arr, len);
	HeapPrintf(&hp);

	//HeapPush(&hp, 16);//����һ��Ԫ��
	//HeapPrintf(&hp);
	printf("�Ѷ�Ԫ�أ�%d \n", HeapTop(&hp));
	printf("�����Ԫ�ظ�����%d\n", HeapSize(&hp));
	HeapSort(arr,len);//��������ж����� ����
	for (int i = 0; i < len; i++)
	{
		printf("%d ", arr[i]);
	}
	return 0;
}