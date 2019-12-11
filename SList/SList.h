#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

// ����+����ͷ+ѭ��
typedef int SLTDateType;
typedef struct SListNode
{
	SLTDateType data;
	struct SListNode* next;
}SListNode;

SListNode* BuySListNode(SLTDateType x);//�����ڵ�
void SListPrint(SListNode* plist);//��ӡ����
void SListPushBack(SListNode** pplist, SLTDateType x);//β��
void SListPushFront(SListNode** pplist, SLTDateType x);//ͷ��
void SListPopBack(SListNode** pplist);//βɾ
void SListPopFront(SListNode** pplist);//ͷɾ



// ���������
SListNode* SListFind(SListNode* plist, SLTDateType x);//����һ���ڵ�

void SListInsertAfter(SListNode* pos, SLTDateType x);//pos�����

void SListEraseAfter(SListNode* pos);//pos��ɾ��