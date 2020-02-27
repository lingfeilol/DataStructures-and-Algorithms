
void Printfarray(int *a, int n)
{
	for (int i = 0; i < n; i++)
	{
		printf("%d ", a[i]);
	}
	printf("\n");
}
int PartSort(int *a, int left, int right)
{
	int key = a[left];
	int start = left;
	while (left < right)
	{
		while (left < right && a[right]>=key)
		{
			right--;
		}
		while (left < right && a[left] <= key)
		{
			left++;
		}
		swap(&a[left], &a[right]);
	}
	swap(&a[left], &a[start]);
	return  left;

}
// 快速排序 非递归实现
void QuickSortNonR(int* a, int left, int right)
{
	Stack s;
	stackinit(&s);
	stackpush(&s, left);
	stackpush(&s, right);
	while (!stackempty(&s))
	{
		int end = stacktop(&s);
		stackpop(&s);
		int begin = stacktop(&s);
		stackpop(&s);
		int midkey = PartSort(a, begin, end);
		if (begin<midkey - 1)
		{
			stackpush(&s, begin);
			stackpush(&s, midkey - 1);
		}
		if (end > midkey + 1)
		{
			stackpush(&s, midkey+1);
			stackpush(&s, end);
		}
	}
}
QuickSortNonR(a,0,sizeof(a) / sizeof(int)-1);
Printfarray(a, sizeof(a) / sizeof(int));//快速排序