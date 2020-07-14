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
			_bits.resize(N / 32 + 1, 0);  //ÿ���ֽ�ӳ��һ��Ԫ�أ����������������ÿһ������Ԫ��ռ��32λ���أ�����ֻ��Ҫ�� N/32�Ŀռ�����ӳ�䵽ÿһ��ֵ
			_bitcount = 0;
		}
		void setbit(size_t x) //��������xԪ��ӳ�䵽λͼ�У�����ӳ��λ����Ϊ1��
		{
			size_t index = x / 32; //�������ӳ���ھ����Ǹ����͵�32bit��
			size_t pos = x % 32;  //����������Ǹ�bitλ
			_bits[index] |= (1 << pos); //����bitλ��Ϊ1        //����λͼ�ﶼ�ǳ�ʼ��Ϊ0�ģ���λ�����������һΪһ����posλ��bit��Ϊ1
			_bitcount++;
		}
		void resetbit(size_t x)//�Ƴ�λͼ��x��Ӧ��bitλ��ɾ��
		{
			size_t index = x / 32;
			size_t pos = x % 32;
			_bits[index] &= ~(1 << pos); //����bitλ��λ0   //����Ӱ�쵽������λ�ã����ҵ�posλ�ã���ȡ��������λ��Ϊ1�ˣ���λΪ0���ٰ�λ&��������posλbit��Ϊ0������λ��Ӱ��
			_bitcount--;
		}
		bool testbit(size_t x)// �ж�x�ڲ���(Ҳ����˵xӳ���λ�Ƿ�Ϊ1)
		{
			size_t index = x / 32;
			size_t pos = x % 32;
			return _bits[index] & (1 << pos); //ֻ���жϣ��������ã���λ&����
		}

	private:
		vector <int> _bits;   //λͼ��ֻ�ܴ洢����
		size_t _bitcount; //ӳ��洢�Ķ��ٸ���Ч����
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