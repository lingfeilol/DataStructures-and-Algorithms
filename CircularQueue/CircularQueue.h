#pragma once

#include<stdio.h>
#define MAXSIZE 20  //队列最大空间
typedef  int  CQDataType;
typedef struct CircularQueue
{
	CQDataType arr[MAXSIZE];
	int front;  //对头指针指示器
	int rear;   //对尾指针指示器
}CQueue;


// 初始化队列
void QueueInit(CQueue* q);

// 队尾入队列
void QueuePush(CQueue* q, CQDataType data);

// 队头出队列
void QueuePop(CQueue* q);

// 获取队列头部元素
CQDataType QueueFront(CQueue* q);

// 获取队列队尾元素
CQDataType QueueBack(CQueue* q);

// 获取队列中有效元素个数
int QueueSize(CQueue* q);

// 检测队列是否为空，如果为空返回非零结果，如果非空返回0
int QueueEmpty(CQueue* q);

// 销毁队列
void QueueDestroy(CQueue* q);

//打印
void QueuePrintf(CQueue* q);