// 从有序顺序表中删除所有重复元素，使表中所有元素值均不同
#include<iostream>
using namespace std;
#define Max 10
struct Sqlist{
    int a[Max]={1,1,2,2,3,3,4,4,4,5};
    int length=10;
};
void deleteList(Sqlist &l){
    // 算法思想：这里的j表示的是新的线性表中的无重复元素个数，这里的i指针表示的是比较原顺序表中的元素重复
    // 如果前一个元素不等于遍历的这个元素，那么就在j的位置上把遍历的这个位置上的元素赋值，并且指针j++ j指针指向下一个不重复的元素
    int j=1;
    for(int i=1;i<l.length;i++){
        if(l.a[i]!=l.a[i-1]){
            l.a[j]=l.a[i];
            j++;
        }
    }
    l.length=j;
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
    deleteList(l);
    disp(l);
    return 0;
}
