#include "binarytree.h"
#include "Queue.h"


// 通过前序遍历的数组"ABD##E#H##CF##G##"构建二叉树
BTNode* BinaryTreeCreate(BTDataType* a, int n, int* pi)
{
	if (a[*pi] == '#' || *pi>=n)//代码健壮性
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

// 二叉树销毁
void BinaryTreeDestory(BTNode** root)
{
	if (*root == NULL)
		return NULL;
	BinaryTreeDestory((*root)->_left);
	BinaryTreeDestory((*root)->_right);
	free(*root);
	*root = NULL;//释放的指针置空
}


// 二叉树节点个数
int BinaryTreeSize(BTNode* root)
{   //分治算法，为空直接返回0，只有一个根节点返回一，有左右子树了递归下去
	/*if (root == NULL)
		return 0;
	else if (root->_left == NULL && root->_right == NULL)
		return 1;
	else
	{
		return 1 + BinaryTreeSize(root->_left) + BinaryTreeSize(root->_right);
	}*/

	//计数算法，使用先序遍历，根节点不为空了就加一
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

// 二叉树叶子节点个数
int BinaryTreeLeafSize(BTNode* root)//利用二叉树遍历判断每个节点
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

//二叉树深度
//左右子树中深度较高者 再加上根节点一层
int BinaryTreeHighlength(BTNode* root)
{
	if (root == NULL)
		return 0;
	int lefthigh = BinaryTreeHighlength(root->_left);
	int righthigh = BinaryTreeHighlength(root->_right);
	return lefthigh > righthigh ? lefthigh + 1 : righthigh + 1;
}
// 二叉树第k层节点个数

//递归方式步骤：
//给定根节点root：
//如果root为空，或者层数k <= 0，则为空树或者不合要求，则返回0；
//如果root不为空，且此时层数 k== 1，则此时root为第K层节点之一，则返回1；
//如果root不为空，且此时层数 k > 1，则此时需要求root左子树（k - 1 ）层节点数和root右子树（k - 1）层节点数
int BinaryTreeLevelKSize(BTNode* root, int k)
{
	if (root == NULL||k<=0)
		return 0;
	if (root != NULL && k == 1)
		return 1;
	return BinaryTreeLevelKSize(root->_left, k - 1) +
		BinaryTreeLevelKSize(root->_right, k - 1);
}

// 二叉树查找值为x的节点
BTNode* BinaryTreeFind(BTNode* root, BTDataType x)
{
	BTNode* ret = NULL;
	if (root == NULL)
		ret=NULL;
	else
	{
		if (root->_data == x)//先判断根
		{
			ret = root;
		}
		else
		{
			if (ret == NULL)//根不是,先看左子树
				ret=BinaryTreeFind(root->_left, x);
			if (ret == NULL)//左子树也不是，再看右子树
				ret=BinaryTreeFind(root->_right, x);
		}

	}
	return ret;
}

// 二叉树前序遍历
void BinaryTreePrevOrder(BTNode* root)//根 左子树 右子树
{
	if (root)
	{
		printf("%c ", root->_data);
		BinaryTreePrevOrder(root->_left);
		BinaryTreePrevOrder(root->_right);
	}
}

// 二叉树中序遍历
void BinaryTreeInOrder(BTNode* root)//左子树 根 右子树
{
	if (root)
	{
		BinaryTreeInOrder(root->_left);
		printf("%c ", root->_data);
		BinaryTreeInOrder(root->_right);
	}
}

// 二叉树后序遍历
void BinaryTreePostOrder(BTNode* root)//左子树 右子树 根
{
	if (root)
	{
		BinaryTreePostOrder(root->_left);
		BinaryTreePostOrder(root->_right);
		printf("%c ", root->_data);
	}

}

// 层序遍历
//利用队列，先进先出，根节点入队列
void BinaryTreeLevelOrder(BTNode* root)
{
	if (root)
	{
		Queue qu;
		QueueInit(&qu); //初始化队列
		QueuePush(&qu, root);  //根节点先入队列
		BTNode* tmp=(BTNode*)malloc(sizeof(BTNode));
		while (!QueueEmpty(&qu)) //队列不为空时
		{
			tmp= QueueFront(&qu);
			//printf("%c", tmp->_data);//打印队列头（先入队列的头节点）
			putchar(tmp->_data);
			if (tmp->_left)   //有左孩子节点就入队列
				QueuePush(&qu, tmp->_left);
			if (tmp->_right)   //有右孩子节点就入队列
				QueuePush(&qu, tmp->_right);
			QueuePop(&qu);//打印完就出队列了
		}
		QueueDestroy(&qu);
	}
	
}
//层序遍历数组实现过程
//1、创建一个指针数组，保存二叉树结构体指针，
//2、保存二叉树根节点，再申请变量 in、out ，控制数组，在遍历过程中，始终能找到节点和该节点的前一个节点，
//3、循环以上过程。
void BinaryTreeLevelOrder2(BTNode* root)
{
	BTNode* temp[100];//创建pTreeNode指针类型的指针数组
	int in = 0;
	int out = 0;
	temp[in++] = root;  //先保存二叉树根节点 

	while (in > out)//入的比出的多就意味着数组里还有没出的
	{
		if (temp[out])
		{
			printf("%c ", root->_data);
			temp[in++] = temp[out]->_left;//根节点的左子树节点入栈
			temp[in++] = temp[out]->_right;//根节点的右子树节点入栈
		}
		out++;//相当于用完后出栈
	}
}

// 判断二叉树是否是完全二叉树
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
		else if (!tmp->_left && tmp->_right)//有右孩子却没左孩子，不是完全二叉树，返回0；
			return 0;
		else if (!tmp->_right)//右孩子为空，不知道左孩子的情况
		{
			flag = 1;//标记右孩子为空
			if (tmp->_left)//且有左孩子
				QueuePush(&qu, tmp->_left);//这个左孩子先入栈，在判断其左右子树，只要有任一左右子树，必然不是完全二叉树，
		}
		if (flag == 1 && (tmp->_left || tmp->_right))//右孩子为空   （本来就缺孩子 你再生有孩子 那绝对不是完全二叉树了）取出的队列头节点不是叶子（有左孩子或者有右孩子）
			return 0;
		QueuePop(&qu);
	}
	QueueDestroy(&qu);
	return 1;
}