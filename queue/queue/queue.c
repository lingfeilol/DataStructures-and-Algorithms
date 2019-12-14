#include"queue.h"



// ��ʼ������
void QueueInit(Queue* q)
{
	q->front = NULL;
	q->rear = NULL;
	q->size = 0;
}
// ��β�����  ����β��
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
	else  //Ϊ��ʱ
	{
		q->front = q->rear = newnode;
	}
}
// ��ͷ������  ����ͷɾ
void QueuePop(Queue* q)
{
	assert(q->size > 0);
	q->size--;
	Node* cur = q->front;//�ȱ���ͷ�ڵ�
	q->front = q->front->next;
	free(cur);
	if (q->front == NULL)//��ֻ��һ���ڵ��ʱ��ͷ���ͷź� β�ڵ�ҲӦ��ָ��NULL
		q->rear = NULL;
}
// ��ȡ����ͷ��Ԫ������
QDataType QueueFront(Queue* q)
{
	return q->front->val;
}
// ��ȡ���ж�βԪ��
QDataType QueueBack(Queue* q)
{
	return q->rear->val;
}
// ��ȡ��������ЧԪ�ظ���
int QueueSize(Queue* q)
{
	return q->size;
}
// �������Ƿ�Ϊ�գ����Ϊ�շ��ط�����������ǿշ���0
int QueueEmpty(Queue* q)
{
	return q->size = 0 ? 1 : 0;
}
// ���ٶ���
void QueueDestroy(Queue* q)
{
	assert(q);
	while (q->front)
	{
		Queuepop(q);
	}

}
