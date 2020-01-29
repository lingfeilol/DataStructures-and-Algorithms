#define MAX 1000
typedef struct stack
{
    int *array;
    int size;
    //int capacity;
}stack;
typedef struct MyQueue{
    stack s1;
    stack s2;
} MyQueue;
// void CheckCapacity(stack* s)
// {
// 	if (s->size >= s->capacity)//判断是否扩容
// 	{
// 		s->capacity *= 2;    //2倍扩容
// 		s->array = (int *)realloc(s->array, s->capacity * sizeof(int));      
// 	}
// }
void StackInit(stack* s)//初始化
{
	s->array = (int *)calloc(MAX,sizeof(int));//开空间并初始化为0
	//s->capacity = MAX;
	s->size = 0;
}
void stackpush(stack* s,int x)
{
   // CheckCapacity(s);
    s->array[s->size]=x;
    s->size++;
}
void stackpop(stack* s)
{
    if(s->size==0)
    {
        return ;
    }
    s->size--;
}
int stacktop(stack* s)
{
    if(s->size==0)
    {
        return 0;
    }
    return s->array[s->size-1];
}
int stackIsempty(stack *s)
{
    return s->size==0;
}
int stackSize(stack* s)//获取里有效元素个数
{
	return s->size;
}
void stackDestory(stack* s)//栈的销毁
{
	if (s->array)
	{
		free(s->array);//一定要释放申请的内存
		s->array = NULL;//且要置空，否则时悬空指针 即释放了内存，但是还是指向的之前指向的那个地址
		s->size = 0;
		//s->capacity = 0;
	}
}

/** Initialize your data structure here. */

MyQueue* myQueueCreate() {
    MyQueue* obj=(MyQueue*)malloc(sizeof(MyQueue));
    StackInit(&(obj->s1));
    StackInit(&(obj->s2));
    return obj;
}

/** Push element x to the back of queue. */
void myQueuePush(MyQueue* obj, int x) {
    if(stackIsempty(&obj->s1)==0)
    {
        stackpush(&obj->s1,x);
    }
    else
    {
        stackpush(&obj->s2,x);
    }
    
}

/** Removes the element from in front of queue and returns that element. */
int myQueuePop(MyQueue* obj) {
   if(stackIsempty(&obj->s1)==0)//有数据的栈 到数据 到另一个空栈里，留一个栈顶的作队首并保存输出，再pop，剩下的数据继续再倒回去一开始所在的那个栈
   {
       while(stackSize(&obj->s1)>0)
       {
           stackpush(&obj->s2,stacktop(&obj->s1));
           stackpop(&obj->s1);
       }
       int ret=stacktop(&obj->s2);
       stackpop(&obj->s2);
       while(stackSize(&obj->s2)>0)
       {
           stackpush(&obj->s1,stacktop(&obj->s2));
           stackpop(&obj->s2);
       }
       return ret;
   }
   else
   {
        while(stackSize(&obj->s2)>0)
        {
            stackpush(&obj->s1,stacktop(&obj->s2));
            stackpop(&obj->s2);
        }
        int ret=stacktop(&obj->s1);
        stackpop(&obj->s1);
        while(stackSize(&obj->s1)>0)
       {
           stackpush(&obj->s2,stacktop(&obj->s1));
           stackpop(&obj->s1);
       }
        return ret;
   }
}

/** Get the front element. */
int myQueuePeek(MyQueue* obj) {
    if(stackIsempty(&obj->s1)==0)
    {
        return (&obj->s1)->array[0];
    }
    else
        return (&obj->s2)->array[0];
}

/** Returns whether the queue is empty. */
bool myQueueEmpty(MyQueue* obj) {
    if(stackIsempty(&obj->s1)==1 &&stackIsempty(&obj->s2)==1)
    {
        return true;
    }
    return false;
}

void myQueueFree(MyQueue* obj) {
    stackDestory(&obj->s1);
    stackDestory(&obj->s2);
    free(obj);
}

/**
 * Your MyQueue struct will be instantiated and called as such:
 * MyQueue* obj = myQueueCreate();
 * myQueuePush(obj, x);
 
 * int param_2 = myQueuePop(obj);
 
 * int param_3 = myQueuePeek(obj);
 
 * bool param_4 = myQueueEmpty(obj);
 
 * myQueueFree(obj);
*/