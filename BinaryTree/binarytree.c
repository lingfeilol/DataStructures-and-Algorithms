#include "binarytree.h"
#include "Queue.h"


// ͨ��ǰ�����������"ABD##E#H##CF##G##"����������
BTNode* BinaryTreeCreate(BTDataType* a, int n, int* pi)
{
	if (a[*pi] == '#' || *pi>=n)//���뽡׳��
	{
		return NULL;
	}
	BTNode* root = (BTNode*)malloc(sizeof(BTNode));
	root->_data = a[*pi];
	(*pi)++;
	root->_left = BinaryTreeCreate(a, n, pi);
	(*pi)++;
	root->_right= BinaryTreeCreate(a, n, pi);

	return root;
}

// ����������
void BinaryTreeDestory(BTNode** root)
{
	if (*root == NULL)
		return NULL;
	BinaryTreeDestory((*root)->_left);
	BinaryTreeDestory((*root)->_right);
	free(*root);
	*root = NULL;//�ͷŵ�ָ���ÿ�
}


// �������ڵ����
int BinaryTreeSize(BTNode* root)
{   //�����㷨��Ϊ��ֱ�ӷ���0��ֻ��һ�����ڵ㷵��һ�������������˵ݹ���ȥ
	/*if (root == NULL)
		return 0;
	else if (root->_left == NULL && root->_right == NULL)
		return 1;
	else
	{
		return 1 + BinaryTreeSize(root->_left) + BinaryTreeSize(root->_right);
	}*/

	//�����㷨��ʹ��������������ڵ㲻Ϊ���˾ͼ�һ
	static count=0;
	if (root == NULL)
		return 0;
	else
	{
		count++;
		BinaryTreeSize(root->_left);
		BinaryTreeSize(root->_right);
	}
	return count;
}

// ������Ҷ�ӽڵ����
int BinaryTreeLeafSize(BTNode* root)//���ö����������ж�ÿ���ڵ�
{
	static count = 0;
	if (root == NULL)
		return 0;
	else
	{
		if (root->_left == NULL && root->_right==NULL)
			count++;
		BinaryTreeLeafSize(root->_left);
		BinaryTreeLeafSize(root->_right);
	}
	return count;
}

//���������
//������������Ƚϸ��� �ټ��ϸ��ڵ�һ��
int BinaryTreeHighlength(BTNode* root)
{
	if (root == NULL)
		return 0;
	int lefthigh = BinaryTreeHighlength(root->_left);
	int righthigh = BinaryTreeHighlength(root->_right);
	return lefthigh > righthigh ? lefthigh + 1 : righthigh + 1;
}
// ��������k��ڵ����

//�ݹ鷽ʽ���裺
//�������ڵ�root��
//���rootΪ�գ����߲���k <= 0����Ϊ�������߲���Ҫ���򷵻�0��
//���root��Ϊ�գ��Ҵ�ʱ���� k== 1�����ʱrootΪ��K��ڵ�֮һ���򷵻�1��
//���root��Ϊ�գ��Ҵ�ʱ���� k > 1�����ʱ��Ҫ��root��������k - 1 ����ڵ�����root��������k - 1����ڵ���
int BinaryTreeLevelKSize(BTNode* root, int k)
{
	if (root == NULL||k<=0)
		return 0;
	if (root != NULL && k == 1)
		return 1;
	return BinaryTreeLevelKSize(root->_left, k - 1) +
		BinaryTreeLevelKSize(root->_right, k - 1);
}

// ����������ֵΪx�Ľڵ�
BTNode* BinaryTreeFind(BTNode* root, BTDataType x)
{
	BTNode* ret = NULL;
	if (root == NULL)
		ret=NULL;
	else
	{
		if (root->_data == x)//���жϸ�
		{
			ret = root;
		}
		else
		{
			if (ret == NULL)//������,�ȿ�������
				ret=BinaryTreeFind(root->_left, x);
			if (ret == NULL)//������Ҳ���ǣ��ٿ�������
				ret=BinaryTreeFind(root->_right, x);
		}

	}
	return ret;
}

// ������ǰ�����
void BinaryTreePrevOrder(BTNode* root)//�� ������ ������
{
	if (root)
	{
		printf("%c ", root->_data);
		BinaryTreePrevOrder(root->_left);
		BinaryTreePrevOrder(root->_right);
	}
}

// �������������
void BinaryTreeInOrder(BTNode* root)//������ �� ������
{
	if (root)
	{
		BinaryTreeInOrder(root->_left);
		printf("%c ", root->_data);
		BinaryTreeInOrder(root->_right);
	}
}

// �������������
void BinaryTreePostOrder(BTNode* root)//������ ������ ��
{
	if (root)
	{
		BinaryTreePostOrder(root->_left);
		BinaryTreePostOrder(root->_right);
		printf("%c ", root->_data);
	}

}

// �������
//���ö��У��Ƚ��ȳ������ڵ������
void BinaryTreeLevelOrder(BTNode* root)
{
	if (root)
	{
		Queue qu;
		QueueInit(&qu); //��ʼ������
		QueuePush(&qu, root);  //���ڵ��������
		BTNode* tmp=(BTNode*)malloc(sizeof(BTNode));
		while (!QueueEmpty(&qu)) //���в�Ϊ��ʱ
		{
			tmp= QueueFront(&qu);
			//printf("%c", tmp->_data);//��ӡ����ͷ��������е�ͷ�ڵ㣩
			putchar(tmp->_data);
			if (tmp->_left)   //�����ӽڵ�������
				QueuePush(&qu, tmp->_left);
			if (tmp->_right)   //���Һ��ӽڵ�������
				QueuePush(&qu, tmp->_right);
			QueuePop(&qu);//��ӡ��ͳ�������
		}
		QueueDestroy(&qu);
	}
	
}
//�����������ʵ�ֹ���
//1������һ��ָ�����飬����������ṹ��ָ�룬
//2��������������ڵ㣬��������� in��out ���������飬�ڱ��������У�ʼ�����ҵ��ڵ�͸ýڵ��ǰһ���ڵ㣬
//3��ѭ�����Ϲ��̡�
void BinaryTreeLevelOrder2(BTNode* root)
{
	BTNode* temp[100];//����pTreeNodeָ�����͵�ָ������
	int in = 0;
	int out = 0;
	temp[in++] = root;  //�ȱ�����������ڵ� 

	while (in > out)//��ıȳ��Ķ����ζ�������ﻹ��û����
	{
		if (temp[out])
		{
			printf("%c ", root->_data);
			temp[in++] = temp[out]->_left;//���ڵ���������ڵ���ջ
			temp[in++] = temp[out]->_right;//���ڵ���������ڵ���ջ
		}
		out++;//�൱��������ջ
	}
}

// �ж϶������Ƿ�����ȫ������
int BinaryTreeComplete(BTNode* root)
{
	Queue qu;
	QueueInit(&qu);
	QueuePush(&qu, root);
	int flag = 0;
	BTNode* tmp;
	while (!QueueEmpty(&qu))
	{
		tmp= QueueFront(&qu);
		if (tmp->_left && tmp->_right)
		{
			QueuePush(&qu, tmp->_left);
			QueuePush(&qu, tmp->_right);
		}
		else if (!tmp->_left && tmp->_right)//���Һ���ȴû���ӣ�������ȫ������������0��
			return 0;
		else if (!tmp->_right)//�Һ���Ϊ�գ���֪�����ӵ����
		{
			flag = 1;//����Һ���Ϊ��
			if (tmp->_left)//��������
				QueuePush(&qu, tmp->_left);//�����������ջ�����ж�������������ֻҪ����һ������������Ȼ������ȫ��������
		}
		if (flag == 1 && (tmp->_left || tmp->_right))//�Һ���Ϊ��   ��������ȱ���� �������к��� �Ǿ��Բ�����ȫ�������ˣ�ȡ���Ķ���ͷ�ڵ㲻��Ҷ�ӣ������ӻ������Һ��ӣ�
			return 0;
		QueuePop(&qu);
	}
	QueueDestroy(&qu);
	return 1;
}