/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
// */
// 此题可以分三步进行：
// 1.拷贝链表的每一个节点，拷贝的节点先链接到被拷贝节点的后面
// 2.复制随机指针的链接：拷贝节点的随机指针指向被拷贝节点随机指针的下一个位置
// 3.拆解链表，把拷贝的链表从原链表中拆解出来
// */
class Solution {
public:
    Node* copyRandomList(Node* head) {
        //1.拷贝节点
        Node* cur=head;
        while(cur)
        {
            Node* Next=cur->next;
            Node* copy=(Node*)malloc(sizeof(Node));
            copy->val=cur->val;
            //拷贝节点放到源节点后面
            cur->next=copy;
            copy->next=Next;

            cur=Next;
        }
        //2.拷贝随即指针给 刚才拷贝的节点
        cur=head;
        while(cur)
        {
            Node* copy=cur->next;
            Node* Next=copy->next;
            //随即指针的指向节点  直接拷贝给 拷贝节点的随即指针
            if(cur->random!=NULL)//可能随机指针为空，下一步中有随即指针的next操作 所以必须要判空
                copy->random=cur->random->next;
            else
                copy->random=NULL;
            cur=Next;//迭代
        }
        //3.去掉旧节点 即把拷贝节点尾插到另一条链上 打印
        cur=head;
        Node* newhead=NULL;//输出用
        Node* curhead=newhead;//迭代更新用
        while(cur)
        {
            Node* copy=cur->next;
            Node* Next=copy->next;

            if(curhead==NULL)
            {
                newhead=curhead=copy;//头节点都赋值
            }
            else
            {
                curhead->next=copy;
                curhead=copy;
            }
            cur->next=Next;//防止链表断链，保持原链表结构
            cur=Next;
        }
        return newhead;
        
    }
};