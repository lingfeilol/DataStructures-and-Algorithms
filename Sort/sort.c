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
void BubbleSort(int* a, int n);

// ��������ݹ�ʵ��
// ��������hoare�汾
int PartSort1(int* a, int left, int right);
// ���������ڿӷ�
int PartSort2(int* a, int left, int right);
// ��������ǰ��ָ�뷨
int PartSort3(int* a, int left, int right);
void QuickSort(int* a, int left, int right);
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
	/*InsertSort(a, sizeof(a) / sizeof(int));
	Printfarray(a, sizeof(a) / sizeof(int));*///һ���������

	/*ShellSort(a, sizeof(a) / sizeof(int));
	Printfarray(a, sizeof(a) / sizeof(int));*///ϣ������


	/*SelectSort(a, sizeof(a) / sizeof(int));
	Printfarray(a, sizeof(a) / sizeof(int));*///ѡ������

	/*HeapSort(a, sizeof(a) / sizeof(int));
	Printfarray(a, sizeof(a) / sizeof(int));*/ //������
	return 0;
}