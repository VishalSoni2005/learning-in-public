class MyCircularQueue {
  int* arr;
  int front;
  int rear;
  int size;

 public:
  MyCircularQueue(int k) {
    size = k;
    arr = new int[k];
    front = rear = -1;
  }

  bool enQueue(int value) {
    // in enqueue, we move rear pointer imagine real queue

    if (isFull())
      return 0;

    if (isEmpty())
      front = rear = 0;
    else
      rear = (rear + 1) % size;

    arr[rear] = value;
    return 1;
  }

  bool deQueue() {
    // move front pointer
    if (isEmpty())
      return 0;

    else if (front == rear) {
      front = rear = -1;

    }

    else
      front = (front + 1) % size;
    return 1;
  }
  int Front() {
    if (isEmpty())
      return -1;
    return arr[front];
  }

  int Rear() {
    if (isEmpty())
      return -1;
    return arr[rear];
  }
  bool isEmpty() { return front == -1; }

  bool isFull() {
    return ((rear + 1) % size == front) or
           (front == 0 and rear == size - 1);
  }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */