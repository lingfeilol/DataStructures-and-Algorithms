#include"Seqlist.h"
int SeqListBinaryFind2(SeqList* psl, SLDataType x)//���ֲ���  ����ҿ�[�����
{
	int begin = 0, end = psl->size;//������� �ҿ�����
	while (begin < end)//ע���� <��     Ҳ����������������������     [1,2��3]  begin=0;end=3; mid=1��
	{
		int mid = (begin + end) / 2;
		if (psl->arr[mid]>x)
		{
			end = mid;//�����1�Ļ����˴�д��end=mid-1;�Ļ�begin==end==0��û�������ˣ�
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