#pragma once
#include <iostream>
#include <string>
#include "HashTable.h"
using namespace std;
using namespace OPEN_HASH;

namespace MyHashMap
{

	// unordered_map中存储的是pair<K, V>的键值对，K为key的类型，V为value的类型，Hash为哈希函数类型，根据指定的关键字类型，对应不同的模板
	// unordered_map在实现时，只需将_maphash中的接口重新封装即可
	template<class K,class V,class Hash=Hash<K>>
	class unordered_map
	{
		struct MapKeyOfT
		{
			const K& operator()(const pair<K, V>& kv)
			{
				return kv.second;
			}
		};
	public:
		typedef typename HashTable<K, pair<K, V>, MapKeyOfT, Hash>::iterator iterator;
		iterator begin()
		{
			return _maphash.begin();
		}
		iterator end()
		{
			return _maphash.end();
		}
		pair<iterator, bool> Insert(const pair<K, V>& kv)
		{
			return _maphash.Insert(kv);
		}
		V& operator[](const K& key) 
		{
			pair<iterator, bool> ret = _maphash.Insert(make_pair(key, V()));  //得到返回的节点
			//return ret.first->second; //再返回节点里键 对应的值，用于修改 ，返回值为引用，且此对象不是临时变量，视为可修改的左值 
			return ret.first->second;
		}
	private:
		HashTable<K, pair<K,V>, MapKeyOfT, Hash> _maphash;
	};



	void test_unordered_map()
	{
		unordered_map<string, string> dict;//定义一个 字典
		//插入
		dict.Insert(make_pair("sort", "排序"));
		dict.Insert(make_pair("left", "左边"));
		dict.Insert(make_pair("string", "字符串"));
		//使用[]更改键对应的值 ，，因为重载[]是使用的引用返回，作为左值，可以被修改
		dict["left"] = "剩余"; //修改value
		dict["end"] = "尾部";//或者插入

		//unordered_map<string, string>::iterator it = dict.begin();
		auto it = dict.begin();
		while (it != dict.end())
		{
			cout << it->first << ":" << it->second << endl;
			++it;
		}
	}
}
