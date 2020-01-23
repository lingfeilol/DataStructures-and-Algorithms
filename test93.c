/*
解题思路：
此题可以先找到中间节点，然后把后半部分逆置，最近前后两部分一一比对，如果节点的值全部相同，则即为回文。
*/
class PalindromeList {
public:
bool chkPalindrome(ListNode* A) {
if (A == NULL || A->next == NULL)
return true;
ListNode* slow, *fast, *prev, *cur, *nxt;
slow = fast = A;
//找到中间节点
while (fast && fast->next)
{
slow = slow->next;
fast = fast->next->next;
}
prev = NULL;
//后半部分逆置
cur = slow;
while (cur)
{
nxt = cur->next;
cur->next = prev;
prev = cur;
cur = nxt;
}
//逐点比对
while (A && prev)
{
if (A->val != prev->val)
return false;
A = A->next;
prev = prev->next;
}
return true;
}
};
/*
此题也可以先把链表中的元素值全部保存到数组中，然后再判断数组是否为回文。不建议使用这种解法，因为如果没有
告诉链表最大长度，则不能同此解法
*/
class PalindromeList {
public:
bool chkPalindrome(ListNode* A) {
// write code here
int a[900] = {0};
ListNode* cur = A;
int n = 0;
//保存链表元素
while(cur)
{
a[n++] = cur->val;
cur = cur->next;
}
//判断数组是否为回文结构
int begin = 0, end = n-1;
while(begin < end)
{
if(a[begin] != a[end])
return false;
++begin;
--end;
}
return true;
}
};