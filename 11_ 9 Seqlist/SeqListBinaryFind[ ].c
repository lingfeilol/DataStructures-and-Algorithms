#include"Seqlist.h"

int SeqListBinaryFind1(SeqList* psl, SLDataType x)//���ֲ���  ����ұ�[]���
{
	int begin = 0, end = psl->size - 1;//������� �ұ�����
	while (begin <= end)//ע���� <=��     ������ֻ������������������     [1,2]  begin=0;end=1; mid=0
	{
		int mid = (begin + end) / 2;
		if (psl->arr[mid]>x)
		{
			end = mid - 1;
		}
		else if (psl->arr[mid] < x)
		{
			begin = mid + 1;
		}
		else
			return mid;

	}
	return -1;
}