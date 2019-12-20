   递归  二叉树遍历
   
  viod BinaryTreePrevOrder(BTNode* root)//前序遍历 根左右
  {
		if(root!=NULL)
		{
			printf("%c",root->data);
			BinaryTreePrevNonR(root->left);
			BinaryTreePrevNonR(root->right);
			
		}
  }
  
  
  viod BinaryTreeINOrder(BTNode* root)//中序遍历   左根右
  {
		if(root!=NULL)
		{
			BinaryTreePrevNonR(root->left);
			printf("%c",root->data);
			BinaryTreePrevNonR(root->right);
			
		}
  }
  
  
  
  viod BinaryTreeFostOrde(BTNode* root)//后序遍历   左右根
  {
		if(root!=NULL)
		{
			BinaryTreePrevNonR(root->left);
			BinaryTreePrevNonR(root->right);
			printf("%c",root->data);
			
		}
  }


二叉树销毁
	// 二叉树销毁
void BinaryTreeDestory(BTNode* root）
{
	BTNode* left,*right;
	if(root)
	{
		left=root->left;
		right=root->right;
		free(root);
		BinaryTreeDestory(left);
		BinaryTreeDestory(right);
	}
}