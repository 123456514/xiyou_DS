// 将两个有序顺序表进行合并，由函数返回结果顺序表
#include<iostream>
using namespace std;
#define Max 10
struct Sqlist{
    int a[Max];
    int length;
};
bool combine(Sqlist &l1,Sqlist &l2,Sqlist &l3){
    if(l3.length<l1.length+l2.length) return false;
    int i=0,j=0,k=0;
    while(i<l1.length&&j<l2.length){
        if(l1.a[i]<=l2.a[j]) l3.a[k++]=l1.a[i++];
        else l3.a[k++]=l2.a[j++];
    }
    while(i<l1.length){
        l3.a[k++]=l1.a[i++];
    }
    while(j<l2.length){
        l3.a[k++]=l2.a[j++];
    }
    l3.length=l1.length+l2.length;
    return true;
}
void disp(Sqlist &l){
    for(int i=0;i<l.length;i++){
        cout<<l.a[i]<<" ";
    }
    cout<<endl;
}
int main(){
    Sqlist a={{1,2,3,4},4};
    Sqlist b={{7,8,9},3};
    Sqlist c;
    c.length=20;
    if(!combine(a,b,c)) cout<<"合并错误"<<endl;
    else{
        for(int i=0;i<c.length;i++){
            cout<<c.a[i]<<" ";
        }
        cout<<endl;
    }
    return 0;
}