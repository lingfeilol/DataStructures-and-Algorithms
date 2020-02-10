#include "Heap.h"
#define FILE_BUFFER_LENGTH 30000
void swap(HPDataType* h1, HPDataType* h2)
{
	HPDataType tmp = *h1;
	*h1 = *h2;
	*h2 = tmp;
}
void JustDown(HPDataType* a, int n, int root)
{
	int parent = root;//传入要开始向下调整的根节点
	int child = 2 * parent + 1;//左孩子
	while (child < n)
	{
		if (a[child] < a[child + 1] && child+1<n)//选出两个孩子中最大的 ,且还要判断是否有右子树，防止越界
		{
			child = child + 1;
		}
		if (a[child]>a[parent])//子节点比父节点大，则交换    //控制大于小于号可调整成大堆或者小堆
		{
			swap(&a[child], &a[parent]);
			//更新条件继续向下
			parent = child;       
			child = parent * 2 + 1;
		}
		else//不比父亲节点大就跳出
		{
			break;
		}
	}
}
void JustUp(HPDataType* a, int n, int _child)
{
	int child = _child;
	int parent = (child - 1) / 2;//根据子节点的下标找到父亲节点下标
	while (parent >= 0)
	{
		if (a[child] >a[parent])//子节点比父亲节点还大，交换
		{
			swap(&a[child], &a[parent]);
			//更新条件 继续迭代
			child = parent;
			parent = (child - 1) / 2;
		}
		else
		{
			break;
		}
	}
}
// 堆的构建
void HeapCreate(Heap* hp, HPDataType* a, int n)
{
	hp->_a = (HPDataType*)malloc(sizeof(HPDataType));
	hp->_capacity = 2 * n;
	hp->_size = n;
	memcpy(hp->_a, a, sizeof(HPDataType) * n);//memcpy可以拷贝自定义类型数据
	// 建堆： 从最后一个非叶子节点开始进行调整
	// 最后一个非叶子节点，按照规则： （最后一个位置索引 - 1） / 2
	// 最后一个位置索引： n - 1
	// 故最后一个非叶子节点位置： (n - 1-1) / 2
	for (int i = (n - 2) / 2; i >= 0; --i)
	{
		JustDown(hp->_a, hp->_size, i);
	}

	//向上调整算法初始化堆
	//从最后一个节点开始调整
	/*int end = n - 1;
	while (end > 0)
	{
		JustUp(hp->_a, hp->_size, end);
		end--;
	}*/
}
// 堆的销毁
void HeapDestory(Heap* hp)
{
	free(hp->_a);
	hp->_a = NULL;
	hp->_capacity = hp->_size = 0;
}
// 堆的插入
void HeapPush(Heap* hp, HPDataType x)
{
	assert(hp);
	if (hp->_size == hp->_capacity)//检查容量是否满了， 扩容
	{
		hp->_capacity *= 2;
		hp->_a = (HPDataType*)realloc(hp->_a, sizeof(HPDataType) * hp->_capacity);
	}
	//开始尾插
	hp->_a[hp->_size] = x;
	hp->_size++;
	JustUp(hp->_a, hp->_size, hp->_size - 1);//再向上调整

}
// 堆的删除
void HeapPop(Heap* hp)
{
	swap(&hp->_a[0], &hp->_a[hp->_size - 1]);  //不可能直接删除根，不然后面全乱了，所以首尾交换，尾删，再把交换过来的向下调整
	hp->_size--;
	JustDown(hp->_a, hp->_size, 0);
}
// 取堆顶的数据
HPDataType HeapTop(Heap* hp)
{
	return hp->_a[0];
}
// 堆的数据个数
int HeapSize(Heap* hp)
{
	return hp->_size;
}
// 堆的判空
int HeapEmpty(Heap* hp)
{
	return hp->_size == 0;
}
//打印堆
void HeapPrintf(Heap* hp)
{
	assert(hp);
	for (int i = 0; i < hp->_size; i++)
	{
		printf("%d ", hp->_a[i]);
	}
	printf("\n");
}
// 对数组进行堆排序
void HeapSort(int* a, int n)
{
	// 排升序需要建大堆：
	// 因为每次都会把堆顶元素拿出来放到当前堆的最后一个位置
	// 相当于每次都会把剩余元素中的最大值（即堆顶元素）找出来
	// 放到它该有的位置（当前堆的最后一个位置
	
	//1.所以先创建维护一个大堆
	for (int i = (n - 2) / 2; i >= 0; i--)
	{
		JustDown(a, n, i);
	}
	//2.然后首尾交换，大的值一旦被换下来就一直不会变动了，所有元素都交换完毕后，升序就排好了
	int end = n - 1;
	while (end > 0)
	{
		swap(&a[0], &a[end]);//大值换到数组最后面
		JustDown(a, end, 0);//再调整，准备下一步再调换
		--end;
	}
}