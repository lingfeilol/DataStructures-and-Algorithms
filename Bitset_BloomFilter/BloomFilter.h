#pragma once
#include "bitset.h"
#include<string>
#include <iostream>
using namespace std;
//��¡����������ӳ���ַ������ͣ���ͨ����ϣ����ת���ͣ���ӳ��  ����������ͬ�Ĺ�ϣ�º����࣬ÿһ��Ԫ��ӳ��������ͬ��bitλ��
//����ϣ��λͼ�Ľ�ϣ�����Ҳ��Ȼ���ڹ�ϣ��ͻ������
namespace MyBloomFilter
{

	struct HashStr1
	{
		//BKDR�㷨
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
		// RSHash�㷨
		size_t operator()(const string& s)
		{
			size_t count = 0;
			size_t magic = 63689; //ħ��
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
		// SDBMHash�㷨
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
			//ֻҪ��һ��ӳ��λ�ò����ڣ�����Բ�����
			if (_bs.testbit(index1) == false)
				return false;
			if (_bs.testbit(index2) == false)
				return false;
			if (_bs.testbit(index3) == false)
				return false;

			return true; // ��������Ҳ��һ��������ڣ����ǿ��ܴ�������   ���ܴ���һ��Ԫ��ӳ�������λ�ÿ�����������Ԫ��ӳ��Ĳ�ͬλ��
			// �ж��ڣ��ǲ�׼ȷ�ģ����ܴ�������
			// �жϲ��ڣ���׼ȷ
		}
		//void resetbit(const K& key)
		//{
			// ��ӳ���λ�ø���0�Ϳ���,������������ϣ������ӳ��λ�ã����Բ������ɾ��
			// ��֧��ɾ�������ܻ������ɾ��һ�㲼¡��������֧��ɾ��	
		//}

	private:
		MyBitSet::bitset _bs;//�ײ�Ҳ����λͼ��ֻ�����������˹�ϣ���������ַ�����˼�룬���м�����ϣ������Ҫ�࿪�����Ŀռ�
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

///�Һ���������ֻ����һ�ε�����
class sultion
{
	//��ǳ��ִ���
	void bitset(size_t x)
	{
		if (_bs1.testbit(x) == false && _bs2.testbit(x) == false) // 00 ����0�εģ���һ��λͼ����Ϊ1 -----��01������Ϊ����һ��
		{
			_bs2.setbit(x);
		}
		else if (_bs1.testbit(x) == false && _bs2.testbit(x) == true) //01 ,�����һ�ε� ------��10.����Ϊ��������
		{
			_bs1.setbit(x);
			_bs2.resetbit(x);
		}
		//����������������μ��������ϵ��ˣ����ù���
	}
	bool findone(size_t x) //�ж��Ƿ����һ�Σ���01״̬��
	{
		if (_bs1.testbit(x) == false && _bs2.testbit(x) == true)
			return true;
	}
	/////��������λͼ�У��ٱ���ÿһ���������Ƿ����һ�μ��ɵó���
private:
	MyBitSet::bitset _bs1; 
	MyBitSet::bitset _bs2;
};