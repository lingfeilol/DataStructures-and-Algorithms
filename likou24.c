struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2){
    if (l1 == NULL) return l2;
    if (l2 == NULL) return l1;
    struct ListNode *l3,*head ;
    head = (struct ListNode*)malloc(sizeof(struct ListNode));
    l3 = head;
    
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
    
    l3 -> next = l1 ? l1 : l2;
       return head -> next;
    

}