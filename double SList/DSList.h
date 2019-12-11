// ��ͷ+˫��+ѭ��������ɾ���ʵ��
#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef int LTDataType;
typedef struct ListNode
{
	LTDataType data;
	struct ListNode* next;
	struct ListNode* prev;
}ListNode;


// �������������ͷ���.
ListNode* ListCreate();
//�����ڵ�
ListNode* Buynode(LTDataType x);
// ˫����������
void ListDestory(ListNode* plist);
// ˫�������ӡ
void ListPrint(ListNode* plist);
// ˫������β��
void ListPushBack(ListNode* plist, LTDataType x);
// ˫������βɾ
void ListPopBack(ListNode* plist);
// ˫������ͷ��
void ListPushFront(ListNode* plist, LTDataType x);
// ˫������ͷɾ
void ListPopFront(ListNode* plist);
// ˫���������
ListNode* ListFind(ListNode* plist, LTDataType x);
// ˫��������pos��ǰ����в���
void ListInsert(ListNode* pos, LTDataType x);
// ˫������ɾ��posλ�õĽڵ�
void ListErase(ListNode* pos);////4.˳����������������ϵ
//˳���һ���ڰٳ�
//�ף��ռ�������֧���������
//��1.�м��ǰ�沿�ֵĲ���ɾ��ʱ�临�Ӷ�O(N) 2.���ݵĴ��۱Ƚϴ�
//����һ(��)������
//�ڣ��Խڵ�Ϊ��λ�洢����֧���������
//���У�1.����λ�ò���ɾ��ʱ�临�Ӷ�ΪO(1) 2.û���������⣬����һ������һ���ռ䡣