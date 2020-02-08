#pragma once

#include <stdio.h>
#include <malloc.h>

typedef char QuDataType;
// ��ʽ�ṹ����ʾ����
typedef struct QListNode
{
	struct QListNode* _next;
	QuDataType _data;
}QueueNode;

// ���еĽṹ
typedef struct Queue
{
	QueueNode* _front;
	QueueNode* _rear;
}Queue;

// ��ʼ������
void QueueInit(Queue* q);

// ��β�����
void QueuePush(Queue* q, QuDataType data);

// ��ͷ������
void QueuePop(Queue* q);

// ��ȡ����ͷ��Ԫ��
QuDataType QueueFront(Queue* q);

// ��ȡ���ж�βԪ��
QuDataType QueueBack(Queue* q);

// ��ȡ��������ЧԪ�ظ���
int QueueSize(Queue* q);

// �������Ƿ�Ϊ�գ����Ϊ�շ��ط�����������ǿշ���0
int QueueEmpty(Queue* q);

// ���ٶ���
void QueueDestroy(Queue* q);