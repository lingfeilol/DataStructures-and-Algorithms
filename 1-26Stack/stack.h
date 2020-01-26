#pragma once
#include <stdio.h>
#include<malloc.h>

typedef int STDataType;
//֧�ֶ�̬������ջ�ṹ
typedef struct Stack
{
	STDataType* array;//����
	STDataType size;//��ЧԪ�ظ���
	STDataType capacity;//����
}Stack;

void CheckCapacity(Stack* ps); //�������
void StackInit(Stack* ps);//��ʼ��ջ
void StackPush(Stack* ps, STDataType x);//��ջ
void StackPop(Stack* ps);//��ջ
STDataType StackTop(Stack* ps);//��ȡջ��Ԫ��
int StackEmpty(Stack* ps);//�ж�ջ�Ƿ�Ϊ��
int StackSize(Stack* ps);//��ջ����ЧԪ��
void StackDestory(Stack* ps);//ջ������
