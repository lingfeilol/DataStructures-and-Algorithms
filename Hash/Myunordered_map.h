#pragma once
#include <iostream>
#include <string>
#include "HashTable.h"
using namespace std;
using namespace OPEN_HASH;

namespace MyHashMap
{

	// unordered_map�д洢����pair<K, V>�ļ�ֵ�ԣ�KΪkey�����ͣ�VΪvalue�����ͣ�HashΪ��ϣ�������ͣ�����ָ���Ĺؼ������ͣ���Ӧ��ͬ��ģ��
	// unordered_map��ʵ��ʱ��ֻ�轫_maphash�еĽӿ����·�װ����
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
			pair<iterator, bool> ret = _maphash.Insert(make_pair(key, V()));  //�õ����صĽڵ�
			//return ret.first->second; //�ٷ��ؽڵ���� ��Ӧ��ֵ�������޸� ������ֵΪ���ã��Ҵ˶�������ʱ��������Ϊ���޸ĵ���ֵ 
			return ret.first->second;
		}
	private:
		HashTable<K, pair<K,V>, MapKeyOfT, Hash> _maphash;
	};



	void test_unordered_map()
	{
		unordered_map<string, string> dict;//����һ�� �ֵ�
		//����
		dict.Insert(make_pair("sort", "����"));
		dict.Insert(make_pair("left", "���"));
		dict.Insert(make_pair("string", "�ַ���"));
		//ʹ��[]���ļ���Ӧ��ֵ ������Ϊ����[]��ʹ�õ����÷��أ���Ϊ��ֵ�����Ա��޸�
		dict["left"] = "ʣ��"; //�޸�value
		dict["end"] = "β��";//���߲���

		//unordered_map<string, string>::iterator it = dict.begin();
		auto it = dict.begin();
		while (it != dict.end())
		{
			cout << it->first << ":" << it->second << endl;
			++it;
		}
	}
}
