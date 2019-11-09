//#pragma once
#ifndef _SEQLIST_H_
#define _SEQLIST_H_
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
typedef int SLDataType;
typedef struct SeqList
{
	SLDataType* arr;//ָ��̬���ٵ�����
	size_t size;//��Ч���ݸ���
	size_t capicity;//�����ռ�Ĵ�С
}SeqList;
//typedef struct SeqList SeqList��


void SeqListInit(SeqList* psl, size_t capacity);//��ʼ����������̬�ڴ�
void SeqListDestory(SeqList* psl);//���١��ͷŶ�̬�ڴ�
void CheckCapacity(SeqList* psl);//���ռ��Ƿ��㹻
void SeqListPushBack(SeqList* psl, SLDataType x);//β��
void SeqListPopBack(SeqList* psl);//βɾ
void SeqListPushFront(SeqList* psl, SLDataType x);//ͷ��
void SeqListPopFront(SeqList* psl);//βɾ
int SeqListFind(SeqList* psl, SLDataType x);//����
void SeqListInsert(SeqList* psl, size_t pos, SLDataType x);//posλ�ò���
void SeqListErase(SeqList* psl, size_t pos);//posλ��ɾ��

void SeqListRemove(SeqList* psl, SLDataType x);//ɾ��һ��x�������
void SeqListRemoveALL(SeqList* psl, SLDataType x);//ɾ������x�������


void SeqListModify(SeqList* psl, size_t pos, SLDataType x);//posλ�õ������޸ĳ�x��ֵ

void SeqListPrint(SeqList* psl);//��ӡ���



#endif