/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
 typedef struct ListNode Node;
bool hasCycle(struct ListNode *head) {
    if(head==NULL||head->next==NULL)
        return false;
    //快慢指针，一步两步    
    Node* n1=head;
    Node* n2=head;
     while(n2 && n2->next)
        {
            n2 = n2 -> next -> next;
            n1 = n1 -> next;
            if(n2 == n1)
                return true;
        }
        return false;
 }