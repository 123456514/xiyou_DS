 // 入队，出队count 记录队列中的元素个数，front，rear，要求不损失一个空间
 // 假设以一维数组elem[0,m-1]存贮循环队列的元素，同时设变量rear和quelen分别指示循环队列中队尾元素的位置和队列中所含元素的个数
// 队空，队满，入队，出队
#include<iostream>
 using namespace std;
# define MAXSIZE 10
 typedef struct seQueue {
     int data[MAXSIZE];  // 存储队列元素的数组
     int rear;           // 队尾元素的位置
     int length;         // 队中元素的个数
 } SeQueue;
 void initial(SeQueue &queue){
     queue.rear=MAXSIZE-1;
     queue.length=0;
 }
 bool enter_queue(SeQueue &seQueue,int x){
     // 判满
     if(seQueue.length == MAXSIZE){
         cout<<"队满";
         return false;
     }
     seQueue.rear=(seQueue.rear+1)%MAXSIZE;
     seQueue.data[seQueue.rear]=x;
     seQueue.length++;
     return true;
 }
 bool poll_queue(SeQueue &seQueue,int &x){
     // 判空
     if(seQueue.length == 0){
         cout<<"队空";
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