// ����һά����elem�洢ջs��Ԫ�أ�����top��¼ջ��Ԫ�ص�λ�ã���д��ջ�ͳ�ջ�㷨
// ��ջ���� push(s,x)
// ��ջ���� pop(s,x)
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
//��ջ
bool Push(SeqStack &s,int x){
    if(s.top==MaxSize-1){
        cout<<"ջ����";
        return false;
    }
    s.elem[++s.top]=x;
    return true;
}
//��ջ
bool Pop(SeqStack &s,int &x){
    if(s.top==-1){
        cout<<"ջΪ��";
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





