#include"Seqlist.h"


void test()
{
	SeqList psl;
	SeqListInit(&psl, 5);//��ʼ��

	
	SeqListPushBack(&psl, 0);//β��
	SeqListPushBack(&psl, 1);
	SeqListPushBack(&psl, 2);
	SeqListPushBack(&psl, 3);
	SeqListPushBack(&psl, 4);
	SeqListPushBack(&psl, 5);

	SeqListPopBack(&psl);//βɾ
	SeqListPopBack(&psl);
	SeqListPopBack(&psl);

	SeqListPrint(&psl);

}
void test2()
{
	SeqList psl;
	SeqListInit(&psl, 5);//��ʼ��


	SeqListPushBack(&psl, 0);//β��
	SeqListPushBack(&psl, 1);
	SeqListPushBack(&psl, 2);
	SeqListPushBack(&psl, 3);
	SeqListPushBack(&psl, 4);
	SeqListPushBack(&psl, 5);

	SeqListPushFront(&psl, 2);//ͷ��
	//SeqListPopFront(&psl);//ͷɾ

	SeqListPrint(&psl);
	
}
void test3()
{
	SeqList psl;
	SeqListInit(&psl, 5);//��ʼ��


	SeqListPushBack(&psl, 0);//β��
	SeqListPushBack(&psl, 1);
	SeqListPushBack(&psl, 2);
	SeqListPushBack(&psl, 3);
	SeqListPushBack(&psl, 4);
	SeqListPushBack(&psl, 5);

	//SeqListFind(&psl, 4);//����
	SeqListPrint(&psl);
	SeqListInsert(&psl, 3, 10);//posλ�ò���
	SeqListPrint(&psl);

	SeqListErase(&psl, 3);//posλ��ɾ��
	SeqListPrint(&psl); 

	SeqListRemove(&psl, 10);//ɾ��x�������
	SeqListPrint(&psl);
	
}
void test4()
{
	SeqList psl;
	SeqListInit(&psl, 5);//��ʼ��


	SeqListPushBack(&psl, 0);//β��
	SeqListPushBack(&psl, 1);
	SeqListPushBack(&psl, 2);
	SeqListPushBack(&psl, 3);
	SeqListPushBack(&psl, 3);
	SeqListPushBack(&psl, 5);
	SeqListPrint(&psl);


	//SeqListModify(&psl, 3, 10);//posλ�õ������޸ĳ�x��ֵ
	//SeqListPrint(&psl);
	SeqListRemoveALL(&psl, 3);
	SeqListPrint(&psl);

}
int main()
{
	test4();
	return 0;
}