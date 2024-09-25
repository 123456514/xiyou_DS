// 从有序表中删除值在给定s与t之间，要求s<t的所有元素，若s,t不合理或顺序表为空，则显示出错信息并退出运行
#include<iostream>
using namespace std;
#define Max 50
struct Sqlist{
    int a[Max]={1,2,3,3,4,5,6,7,7,7,8,9};
    int length=12;
};
void deleteList(Sqlist &l,int s,int t){
    // 1. 给定区间不合法    顺序表中的最后一个元素小于区间第一个元素
    // 区间中只有一部分在顺序表中，是否要删除部分的元素
    if(l.a[l.length-1]<s||s>=t){
        cout<<"给定区间不合法"<<endl;
        return;
    }
    int k=0;
    for(int i=0;i<l.length;i++){
        if(l.a[i]>=s&&l.a[i]<=t){
            k++;
        }else{
            l.a[i-k]=l.a[i];
        }
    }
    l.length=l.length-k;
}
void disp(Sqlist &l){
    for(int i=0;i<l.length;i++){
        cout<<l.a[i]<<" ";
    }
    cout<<endl;
}
int main(){
    Sqlist l;
    disp(l);
    deleteList(l,2,6);
    disp(l);
}