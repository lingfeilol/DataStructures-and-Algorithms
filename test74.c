/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
/**
 * Note: The returned array must be malloced, assume caller calls free().
 //开辟的数组开多大呢? 先求树有多少个节点
 */
 int treesize(struct TreeNode* root)
 {
    if(root==NULL)
        return 0;
    return treesize(root->left)+treesize(root->right)+1;
 }
 //写前序遍历
 //注意数组的下标i必须要传 地址，因为子树递归时会 加加下标，传回来后就改变了本来的值，造成数组下标越界报错
 void _inorderTraversal(struct TreeNode* root,int *a,int *pi)
 {
    if(root==NULL)
       return ;

    _inorderTraversal(root->left,a,pi);
    a[*pi]=root->val;
    ++*pi;
    _inorderTraversal(root->right,a,pi);

 }
int* inorderTraversal(struct TreeNode* root, int* returnSize){
    * returnSize=treesize(root);
    int *a=(int*)malloc(sizeof(int)* (*returnSize));
    int i=0;
    _inorderTraversal(root,a,&i);
    return a;
}