#include"CircularQueue.h"

int main()
{
	CQueue *q;
	QueueInit(&q);
	QueuePush(&q, 1);
	QueuePush(&q, 2);
	QueuePush(&q, 3);
	QueuePush(&q, 4);
	QueuePush(&q, 5);
	QueuePrintf(&q);

	QueuePop(&q);
	QueuePop(&q);
	QueuePrintf(&q);
	printf("%d ", QueueFront(&q));
	printf("%d ", QueueBack(&q));
	return 0;
}