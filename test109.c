/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
/*
解题思路：
判断一个树是否对称，首先要判断左右孩子是否对称相等，还需要判断左孩子的左子树是否和右孩子的右子树对
称，左孩子的右子树是否和右孩子的左子树对称。
*/
bool _isSymmetric(struct TreeNode* leftchild,struct TreeNode* rightchild)
{
    if(leftchild==NULL && rightchild==NULL)//都为空
        return  true;
    if(leftchild==NULL || rightchild== NULL)//一个为空另一个不为空
        return false;
    // if(leftchild->val!=rightchild->val)
    //     return false;
    return (leftchild->val==rightchild->val)
        && _isSymmetric(leftchild->left,rightchild->right)
        && _isSymmetric(leftchild->right,rightchild->left);
}

bool isSymmetric(struct TreeNode* root){
    if(root==NULL)
        return true;
    return _isSymmetric(root->left,root->right);

}

