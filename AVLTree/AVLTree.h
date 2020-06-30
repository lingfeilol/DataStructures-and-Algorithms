#pragma once
#include<assert.h>


template<class K, class V>
struct AVLTreeNode
{
	AVLTreeNode<K, V>* _left;
	AVLTreeNode<K, V>* _right;
	AVLTreeNode<K, V>* _parent;
	int _bf;//平衡因子
	pair<int, int> _kv;//键值对 类型的元素

	//构造函数
	AVLTreeNode(const pair<K,V>& kv)
		: _left(nullptr)
		, _right(nullptr)
		, _parent(nullptr)
		, _bf(0)
		, _kv(kv)
	{ }
};

template<class K,class V>
class AVLTree
{
	typedef AVLTreeNode<const K,V> Node;
public:
	bool Insert(const pair<K, V>& kv)
	{
		//1.按照排序树的规则，找到插入位置
		if (_root == nullptr)//一开始为空时
		{
			_root = new Node(kv);
			_root->_bf = 0;
			return true;
		}
		
		Node* parent = nullptr;
		Node* cur = _root;
		while (cur)
		{
			if (cur->_kv.first < kv.first)
			{
				parent = cur;
				cur = cur->_right;
			}
			else if (cur->_kv.first > kv.first)
			{
				parent = cur;
				cur = cur->_left;
			}
			else
			{
				return false; //之前有过
			}
		}
		//2.找到插入位置后，进行插入
		cur = new Node(kv);
		if (parent->_kv.first < kv.first) //挂载到右子树上
		{
			parent->_right = cur;
			cur->_parent = parent;
		}
		else //挂载到左子树
		{
			parent->_left = cur;
			cur->_parent = parent;
		}
		//3.为了保持平衡，根据平衡因子判断是否需要旋转，且更新平衡因子  平衡因子= 右子树高度-左子树高度
		///新插入的节点，影响的是新插入节点的祖先的平衡因子
			/////////a.右子树的高度变化，则父亲的平衡因子 + 1, 左子树的高度变化，则父亲的平衡因子 - 1
			/////////b.父亲的平衡囚子电新完成后变成1/ -l，则说明父亲所在的子树的高度变了，则继续往上更新。
			////////c.父亲的平衡因子更新完成后变成2 / 2, 则说明父亲所在的子树已经不平衡，那么需要旋转处理让他平衡。
			////////d.父亲的平衡因子更新完成后变成0,则说明父亲所在的子树的高度没变，对上一层没有影响，则更新完成。

		while (parent)
		{
			//更新平衡因子
			if (cur == parent->_left)//挂到其左边的，因子减一
				parent->_bf--;
			else  if(cur == parent->_right)   //挂到右边，因子加一
				parent->_bf++;
			//判断是否需要需要旋转 对应三种情况
			if (parent->_bf == 0)//上层已经是平衡了的
				break;
			else if (abs(parent->_bf)==1)
			{
				cur = parent;
				parent = parent->_parent;//继续向上更新
			}
			else if (parent->_bf == 2 || parent->_bf == -2)
			{
				// 说明parent子树已经不平衡，需要旋转处理，让其平衡
				if (parent->_bf == 2)
				{
					if (cur->_bf == 1)//此情况需进行左单旋
						RotateL(parent);
					else if (cur->_bf == -1)//先右旋再左旋
						RotateRL(parent);
				}
				else if (parent->_bf == -2)
				{
					if (cur->_bf == -1)
					{
						RotateR(parent);//右单旋
					}
					else if (cur->_bf == 1)
					{
						RotateLR(parent);//先左旋再右旋
					}
				}
				//处理完毕后 break;
				break;
			}
		}
		return true;
	}
	void RotateL(Node* parent) //左旋
	{
		Node* subR = parent->_right;  //旋转需要的子树
		Node* subRL = subR->_left;

		//旋转 及 链接旋转之后节点之间的关系
		parent->_right = subRL;
		if (subRL) //可能为空的
			subRL->_parent = parent;
		subR->_left = parent;
		Node* pparent = parent->_parent;//这棵树也可能是其他树的子树，保存其祖先，准备判断
		parent->_parent = subR;

		if (parent == _root) //不是子树,本身就是根,则更新为新的根节点
		{
			_root = subR;
			subR->_parent = nullptr;
		}
		else          //是其他树的子树，则链接上
		{
			if (pparent->_left == parent)
				pparent->_left = subR;
			else if (pparent->_right == parent)
				pparent->_right = subR;
			subR->_parent = pparent;
		}
		//更新平衡因子
		subR->_bf = parent->_bf = 0;
	}
	void RotateR(Node* parent) //右单旋 
	{
		Node* subL = parent->_left;
		Node* subLR = subL->_right;
		parent->_left = subLR;
		if (subLR)
			subLR->_parent = parent;

		subL->_right = parent;
		Node* pparent = parent->_parent;
		parent->_parent = subL;

		if (parent == _root)
		{
			_root = subL;
			subL->_parent = nullptr;
		}
		else
		{
			if (pparent->_left == parent)
				pparent->_left = subL;
			else
				pparent->_right = subL;
			subL->_parent = pparent;
		}
		subL->_bf = parent->_bf = 0;
	}
	void RotateLR(Node* parent)//左右双旋，先对其左子树左旋，再对其右旋   ,但是要注意平衡因子的调整
	{
		Node* subL = parent->_left;
		Node* subLR = subL->_right;
		int bf = subLR->_bf;  //根据插入节点的父节点的平衡因子来判断

		RotateL(subL);
		RotateR(parent);
		//旋转后调节平衡因子
		if (bf == 1)  //本来是平衡的，来插入到右边
		{
			parent->_bf = 0;
			subL->_bf = - 1;
			subLR->_bf = 0;
		}
		else if (bf == -1)//本来是平衡的，来插入到左边
		{
			parent->_bf = 1;
			subL->_bf = 0;
			subLR->_bf = 0;
		}
		else if (bf == 0)//插入到高度低的那一边后，自己是平衡的，则双旋后，都是平衡的了
		{
			parent->_bf = 0;
			subL->_bf = 0;
			subLR->_bf = 0;
		}
	}
	void RotateRL(Node* parent)//右左双旋，先对其右子树右旋，在对其左旋
	{
		Node* subR = parent->_right;
		Node* subRL = subR->_left;
		int bf = subRL->_bf;

		RotateR(subR);
		RotateL(parent);
		
		if (bf == 1)
		{
			parent->_bf = -1;
			subR->_bf = 0;
			subRL->_bf = 0;
		}
		else if (bf == -1)
		{
			parent->_bf = 0;
			subR->_bf = 1;
			subRL->_bf = 0;
		}
		else if (bf == 0)
		{
			parent->_bf = 0;
			subR->_bf = 0;
			subRL->_bf = 0;
		}
	}

	void _InOrder(Node* root)
	{
		if (root == nullptr)
			return;

		_InOrder(root->_left);
		cout << root->_kv.first << ":" << root->_kv.second << endl;
		_InOrder(root->_right);
	}

	void InOrder()
	{
		_InOrder(_root);
	}

	int Height(Node* root)//求最大子树高度
	{
		if (root == nullptr)
			return 0;

		int lefeHeight = Height(root->_left);
		int rightHeight = Height(root->_right);

		return lefeHeight > rightHeight ? lefeHeight + 1 : rightHeight + 1;
	}

	bool _IsBalance(Node* root)//判断是否平衡，即左右子树高度差不超过1，及其左右子树也满足，即为平衡
	{
		if (root == nullptr)
			return true;

		int lefeHeight = Height(root->_left);
		int rightHeight = Height(root->_right);
		int diff = lefeHeight - rightHeight;//当前树的平衡因子

		// 如果计算出的平衡因子与root的平衡因子不相等，或者
		// root平衡因子的绝对值超过1，则一定不是AVL树
		if (diff != root->_bf || (diff > 1 || diff < -1))
		{
			cout << "平衡因子不匹配！" << endl;
			return false;
		}	 
		return  _IsBalance(root->_left) && _IsBalance(root->_right);
	}

	bool IsBalance()
	{
		return _IsBalance(_root);
	}
private:
	Node* _root = nullptr;
};



