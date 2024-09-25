// 假设一维数组elem存储栈s的元素，并设top记录栈顶元素的位置，编写入栈和出栈算法
// 入栈函数 push(s,x)
// 出栈函数 pop(s,x)
#include<iostream>
using namespace std;
#define MaxSize 10
#define M 15
typedef struct{
    int elem[M];
    int top;
}SeqStack;
void initial(SeqStack &s){
    s.top=-1;
}
//入栈
bool Push(SeqStack &s,int x){
    if(s.top==MaxSize-1){
        cout<<"栈满了";
        return false;
    }
    s.elem[++s.top]=x;
    return true;
}
//出栈
bool Pop(SeqStack &s,int &x){
    if(s.top==-1){
        cout<<"栈为空";
        return false;
    }
    x=s.elem[s.top];
    s.top--;
    return true;
}
int main(){
    SeqStack s;
    initial(s);
    int x;
    Push(s,1);
    Pop(s,x);
    cout<<x<<endl;
    Push(s,2);
    Pop(s,x);
    cout<<x<<endl;
    Push(s,3);
    Push(s,4);
    Push(s,5);
    Push(s,1);
    Push(s,1);
    Push(s,1);
    Push(s,1);
    Push(s,1);
    Push(s,1);
    return 0;
}





