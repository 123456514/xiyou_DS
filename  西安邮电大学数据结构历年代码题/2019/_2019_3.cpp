#include<iostream>
using namespace std;
#define MaxSize 10
typedef struct {
    int data[MaxSize];
    int rear,count;
}SeQueue;
// ��ʼ��
void initial(SeQueue &Q){
    Q.count=0;
    Q.rear=MaxSize-1;
}
// ��� ����������һ��λ��
bool enterQueue(SeQueue &Q,int x){
    // �ж϶����Ƿ���
    int front=(Q.rear+1+MaxSize-Q.count)%MaxSize;
    if((Q.rear+2)%MaxSize==front) {
        cout<<"��������"<<endl;
        return false;
    }
    Q.rear=(Q.rear+1)%MaxSize;
    Q.data[Q.rear]=x;
    Q.count++;
    return true;
}
// ����
bool pollQueue(SeQueue &Q,int &x){
    // �п�
    int front=(Q.rear+1+MaxSize-Q.count)%MaxSize;
    if((Q.rear+1)%MaxSize==front) return false;
    x=Q.data[front];
    Q.count--;
    return true;
}
int main()
{
    SeQueue Q;
    initial(Q);
    enterQueue(Q,1);
    enterQueue(Q,2);
    enterQueue(Q,3);
    enterQueue(Q,4);
    enterQueue(Q,5);
    enterQueue(Q,6);
    enterQueue(Q,7);
    enterQueue(Q,8);
    enterQueue(Q,9);
}