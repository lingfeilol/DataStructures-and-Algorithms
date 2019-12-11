#include"DSList.h"


// �������������ͷ���.
ListNode* ListCreate()
{
	ListNode* head = (ListNode*)malloc(sizeof(ListNode));
	if (head != NULL)
	{
		head->next = head;
		head->prev = head;
	}
	return head;
}
//�����ڵ�
ListNode* Buynode(LTDataType x)
{
	ListNode* node = (ListNode*)malloc(sizeof(ListNode));
	if (node != NULL)
		node->data = x;
		node->prev = NULL;
		node->next = NULL;
	return node;
}
// ˫����������
void ListDestory(ListNode* plist)
{
	ListNode*head = plist->next;
	while (head!= plist)
	{
		ListNode* cur = head;//�ȱ�������ڵ�
		cur = cur->next;
		free(cur);
		cur = NULL;
	}
}
// ˫�������ӡ
void ListPrint(ListNode* plist)
{
	assert(plist);
	ListNode* cur = plist->next;
	while (cur != plist)
	{
		printf("%d->", cur->data);
		cur = cur->next;
	}
	return NULL;
}

// ˫������β��
void ListPushBack(ListNode* plist, LTDataType x)
{
	assert(plist);
	ListNode* tail = plist->prev;
	ListNode* newnode = Buynode(x);
	if (plist->next == plist)//������ֻ��һ��ͷ�ڵ�
	{
		//ͷ�ڵ�  newnode
		plist->next = newnode;
		newnode->prev = plist;
		newnode->next = plist;
		plist->prev = newnode;
	}
	else//���������������ϵĽڵ�
	{
		//ͷ�ڵ�    β�ڵ�tail   newnode
		newnode->next = plist;
		plist->prev = newnode;
		tail->next = newnode;
		newnode->prev = tail;
	}
		

}
// ˫������βɾ
void ListPopBack(ListNode* plist)
{
	ListNode* cur= plist->prev->prev;
	ListNode* tail = plist->prev;
	if (plist->next == plist)//ֻ��һ��ͷ���
	{
		return ;
	}
	else
		//ͷ�ڵ�     tail   β�ڵ�   
	{
		cur->next = plist;
		plist->prev = cur;
		free(tail);
		tail = NULL;
	}
	
}
// ˫������ͷ��
void ListPushFront(ListNode* plist, LTDataType x)
{
	//ListNode* head =plist;
	ListNode* first = plist->next;
	ListNode* newnode = Buynode(x);
	if (plist->next == plist)//ֻ��һ��ͷ�ڵ�
	{
		plist->next = newnode;
		newnode->next = plist;
		newnode->prev = plist;
		plist->prev = newnode;
	}
	else
		// ͷ�ڵ�  ����   ��һ����Ч�ڵ�first
	{
		plist->next = newnode;
		newnode->next = first;
		newnode->prev = plist;
		first->prev = newnode;
	}
	
}
// ˫������ͷɾ
void ListPopFront(ListNode* plist)
{
	ListNode* first= plist->next;
	if (plist->next == plist)//ֻ��һ��ͷ�ڵ�
		return;
	else
	{
		plist->next = first->next;
		first->next->prev = plist;
		free(first);
		first = NULL;
	}
	
}

// ˫���������
ListNode* ListFind(ListNode* plist, LTDataType x)
{
	assert(plist);
	ListNode* head = plist->next;
	if (head == plist)
		return;
	while (head != plist)
	{
		if (head->data == x)
		{
			return head;
		}
		head = head->next;
	}
}
// ˫��������pos��ǰ����в���
void ListInsert(ListNode* pos, LTDataType x)
{
	assert(pos);
	// pos->prev  newnode   pos
	ListNode* newnode = Buynode(x);
	newnode->next = pos;
	pos->prev->next= newnode;
	pos->prev = newnode;
	newnode->prev = pos->prev;

}
// ˫������ɾ��posλ�õĽڵ�
void ListErase(ListNode* pos)
{
	// pos->prev  ɾ��pos  pos->next
	pos->prev->next = pos->next;
	pos->next->prev = pos->prev;
	free(pos);
	pos = NULL;
}
