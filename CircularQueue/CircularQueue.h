#pragma once

#include<stdio.h>
#define MAXSIZE 20  //�������ռ�
typedef  int  CQDataType;
typedef struct CircularQueue
{
	CQDataType arr[MAXSIZE];
	int front;  //��ͷָ��ָʾ��
	int rear;   //��βָ��ָʾ��
}CQueue;


// ��ʼ������
void QueueInit(CQueue* q);

// ��β�����
void QueuePush(CQueue* q, CQDataType data);

// ��ͷ������
void QueuePop(CQueue* q);

// ��ȡ����ͷ��Ԫ��
CQDataType QueueFront(CQueue* q);

// ��ȡ���ж�βԪ��
CQDataType QueueBack(CQueue* q);

// ��ȡ��������ЧԪ�ظ���
int QueueSize(CQueue* q);

// �������Ƿ�Ϊ�գ����Ϊ�շ��ط�����������ǿշ���0
int QueueEmpty(CQueue* q);

// ���ٶ���
void QueueDestroy(CQueue* q);

//��ӡ
void QueuePrintf(CQueue* q);