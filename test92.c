/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
 typedef struct ListNode Node;
struct ListNode *detectCycle(struct ListNode *head) {
    if(head==NULL || head->next==NULL)  return  NULL;
    Node* slow=head;
    Node* fast=head;
    while(fast && fast->next)
    {//快慢指针求相遇点
        slow=slow->next;
        fast=fast->next->next;
        if(slow==fast)//相遇点
            break;//slow保留第一次相遇点
    }
    fast=head;//fast重新从头开始
    while(slow) //第二次相遇即是入口点
    {
        if(fast==slow)
        {
            return slow;
        }
        slow=slow->next;
        fast=fast->next;
    }
    return NULL;
}