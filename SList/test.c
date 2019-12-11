#include <stdio.h>

#include "SList.h"

void TestSList1()
{
	SListNode* plist = NULL;
	SListPushBack(&plist, 1);
	SListPushBack(&plist, 2);
	SListPushBack(&plist, 3);
	SListPushBack(&plist, 4);

	SListPrint(plist);

	SListPopBack(&plist);
	SListPrint(plist);

	SListPopBack(&plist);
	SListPrint(plist);

	SListPopBack(&plist);
	SListPrint(plist);

	SListPopBack(&plist);
	SListPrint(plist);
}

void TestSList2()
{
	SListNode* plist = NULL;
	SListPushFront(&plist, 1);
	SListPushFront(&plist, 2);
	SListPushFront(&plist, 3);
	SListPushFront(&plist, 4);

	SListPrint(plist);
}
void TestSList3()
{
	SListNode* plist = NULL;
	SListPushBack(&plist, 1);
	SListPushBack(&plist, 2);
	SListPushBack(&plist, 3);
	SListPushBack(&plist, 4);
	SListNode* ret=SListFind(plist,2);//���ҷ��ص��ǽڵ㣬����Ϊ��
	if (ret != NULL)
		ret->data = 100;//�ҵ����޸�����ڵ��ֵ
	SListPrint(plist);


	SListNode* pos = SListFind(plist, 100);
	SListInsertAfter(pos, 200);//�����������ʹ�ã����ҵ��ڵ㣬�ٴ��Σ����ڴ˽ڵ�����
	SListPrint(plist);


	SListNode* pos1 = SListFind(plist, 100);
	SListEraseAfter(pos1);
	SListPrint(plist);

	
}

int main()
{
	TestSList3();

	return 0;
}