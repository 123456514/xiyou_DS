#include<iostream>
using namespace std;
#define MaxSize 10
typedef struct {
    int data[MaxSize];
    int rear;
    int front;
    int count;
}SeQueue;
// 初始化
void initial(SeQueue &Q){
    Q.front=0;
    Q.rear=MaxSize-1;
    Q.count=0;
}
// 入队
bool enter_queue(SeQueue &Q,int x){
    if((Q.rear+2)%MaxSize==Q.front){
        cout << "队满了"<<endl;
        return false;
    }
    Q.rear=(Q.rear+1)%MaxSize;
    Q.data[Q.rear]=x;
    return true;
}
// 出队
bool poll_queue(SeQueue &Q,int &x){
    if((Q.rear+1) == MaxSize){
        cout << "队为空"<<endl;
        return false;
    }
    x = Q.data[Q.front];
    Q.front = (Q.front+1)%MaxSize;
    return true;
}

// 在这个版本中的定义结构题中只有rear和count
bool enter_queue_2(SeQueue &q,int x){
    if(q.count == MaxSize){
        return false;
    }
    q.rear = (q.rear+1)%MaxSize;
    q.data[q.rear]=x;
    q.count++;
    return true;
}
bool poll_queue_2(SeQueue &q,int &x){
    if(q.count == 0){
        return false;
    }
    int front = (q.rear+1-q.count+MaxSize)%MaxSize;
    x=q.data[front];
    q.count--;
    cout << x <<" ";
    return true;
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
    int x = 0;
   poll_queue_2(q,x);
   poll_queue_2(q,x);
   poll_queue_2(q,x);
   poll_queue_2(q,x);
   poll_queue_2(q,x);
   poll_queue_2(q,x);
    return 0;
}