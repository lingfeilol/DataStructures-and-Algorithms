#include<stdio.h>
#include<assert.h>

void Printfarray(int *a, int n)
{
	for (int i = 0; i < n; i++)
	{
		printf("%d ", a[i]);
	}
	printf("\n");
}

// 插入排序
void InsertSort(int* a, int n)
{
	assert(a);
	for (int i = 0; i < n - 1; i++)
	{
		int end = i;
		int next = a[end + 1];//保存下一个数的值，避免被覆盖
		while (end >= 0 && a[end]>next)//对前面排好序的一部分从后往前在比较，有大的就往后覆盖，下一个还大就覆盖，直到没有大与 要插入的这个next，跳出循环，
		{
			a[end+1] = a[end];
			end--;
		}
		a[end + 1] = next; //再在终止的位置把要插入的next赋值进去
	}
}

// 希尔排序
void ShellSort(int* a, int n)
{
	assert(a);
	int gap = n;
	//不能写成大于0,因为gap的值始终>=1,
	while (gap > 1)
	{
		gap = gap / 3 + 1;     //当gap最后变成1了，才是排完序了  //所以这里要加1
		for (int i = 0; i < n - gap; i++)
		{
			    // 这里只是把插入排序的1换成gap即可
				//但是这里不是排序完一个分组，再去
				//排序另一个分组，而是整体只过一遍
				//这样每次对于每组数据只排一部分
				//整个循环结束之后，所有组的数据排序完成
			int end = i;
			int next = a[end + gap];
			while (end>=0 && a[end] > next)
			{
				a[end + gap] = a[end];
				end -= gap;
			}
			a[end + gap] = next;
		}
	}
}




void swap(int *a, int *b)
{
	int tmp = *a;
	*a = *b;
	*b = tmp;
}
// 选择排序
void SelectSort(int* a, int n)
{
	assert(a);
	int begin = 0;
	int end = n - 1;
	while (begin < end)
	{
		int min = begin;
		int max = begin;
		for (int i = begin; i <= end; i++)
		{
			if (a[i] >= a[max])
			{
				max = i;
			}
			if (a[i] < a[min])
			{
				min = i;
			}
		}
		swap(&a[begin], &a[min]);
		//如果最大的位置在begin位置(第一个数就是最大的)
		//说明min是和最大的交换位置
		//这个时候max的位置就发生了变换
		//max变到了min的位置
		//所以要更新max的位置
		if (begin == max)
		{
			max = min;
		}

		swap(&a[end], &a[max]);
		begin++;
		end--;
	}
}
// 堆排序
void AdjustDwon(int* a, int n, int root)//向下调整算法 大堆
{
	int parent = root;
	int child = parent * 2 + 1;
	while (child < n)
	{
		if ((child + 1) < n && a[child] < a[child + 1])
		{
			child++;
		}
		if (a[child]>a[parent])
		{
			swap(&a[child], &a[parent]);
			parent = child;
			child = parent * 2 + 1;
		}
		else
		{
			break;
		}
	}
}
void HeapSort(int* a, int n)
{
	// 建堆，先从最后两个叶子上的根(索引为(n - 2) / 2开始建堆
	// 先建最小的堆，直到a[0](最大的堆)
	// 这就相当于在已经建好的堆上面，新加入一个
	// 根元素，然后向下调整，让整个完全二叉树
	// 重新满足堆的性质
	for (int i = (n - 2) / 2; i >= 0; i--)//建大堆
	{
		AdjustDwon(a, n, i);
	}
	int end = n - 1;//最后面的数与堆顶的大数交换，在调整，次大的又调整到堆顶，在交换，在调整
	while (end > 0)
	{
		swap(&a[0], &a[end]);
		AdjustDwon(a, end, 0);
		end--;
	}
}
// 冒泡排序
void BubbleSort(int* a, int n);

// 快速排序递归实现
// 快速排序hoare版本
int PartSort1(int* a, int left, int right);
// 快速排序挖坑法
int PartSort2(int* a, int left, int right);
// 快速排序前后指针法
int PartSort3(int* a, int left, int right);
void QuickSort(int* a, int left, int right);
// 快速排序 非递归实现
void QuickSortNonR(int* a, int left, int right);
// 归并排序递归实现
void MergeSort(int* a, int n);
// 归并排序非递归实现
void MergeSortNonR(int* a, int n);
// 计数排序
void CountSort(int* a, int n);







int main()
{
	int a[] = { 5, 4, 6, 7, 8, 1, 2, 3, 9, 0 };
	/*InsertSort(a, sizeof(a) / sizeof(int));
	Printfarray(a, sizeof(a) / sizeof(int));*///一般插入排序

	/*ShellSort(a, sizeof(a) / sizeof(int));
	Printfarray(a, sizeof(a) / sizeof(int));*///希尔排序


	/*SelectSort(a, sizeof(a) / sizeof(int));
	Printfarray(a, sizeof(a) / sizeof(int));*///选择排序

	/*HeapSort(a, sizeof(a) / sizeof(int));
	Printfarray(a, sizeof(a) / sizeof(int));*/ //堆排序
	return 0;
}