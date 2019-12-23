
// 二叉树查找值为x的节点
没找到 返回NULL；
先在根找，再去左子树找，再去右子树找
BTNode* BinaryTreeFind(BTNode* root, BTDataType x)
{
	if(root==NULL)
		return NULL;
	if(root->data==x)
		return root;
	////////////////////if(BinaryTreeFind(root->left,x)==NULL)//左子树里也没找到
	BTNode* ret=BinaryTreeFind(root->left,x);/// 创个节点保存返回值
	if(ret!=NULL)//不为空就是找到了
		return ret;  返回这个节点
	
	BTNode* ret=BinaryTreeFind(root->right,x);/// 
	if(ret!=NULL)//找到了
		return ret;  返回这个节点
	
	else if(ret==NULL) // 左右子树里都没找到
		return NULL;
}


