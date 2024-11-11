// 完成栈存储结构的定义，编写实现 入栈和出栈的函数
#include<iostream>
using namespace std;
#define Max 5
typedef struct {
    int nums[Max];
    int top;
}seqStack;
void initial(seqStack &s){
    s.top = -1; // 初始化，栈为空的时候，栈顶指针记为-1
}
bool is_full(seqStack &s){ // 判断栈是否满
    if(s.top == Max-1){
        cout << "栈满了";
        return true;
    }
    return false;
}
bool is_empty_s(seqStack &s){
    if(s.top == -1){
        cout << "栈空";
        return true;
    }
    return false;
}
// 入栈
bool Push(seqStack &s,int x){
    if(!is_full(s)){
        s.nums[++s.top]=x;
        return true;
    }else{
        return false;
    }
}
// 出栈
bool Pop(seqStack &s,int &x){
    if(!is_empty_s(s)){
        x=s.nums[s.top];
        s.top--;
        return true;
    }else{
        return false;
    }
}

int main(){
    seqStack s;
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
}
