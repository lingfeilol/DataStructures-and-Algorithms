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

// ��������
void InsertSort(int* a, int n)
{
	assert(a);
	for (int i = 0; i < n - 1; i++)
	{
		int end = i;
		int next = a[end + 1];//������һ������ֵ�����ⱻ����
		while (end >= 0 && a[end]>next)//��ǰ���ź����һ���ִӺ���ǰ�ڱȽϣ��д�ľ����󸲸ǣ���һ������͸��ǣ�ֱ��û�д��� Ҫ��������next������ѭ����
		{
			a[end+1] = a[end];
			end--;
		}
		a[end + 1] = next; //������ֹ��λ�ð�Ҫ�����next��ֵ��ȥ
	}
}

// ϣ������
void ShellSort(int* a, int n)
{
	assert(a);
	int gap = n;
	//����д�ɴ���0,��Ϊgap��ֵʼ��>=1,
	while (gap > 1)
	{
		gap = gap / 3 + 1;     //��gap�����1�ˣ�������������  //��������Ҫ��1
		for (int i = 0; i < n - gap; i++)
		{
			    // ����ֻ�ǰѲ��������1����gap����
				//�������ﲻ��������һ�����飬��ȥ
				//������һ�����飬��������ֻ��һ��
				//����ÿ�ζ���ÿ������ֻ��һ����
				//����ѭ������֮��������������������
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
// ѡ������
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
		//�������λ����beginλ��(��һ������������)
		//˵��min�Ǻ����Ľ���λ��
		//���ʱ��max��λ�þͷ����˱任
		//max�䵽��min��λ��
		//����Ҫ����max��λ��
		if (begin == max)
		{
			max = min;
		}

		swap(&a[end], &a[max]);
		begin++;
		end--;
	}
}
// ������
void AdjustDwon(int* a, int n, int root)//���µ����㷨 ���
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
	// ���ѣ��ȴ��������Ҷ���ϵĸ�(����Ϊ(n - 2) / 2��ʼ����
	// �Ƚ���С�Ķѣ�ֱ��a[0](���Ķ�)
	// ����൱�����Ѿ����õĶ����棬�¼���һ��
	// ��Ԫ�أ�Ȼ�����µ�������������ȫ������
	// ��������ѵ�����
	for (int i = (n - 2) / 2; i >= 0; i--)//�����
	{
		AdjustDwon(a, n, i);
	}
	int end = n - 1;//����������Ѷ��Ĵ����������ڵ������δ���ֵ������Ѷ����ڽ������ڵ���
	while (end > 0)
	{
		swap(&a[0], &a[end]);
		AdjustDwon(a, end, 0);
		end--;
	}
}
// ð������
void BubbleSort(int* a, int n)
{
	int end = n - 1;
	while (end > 0)// ��������
	{
		int flag = 0;//����Ҫ��������鱾�˾��Ѿ��ﵽ����ģ�����������Ϳ���û��Ҫ���ˣ���������һ��Ŀ��ֵ����¼���������
		for (int i = 1; i <= end; i++)//һһ�Աȣ�ֱ����һ�˽���
		{
			if (a[i - 1] > a[i])
			{
				swap(&a[i - 1], &a[i]);
				flag = 1;
			}
		}
		if (flag == 0)//�Ѿ���������ˣ��Ͳ����ٽ�����һ���ˣ�ֱ������
		{
			break;
		}
		end--;
	}
}

// ��������ݹ�ʵ��
//ԭʼ�汾  ֱ��ѡ��һ��Ԫ������׼ֵ
//�������з��Ż�    �Ȱ�left   mid    right�������ݵ���λ�� �ŵ���һ��Ԫ������׼ֵ
//�ڿӷ��Ż�   �ѻ�׼ֱֵ�ӱ��һ���ӣ��ȽϺ����������ľͰ��Լ����ȥ���Լ���ɾͿ��ˣ��ټ����ж�
//ǰ��ָ���Ż�  prevָ��ͷ��cur������С������С�ı㽻����
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
// ������������ȡ�з�
int GitMidindex(int *a, int left, int right)//ȡ����������λ���ŵ���һλ����׼ֵ
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
	int mid = GitMidindex(a, left, right);//ѡ���м���Ǹ���
	swap(&a[mid], &a[left]);//�뿪ͷ���Ǹ���׼ֵ������ȷ���ʼʱ������λ������׼ֵ��
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

// ���������ڿӷ�
int PartSort2(int* a, int left, int right)
{
	int mid = GitMidindex(a, left, right);//ѡ���м���Ǹ���
	swap(&a[mid], &a[left]);//�뿪ͷ���Ǹ���׼ֵ������ȷ���ʼʱ������λ������׼ֵ��
	int key = a[left];    //���Լ���ɿ� a[left]�Ϳ��Կ���һ����
	while (left < right)
	{
		while (left<right && a[right]>key)
		{
			right--;
		}
		a[left] = a[right];//С�ľ����ȥ
		while (left < right  && a[left] < key)
		{
			left++;
		}
		a[right] = a[left];//������ȥ
	}
	a[left] = key;//����ٰѻ�׼ֵ����һ������
	return left;//���м�Ļ�׼ֵ��λ�ñ�������
}

// ��������ǰ��ָ�뷨  ˫ָ��prev cur
int PartSort3(int* a, int left, int right)
{
	int mid = GitMidindex(a, left, right);//ѡ���м���Ǹ���
	swap(&a[mid], &a[left]);//�뿪ͷ���Ǹ���׼ֵ������ȷ���ʼʱ������λ������׼ֵ��
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
	//if (left >= right)//�������  1 3 5 4�� 1Ϊ��׼ʱ��endû�ҵ�����С��һֱ������ֱ���������ˣ���ʱleft=right; 1���ȫ�Ǵ������ģ��ұ�ȫ��С�����ģ��Ͳ�������һ����
	//	return;
	if (left < right)
	{
		int keyindex = PartSort3(a, left, right);
		// [left,keyindex-1]    keyindex   [keyindex+1,right]   �������ṹ  ������ ��׼ֵ ������  �����ݹ�

		QuickSort(a, left, keyindex - 1);//��׼ֵ��ߣ��������ģ���������
		QuickSort(a, keyindex + 1, right);//��׼ֵ�ұߣ�С�����ģ�Ҳ����
		//ֱ����С�Ķ��Ѿ����򣨻��ֺ��ˣ�

	}
	
}

// �������� �ǵݹ�ʵ��
void QuickSortNonR(int* a, int left, int right);

// �鲢����ݹ�ʵ��
void MergeSort(int* a, int n);
// �鲢����ǵݹ�ʵ��
void MergeSortNonR(int* a, int n);
// ��������
void CountSort(int* a, int n);







int main()
{
	int a[] = { 5, 4, 6, 7, 8, 1, 2, 3, 9, 0 };
	//��������
	/*InsertSort(a, sizeof(a) / sizeof(int));
	Printfarray(a, sizeof(a) / sizeof(int));*///һ���������
	/*ShellSort(a, sizeof(a) / sizeof(int));
	Printfarray(a, sizeof(a) / sizeof(int));*///ϣ������

	//ѡ������
	/*SelectSort(a, sizeof(a) / sizeof(int));
	Printfarray(a, sizeof(a) / sizeof(int));*///ѡ������
	/*HeapSort(a, sizeof(a) / sizeof(int));
	Printfarray(a, sizeof(a) / sizeof(int));*/ //������

	//��������
	/*BubbleSort(a, sizeof(a) / sizeof(int));
	Printfarray(a, sizeof(a) / sizeof(int));*/ //ð������

	QuickSort(a,0,sizeof(a) / sizeof(int)-1);
	Printfarray(a, sizeof(a) / sizeof(int));
	return 0;
}