  非递归   前序遍历 二叉树
1.先看根节点  打印
2.再看有没有右孩子节点，有 就入栈，没有就看 有没有左孩子节点 有左孩子节点了，直接进入左孩子节点
3.要是没有左孩子节点（左孩子到尽头了），直接去取栈顶元素，在进行出栈操作
重复迭代以上三步
 
 创建一个栈的数据结构
 创建一个二叉树节点 接受函数传来的参数（根节点）
 
 viod BinaryTreePrevNonR(BTNode* root)
 {
	Stack st;
	BTNode* cur=root;
	StackInit(&st,100);//栈的初始化

	while（cur||!StackISEmpty(&st)）//当传入的根节点不为空时或者 栈里不为空（存入的有右孩子节点）
	{
		打印cur->data
		if（cur->right）   将右孩子节点入栈stackpush(&st,cur->right);
		if（cur->left）    进入左孩子节点   cur=cur->left;
		else     
				cur=stackfront(&st);去取栈顶元素 
				stackpop(&st);出栈
	}
	stackdoestry(&st);栈的销毁
 }
