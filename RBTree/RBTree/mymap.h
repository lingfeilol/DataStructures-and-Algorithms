#pragma once
#include "RBTree.h"
namespace mytest
{
	template<class T,class V>
	class map
	{
		struct KeyofT  //ȡ��ֵ�ķº�����
		{
			const T& operator()(const pair<T,V>& data)
			{
				return data.first;
			}
		};
	public:
		typedef typename RBTree<T, pair<T, V>, KeyofT> ::iterator iterator;
		iterator begin()
		{
			return _rbtree.begin();
		}
		iterator end()
		{
			return _rbtree.end();
		}
		pair<iterator, bool> Insert(const pair<T, V>& data)
		{
			return _rbtree.Insert(data);
		}
		//��ʵ��[]�����ʱ���ڲ���ʵ�ǵ�����һ��insert�������.�����Ǽ�ֵ�������������Ƕ���pair�ṹ��ĵڶ������ݣ�
		//ֱ�ӵ�������������͵Ĺ��캯��������һ����������V()Ϊ0��
		V& operator[](const T& key)
		{
			pair<iterator, bool> ret = _rbtree.Insert({ key, V() }); // V()����0
			return ret.first->second;
		}

	private:
		RBTree<T, T, KeyofT> _rbtree;
	};

	void test_map()
	{
		/*map<int, int> m;
		m.Insert(make_pair(1, 1));
		m.Insert(make_pair(3, 3));
		m.Insert(make_pair(10, 10));
		m.Insert(make_pair(5, 5));
		m.Insert(make_pair(6, 6));

		map<int, int>::iterator it = m.begin();
		while (it != m.end())
		{
		cout << it->first << ":" << it->second << endl;
		++it;
		}
		cout << endl;

		for (auto kv : m)
		{
		cout << kv.first << ":" << kv.second << endl;
		}

		cout << endl;*/

		string strs[] = { "����", "ӣ��", "����", "ƻ��", "����", "����", "����", "ƻ��" };
		map<string, int> countMap;
		for (auto& str : strs)
		{
			// 1�����ˮ������map�У���operator[]�����pair<str, 0>, ����ӳ�����(����)�����ý�����++��
			// 2�����ˮ����map�У���operator[]����ˮ����Ӧ��ӳ�����(����)�����ã�����++��
			countMap[str]++;
		}

		for (auto kv : countMap)
		{
			cout << kv.first << ":" << kv.second << endl;
		}
	}
}