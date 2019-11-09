#include"Seqlist.h"


void test()
{
	SeqList psl;
	SeqListInit(&psl, 5);//初始化

	
	SeqListPushBack(&psl, 0);//尾插
	SeqListPushBack(&psl, 1);
	SeqListPushBack(&psl, 2);
	SeqListPushBack(&psl, 3);
	SeqListPushBack(&psl, 4);
	SeqListPushBack(&psl, 5);

	SeqListPopBack(&psl);//尾删
	SeqListPopBack(&psl);
	SeqListPopBack(&psl);

	SeqListPrint(&psl);

}
void test2()
{
	SeqList psl;
	SeqListInit(&psl, 5);//初始化


	SeqListPushBack(&psl, 0);//尾插
	SeqListPushBack(&psl, 1);
	SeqListPushBack(&psl, 2);
	SeqListPushBack(&psl, 3);
	SeqListPushBack(&psl, 4);
	SeqListPushBack(&psl, 5);

	SeqListPushFront(&psl, 2);//头插
	//SeqListPopFront(&psl);//头删

	SeqListPrint(&psl);
	
}
void test3()
{
	SeqList psl;
	SeqListInit(&psl, 5);//初始化


	SeqListPushBack(&psl, 0);//尾插
	SeqListPushBack(&psl, 1);
	SeqListPushBack(&psl, 2);
	SeqListPushBack(&psl, 3);
	SeqListPushBack(&psl, 4);
	SeqListPushBack(&psl, 5);

	//SeqListFind(&psl, 4);//查找
	SeqListPrint(&psl);
	SeqListInsert(&psl, 3, 10);//pos位置插入
	SeqListPrint(&psl);

	SeqListErase(&psl, 3);//pos位置删除
	SeqListPrint(&psl); 

	SeqListRemove(&psl, 10);//删除x这个数字
	SeqListPrint(&psl);
	
}
void test4()
{
	SeqList psl;
	SeqListInit(&psl, 5);//初始化


	SeqListPushBack(&psl, 0);//尾插
	SeqListPushBack(&psl, 1);
	SeqListPushBack(&psl, 2);
	SeqListPushBack(&psl, 3);
	SeqListPushBack(&psl, 3);
	SeqListPushBack(&psl, 5);
	SeqListPrint(&psl);


	//SeqListModify(&psl, 3, 10);//pos位置的数据修改成x的值
	//SeqListPrint(&psl);
	SeqListRemoveALL(&psl, 3);
	SeqListPrint(&psl);

}
int main()
{
	test4();
	return 0;
}