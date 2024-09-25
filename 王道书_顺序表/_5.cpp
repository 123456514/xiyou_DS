// 在顺序表中删除s到t之间的元素，注意此时是无需的，但是上一个题的方法也可以在这里使用
#include<iostream>
using namespace std;
#define Max 50
struct Sqlist{
    int a[Max]={4,1,2,5,0,0,3};
    int length=7;
};
bool deleteList(Sqlist &l,int s,int t){
    // 1. 给定区间不合法    顺序表中的最后一个元素小于区间第一个元素
    // 区间中只有一部分在顺序表中，是否要删除部分的元素
    if(l.length==0||s>=t){
        cout<<"给定区间不合法"<<endl;
        return false;
    }
    //确保在顺序表中有大于s的元素
    bool flag=false;
    for(int i=0;i<l.length;i++){
        if(l.a[i]>=s){
            flag= true;
            break;
        }
    }
    if(!flag) return false;
    int k=0;
    for(int i=0;i<l.length;i++){
        if(l.a[i]>=s&&l.a[i]<=t){
            k++;
        }else{
            l.a[i-k]=l.a[i];
        }
    }
    l.length=l.length-k;
    return true;
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
    deleteList(l,3,5);
    disp(l);
}