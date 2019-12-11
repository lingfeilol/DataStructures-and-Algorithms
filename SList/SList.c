#include"SList.h"


SListNode* BuySListNode(SLTDateType x)
{	
	SListNode* node = (SListNode*)malloc(sizeof(SListNode));
	node->data = x;
	node->next = NULL;
	return node;
}
void SListPrint(SListNode* plist)
{
	SListNode* cur = plist;
	while (cur)
	{
		printf("%d->", cur->data);
		cur = cur->next;
	}
	printf("NULL\n");
}
void SListPushBack(SListNode** pplist, SLTDateType x)
{
	SListNode* newnode = BuySListNode(x);
	if (*pplist == NULL)
	{
		*pplist = newnode;
	}
	else
	{
		SListNode* tail = *pplist;
		while (tail->next)
		{
			tail = tail->next;
		}
		tail -> next = newnode;
	}
}
void SListPushFront(SListNode** pplist, SLTDateType x)
{
	SListNode* newnode = BuySListNode(x);
	if (*pplist == NULL)
	{
		*pplist = newnode;
	}
	else
	{
		newnode->next = *pplist;
		*pplist = newnode;
	}
}
void SListPopBack(SListNode** pplist)//βɾ
{
	SListNode* prev = NULL;
	SListNode* tail = *pplist;
	if (*pplist == NULL || tail->next == NULL)//Ϊ�ջ���ֻ��һ���ڵ�
	{
		free(tail);
		*pplist == NULL;
	}
	else//���������Ͻڵ�
	{
		while (tail->next)
		{
			prev = tail;//����ǰһ�����
			tail = tail->next;
		}
		free(tail);
		tail = NULL;
		prev->next = NULL;

	}
}
void SListPopFront(SListNode** pplist)//ͷɾ
{
	SListNode* prev = *pplist;
	if (*pplist == NULL || prev->next == NULL)
	{
		free(prev);
		*pplist = NULL;
	}
	else
	{
		SListNode* next = prev->next;//�ȱ�����һ��
		free(prev);
		*pplist = next;
	}
}

// ���������
SListNode* SListFind(SListNode* plist, SLTDateType x)
{
	if (plist == NULL)
	{
		return NULL;
	}
	SListNode* cur = plist;
	while (cur->next)
	{
		if (cur->data == x)
		{
			return cur;
		}
		cur = cur->next;
	}
	return NULL;
}
// ��������posλ��֮�����x
// ����˼��Ϊʲô����posλ��֮ǰ���룿
void SListInsertAfter(SListNode* pos, SLTDateType x)
{
	assert(pos);
	SListNode* cur = pos;
	SListNode* newnode = BuySListNode(x);
	newnode->next = cur->next->next;
	cur->next = newnode;
}

// ������ɾ��posλ��֮���ֵ
// ����˼��Ϊʲô��ɾ��posλ�ã�
void SListEraseAfter(SListNode* pos)
{
	assert(pos);
	SListNode* next= pos->next;//����pos��һ���ڵ�
	if (next)
	{
		pos->next = next->next;
		free(next);
	}
}