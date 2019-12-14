#include"stack.h"

// 初始化栈
void StackInit(Stack* ps)
{
	ps->top = 0;
}
// 入栈
void StackPush(Stack* ps, STDataType data)
{
	ps->array[ps->top] = data;
	ps->top++;
}
// 出栈
void StackPop(Stack* ps)
{
	ps->top--;
}
// 获取栈顶元素
STDataType StackTop(Stack* ps)
{
	return  ps->array[ps->top];
}
// 获取栈中有效元素个数
int StackSize(Stack* ps)
{
	return ps->top;
}
// 检测栈是否为空，如果为空返回非零结果，如果不为空返回0
int StackEmpty(Stack* ps)
{
	return ps->top = 0 ? 1 : 0;
}
// 销毁栈
void StackDestroy(Stack* ps)
{
	ps->top = 0;
}