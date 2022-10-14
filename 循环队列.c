/******************本题************************/
typedef struct 
{
    int* data;
    int front;
    int tail;
    int k;
} MyCircularQueue;

bool myCircularQueueIsEmpty(MyCircularQueue* obj);
bool myCircularQueueIsFull(MyCircularQueue* obj) ;

MyCircularQueue* myCircularQueueCreate(int k) 
{
    MyCircularQueue* cq = (MyCircularQueue*)malloc(sizeof(MyCircularQueue));
    cq->data = (int*)malloc(sizeof(int)*(k+1));
    cq->front = 0;
    cq->tail = 0;
    cq->k = k;

    return cq;
}

bool myCircularQueueEnQueue(MyCircularQueue* obj, int value) 
{
    if(myCircularQueueIsFull(obj)) 
        return false;

    obj->data[obj->tail] = value;
    obj->tail++;
    obj->tail %= obj->k + 1;//取模防止越界访问
    return true;
}

bool myCircularQueueDeQueue(MyCircularQueue* obj) 
{
    if(myCircularQueueIsEmpty(obj)) 
        return false;
    
    obj->front++;
    obj->front %= obj->k + 1;//取模防止越界访问
    return true;
}

int myCircularQueueFront(MyCircularQueue* obj) 
{
    if(myCircularQueueIsEmpty(obj)) //调用时总是忘写实参，导致一直在此终止程序
        return -1;

    return obj->data[obj->front];
}

int myCircularQueueRear(MyCircularQueue* obj) 
{
    if(myCircularQueueIsEmpty(obj)) //调用时总是忘写实参，导致一直在此终止程序
        return -1;

    if(obj->tail == 0)//防止tail在0位置的时候
        return obj->data[obj->k];
    else
        return obj->data[obj->tail - 1];
}

bool myCircularQueueIsEmpty(MyCircularQueue* obj) 
{
    return obj->front == obj->tail;
}

bool myCircularQueueIsFull(MyCircularQueue* obj) 
{
    if((obj->tail + 1)%(obj->k + 1) == obj->front)
        return true;
    else
        return false;
}

void myCircularQueueFree(MyCircularQueue* obj) 
{
    free(obj->data);
    obj->data = NULL;
    free(obj);
    obj = NULL;
}

/**
 * Your MyCircularQueue struct will be instantiated and called as such:
 * MyCircularQueue* obj = myCircularQueueCreate(k);
 * bool param_1 = myCircularQueueEnQueue(obj, value);
 
 * bool param_2 = myCircularQueueDeQueue(obj);
 
 * int param_3 = myCircularQueueFront(obj);
 
 * int param_4 = myCircularQueueRear(obj);
 
 * bool param_5 = myCircularQueueIsEmpty(obj);
 
 * bool param_6 = myCircularQueueIsFull(obj);
 
 * myCircularQueueFree(obj);
*/
