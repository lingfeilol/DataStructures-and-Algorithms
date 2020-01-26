#include "Queue.h"
QueueNode * BuyQueueNode(QuDataType x)    //创建节点
{
	QueueNode * cur = (QueueNode *)malloc(sizeof(QueueNode));
	cur->_data = x;
	cur->_next = NULL;
	return cur;
}
void QueueInit(Queue* q) //初始化队列结构
{
	q->_front = NULL;
	q->_rear = NULL;
}
void QueuePush(Queue* q, QuDataType x)  //队列尾部入数据
{
	QueueNode * cur = BuyQueueNode(x);  //先把创建好的节点传过来
	if (q->_front == NULL)             //若是队列本身为空，队列里就只有这一个节点，又为队列头又为队列尾
	{
		q->_front = q->_rear = cur; 
	}
	else
	{
		q->_rear->_next = cur; //否则，链表尾插操作
		q->_rear = cur;
	}
}
void QueuePop(Queue* q)     //队列头部出数据
{
	if (q->_front == NULL)
	{
		return;
    }
	QueueNode* tmp = q->_front->_next;   //先保留下一个节点，防止断链
	free(q->_front);
	q->_front = tmp;   //更新对列头部
}
QuDataType QueueFront(Queue* q)   //获取队列首部元素
{
	return q->_front->_data;
}
QuDataType QueueBack(Queue* q)//获取队列尾部元素
{
	return q->_rear->_data;
}
int QueueEmpty(Queue* q)   //判断队列是否为空
{
	return q->_front == NULL;   //为空，返回1
}
int QueueSize(Queue* q)  //获取队列中的元素个数
{
	QueueNode * cur;
	int count = 0;
	for (cur = q->_front; cur; cur = cur->_next)
	{
		count++;
	}
	return count;
}
void QueueDestory(Queue* q)  //销毁队列
{
	if (q->_front == NULL)
	{
		return;
	}
	while (q->_front)
	{
		QueuePop(q);//对每一个元素迭代出队即可
	}
}