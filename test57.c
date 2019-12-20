 二叉树 广度优先遍历 （层序）递归
  运用队列实现   
 
  // 层序遍历
void BinaryTreeLevelOrder(BTNode* root)
{
	QueueInit(&qu); //初始化队列
	QueuePush(&qu,root);  根节点先入队列
	while(!Queueisempty(&qu)) //队列不为空时
	{	
		tmp=QueueFront（&qu）;
		printf("%c",tmp->data);//打印队列头（先入队列的头节点）
		if（tmp->left）   //有左孩子节点就入队列
			QueuePush(&qu,tmp->left);
		if(tmp->right)   //有右孩子节点就入队列
			QueuePush(&qu,tmp->right);
		
		Queuepop(&qu);//打印完就出队列了
	}
}