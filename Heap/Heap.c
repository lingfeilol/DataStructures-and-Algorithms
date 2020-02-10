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
	int parent = root;//����Ҫ��ʼ���µ����ĸ��ڵ�
	int child = 2 * parent + 1;//����
	while (child < n)
	{
		if (a[child] < a[child + 1] && child+1<n)//ѡ���������������� ,�һ�Ҫ�ж��Ƿ�������������ֹԽ��
		{
			child = child + 1;
		}
		if (a[child]>a[parent])//�ӽڵ�ȸ��ڵ���򽻻�    //���ƴ���С�ںſɵ����ɴ�ѻ���С��
		{
			swap(&a[child], &a[parent]);
			//����������������
			parent = child;       
			child = parent * 2 + 1;
		}
		else//���ȸ��׽ڵ�������
		{
			break;
		}
	}
}
void JustUp(HPDataType* a, int n, int _child)
{
	int child = _child;
	int parent = (child - 1) / 2;//�����ӽڵ���±��ҵ����׽ڵ��±�
	while (parent >= 0)
	{
		if (a[child] >a[parent])//�ӽڵ�ȸ��׽ڵ㻹�󣬽���
		{
			swap(&a[child], &a[parent]);
			//�������� ��������
			child = parent;
			parent = (child - 1) / 2;
		}
		else
		{
			break;
		}
	}
}
// �ѵĹ���
void HeapCreate(Heap* hp, HPDataType* a, int n)
{
	hp->_a = (HPDataType*)malloc(sizeof(HPDataType));
	hp->_capacity = 2 * n;
	hp->_size = n;
	memcpy(hp->_a, a, sizeof(HPDataType) * n);//memcpy���Կ����Զ�����������
	// ���ѣ� �����һ����Ҷ�ӽڵ㿪ʼ���е���
	// ���һ����Ҷ�ӽڵ㣬���չ��� �����һ��λ������ - 1�� / 2
	// ���һ��λ�������� n - 1
	// �����һ����Ҷ�ӽڵ�λ�ã� (n - 1-1) / 2
	for (int i = (n - 2) / 2; i >= 0; --i)
	{
		JustDown(hp->_a, hp->_size, i);
	}

	//���ϵ����㷨��ʼ����
	//�����һ���ڵ㿪ʼ����
	/*int end = n - 1;
	while (end > 0)
	{
		JustUp(hp->_a, hp->_size, end);
		end--;
	}*/
}
// �ѵ�����
void HeapDestory(Heap* hp)
{
	free(hp->_a);
	hp->_a = NULL;
	hp->_capacity = hp->_size = 0;
}
// �ѵĲ���
void HeapPush(Heap* hp, HPDataType x)
{
	assert(hp);
	if (hp->_size == hp->_capacity)//��������Ƿ����ˣ� ����
	{
		hp->_capacity *= 2;
		hp->_a = (HPDataType*)realloc(hp->_a, sizeof(HPDataType) * hp->_capacity);
	}
	//��ʼβ��
	hp->_a[hp->_size] = x;
	hp->_size++;
	JustUp(hp->_a, hp->_size, hp->_size - 1);//�����ϵ���

}
// �ѵ�ɾ��
void HeapPop(Heap* hp)
{
	swap(&hp->_a[0], &hp->_a[hp->_size - 1]);  //������ֱ��ɾ��������Ȼ����ȫ���ˣ�������β������βɾ���ٰѽ������������µ���
	hp->_size--;
	JustDown(hp->_a, hp->_size, 0);
}
// ȡ�Ѷ�������
HPDataType HeapTop(Heap* hp)
{
	return hp->_a[0];
}
// �ѵ����ݸ���
int HeapSize(Heap* hp)
{
	return hp->_size;
}
// �ѵ��п�
int HeapEmpty(Heap* hp)
{
	return hp->_size == 0;
}
//��ӡ��
void HeapPrintf(Heap* hp)
{
	assert(hp);
	for (int i = 0; i < hp->_size; i++)
	{
		printf("%d ", hp->_a[i]);
	}
	printf("\n");
}
// ��������ж�����
void HeapSort(int* a, int n)
{
	// ��������Ҫ����ѣ�
	// ��Ϊÿ�ζ���ѶѶ�Ԫ���ó����ŵ���ǰ�ѵ����һ��λ��
	// �൱��ÿ�ζ����ʣ��Ԫ���е����ֵ�����Ѷ�Ԫ�أ��ҳ���
	// �ŵ������е�λ�ã���ǰ�ѵ����һ��λ��
	
	//1.�����ȴ���ά��һ�����
	for (int i = (n - 2) / 2; i >= 0; i--)
	{
		JustDown(a, n, i);
	}
	//2.Ȼ����β���������ֵһ������������һֱ����䶯�ˣ�����Ԫ�ض�������Ϻ�������ź���
	int end = n - 1;
	while (end > 0)
	{
		swap(&a[0], &a[end]);//��ֵ�������������
		JustDown(a, end, 0);//�ٵ�����׼����һ���ٵ���
		--end;
	}
}