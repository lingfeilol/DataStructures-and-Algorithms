#include"Seqlist.h"

void SeqListInit(SeqList* psl, size_t capacity)//��ʼ��
{
	psl->arr = (SeqList*)malloc(sizeof(SLDataType)*capacity);
	assert(psl&&psl->arr != NULL);
	psl->size = 0;
	psl->capicity = capacity;
}
void SeqListDestory(SeqList* psl)//����
{
	assert(psl);
	free(psl->arr);
	psl->arr = NULL;
	psl->size = 0;
	psl->capicity = 0;
}
void CheckCapacity(SeqList* psl)//���ռ��С
{
	assert(psl);
	if (psl->size == psl->capicity)
	{
		SLDataType* new_psl_arr = (SLDataType*)malloc(sizeof(SLDataType)*psl->capicity * 2);
		assert(new_psl_arr);
		//free(psl->arr);//�ͷžɿռ�
		for (size_t i = 0; i < psl->size; i++)
		{
			new_psl_arr[i] = psl->arr[i];
		}
		psl->capicity = psl->capicity * 2;
	}
}
void SeqListPushBack(SeqList* psl, SLDataType x)//β��
{
	assert(psl);
	CheckCapacity(psl);
	psl->arr[psl->size] = x;
	psl->size++;
}
void SeqListPopBack(SeqList* psl)//βɾ
{
	assert(psl);
	//CheckCapacity(psl);
	//psl->arr[psl->size] = 0;
	psl->size--;
}
void SeqListPushFront(SeqList* psl, SLDataType x)//ͷ��
//���һλ����λ�������ص�
{
	assert(psl);
	CheckCapacity(psl);
	for (size_t i = psl->size; i > 0;i--)
	{
		psl->arr[i] = psl->arr[i-1];
	}
	psl->arr[0] = x;
	psl->size++;
}
void SeqListPopFront(SeqList* psl)//ͷɾ
{
	assert(psl);
	for (size_t i = 0; i < psl->size; i++)
	{
		psl->arr[0] = psl->arr[i + 1];
	}
	psl->size--;

}

int SeqListFind(SeqList* psl, SLDataType x)//����
{
	assert(psl);
	for (size_t i = 0; i < psl->size; i++)
	{
		if (psl->arr[i] == x)
		{
			printf("%d", i);
		}
	}
	return -1;

}

void SeqListInsert(SeqList* psl, size_t pos, SLDataType x)//posλ�ò���
//���һλ����λ
{
	assert(psl&&pos<psl->size);
	CheckCapacity(psl);
	for (size_t i = psl->size; i >pos; i--)
	{
		psl->arr[i] = psl->arr[i-1];
	}
	psl->arr[pos] = x;
	psl->size++;
}
void SeqListErase(SeqList* psl, size_t pos)//posλ��ɾ��
{
	assert(psl&& pos<psl->size);
	for (size_t i =pos; i<psl->size; i++)
	{
		psl->arr[i] = psl->arr[i+1];
	}
	psl->size--;


}

void SeqListRemove(SeqList* psl, SLDataType x)//ɾ��ָ��x�������
{
	assert(psl);
	for (size_t i = 0; i < psl->size; i++)
	{
		if (psl->arr[i] == x)
		{
			SeqListErase(psl, i);
		}
	}

}
void SeqListRemoveALL(SeqList* psl, SLDataType x)//ɾ������x�������
{
	assert(psl);
	for (size_t i = 0; i < psl->size; i++)
	{
		if (psl->arr[i] == x)
		{
			SeqListErase(psl, i);
			i--;
		}

	}

}
void SeqListModify(SeqList* psl, size_t pos, SLDataType x)//posλ�õ������޸ĳ�x��ֵ
{
	assert(psl&&pos < psl->size);
	psl->arr[pos] = x;

}
void SeqListPrint(SeqList* psl){	assert(psl);	size_t i = 0;	for (i = 0; i < psl->size; i++)	{		printf("%d ", psl->arr[i]);	}	printf("\n");}