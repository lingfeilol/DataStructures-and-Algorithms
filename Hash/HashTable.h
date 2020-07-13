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


//��ϣ��ͻ�����
//1.��ɢ�й�ϣ Ҳ�п��Ŷ�ַ������������ϣ��ͻʱ�������ϣ��δ��װ����˵���ڹ�ϣ���б�Ȼ���п�λ�ã���ô���԰�key��ŵ���ͻλ���еġ���һ���� ��λ����ȥ
//���������һ��λ�ã��ַ�Ϊ����̽��Ͷ���̽��
namespace CLOSE_HASH
{
	// ��ϣ��ÿ���ռ�������
	// EMPTY��λ�ÿգ� EXIST��λ���Ѿ���Ԫ�أ� DELETEԪ���Ѿ�ɾ��
	enum State{ EMPTY, EXIST, DELETE };

	//�ڵ㶨��
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
		// �������� = ��������/��Ĵ�С ������ϣ�����ĳ̶�
		// ��Խ�ӽ�������������Խ���׳�ͻ����ͻԽ�࣬Ч��Խ��
		// ��������ԽС����ͻ����Խ�ͣ�����Ч��Խ�ߣ����Ǹ�������ԽС���˷ѵĿռ�Խ��
		// ��ϣ���������˲����ݣ����Ŷ��Ʒ��У�һ�㸺�����ӵ���0.7���ҾͿ�ʼ����
		bool Insert(const T& data)
		{
			////���ݵ�һ���������
			//if (_hashtable.size() == 0 || _num * 10 / _hashtable.size() >= 7) //hash����Ϊ�գ����߸�����
			//{
			//	// 1.��2����С���±�
			//	// 2.�����ɱ�����ݣ����¼������±���λ��
			//	// 3.�ͷžɱ�
			//	//1.
			//	vector<HashData> newtable;
			//	size_t newtablesize = _hashtable.size() == 0 ? 10 : _hashtable.size() * 2;
			//	newtable.resize(newtablesize);
			//	//2.
			//	for (int i = 0; i < _hashtable.size(); i++)
			//	{
			//		if (_hashtable[i]._state == EXIST) //�ҵ��ɱ��е���Ч���ݣ����¼���ӳ�䵽�±���ȥ
			//		{
			//			size_t index = koft(_hashtable[i]._data) % newtablesize;
			//			while (newtable[index]._state == EXIST)//��ϣ��ͻʱ��ʹ������̽������һ����λ��
			//			{
			//				++index;
			//				if (index == newtablesize)//�ص���ͷ������
			//				{
			//					index = 0;
			//				}
			//			}
			//			newtable[index] = _hashtable[i];//����
			//		}
			//	}
			//	_hashtable.swap(newtable);
			//}

			//����insert���룬���Ը��ݲ�ͬ��̽�ⷽʽ������Ĳ���
			if (_hashtable.size() == 0 || _num * 10 / _hashtable.size() >= 7) //hash����Ϊ�գ����߸�����
			{
				HashTable<K, T, KeyOfT> newhashtable;//��һ������
				size_t newtablesize = _hashtable.size() == 0 ? 10 : _hashtable.size() * 2;
				newhashtable._hashtable.resize(newtablesize);
				for (size_t i = 0; i < _hashtable.size(); i++)
				{
					if (_hashtable[i]._state == EXIST)
					{
						newhashtable.Insert(_hashtable[i]._data);//��������insert���������ݲ��뵽�µĿռ�
					}
				}
				_hashtable.swap(newhashtable._hashtable);
			}
			//����û������ʼ�����߼�

			//����̽��
			//�ȼ���data�ڹ�ϣ�����ӳ��λ��
			//size_t index = koft(data) % _hashtable.size();
			//while (_hashtable[index]._state == EXIST)
			//{
			//	if (koft(_hashtable[index]._data) == koft(data))//�������ֵ�ظ�
			//		return false;
			//	++index; //����̽��
			//	index %= _hashtable.size();
			//}
			//_hashtable[index]._data = data;
			//_hashtable[index]._state = EXIST;
			//_num++;
			//return true;

			//����̽��
			size_t start = koft(data) % _hashtable.size();
			size_t index = start;
			int i = 1;
			while (_hashtable[index]._state == EXIST)
			{
				if (koft(_hashtable[index]._data) == koft(data))//�������ֵ�ظ�
					return false;
				index = start + i*i;//����̽��
				i++;
				index %= _hashtable.size();
			}
			_hashtable[index]._data = data;
			_hashtable[index]._state = EXIST;
			_num++;
			return true;
		}
		//���ݼ�ֵ���ң�Ҳ���ȼ�����ӳ���λ�ã����ǿ����Ǵ���̽����λ�ã�������Ҫ���һֱ����ȥ�ң�ֱ��������
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
		vector<HashData> _hashtable; //ӳ���
		size_t _num = 0; //��Ч���ݸ���
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
//2.��ɢ�з��ֽ�����ַ��(������)�����ȶԹؼ��뼯����ɢ�к�������ɢ�е�ַ��������ͬ��ַ�Ĺؼ���
//����ͬһ�Ӽ��ϣ�ÿһ���Ӽ��ϳ�Ϊһ��Ͱ������Ͱ�е�Ԫ��ͨ��һ�������������������������ͷ���洢�ڹ�ϣ���С�
namespace OPEN_HASH
{
	//�ڵ�ṹ
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


	// ǰ������
	template<class K, class T, class KeyOfT, class Hash>
	class HashTable;

	//����ַ����Ͱ�ṹ�ĵ�����
	template <class K,class T,class KeyOfT,class Hash>
	struct hashiterator
	{
		typedef HashNode<T> Node;
		typedef HashTable<K, T, KeyOfT, Hash> HT;
		typedef hashiterator<K, T, KeyOfT, Hash> self;

		Node* _node;// ��ǰ�����������Ľڵ�
		HT* _ht;  // ��ϣͰ--��Ҫ��Ϊ������һ����Ͱʱ�򷽱�

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
		// ע�⣺��Ϊ��ϣͰ�ڵײ��ǵ�����ṹ�����Թ�ϣͰ�ĵ���������Ҫ--����
		self& operator++()
		{
			// ��ǰ��������ָ�ڵ���нڵ�ʱֱ��ȡ����һ���ڵ�
			if (_node->_next)
				_node = _node->_next;
			else // ����һ�����յ�Ͱ�����ظ�Ͱ�е�һ���ڵ�
			{
				KeyOfT koft;
				size_t index = _ht->HashFunc(koft(_node->_data)) % _ht->_hashtable.size();
				index++;
				for (; index < _ht->_hashtable.size(); index++)
				{
					Node* cur = _ht->_hashtable[index];//�ж���һ��Ͱ�Ƿ�Ϊ��
					if (cur)
					{
						_node = cur;
						return *this;
					}
				}
				_node = nullptr;//����һ��Ҳû�У����ÿշ���
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
	struct Hash    //Ĭ�ϵ���������
	{
		const T& operator()(const T& data)
		{
			return data;
		}
	};
	template<>
	struct Hash <string> //���ַ������͵��ػ�
	{
		size_t  operator()(const string& data)
		{
			size_t count = 0;
			for (size_t i = 0; i < data.size(); i++)
			{
				count *= 131;  // ʹ�õ��� BKDR Hash�㷨
				count += data[i];
			}
			return count;
		}
	};




	// K:�ؼ�������
	// T: ��ͬ����V�����Ͳ�ͬ�������unordered_map��T����һ����ֵ�ԣ������unordered_set,TΪ ������
	// KeyOfT: ��ΪT�����Ͳ�ͬ��ͨ��dataȡ���ķ�ʽ�Ͳ�ͬ��
	// Hash: ��ϣ�����º����������ͣ���ϣ����ʹ�ó�������������Ҫ��Keyת��Ϊ�������ֲ���ȡģ��
	//��ϣ����Դ����ͣ������ַ������ͣ���ӳ��ʱ�ַ�������Ҫת��Ϊ��������Ҫ��ϣ�㷨
	template<class K, class T,class KeyOfT,class Hash> 
	class HashTable
	{
		typedef HashNode <T> Node;
	public:
		friend struct hashiterator < K, T, KeyOfT, Hash>;  //��Ϊʵ�ֵ�����ʱ��Ҫ�õ��ҵ���һ��Ͱ��������Ҫ���ʵײ�Ĺ�ϣ������Ϊ˽�г�Ա����������Ԫ����
		typedef hashiterator<K, T, KeyOfT, Hash> iterator;

		iterator begin()
		{
			//��һ����Ϊ�յ�Ͱ�ĵ�һ��Ԫ��
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
			//���һ��Ԫ�ص���һ��Ԫ�أ�����ֱ������Ϊnullptr
			return iterator(nullptr, this);
		}


		~HashTable()
		{
			Clear();
		}
		void Clear()
		{
			//һ��Ͱһ��Ͱ��ɾ��
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

		size_t HashFunc(const K& key)//��ֵȡ����
		{
			Hash hash;
			return hash(key);
		}
		pair<iterator,bool> Insert(const T& data)
		{
			KeyOfT koft;
			//Ҳ����Ҫ���ж��Ƿ�Ҫ���ݣ�
			//��ɢ����õ�����ǣ�ÿ����ϣͰ�иպù�һ���ڵ㣬�ټ�������Ԫ��ʱ��ÿһ�ζ��ᷢ����ϣ��ͻ����ˣ���Ԫ�ظ����պõ���Ͱ�ĸ���ʱ�����Ը���ϣ�����ݡ�
			if (_hashtable.size()== 0 ||_num == _hashtable.size() ) // ����������ӵ���1�������ݣ���������Ĺ�ϣ��ͻ
			{
				// 1.��2����С���±���һ����2����
				// 2.�����ɱ�����ݣ����¼������±���λ��
				// 3.�ͷžɱ�
				//1
				vector<Node*> newtable;
				size_t newtablesize = _hashtable.size() == 0 ? 10 : _hashtable.size() * 2;
				newtable.resize(newtablesize);
				//2.
				for (size_t i = 0; i < _hashtable.size(); i++)
				{
					// ���ɱ��еĽڵ�ȡ�������¼������±��е�λ�ã������뵽�±�
					Node* cur = _hashtable[i];
					while (cur)
					{
						Node* next = cur->_next;
						size_t index = HashFunc(koft(cur->_data)) % newtablesize;//���¼���λ��
						cur->_next = newtable[index];
						newtable[index] = cur;

						cur = next;
					}
					//3.
					_hashtable[i] = nullptr;
				}
				_hashtable.swap(newtable);
			}
			//δ�����������λ�ò���
			size_t index = HashFunc(koft(data)) % _hashtable.size();
			//1.�Ȳ��������ֵ�治����
			Node* cur = _hashtable[index];
			while (cur)
			{
				if (koft(cur->_data) == koft(data))
				{
					return make_pair(iterator(cur,this),false);//������unordered_map������������ظ�ֵ�����Բ�������룬
													/////����[]�ײ��ǵ���insert�����ģ����� �޸ļ���Ӧ��ֵ ��������������� map[2]++��map[2]=4���ļ�2��Ӧ��ֵΪ4�Ȳ���;����Ҫ���ص������ڵ�
				}
				else
					cur = cur->_next;
			}
			//2.�����ͷ�����β�������
			Node* newnode = new Node(data);
			newnode->_next = _hashtable[index];
			_hashtable[index] = newnode;
			++_num;
			return make_pair(iterator(newnode,this),true);
		}
		Node* Find(const K& key)
		{
			KeyOfT koft;
			//Ҳ�����ȼ����ӳ��λ�ã��ڽ��뵽���ص���������
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
			//��Ϊ�ǵ��������Ա���ʱҲҪ����ǰһ��ָ�룬����ɾ���������
			Node* prev = nullptr;
			Node* cur = _hashtable[index];
			while (cur)
			{
				if (koft(cur->_data) == key)
				{
					if (prev == nullptr)//��һ������Ҫɾ����
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
				else   //����������
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