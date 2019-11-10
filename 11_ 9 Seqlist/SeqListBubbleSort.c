#include"Seqlist.h"
void SeqListBubbleSort(SeqList* psl)
{

	while (psl->size--)
	{
		int i = 0;
		int  kongzhi = 0;
		for (i = 0; i <= psl->size; i++)
		{
			if (psl->arr[i] > psl->arr[i + 1])
			{
				int tmp;
				tmp = psl->arr[i];
				psl->arr[i] = psl->arr[i + 1];
				psl->arr[i + 1] = tmp;
				kongzhi = 1;
			}
		}
		if (kongzhi == 0)
		{
			return;
		}

	}

}