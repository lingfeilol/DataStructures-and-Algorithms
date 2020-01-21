题目描述

对于一个链表，请设计一个时间复杂度为O(n),额外空间复杂度为O(1)的算法，判断其是否为回文结构。

给定一个链表的头指针A，请返回一个bool值，代表其是否为回文结构。保证链表长度小于等于900。

测试样例： 1->2->2->1 返回：true

/*
struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};*/
class PalindromeList {
public:
    bool chkPalindrome(ListNode* A) {
        ListNode* B=(ListNode*)malloc(sizeof(ListNode));
        B=NULL;
        ListNode* tmp=A;
        ListNode* Next;
        //  思路：先反转 再判断
        while(tmp)
        {
            //头插
            Next=tmp->next;//先保留下一个要迭代的节点，防止断链
            
            tmp->next=B;
            B=tmp;
            
            tmp=Next;//更新循环条件
        }
        while(A)
        {
            if(A->val != B->val)
                return false;
            A=A->next;
            B=B->next;
        }
        return true;
        // write code here
    }
};