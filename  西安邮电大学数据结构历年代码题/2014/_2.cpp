// ������һά����elem[0,m-1]����ѭ�����е�Ԫ�أ�ͬʱ�����rear��quelen�ֱ�ָʾѭ�������ж�βԪ�ص�λ�úͶ���������Ԫ�صĸ���
// �ӿգ���������ӣ�����
#include<iostream>
using namespace std;
# define MAXSIZE 10
typedef struct seQueue {
    int data[MAXSIZE];  // �洢����Ԫ�ص�����
    int rear;           // ��βԪ�ص�λ��
    int length;         // ����Ԫ�صĸ���
} SeQueue;
void initial(SeQueue &queue){
    queue.rear=MAXSIZE-1;
    queue.length=0;
}
bool enter_queue(SeQueue &seQueue,int x){
    // ����
    if(seQueue.length == MAXSIZE){
        cout<<"����";
        return false;
    }
    seQueue.rear=(seQueue.rear+1)%MAXSIZE;
    seQueue.data[seQueue.rear]=x;
    seQueue.length++;
    return true;
}
bool poll_queue(SeQueue &seQueue,int &x){
    // �п�
    if(seQueue.length == 0){
        cout<<"�ӿ�";
        return false;
    }
    int front=(seQueue.rear+1-seQueue.length+MAXSIZE)%MAXSIZE;
    x=seQueue.data[front];
    seQueue.length--;
    return false;
}
int main(){
    SeQueue q;
    initial(q);
    enter_queue(q,1);
    enter_queue(q,2);
    enter_queue(q,3);
    enter_queue(q,4);
    enter_queue(q,5);
    enter_queue(q,6);
    enter_queue(q,7);
    enter_queue(q,8);
    enter_queue(q,9);
    enter_queue(q,10);
    enter_queue(q,10);
    int x=0;
    poll_queue(q,x);
    cout << x;
    poll_queue(q,x);
    cout << x;
    poll_queue(q,x);
    cout << x;
    poll_queue(q,x);
    cout << x;
    poll_queue(q,x);
    cout << x;
    poll_queue(q,x);
    cout << x;
    poll_queue(q,x);
    cout << x;
    poll_queue(q,x);
    cout << x;
    poll_queue(q,x);
    cout << x;
    poll_queue(q,x);
    cout << x;
    return 0;
}