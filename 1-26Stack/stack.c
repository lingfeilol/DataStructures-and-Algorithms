
#include "stack.h"
#define DEFSTACKSIZE 50
//�������
void CheckCapacity(Stack* ps)
{
	if (ps->size >= ps->capacity)
	{
		ps->capacity *= 2;    //2������
		ps->array = (STDataType *)realloc(ps->array, ps->capacity * sizeof(STDataType));      //ralloc����array���������ռ�
	}
}
void StackInit(Stack* ps)//��ʼ��
{
	ps->array = (STDataType *)calloc(DEFSTACKSIZE, sizeof(STDataType));//calloc:��������ռ䲢��ʼ��Ϊ0
	ps->capacity = DEFSTACKSIZE;
	ps->size = 0;
}
void StackPush(Stack* ps, STDataType x) //����β��������� ����ջ
{
	CheckCapacity(ps);
	ps->array[ps->size] = x;
	ps->size++;
}
void StackPop(Stack* ps)//��ջ
{
	if (ps->size == 0)
	{
		return;
	}
	ps->size--;
}
STDataType StackTop(Stack* ps)//��ȡջ��Ԫ��
{
	if (ps->size == 0)//ջΪ��ʱ��û���κ�Ԫ��
	{
		return (STDataType)0;
	}
	return ps->array[ps->size - 1];//��Ԫ��ʱ������ջ��Ԫ��
}
int StackEmpty(Stack* ps)//ջ�п�
{
	return ps->size == 0;
}
int StackSize(Stack* ps)//��ȡ����ЧԪ�ظ���
{
	return ps->size;
}
void StackDestory(Stack* ps)//ջ������
{
	if (ps->array)
	{
		free(ps->array);//һ��Ҫ�ͷ�������ڴ�
		ps->array = NULL;//��Ҫ�ÿգ�����ʱ����ָ�� ���ͷ����ڴ棬���ǻ���ָ���֮ǰָ����Ǹ���ַ
		ps->size = 0;
		ps->capacity = 0;
	}
}