#pragma once
#include "RBTree.h"

namespace mytest
{
	template<class T>
	class set
	{
		struct KeyofT  //取键值的仿函数类
		{
			const T& operator()(const T& data)
			{
				return data;//因为set只有一个键值，所以传参的data就是一个键值
			}
		};
	public:
		typedef typename RBTree<T, T, KeyofT>::iterator  iterator;

		iterator begin()
		{
			return _rbtree.begin();
		}
		iterator end()
		{
			return _rbtree.end();
		}
		pair<iterator, bool> Insert(const T& T)
		{
			return _rbtree.Insert(T);
		}
	private:
		RBTree<T, T, KeyofT> _rbtree;
	};
	void test_set()
	{
		set<int> s;
		s.Insert(3);
		s.Insert(4);
		s.Insert(1);
		s.Insert(2);
		s.Insert(5);

		set<int>::iterator it = s.begin();
		while (it != s.end())
		{
			cout << *it << " ";
			++it;
		}
		cout << endl;
	}
}