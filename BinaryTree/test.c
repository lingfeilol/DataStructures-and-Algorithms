#define _CRT_SECURE_NO_WARNINGS 1
#include "binarytree.h"
int main()
{
	char* a = "ABD##E#H##CF##G##";
	int n = strlen(a);
	int pi = 0;
	BTNode* root = BinaryTreeCreate(a, n, &pi);
	BinaryTreePrevOrder(root);
	printf("节点个数：%d \n",BinaryTreeSize(root));//节点个数
	printf("叶子节点个数：%d \n", BinaryTreeLeafSize(root));//叶子节点个数

	BTNode* ret=BinaryTreeFind(root,'B');//查找数据为B的节点
	printf("找到了：%c \n ", ret->_data);

	printf("深度k=%d \n",BinaryTreeHighlength(root));
	printf("这层的节点数：%d \n", BinaryTreeLevelKSize(root, 2));//求第二层节点数


	BinaryTreeLevelOrder(root);//层序遍历
	printf("\n");

	printf("是否为完全二叉树：%d\n",BinaryTreeComplete(root));
	return 0;
}


//typedef int BTDatatype;
//typedef struct BTnode
//{
//	struct BTnode* left;
//	struct BTnode* right;
//	BTDatatype val;
//}BTnode;
//void CreateTree(BTnode* root)
//{
//	char ch;
//	ch = getchar();
//	if (ch == '#')  root = NULL;
//	else
//	{
//		root->val = ch;
//		CreateTree(root->left);
//		CreateTree(root->right);
//	}
//}
//int main()
//{
//	BTnode* root=CreateTree()
//	return 0;
//}