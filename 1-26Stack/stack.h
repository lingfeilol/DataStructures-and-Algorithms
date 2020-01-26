#pragma once
#include <stdio.h>
#include<malloc.h>

typedef int STDataType;
//支持动态生长的栈结构
typedef struct Stack
{
	STDataType* array;//数组
	STDataType size;//有效元素个数
	STDataType capacity;//容量
}Stack;

void CheckCapacity(Stack* ps); //容量检测
void StackInit(Stack* ps);//初始化栈
void StackPush(Stack* ps, STDataType x);//入栈
void StackPop(Stack* ps);//出栈
STDataType StackTop(Stack* ps);//获取栈顶元素
int StackEmpty(Stack* ps);//判断栈是否为空
int StackSize(Stack* ps);//求栈的有效元素
void StackDestory(Stack* ps);//栈的销毁
