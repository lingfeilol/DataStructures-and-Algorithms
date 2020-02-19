//桉竖向树状打印二叉树
//逆中序  右子树  根  左子树
void Printtree(BTNode* root, int nlayer)
{
	if (root == NULL)
		return ;
	Printtree(root->_right, nlayer + 1);
	for (int i = 0; i < nlayer; i++)  //按逆中序输出节点 ，用层数深度决定左、右位置
	{
		printf("  ");
	}
	printf("%c\n",root->_data); //换一行
	Printtree(root->_left, nlayer + 1);
}