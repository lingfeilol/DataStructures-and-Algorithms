#pragma once
#include "HashTable.h"

using namespace OPEN_HASH;
namespace MyHashSet
{
	template<class K,class V,class Hash=Hash<K>>
	class unordered_set
	{
		struct SetKeyOfT
		{
			const K& operator()(const K& key)
			{
				return key;
			}
		};

	public:
		typedef typename HashTable<K, V, SetKeyOfT, Hash> ::iterator iterator;
		iterator begin()
		{
			return _hashset.begin();
		}
		iterator end()
		{
			return _hashset.end();
		}
		pair<iterator, bool> Insert(const K& key)
		{
			return _hashset.Insert(key);
		}
		//�����ӿ�Ҳ���ǻ��ڵײ��_hashset�Ľӿں���
	private:
		HashTable<K, V, SetKeyOfT, Hash> _hashset;
	};

	void test_unordered_set()
	{
		unordered_set<int,int> s;
		s.Insert(1);
		s.Insert(5);
		s.Insert(4);
		s.Insert(2);

		unordered_set<int,int>::iterator it = s.begin();
		while (it != s.end())
		{
			cout << *it << " ";
			++it;
		}
		cout << endl;
	}
}