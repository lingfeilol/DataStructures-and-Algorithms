#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

// 单向+不带头+循环
typedef int SLTDateType;
typedef struct SListNode
{
	SLTDateType data;
	struct SListNode* next;
}SListNode;

SListNode* BuySListNode(SLTDateType x);//创建节点
void SListPrint(SListNode* plist);//打印链表
void SListPushBack(SListNode** pplist, SLTDateType x);//尾插
void SListPushFront(SListNode** pplist, SLTDateType x);//头插
void SListPopBack(SListNode** pplist);//尾删
void SListPopFront(SListNode** pplist);//头删



// 单链表查找
SListNode* SListFind(SListNode* plist, SLTDateType x);//返回一个节点

void SListInsertAfter(SListNode* pos, SLTDateType x);//pos后插入

void SListEraseAfter(SListNode* pos);//pos后删除