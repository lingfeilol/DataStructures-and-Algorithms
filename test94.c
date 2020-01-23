题目描述
在一个排序的链表中，存在重复的结点，请删除该链表中重复的结点，重复的结点不保留，返回链表头指针。
例如，链表1->2->3->3->4->4->5 处理后为 1->2->5
/*
struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) :
        val(x), next(NULL) {
    }
};
*/

class Solution {
public:
    ListNode* deleteDuplication(ListNode* pHead)
    {
          if(pHead==NULL||pHead->next==NULL) return pHead;
          else
          {
              //新建一个节点，防止头结点要被删除
              ListNode* newHead=(ListNode*)malloc(sizeof(ListNode));
              newHead->next=pHead;
              
              ListNode* pre=newHead;
              ListNode* p=pHead;
              ListNode* Next=NULL;
              while(p!=NULL && p->next!=NULL)
              {
                  Next=p->next;
                  if(p->val==Next->val)//如果当前节点的值和下一个节点的值相等
                  {
                      while(Next!=NULL && Next->val==p->val)//向后重复查找
                          Next=Next->next;
                    pre->next=Next;//指针赋值，就相当于删除
                    p=Next;
                  }
                  else//如果当前节点和下一个节点值不等，则向后移动一位
                  {
                      pre=p;
                      p=p->next;
                  }
              }
           return newHead->next;//返回头结点的下一个节点
               
          }
    }
};
