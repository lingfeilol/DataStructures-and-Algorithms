#include <stdio.h>

#include "DSList.h"

void TestDSList1()
{
	ListNode* plist = NULL;
	plist=ListCreate();
	ListPushBack(plist, 1);
	ListPushBack(plist, 2);
	ListPushBack(plist, 3);
	ListPushBack(plist, 4);
	ListPrint(plist);
}

void TestDSList2()
{
	ListNode* plist = ListCreate();
	ListPushFront(plist, 1);
	ListPushFront(plist, 2);
	ListPushFront(plist, 3);
	ListPushFront(plist, 4);

	ListPrint(plist);
}
void TestDSList3()
{
	ListNode* plist = ListCreate();
	ListPushBack(plist, 1);
	ListPushBack(plist, 2);
	ListPushBack(plist, 3);
	ListPushFront(plist, 4);
	ListPopFront(plist);
	ListPopBack(plist);
	


	ListPrint(plist);
}

void TestDSList4()
{
	ListNode* plist = ListCreate();
	ListPushBack(plist, 1);
	ListPushBack(plist, 2);
	ListPushBack(plist, 3);
	ListPushBack(plist, 4);

	ListInsert(ListFind(plist, 1), 100);

	//ListErase(ListFind(plist, 2));

	ListPrint(plist);
}

int main()
{
	TestDSList4();

	return 0;
}