#include "stack.h"
int main()
{
	Stack ps;
	StackInit(&ps);
	StackPush(&ps, 1);
	StackPush(&ps, 2);
	StackPush(&ps, 3);
	StackPush(&ps, 4);//1 2 3 4依次入栈 

	printf("%d\n",StackTop(&ps));//栈顶元素 4
	StackPop(&ps);  //4出栈
	printf("%d\n", StackTop(&ps));//3为栈顶
	StackPop(&ps);//3出栈
	printf("%d\n", StackTop(&ps));//2为栈顶
	StackPop(&ps);//2出栈
	return 0;
}