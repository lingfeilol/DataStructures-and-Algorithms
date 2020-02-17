#include"CircularQueue.h"
// ��ʼ������
void QueueInit(CQueue* q)
{
	q->front = q->rear = 0; //��ʼ����һ���յ�ѭ������
}

// ��β�����
void QueuePush(CQueue* q, CQDataType data)
{
	if ((q->rear + 1) % MAXSIZE != q->front)//����û��
	{
		q->arr[q->rear] = data;
		q->rear = (q->rear + 1) % MAXSIZE;  //�������ö�βָ��
	}
}

// ��ͷ������
void QueuePop(CQueue* q)
{
	if (q->front != q->rear)//���в�Ϊ��
	{
		q->front = (q->front + 1) % MAXSIZE;
	}
}

// ��ȡ����ͷ��Ԫ��
CQDataType QueueFront(CQueue* q)
{
	return q->arr[q->front-1];
}

// ��ȡ���ж�βԪ��
CQDataType QueueBack(CQueue* q)
{
	return q->arr[q->rear-1];
}

// �������Ƿ�Ϊ�������Ϊ�����ط������������������0
int QueueFull(CQueue* q)
{
	return (q->rear + 1) % MAXSIZE == q->front; //βָ���һ׷��ͷָ�룬��־�����Ѿ�����
}
// �������Ƿ�Ϊ�գ����Ϊ�շ��ط�����������ǿշ���0
int QueueEmpty(CQueue* q)
{
	return q->front==q->rear;     //��ͷ��β����Ϊ��
}

// ���ٶ���
void QueueDestroy(CQueue* q)
{
	q->front = q->rear = 0;
}
//��ӡ
void QueuePrintf(CQueue* q)
{
	for (int i = q->front; i < q->rear;i++)
	{
		printf("%d ", q->arr[i]);
	}
}