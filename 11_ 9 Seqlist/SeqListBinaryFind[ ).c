#include"Seqlist.h"
int SeqListBinaryFind2(SeqList* psl, SLDataType x)//二分查找  左闭右开[）情况
{
	int begin = 0, end = psl->size;//左闭区间 右开区间
	while (begin < end)//注意是 <号     也可以拿三个数的例子来想     [1,2，3]  begin=0;end=3; mid=1；
	{
		int mid = (begin + end) / 2;
		if (psl->arr[mid]>x)
		{
			end = mid;//如果找1的话，此处写成end=mid-1;的话begin==end==0就没有意义了；
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