// 计数排序
void CountSort(int* a, int n)
{
	
	//找出区间
	int min = a[0];//必须是数组里面的值，要比较的
	int max = a[0];
	for (int i = 0; i < n; i++)
	{
		if (a[i] < min)
			min = a[i];
		if (a[i] > max)
			max = a[i];
	}
	//区间知道了，就开始创建数组来存出现的个数
	int range = max - min + 1; //要开辟的数组大小
	int* tmp = (int *)malloc(sizeof(int)*range);
	memset(tmp, 0, range); //初始化为0
	//1.统计每个数字出现的个数
	for (int i = 0; i < n; i++)
	{
		int j = a[i] - min;
		tmp[j]++;
	}
	//2.在排序输出
	int k = 0;
	for (int i = 0; i < range; i++)
	{
		while (tmp[i]--)
		{
			a[k++] = i+min;
		}
	}
}