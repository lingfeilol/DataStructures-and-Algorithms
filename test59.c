// 二叉树叶子节点个数
分解成 三部分  左子树叶子节点数  右子树叶子节点数 总结点数就是两部分之和
终止条件  //空树；一个节点的树(无孩子节点) 两种情况
int BinaryTreeLeafSize(BTNode* root)
{
	if(root==NULL)
		return 0;
	if(root->left==NULL&&root->right==NULL)
		return 1;
	int left=BinaryTreeLeafSize(root->left);
	int right=BinaryTreeLeafSize(root->right);
	return left+right;	
}




//二叉树的层数
int gethigh(BTNode* root)
{	
	if(root==NULL)
		return 0;
	
	int left=gethigh(root->left);
	int right=gethigh(root->right);
	return (left>right？left:right)+1;
}
