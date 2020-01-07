/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
int maxDepth(struct TreeNode* root){//先求高度
    if(root==NULL)
        return 0;
    int left=maxDepth(root->left);
    int right=maxDepth(root->right);
    return left>right? left+1:right+1;
}

bool isBalanced(struct TreeNode* root){
    if(root==NULL)
        return true;
    int leftDepth=maxDepth(root->left);
    int rightDepth=maxDepth(root->right);//比左右子树的高度差
    return  abs(leftDepth-rightDepth)<2
           &&  isBalanced(root->left) && isBalanced(root->right);
    // return ((maxDepth(root->left)-maxDepth(root->right)<2)||(maxDepth(root->right)-maxDepth(root->left)<2))
    //          &&  isBalanced(root->left) && isBalanced(root->right);

}