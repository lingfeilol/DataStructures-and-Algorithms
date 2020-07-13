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
		//其他接口也都是基于底层的_hashset的接口函数
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