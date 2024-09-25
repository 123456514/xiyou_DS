// 设计一个算法，长度为n的顺序表，编写一个时间复杂度On，空间复杂度O1的算法，该算法实现删除线性表中所有值为x的元素
#include<iostream>
using namespace std;
#define Max 50
struct Sqlist{
    int a[Max]={3,4,5,6,7,2,4,6,4,6,4,4};
    int length=12;
};
void deleteList(Sqlist &l,int x){
    int k=0; // 这里的k表示的是出现在线性表中的x的个数，这里使用线性表的长度 - 出现的x的个数 等于新的线性表中的元素的所在位置，最后让在原有的长度上减去k，得到的就是删除所有x的线性表
    for(int i=0;i<l.length;i++){
        if(l.a[i]==x){
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
int main()
{
    Sqlist l;
    disp(l);
    deleteList(l,4);
    disp(l);
    return 0;
}