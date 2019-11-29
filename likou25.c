/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

typedef struct ListNode Node;
struct ListNode* middleNode(struct ListNode* head){
    Node* solw=head;
    Node* fast=head;
   //快慢指针   慢的走一步，快的走两步（相当于除2），因为此题中间节点可看成总长度除以2；
    while(fast!=NULL&&fast->next!=NULL)
    {
        solw=solw->next;
        fast=fast->next->next;
    }
    return solw;
}