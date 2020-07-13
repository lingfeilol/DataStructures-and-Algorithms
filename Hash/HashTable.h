#pragma once
#include <vector>
#include <iostream>
using namespace std;

template<class K>
struct SetKeyOfT
{
	const K& operator()(const K& key)
	{
		return key;
	}
};


//哈希冲突解决：
//1.闭散列哈希 也叫开放定址法，当发生哈希冲突时，如果哈希表未被装满，说明在哈希表中必然还有空位置，那么可以把key存放到冲突位置中的“下一个” 空位置中去
//而找这个下一个位置，又分为线性探测和二次探测
namespace CLOSE_HASH
{
	// 哈希表每个空间给个标记
	// EMPTY此位置空， EXIST此位置已经有元素， DELETE元素已经删除
	enum State{ EMPTY, EXIST, DELETE };

	//节点定义
	template <class T>
	struct HashData
	{
		T _data;
		State _state;
	};
	template <class K, class T, class KeyOfT>
	class HashTable
	{
		typedef HashData<T> HashData;
	public:
		KeyOfT koft;
		// 负载因子 = 表中数据/表的大小 衡量哈希表满的程度
		// 表越接近满，插入数据越容易冲突，冲突越多，效率越低
		// 负载因子越小，冲突概率越低，整体效率越高，但是负载因子越小，浪费的空间越大，
		// 哈希表并不是满了才增容，开放定制法中，一般负载因子到了0.7左右就开始增容
		bool Insert(const T& data)
		{
			////扩容的一般的做法：
			//if (_hashtable.size() == 0 || _num * 10 / _hashtable.size() >= 7) //hash表里为空，或者该扩容
			//{
			//	// 1.开2倍大小的新表
			//	// 2.遍历旧表的数据，重新计算在新表中位置
			//	// 3.释放旧表
			//	//1.
			//	vector<HashData> newtable;
			//	size_t newtablesize = _hashtable.size() == 0 ? 10 : _hashtable.size() * 2;
			//	newtable.resize(newtablesize);
			//	//2.
			//	for (int i = 0; i < _hashtable.size(); i++)
			//	{
			//		if (_hashtable[i]._state == EXIST) //找到旧表中的有效数据，重新计算映射到新表中去
			//		{
			//			size_t index = koft(_hashtable[i]._data) % newtablesize;
			//			while (newtable[index]._state == EXIST)//哈希冲突时，使用线性探测找下一个空位置
			//			{
			//				++index;
			//				if (index == newtablesize)//回到开头继续找
			//				{
			//					index = 0;
			//				}
			//			}
			//			newtable[index] = _hashtable[i];//插入
			//		}
			//	}
			//	_hashtable.swap(newtable);
			//}

			//利用insert插入，可以根据不同的探测方式来具体的插入
			if (_hashtable.size() == 0 || _num * 10 / _hashtable.size() >= 7) //hash表里为空，或者该扩容
			{
				HashTable<K, T, KeyOfT> newhashtable;//开一个对象
				size_t newtablesize = _hashtable.size() == 0 ? 10 : _hashtable.size() * 2;
				newhashtable._hashtable.resize(newtablesize);
				for (size_t i = 0; i < _hashtable.size(); i++)
				{
					if (_hashtable[i]._state == EXIST)
					{
						newhashtable.Insert(_hashtable[i]._data);//继续利用insert函数把数据插入到新的空间
					}
				}
				_hashtable.swap(newhashtable._hashtable);
			}
			//容量没满，则开始插入逻辑

			//线性探测
			//先计算data在哈希表里的映射位置
			//size_t index = koft(data) % _hashtable.size();
			//while (_hashtable[index]._state == EXIST)
			//{
			//	if (koft(_hashtable[index]._data) == koft(data))//不允许键值重复
			//		return false;
			//	++index; //线性探测
			//	index %= _hashtable.size();
			//}
			//_hashtable[index]._data = data;
			//_hashtable[index]._state = EXIST;
			//_num++;
			//return true;

			//二次探测
			size_t start = koft(data) % _hashtable.size();
			size_t index = start;
			int i = 1;
			while (_hashtable[index]._state == EXIST)
			{
				if (koft(_hashtable[index]._data) == koft(data))//不允许键值重复
					return false;
				index = start + i*i;//二次探测
				i++;
				index %= _hashtable.size();
			}
			_hashtable[index]._data = data;
			_hashtable[index]._state = EXIST;
			_num++;
			return true;
		}
		//根据键值查找，也是先计算其映射的位置，但是可能是存在探测后的位置，所以需要向后一直遍历去找，直到遇到空
		HashData* Find(const K& key)
		{
			KeyOfT koft;
			size_t index = key%_hashtable.size();
			while (_hashtable[index]._state != EMPTY)
			{
				if (koft(_hashtable[index]._data) == key)
				{
					if (_hashtable[index]._state == EXIST)
					{
						return &_hashtable[index];
					}
					else if (_hashtable[index]._state == DELETE)
					{
						return nullptr;
					}
				}
				++index;
				index %= _hashtable.size();
			}
			return nullptr;
		}

		bool Erase(const K& key)
		{
			HashData* ret = Find(key);
			if (ret)
			{
				ret->_state = DELETE;
				--_num;
				return true;
			}
			return false;
		}
	private:
		vector<HashData> _hashtable; //映射表
		size_t _num = 0; //有效数据个数
	};


	void TestHashTable()
	{
		HashTable<int, int, SetKeyOfT<int>> ht;
		ht.Insert(4);
		ht.Insert(14);
		ht.Insert(24);
		ht.Insert(5);
		ht.Insert(15);
		ht.Insert(25);
		ht.Insert(6);
		ht.Insert(16);
	}
}
//2.开散列法又叫链地址法(开链法)，首先对关键码集合用散列函数计算散列地址，具有相同地址的关键码
//归于同一子集合，每一个子集合称为一个桶，各个桶中的元素通过一个单链表链接起来，各链表的头结点存储在哈希表中。
namespace OPEN_HASH
{
	//节点结构
	template<class T>
	struct HashNode
	{
		T _data;
		HashNode<T>* _next;
		HashNode(const T& data)
			:_data(data)
			, _next(nullptr)
		{}
	};


	// 前置声明
	template<class K, class T, class KeyOfT, class Hash>
	class HashTable;

	//连地址法的桶结构的迭代器
	template <class K,class T,class KeyOfT,class Hash>
	struct hashiterator
	{
		typedef HashNode<T> Node;
		typedef HashTable<K, T, KeyOfT, Hash> HT;
		typedef hashiterator<K, T, KeyOfT, Hash> self;

		Node* _node;// 当前迭代器关联的节点
		HT* _ht;  // 哈希桶--主要是为了找下一个空桶时候方便

		hashiterator(Node* node,HT* ht)
			:_node(node)
			, _ht(ht)
		{}

		T& operator*()
		{
			return _node->_data;
		}

		T* operator->()
		{
			return &_node->_data;
		}
		// 注意：因为哈希桶在底层是单链表结构，所以哈希桶的迭代器不需要--操作
		self& operator++()
		{
			// 当前迭代器所指节点后还有节点时直接取其下一个节点
			if (_node->_next)
				_node = _node->_next;
			else // 找下一个不空的桶，返回该桶中第一个节点
			{
				KeyOfT koft;
				size_t index = _ht->HashFunc(koft(_node->_data)) % _ht->_hashtable.size();
				index++;
				for (; index < _ht->_hashtable.size(); index++)
				{
					Node* cur = _ht->_hashtable[index];//判断下一个桶是否为空
					if (cur)
					{
						_node = cur;
						return *this;
					}
				}
				_node = nullptr;//后面一个也没有，则置空返回
			}
			return *this;	
		}
		bool operator!=(const self& s)
		{
			return _node != s._node;
		}
		bool operator==(const self& s)
		{
			return _node == s._node;
		}

	};

	template<class T>
	struct Hash    //默认的整型类型
	{
		const T& operator()(const T& data)
		{
			return data;
		}
	};
	template<>
	struct Hash <string> //对字符串类型的特化
	{
		size_t  operator()(const string& data)
		{
			size_t count = 0;
			for (size_t i = 0; i < data.size(); i++)
			{
				count *= 131;  // 使用的是 BKDR Hash算法
				count += data[i];
			}
			return count;
		}
	};




	// K:关键码类型
	// T: 不同容器V的类型不同，如果是unordered_map，T代表一个键值对，如果是unordered_set,T为 键类型
	// KeyOfT: 因为T的类型不同，通过data取键的方式就不同，
	// Hash: 哈希函数仿函数对象类型，哈希函数使用除留余数法，需要将Key转换为整形数字才能取模，
	//哈希表可以存整型，或者字符串类型，而映射时字符串必须要转化为整数，需要哈希算法
	template<class K, class T,class KeyOfT,class Hash> 
	class HashTable
	{
		typedef HashNode <T> Node;
	public:
		friend struct hashiterator < K, T, KeyOfT, Hash>;  //因为实现迭代器时需要用到找到下一个桶，所以需要访问底层的哈希表，但是为私有成员，所以用友元声明
		typedef hashiterator<K, T, KeyOfT, Hash> iterator;

		iterator begin()
		{
			//第一个不为空的桶的第一个元素
			for (size_t i = 0; i < _hashtable.size(); i++)
			{
				if (_hashtable[i])
				{
					return iterator(_hashtable[i],this);
				}
			}
			return end();
		}
		iterator end()
		{
			//最后一个元素的下一个元素，可以直接设置为nullptr
			return iterator(nullptr, this);
		}


		~HashTable()
		{
			Clear();
		}
		void Clear()
		{
			//一个桶一个桶的删除
			for (int i = 0; i < _hashtable.size(); i++)
			{
				Node* cur = _hashtable[i];
				while (cur)
				{
					Node* next = cur->_next;
					delete cur;
					cur = next;
				}
				_hashtable[i] = nullptr;
			}
		}

		size_t HashFunc(const K& key)//键值取整型
		{
			Hash hash;
			return hash(key);
		}
		pair<iterator,bool> Insert(const T& data)
		{
			KeyOfT koft;
			//也还是要先判断是否要增容，
			//开散列最好的情况是：每个哈希桶中刚好挂一个节点，再继续插入元素时，每一次都会发生哈希冲突，因此，在元素个数刚好等于桶的个数时，可以给哈希表增容。
			if (_hashtable.size()== 0 ||_num == _hashtable.size() ) // 如果负载因子等于1，则增容，避免大量的哈希冲突
			{
				// 1.开2倍大小的新表（不一定是2倍）
				// 2.遍历旧表的数据，重新计算在新表中位置
				// 3.释放旧表
				//1
				vector<Node*> newtable;
				size_t newtablesize = _hashtable.size() == 0 ? 10 : _hashtable.size() * 2;
				newtable.resize(newtablesize);
				//2.
				for (size_t i = 0; i < _hashtable.size(); i++)
				{
					// 将旧表中的节点取下来重新计算在新表中的位置，并插入到新表
					Node* cur = _hashtable[i];
					while (cur)
					{
						Node* next = cur->_next;
						size_t index = HashFunc(koft(cur->_data)) % newtablesize;//重新计算位置
						cur->_next = newtable[index];
						newtable[index] = cur;

						cur = next;
					}
					//3.
					_hashtable[i] = nullptr;
				}
				_hashtable.swap(newtable);
			}
			//未满，计算插入位置插入
			size_t index = HashFunc(koft(data)) % _hashtable.size();
			//1.先查找这个键值存不存在
			Node* cur = _hashtable[index];
			while (cur)
			{
				if (koft(cur->_data) == koft(data))
				{
					return make_pair(iterator(cur,this),false);//，对于unordered_map，不允许存在重复值，所以不允许插入，
													/////但是[]底层是调用insert函数的，存在 修改键对应的值 的这个操作，例如 map[2]++、map[2]=4更改键2对应的值为4等操作;所以要返回迭代器节点
				}
				else
					cur = cur->_next;
			}
			//2.则可以头插或者尾插进链表
			Node* newnode = new Node(data);
			newnode->_next = _hashtable[index];
			_hashtable[index] = newnode;
			++_num;
			return make_pair(iterator(newnode,this),true);
		}
		Node* Find(const K& key)
		{
			KeyOfT koft;
			//也还是先计算出映射位置，在进入到挂载的链表里找
			size_t index = HashFunc(key) % _hashtable.size();
			Node* cur = _hashtable[index];
			while (cur)
			{
				if (koft(cur->_data) == key)
				{
					return cur;
				}
				cur = cur->_next;
			}
			return nullptr;
		}
		bool Erase(const K& key)
		{
			KeyOfT koft;
			size_t index = HashFunc(key) % _hashtable.size();
			//因为是单链表，所以遍历时也要保存前一个指针，方便删除后的链接
			Node* prev = nullptr;
			Node* cur = _hashtable[index];
			while (cur)
			{
				if (koft(cur->_data) == key)
				{
					if (prev == nullptr)//第一个就是要删除的
					{
						_hashtable[index] = cur->_next;
					}
					else
					{
						prev->_next = cur->_next;
					}
					delete cur;
					return true;
				}
				else   //继续往下找
				{
					prev = cur;
					cur = cur->_next;
				}
			}
			return false;

		}
	private:
		vector<Node*> _hashtable;
		size_t _num = 0;
	};



	void TestHashTable1()
	{
		HashTable<int, int, SetKeyOfT<int>, Hash<int>> ht;
		ht.Insert(4);
		ht.Insert(14);
		ht.Insert(24);
		ht.Insert(5);
		ht.Insert(15);
		ht.Insert(25);
		ht.Insert(6);
		ht.Insert(16);
		ht.Insert(26);
		ht.Insert(36);
		ht.Insert(33);
		ht.Insert(44);
		auto it = ht.begin();
		while (it != ht.end())
		{
			cout << *it << ' ';
			++it;
		}
		cout << endl;

		ht.Erase(4);
		ht.Erase(44);
		it = ht.begin();
		while (it != ht.end())
		{
			cout << *it << ' ';
			++it;
		}
		cout << endl;
	}

	void TestHashTable2()
	{
		//HashTable<string, string, SetKeyOfT<string>, _HashString> ht;
		HashTable<string, string, SetKeyOfT<string>, Hash<string>> ht;
		ht.Insert("sort");
		ht.Insert("string");
		ht.Insert("left");

		cout << ht.HashFunc("abcd") << endl;
		cout << ht.HashFunc("aadd") << endl;
	}
}