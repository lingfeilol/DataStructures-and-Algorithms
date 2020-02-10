#include "Heap.h"
int main()
{
	Heap hp;
	int arr[] = {1,2,3,4,5,6,7,8,9,0};
	int len = sizeof(arr) / sizeof(int);
	HeapCreate(&hp, arr, len);
	HeapPrintf(&hp);

	HeapPush(&hp, 16);//插入一个元素
	HeapPrintf(&hp);
	printf("堆顶元素：%d \n", HeapTop(&hp));
	printf("堆里的元素个数：%d\n", HeapSize(&hp));

	HeapSort(arr,len);//对数组进行堆排序 升序
	for (int i = 0; i < len; i++)
	{
		printf("%d ", arr[i]);
	}
	return 0;
}