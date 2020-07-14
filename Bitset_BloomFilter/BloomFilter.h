#pragma once
#include "bitset.h"
#include<string>
#include <iostream>
using namespace std;
//布隆过滤器可以映射字符串类型，即通过哈希函数转整型，再映射  定义三个不同的哈希仿函数类，每一个元素映射三个不同的bit位，
//即哈希和位图的结合，但是也必然存在哈希冲突的问题
namespace MyBloomFilter
{

	struct HashStr1
	{
		//BKDR算法
		size_t operator()(const string& s)
		{
			size_t count = 0;
			for (size_t i = 0; i < s.size(); i++)
			{
				count *= 131;
				count += s[i];
			}
			return count;
		}
	};
	struct HashStr2
	{
		// RSHash算法
		size_t operator()(const string& s)
		{
			size_t count = 0;
			size_t magic = 63689; //魔数
			for (size_t i = 0; i < s.size(); i++)
			{
				count *= magic;
				count += s[i];
				magic *= 378551;
			}
			return count;
		}
	};
	struct HashStr3
	{
		// SDBMHash算法
		size_t operator()(const string& s)
		{
			size_t count = 0;
			for (size_t i = 0; i < s.size(); i++)
			{
				count *= 65599;
				count += s[i];
			}
			return count;
		}

	};
	template <class K=string, class Hash1 = HashStr1,class Hash2 = HashStr2,class Hash3 = HashStr3>
	class bloomfilter
	{
	public:
		bloomfilter(size_t N)
			:_bs(3*N)
			, _bitnum(3*N)
		{}
		void setbit(const K& key)
		{
			size_t index1 = Hash1()(key) % _bitnum;
			size_t index2 = Hash2()(key) % _bitnum;
			size_t index3 = Hash3()(key) % _bitnum;
			_bs.setbit(index1);
			_bs.setbit(index2);
			_bs.setbit(index3);
		}
		bool testbit(const K& key)
		{
			size_t index1 = Hash1()(key) % _bitnum;
			size_t index2 = Hash2()(key) % _bitnum;
			size_t index3 = Hash3()(key) % _bitnum;
			//只要有一个映射位置不存在，则绝对不存在
			if (_bs.testbit(index1) == false)
				return false;
			if (_bs.testbit(index2) == false)
				return false;
			if (_bs.testbit(index3) == false)
				return false;

			return true; // 但是这里也不一定是真的在，还是可能存在误判   可能存在一个元素映射的三个位置可能是其他的元素映射的不同位置
			// 判断在，是不准确的，可能存在误判
			// 判断不在，是准确
		}
		//void resetbit(const K& key)
		//{
			// 将映射的位置给置0就可以,但是是三个哈希函数的映射位置，所以不能随便删除
			// 不支持删除，可能会存在误删。一般布隆过滤器不支持删除	
		//}

	private:
		MyBitSet::bitset _bs;//底层也还是位图，只不过还利用了哈希函数处理字符串的思想，且有几个哈希函数便要多开几倍的空间
		size_t _bitnum;
	};

	void test_bloomfilter()
	{
		bloomfilter<std::string> bf(100);
		bf.setbit("abcd");
		bf.setbit("aadd");
		bf.setbit("bcad");

		cout << bf.testbit("abcd") << endl;
		cout << bf.testbit("aadd") << endl;
		cout << bf.testbit("bcad") << endl;
		cout << bf.testbit("cbad") << endl;
	}
}

///找海量数据里只出现一次的整数
class sultion
{
	//标记出现次数
	void bitset(size_t x)
	{
		if (_bs1.testbit(x) == false && _bs2.testbit(x) == false) // 00 出现0次的，则一个位图设置为1 -----》01，设置为出现一次
		{
			_bs2.setbit(x);
		}
		else if (_bs1.testbit(x) == false && _bs2.testbit(x) == true) //01 ,则出现一次的 ------》10.设置为出现两次
		{
			_bs1.setbit(x);
			_bs2.resetbit(x);
		}
		//其他的情况就是两次即两次以上的了，不用关心
	}
	bool findone(size_t x) //判断是否出现一次，即01状态的
	{
		if (_bs1.testbit(x) == false && _bs2.testbit(x) == true)
			return true;
	}
	/////遍历插入位图中，再遍历每一个数，看是否出现一次即可得出答案
private:
	MyBitSet::bitset _bs1; 
	MyBitSet::bitset _bs2;
};