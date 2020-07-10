#pragma once
#include<iostream>
#include<string>
using namespace std;
//红黑树的性质
//1. 每个结点不是红色就是黑色
//2. 根节点是黑色的
//3. 如果一个节点是红色的，则它的两个孩子结点是黑色的
//4. 对于每个结点，从该结点到其所有后代叶结点的简单路径上，均 包含相同数目的黑色结点
//5. 每个叶子结点都是黑色的(此处的叶子结点指的是空结点)

//红黑树节点的颜色
enum Colour
{
	RED,  //红色
	BLACK, //黑色
};
//红黑树节点的定义
template<class T>  //节点里可以保存键值对（对应map）也可以只保存键值(对应set)
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
		, _col(RED)   //默认新插入的节点为红色，是根据红黑树的性质决定的，要是默认为黑色，由于本来每条路径的黑节点数量是相等，
		//但是此路径加一个黑结点之后便会影响整个树结构，而默认为红色，最后只会影响所在的那棵子树结构
	{}
};

template<class T,class Ref,class Ptr>  //封装搜索树的迭代器
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
		//根据搜索树的特点
		// 1、如果右不为空，中序的下一个就是其右子树的最左节点
		// 2、如果右为空或者已经访问完，表示_node所在的子树已经访问完成,则下一个节点在他的祖先中找
		//  沿着路径往上找 我是它的左孩子的那个祖先节点
		if (_node->_right != nullptr)
		{
			Node* subleft = _node->_right;
			while (subleft->_left)
			{
				subleft = subleft->_left;
			}
			_node = subleft;
		}
		else //右边为空，按照搜索树的中序遍历则说明整棵树都已经走完 ，需要回到此子树的根节点为左子树的祖先节点
		{
			Node* cur = _node;
			Node* parent = cur->_parent;
			while (parent && parent->_right == cur) //往上回退
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
		//减减就要找左边走，思路与加加相同，就是换个方向找即中序的逆序
		//1.如果左不为空，就找其左子树的最右节点
		if (_node->_left)
		{
			Node* subright = _node->_left;
			while (subright->_right)
			{
				subright=subright->_right;
			}
			_node = subright;
		}
		else  //2.要是左为空，就回退到以此子树为右子树的父亲节点
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



template<class K, class T,class KeyofT >   //是键值对还是单个键值，有定义对象时的参数决定
class RBTree
{
	typedef RBTreeNode<T> Node;
public:
	typedef Treeiterator<T, T&, T*> iterator; 
	typedef Treeiterator<T, const T&, const T*> const_iterator; //两个迭代器

	iterator begin() //最小值即最左节点
	{
		Node* cur = _root;
		while (cur && cur->_left)
		{
			cur = cur->_left;
		}
		return iterator(cur);//构造为迭代器类型
	}
	iterator end()//注意：为最大值即最右节点的下一个节点 ，一般可以投机取巧为nullptr就行
	{
		return iterator(nullptr);
	}

	pair<iterator, bool> Insert(const T& data)
	{
		//1.按照常规搜索树的规则插入节点
		if (_root == nullptr) //树为空时
		{
			_root = new Node(data);
			_root->_col = BLACK;//红黑树根节点为黑色节点
			return make_pair(iterator(_root),true);
		}
		KeyofT koft;//仿函数对象，map和set底层都是用的红黑树，利用这个仿函数对象取键值，可以只封装一个底层结构供两者使用
		Node* parent = nullptr;
		Node* cur = _root;
		while (cur)
		{
			if (cur->_data.first <data.first)  //根据键值对的关键字来判断
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
				return make_pair(iterator(cur),false);//已有该键值
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
		//2. 检测新节点插入后，红黑树的性质是否造到破坏，
		// 若满足性质直接退出，否则对红黑树分情况进行旋转着色处理，


		/*因为新节点的默认颜色是红色，因此：如果其双亲节点的颜色是黑色，没有违反红黑树任何性质，则不
			需要调整；但当新插入节点的双亲节点颜色为红色时，就违反了性质三不能有连在一起的红色节点，此时需要对红黑树分情况来讨论：
		*/
		//注意前提：每个节点插入之前，树一定是符合红黑树性质的
		//约定: cur为当前节点，p为父节点，g为祖父节点，u为叔叔节点

		//插入红节点，他的父亲是红色的，可以推断他的祖父存在且一定为黑色。关键看叔叔。
		while (parent && parent->_col == RED)
		{
			Node* grandfather = parent->_parent;
			if (parent == grandfather->_left)
			{
				Node* uncle = grandfather->_right; 
				//	情况一: cur为红，p为红，g为黑，u存在且为红
				if (uncle && uncle->_col == RED)
				{
					parent->_col = uncle->_col = BLACK;
					grandfather->_col = RED;
					//继续向上调整
					cur = grandfather;
					parent = grandfather->_parent;
				}
				else
				{
					//  情况二：cur为红，p为红，g为黑，u不存在 / u为黑    
					//这里其实又分为四个不同情况，即单旋的两种（情况二）和双旋的两种（情况三）

				/*说明: u的情况有两种
					1.如果u节点不存在, 则cur -定是新插入节点，因为如果cur不是新插入节点，
					则cur和p - 定有一个节点的颜色是色，就不满足性质4 : 每条路径黑色节点个数相同。
					2.如果u节点存在，则其 - -定是黑色的，那么cur节点原来的颜色-定是黑色的，
					现在看到其是红色的原因是因为cur的子树在调整的过程中将cur节点的颜色由黑色改成红色（即是由下面调整上来的）。*/


					//先考虑双旋的情况，因为双旋情况都是会进一步调整转换成单旋来处理的(情况三)
					if (cur == parent->_right)
					{
						RotateL(parent);
						swap(parent, cur);
					}
					//单旋的逻辑，可能是由上面双旋旋转一次后的逻辑（即cur节点不是新增节点），也可能是新增节点引起的简单单旋逻辑
					//对grandfather进行一次右旋（情况二）
					RotateR(grandfather);
					grandfather->_col = RED;
					parent->_col = BLACK;
				}
			}
			else if (parent == grandfather->_right) //与上面逻辑相对
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
		_root->_col = BLACK;//确保根节点为空的性质
		return make_pair(iterator(returnnode),true);
	}

	//和之前AVL树的左旋右旋一样
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

		// 1、原来parent是这颗树的跟，现在subR是根
		// 2、parent为根的树只是整颗树中的子树，改变链接关系，那么subR要顶替他的位置
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

	
		//对于红黑树的检测，由性质决定
		/*1.根节点为黑色
		2.对于每一个结点，从该节点到叶子节点的所有路径中（子树路径），黑色节点个数相等
		3.没有连续的红色节点
		另外，也要检测看看中序是不是有序*/
	bool IsRBTree()
	{
		Node* cur = _root;
		if (cur == nullptr)// 空树也是红黑树
		{
			return true;
		}
		// 检测根节点是否满足情况,即根节点必须为黑色
		if (cur->_col != BLACK)
		{
			cout << "违反红黑树性质二：根节点必须为黑色" << endl;
			return false;
		}
		// 获取任意一条路径中黑色节点的个数，与其他路劲对比黑色节点个数
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
		// 检测是否满足红黑树的性质，k用来记录每条路径中黑色节点的个数，一一对比
		size_t k = 0;
		return _IsRBTree(_root, k, blcakcount);
	}
	bool _IsRBTree(Node* proot, size_t k, size_t blackcount)  //以此根为起点的每条路径的黑节点个数判断以及是否有连续的红节点
	{
		//走到null之后，判断k和black是否相等
		if (proot == nullptr)
		{
			if (k != blackcount)
			{
				cout << "违反性质四：每条路径中黑色节点的个数必须相同" << endl;
				return false
			}
			return true;
		}
		//统计此路径黑色节点个数
		if (proot->_col == BLACK)
		{
			k++;
		}
		// 检测当前节点与其双亲是否都为红色
		Node* parent = proot->_parent;
		if ( parent &&parent->_col == RED && proot->_col == RED)
		{
			cout << "违反性质三：不存在连续的红色节点" << endl;
			return false;
		}
		return _IsRBTree(proot->_left, k, blackcount) && _IsRBTree(proot->_right, k, blackcount);
	}

	//根据键值查找
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

