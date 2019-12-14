#pragma once
#include<stdio.h>
#include<assert.h>

typedef int QDataType;
typedef struct Node
{
	QDataType val;
	struct Node *next;
} Node;
//头删和尾插
typedef struct Queue{
	Node* front;   //链表第一个节点
	Node* rear;		//链表最后一个节点
	QDataType size; //数据个数
}Queue;

// 初始化队列
void QueueInit(Queue* q);
// 队尾入队列 链表尾插
void QueuePush(Queue* q, QDataType data);
// 队头出队列  链表头删
void QueuePop(Queue* q);
// 获取队列头部元素
QDataType QueueFront(Queue* q);
// 获取队列队尾元素
QDataType QueueBack(Queue* q);
// 获取队列中有效元素个数
int QueueSize(Queue* q);
// 检测队列是否为空，如果为空返回非零结果，如果非空返回0
int QueueEmpty(Queue* q);
// 销毁队列
void QueueDestroy(Queue* q);
