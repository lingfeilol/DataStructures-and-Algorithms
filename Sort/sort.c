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
void BubbleSort(int* a, int n)
{
	int end = n - 1;
	while (end > 0)// 控制趟数
	{
		int flag = 0;//可能要排序的数组本趟就已经达到有序的，后面的趟数就可以没必要跑了，所以设置一个目标值来记录这这种情况
		for (int i = 1; i <= end; i++)//一一对比，直到这一趟结束
		{
			if (a[i - 1] > a[i])
			{
				swap(&a[i - 1], &a[i]);
				flag = 1;
			}
		}
		if (flag == 0)//已经是有序的了，就不用再接着下一躺了，直接跳出
		{
			break;
		}
		end--;
	}
}

// 快速排序递归实现
//原始版本  直接选第一个元素做基准值
//三数区中法优化    先把left   mid    right这三数据的中位数 放到第一个元素做基准值
//挖坑法优化   把基准值直接变成一个坑，比较后满足条件的就把自己填过去，自己变成就坑了，再继续判断
//前后指针优化  prev指向开头，cur遍历找小，遇到小的便交换，
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
// 快速排序三数取中法
int GitMidindex(int *a, int left, int right)//取三个数的中位数放到第一位做基准值
{
	int mid = (left + right) / 2;
	if (a[left] > a[mid])
	{
		if (a[mid] > a[right])
			return mid;
		else  if (a[right] > a[left])
			return left;
		else
			return right;
	}
	else    //a[left] <a[mid]
	{
		if (a[mid] < a[right])
			return mid;
		else if (a[left]>a[right])
			return left;
		else
			return right;
	}
}
int PartSort1(int* a, int left, int right)
{
	int mid = GitMidindex(a, left, right);//选出中间的那个数
	swap(&a[mid], &a[left]);//与开头的那个基准值交换，确保最开始时是用中位数做基准值的
	int key = a[left];
	int start = left;
	while (left < right)
	{
		while (left < right && a[right] >= key)
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

// 快速排序挖坑法
int PartSort2(int* a, int left, int right)
{
	int mid = GitMidindex(a, left, right);//选出中间的那个数
	swap(&a[mid], &a[left]);//与开头的那个基准值交换，确保最开始时是用中位数做基准值的
	int key = a[left];    //把自己变成坑 a[left]就可以看成一个坑
	while (left < right)
	{
		while (left<right && a[right]>key)
		{
			right--;
		}
		a[left] = a[right];//小的就填进去
		while (left < right  && a[left] < key)
		{
			left++;
		}
		a[right] = a[left];//大的填进去
	}
	a[left] = key;//最后再把基准值填到最后一个坑里
	return left;//把中间的基准值的位置保留下来
}

// 快速排序前后指针法  双指针prev cur
int PartSort3(int* a, int left, int right)
{
	int mid = GitMidindex(a, left, right);//选出中间的那个数
	swap(&a[mid], &a[left]);//与开头的那个基准值交换，确保最开始时是用中位数做基准值的
	int key = a[left];
	int prev = left;
	int cur = left + 1;
	while (cur <= right)
	{
		if(a[cur] < key)
		{
			prev++;
			swap(&a[cur], &a[prev]);
			cur++;
		}
		else
		{
			cur++;
		}
	}
	swap(&a[left], &a[prev]);
	return prev;

}

void QuickSort(int* a, int left, int right)
{
	//if (left >= right)//特殊情况  1 3 5 4， 1为基准时，end没找到比它小的一直减减，直到它本身了，此时left=right; 1左边全是大于它的，右边全是小于它的，就不用再排一趟了
	//	return;
	if (left < right)
	{
		int keyindex = PartSort3(a, left, right);
		// [left,keyindex-1]    keyindex   [keyindex+1,right]   二叉树结构  左区间 基准值 右区间  继续递归

		QuickSort(a, left, keyindex - 1);//基准值左边（大于它的）继续划分
		QuickSort(a, keyindex + 1, right);//基准值右边（小于它的）也继续
		//直到最小的都已经有序（划分好了）

	}
	
}

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
	//插入排序
	/*InsertSort(a, sizeof(a) / sizeof(int));
	Printfarray(a, sizeof(a) / sizeof(int));*///一般插入排序
	/*ShellSort(a, sizeof(a) / sizeof(int));
	Printfarray(a, sizeof(a) / sizeof(int));*///希尔排序

	//选择排序
	/*SelectSort(a, sizeof(a) / sizeof(int));
	Printfarray(a, sizeof(a) / sizeof(int));*///选择排序
	/*HeapSort(a, sizeof(a) / sizeof(int));
	Printfarray(a, sizeof(a) / sizeof(int));*/ //堆排序

	//交换排序#include<stdio.h>
#include<assert.h>
#include<string.h>
void Printfarray(int *a, int n)
{
	for (int i = 0; i < n; i++)
	{
		printf("%d ", a[i]);
	}
	printf("\n");
}

// 直接插入排序
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
		a[end + 1] = next; // 前面的都比他小，直接尾插 
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
	//assert(a);
	//int begin = 0;
	//int end = n - 1;
	//while (begin < end)
	//{
	//	int min = begin;
	//	int max = begin;
	//	for (int i = begin; i <= end; i++)
	//	{
	//		if (a[i] >= a[max])
	//		{
	//			max = i;
	//		}
	//		if (a[i] < a[min])
	//		{
	//			min = i;
	//		}
	//	}
	//	swap(&a[begin], &a[min]);
	//	//如果最大的位置在begin位置(第一个数就是最大的)
	//	//说明min是和最大的交换位置
	//	//这个时候max的位置就发生了变换
	//	//max变到了min的位置
	//	//所以要更新max的位置
	//	if (begin == max)
	//	{
	//		max = min;
	//	}

	//	swap(&a[end], &a[max]);
	//	begin++;
	//	end--;
	//}
	
	for (int i = 0; i < n; i++)             
	{
		int min = i;
		for (int j = i+1; j < n; j++)
		{
			if (a[j] < a[min])//直到最左边找到最小值的下标
			{
				min = j;
			}
		}
		swap(&a[i], &a[min]);//小的就交换到前面去，接着下一轮的比较选择
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
void BubbleSort(int* a, int n)
{
	int end = n - 1;
	while (end > 0)// 控制趟数
	{
		int flag = 0;//可能要排序的数组本趟就已经达到有序的，后面的趟数就可以没必要跑了，所以设置一个目标值来记录这这种情况
		for (int i = 1; i <= end; i++)//一一对比，直到这一趟结束
		{
			if (a[i - 1] > a[i])
			{
				swap(&a[i - 1], &a[i]);
				flag = 1;
			}
		}
		if (flag == 0)//已经是有序的了，就不用再接着下一躺了，直接跳出
		{
			break;
		}
		end--;
	}
}

// 快速排序递归实现
//原始版本  直接选第一个元素做基准值 
//      比较一趟    从最左边先开始，right 找小的，比基准值大的就往回走， begin找大的，比基准值小了就往前走  两者停下，就交换一次，再入循环 在重复以上步骤，
//               最后一步，把基准值换到最后停下的下标，返回此下标索引
//三数区中法优化    先求left   mid    right这三下标的数据的中位数，return此下标 ，
//                                                之后 放到第一个元素做基准值
//挖坑法优化   把基准值先保存，再假想成一个坑，比较后满足条件的就把自己（覆盖）填过去，自己就又是坑了，再继续判断

//前后指针优化  prev指向开头，cur遍历找小，遇到小的便与之前prev保留的小的交换，遇到大的就下一个，

//普通版本
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
// 快速排序   三数取中优化法
int GitMidindex(int *a, int left, int right)//取三个数的中位数放到第一位做基准值
{
	int mid = (left + right) / 2;
	//int mid=left+ ((right-left)>>1) 可能整数溢出的处理方法
	if (a[left] > a[mid])
	{
		if (a[mid] > a[right])
			return mid;
		else  if (a[right] > a[left])
			return left;
		else
			return right;
	}
	else    //a[left] <a[mid]
	{
		if (a[mid] < a[right])
			return mid;
		else if (a[left]>a[right])
			return left;
		else
			return right;
	}
	//返回中位数的索引
}
int PartSort1(int* a, int left, int right)
{
	int mid = GitMidindex(a, left, right);//中位数的下标索引
	swap(&a[mid], &a[left]);//与开头的那个值交换，确保最开始时是用中位数做基准值的
	int key = a[left];
	int start = left;
	while (left < right)
	{
		while (left < right && a[right] >= key)
		{
			right--;
		}
		while (left < right && a[left] <= key)
		{
			left++;
		}
		swap(&a[left], &a[right]);
	}
	swap(&a[left], &a[start]);//比较完后把基准值换到停下的地方，一趟就排完了
	return  left;
	
}

// 快速排序挖坑法
int PartSort2(int* a, int left, int right)
{
	int key = a[left];    //把自己变成坑 a[left]就可以看成一个坑
	while (left < right)
	{
		while (left<right && a[right]>=key)
		{
			right--;
		}
		a[left] = a[right];//小的就填进去  right就是新的坑了
		while (left < right  && a[left] <= key)
		{
			left++;
		}
		a[right] = a[left];//大的填进去 left就是新的坑
	}
	a[left] = key;//最后再把基准值填到最后一个坑里
	return left;//把中间的基准值的位置保留下来
}

// 快速排序前后指针法  双指针prev cur
int PartSort3(int* a, int left, int right)
{
	int mid = GitMidindex(a, left, right);//选出中间的那个数
	swap(&a[mid], &a[left]);//与开头的那个基准值交换，确保最开始时是用中位数做基准值的
	int key = a[left];
	int prev = left;
	int cur = left + 1;
	while (cur <= right)
	{
		if(a[cur] < key)
		{
			prev++;
			swap(&a[cur], &a[prev]);
			cur++;
		}
		else
		{
			cur++;
		}
	}
	swap(key, &a[prev]);
	return prev;

}

void QuickSort(int* a, int left, int right)
{
	//if (left >= right)//特殊情况  1 3 5 4， 当排第一趟时1为基准，end没找到比它小的一直减减，直到它本身了，此时left=right，返回keyindex为没动的left; 在递归下一趟时left为0，大于keyindex-1的-1，就不做左边无意义的递归趟数了
	//	return;   如果区域不存在或只有一个数据则不递归排序
	if (left < right)
	{
		if (left-right +1 < 10)//小区间优化：   区间内数据小于一定值了，就没必要用快排的递归下去了，小数据还是可以用插入排序的
		{
			InsertSort(a+left, right-left + 1); //相当于也是传区间
		}
		else
		{
			int keyindex = PartSort3(a, left, right);
			// [left,keyindex-1]    keyindex   [keyindex+1,right]   二叉树结构  左区间 基准值 右区间  继续递归
			QuickSort(a, left, keyindex - 1);//基准值左边（大于它的）继续划分
			QuickSort(a, keyindex + 1, right);//基准值右边（小于它的）也继续
			//直到最小的都已经有序（划分好了）
		}
	}
}

// 快速排序 非递归实现
void QuickSortNonR(int* a, int left, int right);

//归并排序 先划分在合并
void _MergeSort(int* a, int left, int right, int* tmp)
{
	if (left >= right)  //一直分到每组只剩一个元素就停止划分，准备开始归并
	{
		return;
	}
	int mid = left + ((right - left) >> 1);
	_MergeSort(a, left, mid, tmp);     //先递归划分，再出栈合并
	_MergeSort(a, mid + 1, right, tmp);
	// [left, mid]
	// [mid+1, right]
	int i = left, j = mid;
	int x = mid + 1, z = right;
	int k = left;
	
	//将有二个有序数列a[left...mid]和a[mid...right]合并。
	while (i <= j && x<=z)
	{
		if (a[i] <=a[x])
		{
			tmp[k++] = a[i++];
		}
		else
		{
			tmp[k++] = a[x++];
		}
	}
	while(i <= j)
		tmp[k++] = a[i++];
	while(x <= z)
		tmp[k++] = a[x++];
	for (i = 0; i<k; i++)
		a[left + i] = tmp[i];
	//memcpy(a + left, tmp + left, sizeof(int)*(right - left+1 ));
}
// 归并排序递归实现
void MergeSort(int* a, int n)
{
	int* tmp = (int *)malloc(sizeof(int)*n);
	_MergeSort(a, 0, n - 1, tmp);
	free(tmp);

}
// 归并排序非递归实现
void MergeSortNonR(int* a, int n);
// 计数排序
void CountSort(int* a, int n);

int main()
{
	int a[] = { -2,3,-5};
	//插入排序
	/*InsertSort(a, sizeof(a) / sizeof(int));
	Printfarray(a, sizeof(a) / sizeof(int));*///一般插入排序
	/*ShellSort(a, sizeof(a) / sizeof(int));
	Printfarray(a, sizeof(a) / sizeof(int));*///希尔排序

	//选择排序
	//SelectSort(a, sizeof(a) / sizeof(int));
	//Printfarray(a, sizeof(a) / sizeof(int));//选择排序
	/*HeapSort(a, sizeof(a) / sizeof(int));
	Printfarray(a, sizeof(a) / sizeof(int));*/ //堆排序

	//交换排序
	/*BubbleSort(a, sizeof(a) / sizeof(int));
	Printfarray(a, sizeof(a) / sizeof(int));*/ //冒泡排序

	QuickSort(a,0,sizeof(a) / sizeof(int)-1);
	Printfarray(a, sizeof(a) / sizeof(int));//快速排序

	//归并排序递归版
	/*MergeSort(a, sizeof(a) / sizeof(int));
	Printfarray(a, sizeof(a) / sizeof(int));*/

	return 0;
}
	/*BubbleSort(a, sizeof(a) / sizeof(int));
	Printfarray(a, sizeof(a) / sizeof(int));*/ //冒泡排序

	QuickSort(a,0,sizeof(a) / sizeof(int)-1);
	Printfarray(a, sizeof(a) / sizeof(int));
	return 0;
}