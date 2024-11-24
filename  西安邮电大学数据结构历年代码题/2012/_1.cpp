// 假设循环队列中设置rear和length两个变量存储队尾元素的位置和队中元素的个数，且队列长度为MAXSIZE，试给循环队列的定义，并分别写出入队和出队的实际算法

#include <stdio.h>
#define MAXSIZE 3  // 定义队列的最大长度，可按需调整
// 循环队列总结：
// 在一般的循环队列中，是需要空出一个位置，用于判断队列是否为空，或者为满
// 判满条件 if((rear + 1) % maxsize == front)
// 判空条件 if(front == rear)
// 在这种条件下得到队列中的元素个数 count = (rear - front + maxsize) % maxsize
// 定义循环队列结构体

// 已知题目中给出 count 和 rear那么 这个队列中就不能有空余的位
// 此时的 判空判满条件都很简单 分别等于 count 和 0 即可
// 但是在出队的时候一定要注意 根据 count MAXSIZE 和 rear 需要计算出 front

// 那么此时的 front = (rear+1-count+MAXSIZE)MAXSIZE
typedef struct CircularQueue {
    int data[MAXSIZE];  // 存储队列元素的数组
    int rear;           // 队尾元素的位置
    int length;         // 队中元素的个数
} CircularQueue;

// 初始化循环队列
void initQueue(CircularQueue *queue) {
    queue->rear = MAXSIZE-1;
    queue->length = 0;
}
// 入队函数
int enQueue(CircularQueue *queue, int element) {
    if (queue->length == MAXSIZE) {
        return 0;
    }
    queue->rear = (queue->rear+1)%MAXSIZE;
    queue->data[queue->rear] = element;
    queue->length++;
    return 1;
}
// 出队函数
int deQueue(CircularQueue *queue, int &data) {
   if(queue->length == 0){
       return 0;
   }
   int pos = (queue->rear+1-queue->length+MAXSIZE)%MAXSIZE;
   data = queue->data[pos];
   queue->length--;
   return 1;
}
int main() {
    CircularQueue myQueue;
    initQueue(&myQueue);
    // 入队测试
    for (int i = 1; i <= 5; i++) {
        if (enQueue(&myQueue, i)) {
            printf("%d入队成功\n", i);
        }
        else {
            printf("队列已满，无法入队\n");
        }
    }
    // 出队测试
    int outElement;
    for (int i = 1; i <= 5; i++) {
        if (deQueue(&myQueue, outElement)) {
            printf("%d出队成功\n", outElement);
        }
        else {
            printf("队列已空，无法出队\n");
        }
    }
    return 0;
}