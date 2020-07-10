#pragma once
#include "RBTree.h"
namespace mytest
{
	template<class T,class V>
	class map
	{
		struct KeyofT  //取键值的仿函数类
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
		//在实现[]运算符时，内部其实是调用了一次insert插入操作.由于是键值对类型所以我们对于pair结构体的第二个数据，
		//直接调用这个数据类型的构造函数，创建一个匿名对象即V()为0。
		V& operator[](const T& key)
		{
			pair<iterator, bool> ret = _rbtree.Insert({ key, V() }); // V()便是0
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

		string strs[] = { "西瓜", "樱桃", "西瓜", "苹果", "西瓜", "西瓜", "西瓜", "苹果" };
		map<string, int> countMap;
		for (auto& str : strs)
		{
			// 1、如果水果不在map中，则operator[]会插入pair<str, 0>, 返回映射对象(次数)的引用进行了++。
			// 2、如果水边在map中，则operator[]返回水果对应的映射对象(次数)的引用，对它++。
			countMap[str]++;
		}

		for (auto kv : countMap)
		{
			cout << kv.first << ":" << kv.second << endl;
		}
	}
}