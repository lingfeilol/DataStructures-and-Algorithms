// 带头+双向+循环链表增删查改实现
#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef int LTDataType;
typedef struct ListNode
{
	LTDataType data;
	struct ListNode* next;
	struct ListNode* prev;
}ListNode;


// 创建返回链表的头结点.
ListNode* ListCreate();
//创建节点
ListNode* Buynode(LTDataType x);
// 双向链表销毁
void ListDestory(ListNode* plist);
// 双向链表打印
void ListPrint(ListNode* plist);
// 双向链表尾插
void ListPushBack(ListNode* plist, LTDataType x);
// 双向链表尾删
void ListPopBack(ListNode* plist);
// 双向链表头插
void ListPushFront(ListNode* plist, LTDataType x);
// 双向链表头删
void ListPopFront(ListNode* plist);
// 双向链表查找
ListNode* ListFind(ListNode* plist, LTDataType x);
// 双向链表在pos的前面进行插入
void ListInsert(ListNode* pos, LTDataType x);
// 双向链表删除pos位置的节点
void ListErase(ListNode* pos);////4.顺序表和链表的区别和联系
//顺序表：一白遮百丑
//白：空间连续、支持随机访问
//丑：1.中间或前面部分的插入删除时间复杂度O(N) 2.增容的代价比较大。
//链表：一(黑)毁所有
//黑：以节点为单位存储，不支持随机访问
//所有：1.任意位置插入删除时间复杂度为O(1) 2.没有增容问题，插入一个开辟一个空间。