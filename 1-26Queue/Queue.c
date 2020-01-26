#include "Queue.h"
QueueNode * BuyQueueNode(QuDataType x)    //�����ڵ�
{
	QueueNode * cur = (QueueNode *)malloc(sizeof(QueueNode));
	cur->_data = x;
	cur->_next = NULL;
	return cur;
}
void QueueInit(Queue* q) //��ʼ�����нṹ
{
	q->_front = NULL;
	q->_rear = NULL;
}
void QueuePush(Queue* q, QuDataType x)  //����β��������
{
	QueueNode * cur = BuyQueueNode(x);  //�ȰѴ����õĽڵ㴫����
	if (q->_front == NULL)             //���Ƕ��б���Ϊ�գ��������ֻ����һ���ڵ㣬��Ϊ����ͷ��Ϊ����β
	{
		q->_front = q->_rear = cur; 
	}
	else
	{
		q->_rear->_next = cur; //��������β�����
		q->_rear = cur;
	}
}
void QueuePop(Queue* q)     //����ͷ��������
{
	if (q->_front == NULL)
	{
		return;
    }
	QueueNode* tmp = q->_front->_next;   //�ȱ�����һ���ڵ㣬��ֹ����
	free(q->_front);
	q->_front = tmp;   //���¶���ͷ��
}
QuDataType QueueFront(Queue* q)   //��ȡ�����ײ�Ԫ��
{
	return q->_front->_data;
}
QuDataType QueueBack(Queue* q)//��ȡ����β��Ԫ��
{
	return q->_rear->_data;
}
int QueueEmpty(Queue* q)   //�ж϶����Ƿ�Ϊ��
{
	return q->_front == NULL;   //Ϊ�գ�����1
}
int QueueSize(Queue* q)  //��ȡ�����е�Ԫ�ظ���
{
	QueueNode * cur;
	int count = 0;
	for (cur = q->_front; cur; cur = cur->_next)
	{
		count++;
	}
	return count;
}
void QueueDestory(Queue* q)  //���ٶ���
{
	if (q->_front == NULL)
	{
		return;
	}
	while (q->_front)
	{
		QueuePop(q);//��ÿһ��Ԫ�ص������Ӽ���
	}
}