#include"stack.h"

// ��ʼ��ջ
void StackInit(Stack* ps)
{
	ps->top = 0;
}
// ��ջ
void StackPush(Stack* ps, STDataType data)
{
	ps->array[ps->top] = data;
	ps->top++;
}
// ��ջ
void StackPop(Stack* ps)
{
	ps->top--;
}
// ��ȡջ��Ԫ��
STDataType StackTop(Stack* ps)
{
	return  ps->array[ps->top];
}
// ��ȡջ����ЧԪ�ظ���
int StackSize(Stack* ps)
{
	return ps->top;
}
// ���ջ�Ƿ�Ϊ�գ����Ϊ�շ��ط������������Ϊ�շ���0
int StackEmpty(Stack* ps)
{
	return ps->top = 0 ? 1 : 0;
}
// ����ջ
void StackDestroy(Stack* ps)
{
	ps->top = 0;
}