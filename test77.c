#include<stdio.h>
#include<malloc.h>
typedef struct BTnode
{
    struct BTnode* left;
    struct BTnode* right;
    int val;
}BTnode;
BTnode *creattree(char* a,int* index)//前序遍历的初始化
{
    if(a[*index]=='#')
         return NULL;
    BTnode* root=(BTnode*)malloc(sizeof(BTnode));
    root->val=a[*index];
    ++(*index);
    root->left=creattree(a,index);
    ++(*index);
    root->right=creattree(a,index);
}
void inorder(BTnode* root)//中序遍历
{
    if(root==NULL)
        return ;
    inorder(root->left);
    printf("%c ",root->val);
    inorder(root->right);
}
int main()
{
    char a[100]={0};
    scanf("%s",a);
    int index=0;
    BTnode* root=creattree(a,&index);
    inorder(root);
    return 0;
}