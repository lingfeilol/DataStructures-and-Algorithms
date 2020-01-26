#include "stack.h"
int main()
{
	Stack ps;
	StackInit(&ps);
	StackPush(&ps, 1);
	StackPush(&ps, 2);
	StackPush(&ps, 3);
	StackPush(&ps, 4);//1 2 3 4������ջ 

	printf("%d\n",StackTop(&ps));//ջ��Ԫ�� 4
	StackPop(&ps);  //4��ջ
	printf("%d\n", StackTop(&ps));//3Ϊջ��
	StackPop(&ps);//3��ջ
	printf("%d\n", StackTop(&ps));//2Ϊջ��
	StackPop(&ps);//2��ջ
	return 0;
}