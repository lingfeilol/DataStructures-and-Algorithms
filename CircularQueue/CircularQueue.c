#include"CircularQueue.h"
// 初始化队列
void QueueInit(CQueue* q)
{
	q->front = q->rear = 0; //初始化成一个空的循环队列
}

// 队尾入队列
void QueuePush(CQueue* q, CQDataType data)
{
	if ((q->rear + 1) % MAXSIZE != q->front)//队列没满
	{
		q->arr[q->rear] = data;
		q->rear = (q->rear + 1) % MAXSIZE;  //重新设置队尾指针
	}
}

// 队头出队列
void QueuePop(CQueue* q)
{
	if (q->front != q->rear)//队列不为空
	{
		q->front = (q->front + 1) % MAXSIZE;
	}
}

// 获取队列头部元素
CQDataType QueueFront(CQueue* q)
{
	return q->arr[q->front-1];
}

// 获取队列队尾元素
CQDataType QueueBack(CQueue* q)
{
	return q->arr[q->rear-1];
}

// 检测队列是否为满，如果为满返回非零结果，如果非满返回0
int QueueFull(CQueue* q)
{
	return (q->rear + 1) % MAXSIZE == q->front; //尾指针加一追上头指针，标志队列已经满了
}
// 检测队列是否为空，如果为空返回非零结果，如果非空返回0
int QueueEmpty(CQueue* q)
{
	return q->front==q->rear;     //队头队尾相遇为空
}

// 销毁队列
void QueueDestroy(CQueue* q)
{
	q->front = q->rear = 0;
}
//打印
void QueuePrintf(CQueue* q)
{
	for (int i = q->front; i < q->rear;i++)
	{
		printf("%d ", q->arr[i]);
	}
}