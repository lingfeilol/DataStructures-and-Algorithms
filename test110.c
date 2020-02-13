/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
 // 插入排序   超出时间限制
void InsertSort(int* a, int n)
{
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
//希尔排序   可以通过
void ShellSort(int *a,int n)
{
    int gap=n;
    while(gap>1)
    {
        gap=gap/3+1;
        for(int i=0;i<n-gap;i++)
        {
            int end=i;
            int next=a[end+gap];
            while(end>=0 && a[end]>next)
            {
                a[end+gap]=a[end];
                end-=gap;
            }
            a[end+gap]=next;
        }
    }
}
void swap(int *a, int *b)
{
	int tmp = *a;
	*a = *b;
	*b = tmp;
}
// 选择排序  超出时间限制
void SelectSort(int* a, int n)
{
    int begin=0;
    int end=n-1;
    while(begin<end)
    {
        int min=begin;
        int max=end;
        for(int i=begin;i<=end;i++)
        {
            if(a[max]<=a[i])
            {
                max=i;
            }
            if(a[min]>a[i])
            {
                min=i;
            }
        }
        swap(&a[begin],&a[min]);
        if(begin==max)
        {
            max=min;
        }
        swap(&a[end],&a[max]);
        begin++;
        end--;
    }
}
//堆排序     可以提交
void justdown(int *a,int n,int root)//向下调整算法
{
    int parent=root;
    int child=parent*2+1;
    while(child<n)
    {
        if((child+1)<n && a[child+1]>a[child])
        {
            child++;
        }
        if(a[child]>a[parent])
        {
            swap(&a[child],&a[parent]);
            parent=child;
            child=parent*2+1;
        }
        else
        {
            break;
        }
    }
}
void HeapSort(int *a,int n)//堆排
{
    for(int i=(n-2)/2;i>=0;i--)
    {
        justdown(a,n,i);
    }
    int end=n-1;
    while(end>0)
    {
        swap(&a[0],&a[end]);
        justdown(a,end,0);
        end--;
    }
}
// 冒泡排序   超时
void BubbleSort(int* a, int n)
{
    int end=n-1;
    while(end>0)
    {
        int flag=0;
        for(int i=1;i<=end;i++)
        {
            if(a[i-1]>a[i])
            {
                swap(&a[i-1],&a[i]);
                flag=1;
            }
        }
        if(flag==0)
        {
            break;
        }
        end--;
    }
}
int* sortArray(int* nums, int numsSize, int* returnSize){
    BubbleSort(nums,numsSize);
    *returnSize=numsSize;
    return nums;

}