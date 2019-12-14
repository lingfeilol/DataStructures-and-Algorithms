#include"queue.h"



// 初始化队列
void QueueInit(Queue* q)
{
	q->front = NULL;
	q->rear = NULL;
	q->size = 0;
}
// 队尾入队列  链表尾插
void QueuePush(Queue* q, QDataType data)
{
	Node* newnode = (Node*)malloc(sizeof(Node));
	newnode->val = data;
	newnode->next = NULL;
	q->size++;
	if (q->rear != NULL)
	{
		q->rear->next = newnode;
		q->rear = newnode;
	}
	else  //为空时
	{
		q->front = q->rear = newnode;
	}
}
// 队头出队列  链表头删
void QueuePop(Queue* q)
{
	assert(q->size > 0);
	q->size--;
	Node* cur = q->front;//先保存头节点
	q->front = q->front->next;
	free(cur);
	if (q->front == NULL)//但只有一个节点的时候头被释放后 尾节点也应该指向NULL
		q->rear = NULL;
}
// 获取队列头部元素数据
QDataType QueueFront(Queue* q)
{
	return q->front->val;
}
// 获取队列队尾元素
QDataType QueueBack(Queue* q)
{
	return q->rear->val;
}
// 获取队列中有效元素个数
int QueueSize(Queue* q)
{
	return q->size;
}
// 检测队列是否为空，如果为空返回非零结果，如果非空返回0
int QueueEmpty(Queue* q)
{
	return q->size = 0 ? 1 : 0;
}
// 销毁队列
void QueueDestroy(Queue* q)
{
	assert(q);
	while (q->front)
	{
		Queuepop(q);
	}

}
