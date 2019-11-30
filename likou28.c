/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* removeElements(struct ListNode* head, int val){
    if(head==NULL)  return head;
    struct ListNode* cur=head;
    while(cur->next!=NULL)//从第二个开始考虑
    {
        if(cur->next->val==val)
        {
            cur->next=cur->next->next;
        }
        else
        {
            cur=cur->next;
        }
    } 
    if(head->val==val)//回来考虑第一个
    {
        head=head->next;
    }
    return head;
}