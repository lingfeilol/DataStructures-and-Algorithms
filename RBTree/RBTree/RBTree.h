#pragma once
#include<iostream>
#include<string>
using namespace std;
//�����������
//1. ÿ����㲻�Ǻ�ɫ���Ǻ�ɫ
//2. ���ڵ��Ǻ�ɫ��
//3. ���һ���ڵ��Ǻ�ɫ�ģ��������������ӽ���Ǻ�ɫ��
//4. ����ÿ����㣬�Ӹý�㵽�����к��Ҷ���ļ�·���ϣ��� ������ͬ��Ŀ�ĺ�ɫ���
//5. ÿ��Ҷ�ӽ�㶼�Ǻ�ɫ��(�˴���Ҷ�ӽ��ָ���ǿս��)

//������ڵ����ɫ
enum Colour
{
	RED,  //��ɫ
	BLACK, //��ɫ
};
//������ڵ�Ķ���
template<class T>  //�ڵ�����Ա����ֵ�ԣ���Ӧmap��Ҳ����ֻ�����ֵ(��Ӧset)
struct RBTreeNode
{
	typedef RBTreeNode<T> Node;
	Node* _left;
	Node* _right;
	Node* _parent;
	T _data;
	Colour _col;

	RBTreeNode(const T& data)
		:_left(nullptr)
		, _right(nullptr)
		, _parent(nullptr)
		, _data(data)
		, _col(RED)   //Ĭ���²���Ľڵ�Ϊ��ɫ���Ǹ��ݺ���������ʾ����ģ�Ҫ��Ĭ��Ϊ��ɫ�����ڱ���ÿ��·���ĺڽڵ���������ȣ�
		//���Ǵ�·����һ���ڽ��֮����Ӱ���������ṹ����Ĭ��Ϊ��ɫ�����ֻ��Ӱ�����ڵ��ǿ������ṹ
	{}
};

template<class T,class Ref,class Ptr>  //��װ�������ĵ�����
struct Treeiterator
{
	typedef RBTreeNode<T> Node;
	typedef Treeiterator<T, Ref, Ptr> self;
	Node* _node;
	Treeiterator(Node* node)
		:_node(node)
	{}

	Ref operator*()
	{
		return  _node->_data;
	}
	Ptr operator->()
	{
		return &_node->_data;
	}
	self& operator++()
	{
		//�������������ص�
		// 1������Ҳ�Ϊ�գ��������һ��������������������ڵ�
		// 2�������Ϊ�ջ����Ѿ������꣬��ʾ_node���ڵ������Ѿ��������,����һ���ڵ���������������
		//  ����·�������� �����������ӵ��Ǹ����Ƚڵ�
		if (_node->_right != nullptr)
		{
			Node* subleft = _node->_right;
			while (subleft->_left)
			{
				subleft = subleft->_left;
			}
			_node = subleft;
		}
		else //�ұ�Ϊ�գ����������������������˵�����������Ѿ����� ����Ҫ�ص��������ĸ��ڵ�Ϊ�����������Ƚڵ�
		{
			Node* cur = _node;
			Node* parent = cur->_parent;
			while (parent && parent->_right == cur) //���ϻ���
			{
				cur = parent;
				parent = parent->_parent;
			}
			_node = parent;
		}
		return *this;
	}
	self& operator--()
	{
		//������Ҫ������ߣ�˼·��Ӽ���ͬ�����ǻ��������Ҽ����������
		//1.�����Ϊ�գ������������������ҽڵ�
		if (_node->_left)
		{
			Node* subright = _node->_left;
			while (subright->_right)
			{
				subright=subright->_right;
			}
			_node = subright;
		}
		else  //2.Ҫ����Ϊ�գ��ͻ��˵��Դ�����Ϊ�������ĸ��׽ڵ�
		{
			Node* cur = _node;
			Node* parent = cur->_parent;
			while (parent && cur == parent->_left)
			{
				cur =parent;
				parent = parent->_parent;
			}
			_node = parent;
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



template<class K, class T,class KeyofT >   //�Ǽ�ֵ�Ի��ǵ�����ֵ���ж������ʱ�Ĳ�������
class RBTree
{
	typedef RBTreeNode<T> Node;
public:
	typedef Treeiterator<T, T&, T*> iterator; 
	typedef Treeiterator<T, const T&, const T*> const_iterator; //����������

	iterator begin() //��Сֵ������ڵ�
	{
		Node* cur = _root;
		while (cur && cur->_left)
		{
			cur = cur->_left;
		}
		return iterator(cur);//����Ϊ����������
	}
	iterator end()//ע�⣺Ϊ���ֵ�����ҽڵ����һ���ڵ� ��һ�����Ͷ��ȡ��Ϊnullptr����
	{
		return iterator(nullptr);
	}

	pair<iterator, bool> Insert(const T& data)
	{
		//1.���ճ����������Ĺ������ڵ�
		if (_root == nullptr) //��Ϊ��ʱ
		{
			_root = new Node(data);
			_root->_col = BLACK;//��������ڵ�Ϊ��ɫ�ڵ�
			return make_pair(iterator(_root),true);
		}
		KeyofT koft;//�º�������map��set�ײ㶼���õĺ��������������º�������ȡ��ֵ������ֻ��װһ���ײ�ṹ������ʹ��
		Node* parent = nullptr;
		Node* cur = _root;
		while (cur)
		{
			if (cur->_data.first <data.first)  //���ݼ�ֵ�ԵĹؼ������ж�
			{
				parent = cur;
				cur = cur->_right;
			}
			else if (cur->_data.first > data.first)
			{
				parent = cur;
				cur = cur->_left;
			}
			else
				return make_pair(iterator(cur),false);//���иü�ֵ
		}
		cur = new Node(data);
		Node* returnnode = cur;
		if (cur == parent->_left)
		{
			parent->_left = cur;
			cur->_parent = parent;
		}
		else if (cur == parent->_right)
		{
			parent->_right = cur;
			cur->_parent = parent;
		}
		//2. ����½ڵ����󣬺�����������Ƿ��쵽�ƻ���
		// ����������ֱ���˳�������Ժ���������������ת��ɫ����


		/*��Ϊ�½ڵ��Ĭ����ɫ�Ǻ�ɫ����ˣ������˫�׽ڵ����ɫ�Ǻ�ɫ��û��Υ��������κ����ʣ���
			��Ҫ�����������²���ڵ��˫�׽ڵ���ɫΪ��ɫʱ����Υ��������������������һ��ĺ�ɫ�ڵ㣬��ʱ��Ҫ�Ժ��������������ۣ�
		*/
		//ע��ǰ�᣺ÿ���ڵ����֮ǰ����һ���Ƿ��Ϻ�������ʵ�
		//Լ��: curΪ��ǰ�ڵ㣬pΪ���ڵ㣬gΪ�游�ڵ㣬uΪ����ڵ�

		//�����ڵ㣬���ĸ����Ǻ�ɫ�ģ������ƶ������游������һ��Ϊ��ɫ���ؼ������塣
		while (parent && parent->_col == RED)
		{
			Node* grandfather = parent->_parent;
			if (parent == grandfather->_left)
			{
				Node* uncle = grandfather->_right; 
				//	���һ: curΪ�죬pΪ�죬gΪ�ڣ�u������Ϊ��
				if (uncle && uncle->_col == RED)
				{
					parent->_col = uncle->_col = BLACK;
					grandfather->_col = RED;
					//�������ϵ���
					cur = grandfather;
					parent = grandfather->_parent;
				}
				else
				{
					//  �������curΪ�죬pΪ�죬gΪ�ڣ�u������ / uΪ��    
					//������ʵ�ַ�Ϊ�ĸ���ͬ����������������֣����������˫�������֣��������

				/*˵��: u�����������
					1.���u�ڵ㲻����, ��cur -�����²���ڵ㣬��Ϊ���cur�����²���ڵ㣬
					��cur��p - ����һ���ڵ����ɫ��ɫ���Ͳ���������4 : ÿ��·����ɫ�ڵ������ͬ��
					2.���u�ڵ���ڣ����� - -���Ǻ�ɫ�ģ���ôcur�ڵ�ԭ������ɫ-���Ǻ�ɫ�ģ�
					���ڿ������Ǻ�ɫ��ԭ������Ϊcur�������ڵ����Ĺ����н�cur�ڵ����ɫ�ɺ�ɫ�ĳɺ�ɫ��������������������ģ���*/


					//�ȿ���˫�����������Ϊ˫��������ǻ��һ������ת���ɵ����������(�����)
					if (cur == parent->_right)
					{
						RotateL(parent);
						swap(parent, cur);
					}
					//�������߼���������������˫����תһ�κ���߼�����cur�ڵ㲻�������ڵ㣩��Ҳ�����������ڵ�����ļ򵥵����߼�
					//��grandfather����һ���������������
					RotateR(grandfather);
					grandfather->_col = RED;
					parent->_col = BLACK;
				}
			}
			else if (parent == grandfather->_right) //�������߼����
			{
				Node* uncle = grandfather->_left;
				if (uncle&& uncle->_col == RED)
				{
					parent->_col = uncle->_col = BLACK;
					grandfather->_col = RED;
				}
				else
				{
					if (cur == parent->_left)
					{
						RotateR(parent);
						swap(cur, parent);
					}

					RotateL(grandfather);
					grandfather->_col = RED;
					parent->_col = BLACK;
				}
			}
		}
		_root->_col = BLACK;//ȷ�����ڵ�Ϊ�յ�����
		return make_pair(iterator(returnnode),true);
	}

	//��֮ǰAVL������������һ��
	void RotateL(Node* parent)
	{
		Node* subR = parent->_right;
		Node* subRL = subR->_left;

		parent->_right = subRL;
		if (subRL)
			subRL->_parent = parent;

		subR->_left = parent;
		Node* ppNode = parent->_parent;
		parent->_parent = subR;

		// 1��ԭ��parent��������ĸ�������subR�Ǹ�
		// 2��parentΪ������ֻ���������е��������ı����ӹ�ϵ����ôsubRҪ��������λ��
		if (_root == parent)
		{
			_root = subR;
			subR->_parent = nullptr;
		}
		else
		{
			if (ppNode->_left == parent)
				ppNode->_left = subR;
			else
				ppNode->_right = subR;

			subR->_parent = ppNode;
		}
	}

	void RotateR(Node* parent)
	{
		Node* subL = parent->_left;
		Node* subLR = subL->_right;

		parent->_left = subLR;
		if (subLR)
			subLR->_parent = parent;

		subL->_right = parent;
		Node* ppNode = parent->_parent;
		parent->_parent = subL;

		if (_root == parent)
		{
			_root = subL;
			subL->_parent = nullptr;
		}
		else
		{
			if (ppNode->_left == parent)
				ppNode->_left = subL;
			else
				ppNode->_right = subL;

			subL->_parent = ppNode;
		}
	}

	
		//���ں�����ļ�⣬�����ʾ���
		/*1.���ڵ�Ϊ��ɫ
		2.����ÿһ����㣬�Ӹýڵ㵽Ҷ�ӽڵ������·���У�����·��������ɫ�ڵ�������
		3.û�������ĺ�ɫ�ڵ�
		���⣬ҲҪ��⿴�������ǲ�������*/
	bool IsRBTree()
	{
		Node* cur = _root;
		if (cur == nullptr)// ����Ҳ�Ǻ����
		{
			return true;
		}
		// �����ڵ��Ƿ��������,�����ڵ����Ϊ��ɫ
		if (cur->_col != BLACK)
		{
			cout << "Υ����������ʶ������ڵ����Ϊ��ɫ" << endl;
			return false;
		}
		// ��ȡ����һ��·���к�ɫ�ڵ�ĸ�����������·���ԱȺ�ɫ�ڵ����
		size_t blackcount = 0;
		Node* tmp = _root;
		while (tmp)
		{
			if (tmp->_col == BLACK)
			{
				blackcount++;
			}
			tmp = tmp->_left;
		}
		// ����Ƿ��������������ʣ�k������¼ÿ��·���к�ɫ�ڵ�ĸ�����һһ�Ա�
		size_t k = 0;
		return _IsRBTree(_root, k, blcakcount);
	}
	bool _IsRBTree(Node* proot, size_t k, size_t blackcount)  //�Դ˸�Ϊ����ÿ��·���ĺڽڵ�����ж��Լ��Ƿ��������ĺ�ڵ�
	{
		//�ߵ�null֮���ж�k��black�Ƿ����
		if (proot == nullptr)
		{
			if (k != blackcount)
			{
				cout << "Υ�������ģ�ÿ��·���к�ɫ�ڵ�ĸ���������ͬ" << endl;
				return false
			}
			return true;
		}
		//ͳ�ƴ�·����ɫ�ڵ����
		if (proot->_col == BLACK)
		{
			k++;
		}
		// ��⵱ǰ�ڵ�����˫���Ƿ�Ϊ��ɫ
		Node* parent = proot->_parent;
		if ( parent &&parent->_col == RED && proot->_col == RED)
		{
			cout << "Υ���������������������ĺ�ɫ�ڵ�" << endl;
			return false;
		}
		return _IsRBTree(proot->_left, k, blackcount) && _IsRBTree(proot->_right, k, blackcount);
	}

	//���ݼ�ֵ����
	Node* Find(const K& key)
	{
		KeyofT koft;
		Node* cur = _root;
		while (cur)
		{
			if (koft(cur->_data) < koft(data))
			{
				cur = cur->_right;
			}
			else if (koft(cur->_data) > koft(data))
			{
				cur = cur->_left;
			}
			else
			{
				return cur;
			}
		}

		return nullptr;
	}
private:
	Node* _root = nullptr;
};

