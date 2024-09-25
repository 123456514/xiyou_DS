// ����ѭ������������front rear �� count �ֱ�ָʾ��ͷԪ�ص�λ�ã���βԪ�ص�λ�úͶ���Ԫ�صĸ���
// ��д�㷨��ʵ�ֻ��ڴ˽ṹ��ѭ�����еĳ�ʼ������ӣ����Ӳ�����
#include<iostream>
using namespace std;
#define MaxSize 10
typedef struct{
    int data[MaxSize];
    int front,rear,count;
}SeQueue;
void initial(SeQueue &Q){
    Q.front=0;
    Q.rear=MaxSize-1;
    Q.count=0;
}
bool enterQueue(SeQueue &Q,int x){
    if((Q.rear+2)%MaxSize==Q.front||Q.count==MaxSize) {
        cout<<"��������"<<endl;
        return false;
    }
    Q.rear=(Q.rear+1)%MaxSize;
    Q.data[Q.rear]=x;
    Q.count++;
    return true;
}
bool pollQueue(SeQueue &Q,int &x){
    if((Q.rear+1)%MaxSize==Q.front||Q.count==0){
        cout<<"����Ϊ��"<<endl;
        return false;
    } 
    x=Q.data[Q.front];
    Q.front=(Q.front+1)%MaxSize;
    Q.count--;
    return false;
}
int main(){
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
    int x=0;
    pollQueue(Q,x);
    cout<<x<<" ";
    pollQueue(Q,x);
    cout<<x<<" ";
    pollQueue(Q,x);
    cout<<x<<" ";
    pollQueue(Q,x);
    cout<<x<<" ";
    pollQueue(Q,x);
    cout<<x<<" ";
    pollQueue(Q,x);
    cout<<x<<" ";
    pollQueue(Q,x);
    cout<<x<<" ";
    pollQueue(Q,x);
    cout<<x<<" ";
    pollQueue(Q,x);
    cout<<x<<" ";
}