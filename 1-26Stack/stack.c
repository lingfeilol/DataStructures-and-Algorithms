
#include "stack.h"
#define DEFSTACKSIZE 50
//容量检测
void CheckCapacity(Stack* ps)
{
	if (ps->size >= ps->capacity)
	{
		ps->capacity *= 2;    //2倍扩容
		ps->array = (STDataType *)realloc(ps->array, ps->capacity * sizeof(STDataType));      //ralloc：在array后继续申请空间
	}
}
void StackInit(Stack* ps)//初始化
{
	ps->array = (STDataType *)calloc(DEFSTACKSIZE, sizeof(STDataType));//calloc:申请数组空间并初始化为0
	ps->capacity = DEFSTACKSIZE;
	ps->size = 0;
}
void StackPush(Stack* ps, STDataType x) //数组尾部添加数据 即入栈
{
	CheckCapacity(ps);
	ps->array[ps->size] = x;
	ps->size++;
}
void StackPop(Stack* ps)//出栈
{
	if (ps->size == 0)
	{
		return;
	}
	ps->size--;
}
STDataType StackTop(Stack* ps)//获取栈顶元素
{
	if (ps->size == 0)//栈为空时即没有任何元素
	{
		return (STDataType)0;
	}
	return ps->array[ps->size - 1];//有元素时，返回栈顶元素
}
int StackEmpty(Stack* ps)//栈判空
{
	return ps->size == 0;
}
int StackSize(Stack* ps)//获取里有效元素个数
{
	return ps->size;
}
void StackDestory(Stack* ps)//栈的销毁
{
	if (ps->array)
	{
		free(ps->array);//一定要释放申请的内存
		ps->array = NULL;//且要置空，否则时悬空指针 即释放了内存，但是还是指向的之前指向的那个地址
		ps->size = 0;
		ps->capacity = 0;
	}
}