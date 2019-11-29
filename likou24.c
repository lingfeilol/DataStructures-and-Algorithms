/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

typedef struct ListNode Node;
struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2){
    if (l1 == NULL) return l2;
    if (l2 == NULL) return l1;
    Node*head = (struct ListNode*)malloc(sizeof(struct ListNode));
     Node *l3=head;
   while(l1&&l2){
        if (l1 -> val < l2 -> val){
           l3 -> next =l1;
            l1 = l1 -> next; 
            l3 = l3 -> next;
        } 
       else {
           l3 -> next = l2;
           l2 = l2 -> next;
           l3 = l3 -> next;
        } 
   }
   //跳出循环后还有一个没遍历完，直接链接到后面
    if(l1)
        l3->next=l1;
    if(l2)
        l3->next=l2;
    return head -> next;
}
