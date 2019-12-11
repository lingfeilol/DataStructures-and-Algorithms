#include"DSList.h"


// 创建返回链表的头结点.
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
//创建节点
ListNode* Buynode(LTDataType x)
{
	ListNode* node = (ListNode*)malloc(sizeof(ListNode));
	if (node != NULL)
		node->data = x;
		node->prev = NULL;
		node->next = NULL;
	return node;
}
// 双向链表销毁
void ListDestory(ListNode* plist)
{
	ListNode*head = plist->next;
	while (head!= plist)
	{
		ListNode* cur = head;//先保留这个节点
		cur = cur->next;
		free(cur);
		cur = NULL;
	}
}
// 双向链表打印
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

// 双向链表尾插
void ListPushBack(ListNode* plist, LTDataType x)
{
	assert(plist);
	ListNode* tail = plist->prev;
	ListNode* newnode = Buynode(x);
	if (plist->next == plist)//链表里只有一个头节点
	{
		//头节点  newnode
		plist->next = newnode;
		newnode->prev = plist;
		newnode->next = plist;
		plist->prev = newnode;
	}
	else//链表里有两个以上的节点
	{
		//头节点    尾节点tail   newnode
		newnode->next = plist;
		plist->prev = newnode;
		tail->next = newnode;
		newnode->prev = tail;
	}
		

}
// 双向链表尾删
void ListPopBack(ListNode* plist)
{
	ListNode* cur= plist->prev->prev;
	ListNode* tail = plist->prev;
	if (plist->next == plist)//只有一个头结点
	{
		return ;
	}
	else
		//头节点     tail   尾节点   
	{
		cur->next = plist;
		plist->prev = cur;
		free(tail);
		tail = NULL;
	}
	
}
// 双向链表头插
void ListPushFront(ListNode* plist, LTDataType x)
{
	//ListNode* head =plist;
	ListNode* first = plist->next;
	ListNode* newnode = Buynode(x);
	if (plist->next == plist)//只有一个头节点
	{
		plist->next = newnode;
		newnode->next = plist;
		newnode->prev = plist;
		plist->prev = newnode;
	}
	else
		// 头节点  插入   第一个有效节点first
	{
		plist->next = newnode;
		newnode->next = first;
		newnode->prev = plist;
		first->prev = newnode;
	}
	
}
// 双向链表头删
void ListPopFront(ListNode* plist)
{
	ListNode* first= plist->next;
	if (plist->next == plist)//只有一个头节点
		return;
	else
	{
		plist->next = first->next;
		first->next->prev = plist;
		free(first);
		first = NULL;
	}
	
}

// 双向链表查找
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
// 双向链表在pos的前面进行插入
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
// 双向链表删除pos位置的节点
void ListErase(ListNode* pos)
{
	// pos->prev  删除pos  pos->next
	pos->prev->next = pos->next;
	pos->next->prev = pos->prev;
	free(pos);
	pos = NULL;
}
