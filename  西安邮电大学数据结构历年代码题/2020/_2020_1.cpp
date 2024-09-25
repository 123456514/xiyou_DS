// 已知顺序表l中的数据元素是整数类型，编写算法删除顺序表中值最小的数据元素。
#include<iostream>
using namespace std;
#define maxsize  100
typedef struct{
    int data[maxsize]={5,4,8,6,10};
    int length=5;
}SeqList;
// 最小值默认为顺序表中的第一个元素，并且使用一个标志位记录最小的一个元素的下标位置
void delete_min(SeqList &s)
{
    int min=s.data[0];
    int index=0;
    for(int i=1;i<s.length;i++){
        if(min>s.data[i]){
            min=s.data[i];
            index=i;
        }
    }
    for(int j=index;j<s.length-1;j++){
        s.data[j]=s.data[j+1];
    }
    s.length--;
}
void print(SeqList &s)
{
    for(int i=0;i<s.length;i++){
        cout<<s.data[i]<<" ";
    }
    cout<<endl;
}
int main(){
    SeqList l;
    print(l);
    delete_min(l);
    print(l);
    return 0;
}