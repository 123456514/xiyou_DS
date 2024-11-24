// ����ѭ������������rear��length���������洢��βԪ�ص�λ�úͶ���Ԫ�صĸ������Ҷ��г���ΪMAXSIZE���Ը�ѭ�����еĶ��壬���ֱ�д����Ӻͳ��ӵ�ʵ���㷨

#include <stdio.h>
#define MAXSIZE 3  // ������е���󳤶ȣ��ɰ������
// ѭ�������ܽ᣺
// ��һ���ѭ�������У�����Ҫ�ճ�һ��λ�ã������ж϶����Ƿ�Ϊ�գ�����Ϊ��
// �������� if((rear + 1) % maxsize == front)
// �п����� if(front == rear)
// �����������µõ������е�Ԫ�ظ��� count = (rear - front + maxsize) % maxsize
// ����ѭ�����нṹ��

// ��֪��Ŀ�и��� count �� rear��ô ��������оͲ����п����λ
// ��ʱ�� �п������������ܼ� �ֱ���� count �� 0 ����
// �����ڳ��ӵ�ʱ��һ��Ҫע�� ���� count MAXSIZE �� rear ��Ҫ����� front

// ��ô��ʱ�� front = (rear+1-count+MAXSIZE)MAXSIZE
typedef struct CircularQueue {
    int data[MAXSIZE];  // �洢����Ԫ�ص�����
    int rear;           // ��βԪ�ص�λ��
    int length;         // ����Ԫ�صĸ���
} CircularQueue;

// ��ʼ��ѭ������
void initQueue(CircularQueue *queue) {
    queue->rear = MAXSIZE-1;
    queue->length = 0;
}
// ��Ӻ���
int enQueue(CircularQueue *queue, int element) {
    if (queue->length == MAXSIZE) {
        return 0;
    }
    queue->rear = (queue->rear+1)%MAXSIZE;
    queue->data[queue->rear] = element;
    queue->length++;
    return 1;
}
// ���Ӻ���
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
    // ��Ӳ���
    for (int i = 1; i <= 5; i++) {
        if (enQueue(&myQueue, i)) {
            printf("%d��ӳɹ�\n", i);
        }
        else {
            printf("�����������޷����\n");
        }
    }
    // ���Ӳ���
    int outElement;
    for (int i = 1; i <= 5; i++) {
        if (deQueue(&myQueue, outElement)) {
            printf("%d���ӳɹ�\n", outElement);
        }
        else {
            printf("�����ѿգ��޷�����\n");
        }
    }
    return 0;
}