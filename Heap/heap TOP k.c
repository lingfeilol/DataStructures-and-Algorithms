//堆这种数据结构的使用场景    TOP k问题：从一堆数据中选出最大或最小的K个数
//若是找最大的K个数 1.需要维护一个k个数据的小堆 
//2.从堆外第一个数据开始与堆顶数据比较，大于堆顶数据时，交换它们，这个大一点的数就进入这个堆结构里了，小的数换出去，然后维护这个堆，
//3.接着再下一个数据开始重复第二步的比较，直到这堆数据全部都比较完。

void PrintTopKMax(int* a, int n, int k)
{
	Heap hp;
	HeapCreate(&hp, a, k);//创建出要维护的k个大小的堆

   //因为堆初始化时用的向下调整建小堆，前k个数已经在堆里了
	//故从下标k开始做比较
	for (int i = k; i < n; i++)
	{
		if (HeapTop(&hp) < a[i])//比堆顶大，则换进去
		{
			HeapPop(&hp);//去除堆顶元素
			HeapPush(&hp, a[i]);//换进去，并维护
		}
	}
	for (int i = 0; i < k; i++)
	{
		printf("%d ", HeapTop(&hp));
		HeapPop(&hp);
	}
}
//2. 找最小的K个元素
//假设堆为大堆
void PrintTopKMin(int* a, int n, int k)
{
	Heap hp;
	//建立含有K个元素的堆
	HeapCreate(&hp, a, k);
	for (size_t i = k; i < n; ++i) // N
	{
		//每次和堆顶元素比较，小于堆顶元素，则删除堆顶元素，插入新的元素
		if (a[i] < HeapTop(&hp))
		{
			HeapPop(&hp);
			HeapPush(&hp, a[i]);
		}
	}
	for (int i = 0; i < k; i++)
	{
		printf("%d ", HeapTop(&hp));
		HeapPop(&hp);
	}
}