#define ElementType int 
#define MaxSize 1024
typedef struct {
    int front;
    int rear;
    int size;
    ElementType *array;
} MyStack;

/** Initialize your data structure here. */

MyStack* myStackCreate() {
    MyStack *a;
    a = malloc(sizeof(MyStack));
    a->array = malloc(sizeof(ElementType)*MaxSize);
    a->front = 0;
    a->rear  = 0;
    a->size  = 0;
    return a;
}

/** Push element x onto stack. */
void myStackPush(MyStack* obj, int x) {
    obj->size++;
    obj->rear++;
    obj->array[obj->rear] = x;
}

/** Removes the element on top of the stack and returns that element. */
int myStackPop(MyStack* obj) {
    int last = obj->rear;
    int num  = 0; 
    num = obj->array[last];
    obj->rear = last - 1;
    obj->size--;
    return num;
}

/** Get the top element. */
int myStackTop(MyStack* obj) {
    return obj->array[obj->rear];
}

/** Returns whether the stack is empty. */
bool myStackEmpty(MyStack* obj) {
    if(obj->size == 0)
        return true;
    else
        return false;
}

void myStackFree(MyStack* obj) {
    free(obj);
}