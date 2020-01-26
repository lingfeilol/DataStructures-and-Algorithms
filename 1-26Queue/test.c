#include "Queue.h"

int main()
{
	Queue q;
	QueueInit(&q);
	QueuePush(&q, 1);
	QueuePush(&q, 2);
	QueuePush(&q, 3);
	QueuePush(&q, 4);

	printf("%d\n", QueueFront(&q)); //1
	QueuePop(&q);
	printf("%d\n", QueueFront(&q));//2

	printf("%d\n", QueueBack(&q));//4

	return 0;
}