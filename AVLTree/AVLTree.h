#pragma once
#include<assert.h>


template<class K, class V>
struct AVLTreeNode
{
	AVLTreeNode<K, V>* _left;
	AVLTreeNode<K, V>* _right;
	AVLTreeNode<K, V>* _parent;
	int _bf;//ƽ������
	pair<int, int> _kv;//��ֵ�� ���͵�Ԫ��

	//���캯��
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
		//1.�����������Ĺ����ҵ�����λ��
		if (_root == nullptr)//һ��ʼΪ��ʱ
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
				return false; //֮ǰ�й�
			}
		}
		//2.�ҵ�����λ�ú󣬽��в���
		cur = new Node(kv);
		if (parent->_kv.first < kv.first) //���ص���������
		{
			parent->_right = cur;
			cur->_parent = parent;
		}
		else //���ص�������
		{
			parent->_left = cur;
			cur->_parent = parent;
		}
		//3.Ϊ�˱���ƽ�⣬����ƽ�������ж��Ƿ���Ҫ��ת���Ҹ���ƽ������  ƽ������= �������߶�-�������߶�
		///�²���Ľڵ㣬Ӱ������²���ڵ�����ȵ�ƽ������
			/////////a.�������ĸ߶ȱ仯�����׵�ƽ������ + 1, �������ĸ߶ȱ仯�����׵�ƽ������ - 1
			/////////b.���׵�ƽ�����ӵ�����ɺ���1/ -l����˵���������ڵ������ĸ߶ȱ��ˣ���������ϸ��¡�
			////////c.���׵�ƽ�����Ӹ�����ɺ���2 / 2, ��˵���������ڵ������Ѿ���ƽ�⣬��ô��Ҫ��ת��������ƽ�⡣
			////////d.���׵�ƽ�����Ӹ�����ɺ���0,��˵���������ڵ������ĸ߶�û�䣬����һ��û��Ӱ�죬�������ɡ�

		while (parent)
		{
			//����ƽ������
			if (cur == parent->_left)//�ҵ�����ߵģ����Ӽ�һ
				parent->_bf--;
			else  if(cur == parent->_right)   //�ҵ��ұߣ����Ӽ�һ
				parent->_bf++;
			//�ж��Ƿ���Ҫ��Ҫ��ת ��Ӧ�������
			if (parent->_bf == 0)//�ϲ��Ѿ���ƽ���˵�
				break;
			else if (abs(parent->_bf)==1)
			{
				cur = parent;
				parent = parent->_parent;//�������ϸ���
			}
			else if (parent->_bf == 2 || parent->_bf == -2)
			{
				// ˵��parent�����Ѿ���ƽ�⣬��Ҫ��ת��������ƽ��
				if (parent->_bf == 2)
				{
					if (cur->_bf == 1)//��������������
						RotateL(parent);
					else if (cur->_bf == -1)//������������
						RotateRL(parent);
				}
				else if (parent->_bf == -2)
				{
					if (cur->_bf == -1)
					{
						RotateR(parent);//�ҵ���
					}
					else if (cur->_bf == 1)
					{
						RotateLR(parent);//������������
					}
				}
				//������Ϻ� break;
				break;
			}
		}
		return true;
	}
	void RotateL(Node* parent) //����
	{
		Node* subR = parent->_right;  //��ת��Ҫ������
		Node* subRL = subR->_left;

		//��ת �� ������ת֮��ڵ�֮��Ĺ�ϵ
		parent->_right = subRL;
		if (subRL) //����Ϊ�յ�
			subRL->_parent = parent;
		subR->_left = parent;
		Node* pparent = parent->_parent;//�����Ҳ�����������������������������ȣ�׼���ж�
		parent->_parent = subR;

		if (parent == _root) //��������,������Ǹ�,�����Ϊ�µĸ��ڵ�
		{
			_root = subR;
			subR->_parent = nullptr;
		}
		else          //������������������������
		{
			if (pparent->_left == parent)
				pparent->_left = subR;
			else if (pparent->_right == parent)
				pparent->_right = subR;
			subR->_parent = pparent;
		}
		//����ƽ������
		subR->_bf = parent->_bf = 0;
	}
	void RotateR(Node* parent) //�ҵ��� 
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
	void RotateLR(Node* parent)//����˫�����ȶ����������������ٶ�������   ,����Ҫע��ƽ�����ӵĵ���
	{
		Node* subL = parent->_left;
		Node* subLR = subL->_right;
		int bf = subLR->_bf;  //���ݲ���ڵ�ĸ��ڵ��ƽ���������ж�

		RotateL(subL);
		RotateR(parent);
		//��ת�����ƽ������
		if (bf == 1)  //������ƽ��ģ������뵽�ұ�
		{
			parent->_bf = 0;
			subL->_bf = - 1;
			subLR->_bf = 0;
		}
		else if (bf == -1)//������ƽ��ģ������뵽���
		{
			parent->_bf = 1;
			subL->_bf = 0;
			subLR->_bf = 0;
		}
		else if (bf == 0)//���뵽�߶ȵ͵���һ�ߺ��Լ���ƽ��ģ���˫���󣬶���ƽ�����
		{
			parent->_bf = 0;
			subL->_bf = 0;
			subLR->_bf = 0;
		}
	}
	void RotateRL(Node* parent)//����˫�����ȶ����������������ڶ�������
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

	int Height(Node* root)//����������߶�
	{
		if (root == nullptr)
			return 0;

		int lefeHeight = Height(root->_left);
		int rightHeight = Height(root->_right);

		return lefeHeight > rightHeight ? lefeHeight + 1 : rightHeight + 1;
	}

	bool _IsBalance(Node* root)//�ж��Ƿ�ƽ�⣬�����������߶Ȳ����1��������������Ҳ���㣬��Ϊƽ��
	{
		if (root == nullptr)
			return true;

		int lefeHeight = Height(root->_left);
		int rightHeight = Height(root->_right);
		int diff = lefeHeight - rightHeight;//��ǰ����ƽ������

		// ����������ƽ��������root��ƽ�����Ӳ���ȣ�����
		// rootƽ�����ӵľ���ֵ����1����һ������AVL��
		if (diff != root->_bf || (diff > 1 || diff < -1))
		{
			cout << "ƽ�����Ӳ�ƥ�䣡" << endl;
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



