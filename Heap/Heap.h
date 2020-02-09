#pragma once
#include<stdio.h>
#include <string.h>
#include <malloc.h>
typedef int HPDataType;
typedef struct Heap
{
	HPDataType* _a;
	int _size;  //��ЧԪ�ظ���
	int _capacity;//����
}Heap;
// �ѵĹ���
void HeapCreate(Heap* hp, HPDataType* a, int n);
// �ѵ�����
void HeapDestory(Heap* hp);
// �ѵĲ���
void HeapPush(Heap* hp, HPDataType x);
// �ѵ�ɾ��
void HeapPop(Heap* hp);
// ȡ�Ѷ�������
HPDataType HeapTop(Heap* hp);
// �ѵ����ݸ���
int HeapSize(Heap* hp);
// �ѵ��п�
int HeapEmpty(Heap* hp);
//�ѵĴ�ӡ
void HeapPrintf(Heap* hp);
// ��������ж�����
void HeapSort(int* a, int n);