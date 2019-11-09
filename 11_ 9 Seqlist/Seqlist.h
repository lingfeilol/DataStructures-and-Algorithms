//#pragma once
#ifndef _SEQLIST_H_
#define _SEQLIST_H_
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
typedef int SLDataType;
typedef struct SeqList
{
	SLDataType* arr;//指向动态开辟的数组
	size_t size;//有效数据个数
	size_t capicity;//容量空间的大小
}SeqList;
//typedef struct SeqList SeqList；


void SeqListInit(SeqList* psl, size_t capacity);//初始化。创建动态内存
void SeqListDestory(SeqList* psl);//销毁。释放动态内存
void CheckCapacity(SeqList* psl);//检查空间是否足够
void SeqListPushBack(SeqList* psl, SLDataType x);//尾插
void SeqListPopBack(SeqList* psl);//尾删
void SeqListPushFront(SeqList* psl, SLDataType x);//头插
void SeqListPopFront(SeqList* psl);//尾删
int SeqListFind(SeqList* psl, SLDataType x);//查找
void SeqListInsert(SeqList* psl, size_t pos, SLDataType x);//pos位置插入
void SeqListErase(SeqList* psl, size_t pos);//pos位置删除

void SeqListRemove(SeqList* psl, SLDataType x);//删除一个x这个数字
void SeqListRemoveALL(SeqList* psl, SLDataType x);//删除所有x这个数字


void SeqListModify(SeqList* psl, size_t pos, SLDataType x);//pos位置的数据修改成x的值

void SeqListPrint(SeqList* psl);//打印输出



#endif