#pragma once
#include<vector>
using namespace std;

namespace MyBitSet
{
	class bitset
	{
	public:
		bitset(int N)
		{
			_bits.resize(N / 32 + 1, 0);  //每个字节映射一个元素，而这个整型数组里每一个整形元素占用32位比特，所以只需要开 N/32的空间便可以映射到每一个值
			_bitcount = 0;
		}
		void setbit(size_t x) //将此整型x元素映射到位图中，即该映射位置置为1，
		{
			size_t index = x / 32; //算出具体映射在具体那个整型的32bit里
			size_t pos = x % 32;  //算出具体在那个bit位
			_bits[index] |= (1 << pos); //将此bit位置为1        //本来位图里都是初始化为0的，按位或操作，即有一为一，将pos位的bit置为1
			_bitcount++;
		}
		void resetbit(size_t x)//移除位图中x对应的bit位，删除
		{
			size_t index = x / 32;
			size_t pos = x % 32;
			_bits[index] &= ~(1 << pos); //将此bit位置位0   //不能影响到其他的位置，先找到pos位置，再取反，其他位就为1了，此位为0，再按位&操作，将pos位bit置为0，其他位不影响
			_bitcount--;
		}
		bool testbit(size_t x)// 判断x在不在(也就是说x映射的位是否为1)
		{
			size_t index = x / 32;
			size_t pos = x % 32;
			return _bits[index] & (1 << pos); //只是判断，并不设置，按位&操作
		}

	private:
		vector <int> _bits;   //位图里只能存储整型
		size_t _bitcount; //映射存储的多少个有效数据
	};

	void test_bitset()
	{
		bitset bs(100);
		bs.setbit(99);
		bs.setbit(98);
		bs.setbit(97);
		bs.setbit(5);
		bs.resetbit(98);

		for (size_t i = 0; i < 100; ++i)
		{
			printf("[%d]:%d\n", i, bs.testbit(i));
		}

		//bitset bs(-1);
		//bitset bs(0xffffffff);

	}
}