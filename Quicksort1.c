
快排优化
1.三数区中法   最左边  中间   最右边三个数中的中位数的下标
先找出数组中三者之间中间数的下标 作为快排的基准值
int Gitmidindex(int *a,int begin,int end)
{
	int mid=(begin+end)/2;
	if(a[begin]<a[mid])
	{
		if(a[end]>a[mid])
		{
			return mid;
		}
		else if(a[[begin]>a[end]])
		{
			return begin;
		}
		else
			return end;
	}
	else //a[begin]>a[mid]
	{
		if(a[mid]>a[end])
		{
			return mid; 
		}
		else if(a[end]>a[begin])
		{
			return begin;
		}
		else
			return end;
	
	}
	
int partsort(int *a,int begin,int end)//传一个数组和区间
{
	int mid=Gitmidindex(a,begin,end)//选出中间的那个数
	swap(&a[mid],&a[begin]);//与开头的那个基准值交换，确保最开始时是用中位数做基准值的
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
	
	
2.挖坑法
和之前一样的思路，只不过顾名思义把基准值挖个坑
	
int partsort2(int *a,int begin,int end)
{
	int mid=Gitmidindex(a,begin,end)
	swap(&a[mid],&a[begin]);
	//begin是第一个坑位
	int key=a[begin];//直接把值给key，自己变为一个坑，啥也没有了
	while（begin<end）
	{
		while(begin<end &&a[end]>=key )//比基准大就继续走，要加等号
		{
			--end;
		}
		a[begin]=a[end];//小的就填进去
		while(begin<end &&a[begin]<=key )/比基准小就继续走，
		{
			++begin;
		}
		a[end]=a[begin];//大了也填到新坑位里
	}
	
	a[begin]=key;//最后再把基准值填到最后一个坑里
	return begin;//把中间的基准值的位置保留下来
}
	
	
	
3.前后指针法
prev  cur找小的
int partsort2(int *a,int begin,int end)
{
	int prev=begin-1;
	int cur=begin;
	int key=end;
	while(cur<end)//终止条件
	
	{
		if(a[cur]<a[key])
		{
			++prev;
			swap(&a[cur],&a[prev]);
			++cur;
		}
		else
			++cur;
	}
	swap(&a[++prev],&a[key]);
	return prev;

}