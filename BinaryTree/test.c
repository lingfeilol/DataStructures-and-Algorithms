#define _CRT_SECURE_NO_WARNINGS 1
#include "binarytree.h"
int main()
{
	char* a = "ABD##E#H##CF##G##";
	int n = strlen(a);
	int pi = 0;
	BTNode* root = BinaryTreeCreate(a, n, &pi);
	BinaryTreePrevOrder(root);
	printf("�ڵ������%d \n",BinaryTreeSize(root));//�ڵ����
	printf("Ҷ�ӽڵ������%d \n", BinaryTreeLeafSize(root));//Ҷ�ӽڵ����

	BTNode* ret=BinaryTreeFind(root,'B');//��������ΪB�Ľڵ�
	printf("�ҵ��ˣ�%c \n ", ret->_data);

	printf("���k=%d \n",BinaryTreeHighlength(root));
	printf("���Ľڵ�����%d \n", BinaryTreeLevelKSize(root, 2));//��ڶ���ڵ���


	BinaryTreeLevelOrder(root);//�������
	printf("\n");

	printf("�Ƿ�Ϊ��ȫ��������%d\n",BinaryTreeComplete(root));
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