
// 二叉树第k层节点个数
int BinaryTreeLevelKSize(BTNode* root, int k)
{
	if(root==NULL)
		return 0;
	if(k==1) 
		return 1;只有递推到最后一层（第k层时）
	int left=BinaryTreeLevelKSize(root->left,k-1);
	int right=BinaryTreeLevelKSize(root->right,k-1);
	return left+right;
}
