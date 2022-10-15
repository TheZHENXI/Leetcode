
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <assert.h>

typedef int QueueDataType;
typedef struct QueueNode
{
    struct QueueNode* next;
    QueueDataType data;
}QueueNode;
typedef struct Queue
{
    struct QueueNode* head;
    struct QueueNode* tail;
}Queue;
void QueueInit(Queue* ps);
void QueueDestroy(Queue* ps);
void QueuePush(Queue* ps,QueueDataType x);
void QueuePop(Queue* ps);
QueueDataType QueueFront(Queue* pq);
QueueDataType QueueBuck(Queue* pq);
int QueueSize(Queue* ps);
bool QueueEmpty(Queue* ps);
/***********************************************************/
void QueueInit(Queue* pq)
{
    assert(pq);
    pq->head = NULL;
    pq->tail = NULL;
}
void QueueDestroy(Queue* pq)
{
    assert(pq);
    QueueNode* cur = pq->head;
    while(cur)
    {
        QueueNode* tmp = cur->next;
        free(cur);
        cur = tmp;
    }
    pq->head = NULL;
    pq->tail = NULL;
}
void QueuePush(Queue* pq,QueueDataType x)
{
    assert(pq);
    QueueNode* newnode = (QueueNode*)malloc(sizeof(QueueNode));
    newnode->next = NULL;
    newnode->data = x;
    if(pq->head == NULL)
    {
        pq->head = pq->tail = newnode;
    }
    else
    {
        pq->tail->next = newnode;
        pq->tail = newnode;
    }
}
void QueuePop(Queue* pq)
{
    assert(pq);
    assert(!QueueEmpty(pq));

    QueueNode* tmp = pq->head->next;
    free(pq->head);
    pq->head = tmp;
    if(pq->head == NULL)//防止整个队列已删完，但tail未置空，成为野指针
        pq->tail = NULL;
}
QueueDataType QueueFront(Queue* pq)
{
    assert(pq);
    assert(!QueueEmpty(pq));
    return pq->head->data;
}
QueueDataType QueueBuck(Queue* pq)
{
    assert(pq);
    assert(!QueueEmpty(pq));
    return pq->tail->data;
}
int QueueSize(Queue* pq)
{
    int n = 0;
    QueueNode* cur = pq->head;
    while(cur)
    {
        n++;
        cur = cur->next;
    }
    return n;
}
bool QueueEmpty(Queue* pq)
{
    if(pq->head == NULL)
        return true;
    else
        return false;
}

/********************本题****************************/
typedef struct 
{
    Queue q1;
    Queue q2;
} MyStack;


MyStack* myStackCreate() 
{
    MyStack* obj = (MyStack*)malloc(sizeof(MyStack));
    QueueInit(&obj->q1);
    QueueInit(&obj->q2);

    return obj;
}

void myStackPush(MyStack* obj, int x) 
{
    if(QueueEmpty(&obj->q1))
    {
        QueuePush(&obj->q2,x);
    }
    else
    {
        QueuePush(&obj->q1,x);
    }
}

int myStackPop(MyStack* obj) 
{
    Queue* NoneEm = &obj->q1;
    Queue* Empty = &obj->q2;
    if(QueueEmpty(&obj->q1))
    {
        NoneEm = &obj->q2;
        Empty = &obj->q1;
    }
    while(QueueSize(NoneEm) > 1)
    {
        QueuePush(Empty,QueueFront(NoneEm));
        QueuePop(NoneEm);
    }
    int ret = QueueBuck(NoneEm);
    QueuePop(NoneEm);

    return ret;
}

int myStackTop(MyStack* obj) 
{
    Queue* NoneEm = &obj->q1;
    Queue* Empty = &obj->q2;
    if(QueueEmpty(&obj->q1))
    {
        NoneEm = &obj->q2;
        Empty = &obj->q1;
    }

    return QueueBuck(NoneEm);
}

bool myStackEmpty(MyStack* obj) 
{
    return QueueEmpty(&obj->q1) && QueueEmpty(&obj->q2);
}

void myStackFree(MyStack* obj) 
{
    QueueDestroy(&obj->q1);
    QueueDestroy(&obj->q2);
    free(obj);
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

作者：小呀小菜鸟
链接：https://leetcode.cn/problems/implement-stack-using-queues/solutions/1893962/by-zhang_zhenxi-a8m3/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
