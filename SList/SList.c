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
void SListPopBack(SListNode** pplist)//尾删
{
	SListNode* prev = NULL;
	SListNode* tail = *pplist;
	if (*pplist == NULL || tail->next == NULL)//为空或者只有一个节点
	{
		free(tail);
		*pplist == NULL;
	}
	else//有两个以上节点
	{
		while (tail->next)
		{
			prev = tail;//保留前一个结点
			tail = tail->next;
		}
		free(tail);
		tail = NULL;
		prev->next = NULL;

	}
}
void SListPopFront(SListNode** pplist)//头删
{
	SListNode* prev = *pplist;
	if (*pplist == NULL || prev->next == NULL)
	{
		free(prev);
		*pplist = NULL;
	}
	else
	{
		SListNode* next = prev->next;//先保留下一个
		free(prev);
		*pplist = next;
	}
}

// 单链表查找
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
// 单链表在pos位置之后插入x
// 分析思考为什么不在pos位置之前插入？
void SListInsertAfter(SListNode* pos, SLTDateType x)
{
	assert(pos);
	SListNode* cur = pos;
	SListNode* newnode = BuySListNode(x);
	newnode->next = cur->next->next;
	cur->next = newnode;
}

// 单链表删除pos位置之后的值
// 分析思考为什么不删除pos位置？
void SListEraseAfter(SListNode* pos)
{
	assert(pos);
	SListNode* next= pos->next;//保留pos下一个节点
	if (next)
	{
		pos->next = next->next;
		free(next);
	}
}