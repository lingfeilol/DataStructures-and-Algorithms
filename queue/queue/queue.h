#pragma once
#include<stdio.h>
#include<assert.h>

typedef int QDataType;
typedef struct Node
{
	QDataType val;
	struct Node *next;
} Node;
//ͷɾ��β��
typedef struct Queue{
	Node* front;   //�����һ���ڵ�
	Node* rear;		//�������һ���ڵ�
	QDataType size; //���ݸ���
}Queue;

// ��ʼ������
void QueueInit(Queue* q);
// ��β����� ����β��
void QueuePush(Queue* q, QDataType data);
// ��ͷ������  ����ͷɾ
void QueuePop(Queue* q);
// ��ȡ����ͷ��Ԫ��
QDataType QueueFront(Queue* q);
// ��ȡ���ж�βԪ��
QDataType QueueBack(Queue* q);
// ��ȡ��������ЧԪ�ظ���
int QueueSize(Queue* q);
// �������Ƿ�Ϊ�գ����Ϊ�շ��ط�����������ǿշ���0
int QueueEmpty(Queue* q);
// ���ٶ���
void QueueDestroy(Queue* q);
