// 在顺序表中，查找值为key的元素，若找到则输出他的位置，否则输出0
#include<iostream>
using namespace std;
#define MaxSize 10
typedef struct{
    int data[MaxSize]={1,2,3,4,5,6,7,8,9,10};
    int length;
}SeqList;

int getIndex(SeqList &l,int key){
    int len=sizeof(l.data)/sizeof(int);
    for(int i=0;i<len;i++){
        if(l.data[i]==key){
            return i+1;
        }
    }
    return 0;
}
int main(){
    SeqList l;
    cout<<getIndex(l,11);
    return 0;
}