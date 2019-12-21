// 二叉树节点个数
遍历的方式   (前中后三种排序方式)  遇到一个节点 就count++
int BinaryTreeSize(BTNode * root)
{
	int size;
	if(root==NULL)
		return ;
	size++;
	BinaryTreeSize(root->left);
	BinaryTreeSize(root->right);
	return size;
}
递推的方式
分解成 三部分  左子树  根节点  右子树 总结点数就是三部分之和
int BinaryTreeSize(BTNode * root)
{
	if（root==NULL）
		return 0;
	int left=BinaryTreeSize(root->left);
	int right=BinaryTreeSize(root->rihgt);
	
	return left+right+1;

}