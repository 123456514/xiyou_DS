// ���ջ�洢�ṹ�Ķ��壬��дʵ�� ��ջ�ͳ�ջ�ĺ���
#include<iostream>
using namespace std;
#define Max 5
typedef struct {
    int nums[Max];
    int top;
}seqStack;
void initial(seqStack &s){
    s.top = -1; // ��ʼ����ջΪ�յ�ʱ��ջ��ָ���Ϊ-1
}
bool is_full(seqStack &s){ // �ж�ջ�Ƿ���
    if(s.top == Max-1){
        cout << "ջ����";
        return true;
    }
    return false;
}
bool is_empty_s(seqStack &s){
    if(s.top == -1){
        cout << "ջ��";
        return true;
    }
    return false;
}
// ��ջ
bool Push(seqStack &s,int x){
    if(!is_full(s)){
        s.nums[++s.top]=x;
        return true;
    }else{
        return false;
    }
}
// ��ջ
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
