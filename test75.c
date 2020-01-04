/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
 bool isSameTree(struct TreeNode* p, struct TreeNode* q){//相同树函数
    if(p==NULL && q!=NULL)
        return false;
    else if(p!=NULL && q==NULL)
        return false;
    else if(p==NULL && q==NULL)
        return true;
    else if(p->val != q->val)
        return false;
    return isSameTree(p->left,q->left)
            &&isSameTree(p->right,q->right);
}
bool isSubtree(struct TreeNode* s, struct TreeNode* t){//题中所说两个非空二叉树 就只需要考虑结束条件 s为NULL这个条件了
    // if(s==NULL && t==NULL)
    //     return true;
    // else if(s==NULL &&t!=NULL)
    //     return false;
    // else if(s!=NULL && t==NULL)
    //     return false;
    if(s==NULL)
        return false;
    if(isSameTree(s,t))//从根节点就相等了，直接为真
        return true;
    return  isSubtree(s->left,t) ||  isSubtree(s->right,t);//考虑左子树和右子树中有没有相同
}