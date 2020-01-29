typedef struct QueueNode
{
    int data;
    struct QueueNode* next;
}QNode;
typedef struct queue{
    QNode* front;
    QNode* tear;  
}queue;
typedef struct MyStack
{
    queue q1;
    queue q2;
}MyStack;
//先定义需要的队列数据结构的功能
void queueinit(queue* q)//从初始化
{
    q->front=NULL;
    q->tear=NULL;
}
void queueDestory(queue* q)//销毁
{
	QNode* cur = q->front;
	while (cur != NULL)
	{
		QNode* next = cur->next;
		free(cur);
		cur = next;
	}
	
	q->front = q->tear = NULL;
}
QNode* Buyqueuenode(int x)
{
    QNode* tmp=(QNode*)malloc(sizeof(QNode));
    tmp->data=x;
    tmp->next=NULL;
    return tmp;
}
void queuePush(queue* q,int x)//入对列
{
    QNode* cur=Buyqueuenode(x);
    if(q->tear==NULL)
    {
        q->front=q->tear=cur;
    }
    else
    {
        q->tear->next=cur;
        q->tear=cur;
    }
}
void queuePop(queue* q)//出队列
{
    QNode* tmp=q->front->next;
    free(q->front);
    q->front=tmp;
    if(q->front==NULL)//最后一个节点也出队列时，不能只置空头节点，尾节点也要置空，不然还指向最后那个被free的空间
    {
        q->tear=NULL;
    }
}

int queueFront(queue* q)//获取对头数据元素
{
	return q->front->data;
}
int queuetear(queue* q)//获取队尾元素
{
    return q->tear->data;
}
int queueSize(queue* q)//对列有效数据个数
{
    QNode* cur=q->front;
    int count=0;
    while(cur)
    {
        cur=cur->next;
        count++;
    }
    return count;
}
int IsEmpty(queue* q)//队列判空
{
    return q->front==NULL? 1:0;
}

/** Initialize your data structure here. */

MyStack* myStackCreate() {
    MyStack* obj=(MyStack*)malloc(sizeof(MyStack));
    queueinit(&(obj->q1));//要用传指针传参
    queueinit(&(obj->q2));
    return obj;
}

/** Push element x onto stack. */
void myStackPush(MyStack* obj, int x) {
    if(IsEmpty(&(obj->q1))==0)//往空的队列里入数据
        queuePush(&(obj->q1),x);
    else
        queuePush(&(obj->q2),x);
}

/** Removes the element on top of the stack and returns that element. */
int myStackPop(MyStack* obj) {
   if(IsEmpty(&(obj->q1))==0)//不为空，就只留最后一个队尾并保存，其他全部去入另一个空队列，再把留下的这个队尾当作栈顶返回
   {
       while(queueSize(&(obj->q1)) > 1)
       {
        queuePush( (&(obj->q2)) , queueFront(&(obj->q1)) );
        queuePop(&(obj->q1)); 
       }
       int teartop=queueFront(&(obj->q1));
       queuePop(&(obj->q1));
       return teartop;
   }
   else
   {
        while(queueSize(&(obj->q2)) > 1)
       {
        queuePush(&(obj->q1),queueFront(&(obj->q2)));
        queuePop(&(obj->q2));
       }
       int teartop=queueFront(&(obj->q2));
       queuePop(&(obj->q2));
       return teartop;

   }
}

/** Get the top element. */
int myStackTop(MyStack* obj) {//返回不为空的队列的队尾元素
    if(IsEmpty(&(obj->q1))==0)
    {
        return queuetear(&(obj->q1));
    }
    else
    {
        return queuetear(&(obj->q2));
    }

}

/** Returns whether the stack is empty. */
bool myStackEmpty(MyStack* obj) {
    if(IsEmpty(&(obj->q1))==1 && IsEmpty(&(obj->q2))==1)//两个队列里都没有数据时，这个栈也就为空了
    {
        return true;
    }
    return false;
}

void myStackFree(MyStack* obj) {
    queueDestory(&(obj->q1));//销毁掉两个队列
    queueDestory(&(obj->q2));
    free(obj);//再free掉这个栈开辟的空间
}

/**
 * Your MyStack struct will be instantiated and called as such:
 * MyStack* obj = myStackCreate();
 * myStackPush(obj, x);
 
 * int param_2 = myStackPop(obj);
 
 * int param_3 = myStackTop(obj);
 
 * bool param_4 = myStackEmpty(obj);
 
 * myStackFree(obj);
*/