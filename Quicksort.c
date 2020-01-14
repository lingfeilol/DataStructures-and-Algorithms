快排
单趟排序 只需要排完后左边都是小于基准的    基准值  右边都是大于基准的
begin 找大的     end 找小的
int partsort(int *a,int begin,int end)//传一个数组和区间
{
	int key=begin;//选第一个为基准   先走最左边的end
	while（begin<end）
	{
		while(begin<end &&a[end]>=a[key] )//比基准大就继续走，要加等号
		{
			--end;
		}
		while(begin<end &&a[begin]<=a[key] )/比基准小就继续走，
		{
			++begin;
		}
		swap(&a[begin],&a[end]);//停下后交换一次，再继续迭代走
	}
	
	swap(&a[key],&a[begin]);//最后再把基准值和停下的位置一换就结束了
	return begin;//把中间的基准值的位置保留下来
}
快排就像是二叉树的类似结构，要用到递归分治的思想
void Quicksort(int *a,int left,int right)
{
	if(left>=right)//特殊情况  1 3 5 4， 1为基准时，end没找到比它小的一直减减，直到它本身了，此时left=right; 1左边全是大于它的，右边全是小于它的，就不用再排一趟了
		return ;
	int keyindex=partsort(a,left,right);
	// [left,keyindex-1]    keyindex   [keyindex+1,right]   二叉树结构  左区间 基准值 右区间  继续递归
	
	Quicksort(a,left,keyindex-1);//基准值左边（大于它的）继续划分
	Quicksort(a,keyindex+1,right);//基准值右边（小于它的）也继续
	直到最小的都已经有序（划分好了）
}



有序数组的话 用快排就是最坏的情况 O（N^2）
每次选基准都选到中位数最好   O（N*logN） 二叉树结构的深度相似
