**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

typedef struct ListNode Node;
struct ListNode* reverseList(struct ListNode* head){
    Node* cur=head;
    Node* newhead=NULL;
  while (head){
        cur= head -> next;//记录下一结点
        head -> next = newhead;//当前遍历的结点连接newhead
        newhead= head;//newhead指向当前结点，当前结点成为新表的首结点
        head = cur;//指向当前结点下一结点，所以nex的作用在于辅助遍历，防止断链
    }
    return newhead;//返回新表首结点
}