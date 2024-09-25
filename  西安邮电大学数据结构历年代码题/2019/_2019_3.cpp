#include<iostream>
using namespace std;
#define MaxSize 10
typedef struct {
    int data[MaxSize];
    int rear,count;
}SeQueue;
// 初始化
void initial(SeQueue &Q){
    Q.count=0;
    Q.rear=MaxSize-1;
}
// 入队 这里牺牲了一个位置
bool enterQueue(SeQueue &Q,int x){
    // 判断队列是否满
    int front=(Q.rear+1+MaxSize-Q.count)%MaxSize;
    if((Q.rear+2)%MaxSize==front) {
        cout<<"队列满了"<<endl;
        return false;
    }
    Q.rear=(Q.rear+1)%MaxSize;
    Q.data[Q.rear]=x;
    Q.count++;
    return true;
}
// 出队
bool pollQueue(SeQueue &Q,int &x){
    // 判空
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