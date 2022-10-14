 #define newcapacity 1000
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <assert.h>

typedef int StackDataType;
typedef struct stack
{
    StackDataType* data;
    int top;
    int capacity;
}ST;
typedef struct 
{
    ST Push;//始终把进栈元素放入Push
    ST Pop;//出栈从Pop出
} CQueue;


void StackInit(ST* ps);
void StackDestroy(ST* ps);
void StackPush(ST* ps,StackDataType x);
void StackPop(ST* ps);
StackDataType StackTop(ST* ps);
int StackSize(ST* ps);
bool StackEmpty(ST* ps);
/********************栈函数****************************/
void StackInit(ST* ps)
{
    assert(ps);
    ps->data = (int*)malloc(sizeof(int)*newcapacity);
    ps->capacity = 1000;
    ps->top = 0;
}
void StackDestroy(ST* ps)
{
    assert(ps);
    free(ps->data);
    ps->data = NULL;
    ps->capacity = 0;
    ps->top = 0;
}
void StackPush(ST* ps,StackDataType x)
{
    assert(ps);

    ps->data[ps->top] = x;
    ps->top++;
}
void StackPop(ST* ps)
{
    assert(ps);
    assert(!StackEmpty(ps));

    ps->top--;
}
StackDataType StackTop(ST* ps)
{
    assert(ps);
    assert(!StackEmpty(ps));

    return ps->data[ps->top-1];
}
int StackSize(ST* ps)
{
    assert(ps);

    return ps->top;
}
bool StackEmpty(ST* ps)
{
    return ps->top == 0;
}
/*****************本题**********************/
bool cQueueEmpty(CQueue* q)
{
    return (StackEmpty(&q->Push) && StackEmpty(&q->Pop));
}

CQueue* cQueueCreate()
{
    CQueue* q = (CQueue*)malloc(sizeof(CQueue));
    StackInit(&q->Push);
    StackInit(&q->Pop);

    return q;
}

void cQueueAppendTail(CQueue* obj, int value) {
    StackPush(&obj->Push,value);
}

int cQueueDeleteHead(CQueue* obj) {
    if(cQueueEmpty(obj)) return -1;
    //obj的Pop为空时，将obj->Push中的元素全都进栈带obj->Pop
    //从而实现先进先出
    if(StackEmpty(&obj->Pop))
    {
        while(!StackEmpty(&obj->Push))
        {
            StackPush(&obj->Pop,StackTop(&obj->Push));
            StackPop(&obj->Push);
        }
    }
    int ret = StackTop(&obj->Pop);
    StackPop(&obj->Pop);
    
    return ret;
}

void cQueueFree(CQueue* obj) {
    StackDestroy(&obj->Push);
    StackDestroy(&obj->Pop);
    free(obj);
    obj = NULL;
}

/**
 * Your CQueue struct will be instantiated and called as such:
 * CQueue* obj = cQueueCreate();
 * cQueueAppendTail(obj, value);
 
 * int param_2 = cQueueDeleteHead(obj);
 
 * cQueueFree(obj);
*/
