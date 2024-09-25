// 编写算法，该表a中的元素循环右移k位，要求空间复杂度为01
#include<iostream>
using namespace std;
#define maxsize 10
typedef struct{
    int elem[maxsize]={1,2,3,4,5};
    int length=5;
}SeqList;
void reverse(SeqList &s,int start,int k){
    int left=start,right=k-1;
    while(left<right){
        int temp=s.elem[left];
        s.elem[left]=s.elem[right];
        s.elem[right]=temp;
        left++;
        right--;
    }
}

void right_remove(SeqList &s,int k){
    reverse(s,0,s.length);
    reverse(s,0,2);
    reverse(s,k,s.length);
}
void print(SeqList &s){
    for(int i=0;i<s.length;i++){
        cout<<s.elem[i]<<" ";
    }
    cout<<endl;
}
int main(){
    SeqList s;
    print(s);
    right_remove(s,2);
    print(s);
}