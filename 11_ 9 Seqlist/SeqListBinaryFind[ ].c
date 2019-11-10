#include"Seqlist.h"

int SeqListBinaryFind1(SeqList* psl, SLDataType x)//二分查找  左闭右闭[]情况
{
	int begin = 0, end = psl->size - 1;//左闭区间 右闭区间
	while (begin <= end)//注意是 <=号     可以拿只有两个数的例子来想     [1,2]  begin=0;end=1; mid=0
	{
		int mid = (begin + end) / 2;
		if (psl->arr[mid]>x)
		{
			end = mid - 1;
		}
		else if (psl->arr[mid] < x)
		{
			begin = mid + 1;
		}
		else
			return mid;

	}
	return -1;
}