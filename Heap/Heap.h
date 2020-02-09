#pragma once
#include<stdio.h>
#include <string.h>
#include <malloc.h>
typedef int HPDataType;
typedef struct Heap
{
	HPDataType* _a;
	int _size;  //有效元素个数
	int _capacity;//容量
}Heap;
// 堆的构建
void HeapCreate(Heap* hp, HPDataType* a, int n);
// 堆的销毁
void HeapDestory(Heap* hp);
// 堆的插入
void HeapPush(Heap* hp, HPDataType x);
// 堆的删除
void HeapPop(Heap* hp);
// 取堆顶的数据
HPDataType HeapTop(Heap* hp);
// 堆的数据个数
int HeapSize(Heap* hp);
// 堆的判空
int HeapEmpty(Heap* hp);
//堆的打印
void HeapPrintf(Heap* hp);
// 对数组进行堆排序
void HeapSort(int* a, int n);