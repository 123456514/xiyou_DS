// 从有序表中删除值在给定s与t之间，要求s<t的所有元素，若s,t不合理或顺序表为空，则显示出错信息并退出运行
// 王道 顺序表 一样的题
#include<iostream>
using namespace std;
#define Max 50
struct Sqlist{
    int a[Max]={1,2,3,3,4,5,6,7,7,7,8,9};
    int length=12;
};
void deleteList(Sqlist &l,int s,int t){
    if(l.a[l.length-1]<s||s>=t){
        cout<<"给定区间不合法"<<endl;
        return;
    }
    int k=0;
    // 如果遍历的元素中有在区域之间的，那么就直接k++,不在数组中赋值,遇到了在区域之外的那么就i-k
    // 这里的i-k表示的是删除区域元素之后，元素所在的位置
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