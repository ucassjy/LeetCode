typedef struct {
    int* qarray;
	int front;
	int rear;
	int length;
} MyCircularQueue;

/** Initialize your data structure here. Set the size of the queue to be k. */
MyCircularQueue* myCircularQueueCreate(int k) {
    MyCircularQueue* q = (MyCircularQueue*)malloc(sizeof(MyCircularQueue));
	q->qarray = (int*)malloc((k+1) * sizeof(int));
	q->front = q->rear = 0;
	q->length = k + 1;
	return q;
}

/** Insert an element into the circular queue. Return true if the operation is successful. */
bool myCircularQueueEnQueue(MyCircularQueue* obj, int value) {
    if(!obj || (obj->rear + 1) % obj->length == obj->front)  return false;
	obj->qarray[obj->rear] = value;
	obj->rear++;
	obj->rear %= obj->length;
	return true;
}

/** Delete an element from the circular queue. Return true if the operation is successful. */
bool myCircularQueueDeQueue(MyCircularQueue* obj) {
    if(!obj || obj->front == obj->rear)  return false;
	obj->front++;
	obj->front %= obj->length;
	return true;
}

/** Get the front item from the queue. */
int myCircularQueueFront(MyCircularQueue* obj) {
    if(!obj || obj->front == obj->rear) return -1;
	return obj->qarray[obj->front];
}

/** Get the last item from the queue. */
int myCircularQueueRear(MyCircularQueue* obj) {
    if(!obj || obj->front == obj->rear) return -1;
	return obj->qarray[(obj->rear-1+obj->length) % obj->length];
}

/** Checks whether the circular queue is empty or not. */
bool myCircularQueueIsEmpty(MyCircularQueue* obj) {
    return !obj || obj->front == obj->rear;
}

/** Checks whether the circular queue is full or not. */
bool myCircularQueueIsFull(MyCircularQueue* obj) {
    return !obj || (obj->rear + 1) % obj->length == obj->front;
}

void myCircularQueueFree(MyCircularQueue* obj) {
    if(!obj) free(obj);
}

/**
 * Your MyCircularQueue struct will be instantiated and called as such:
 * struct MyCircularQueue* obj = myCircularQueueCreate(k);
 * bool param_1 = myCircularQueueEnQueue(obj, value);
 * bool param_2 = myCircularQueueDeQueue(obj);
 * int param_3 = myCircularQueueFront(obj);
 * int param_4 = myCircularQueueRear(obj);
 * bool param_5 = myCircularQueueIsEmpty(obj);
 * bool param_6 = myCircularQueueIsFull(obj);
 * myCircularQueueFree(obj);
 */