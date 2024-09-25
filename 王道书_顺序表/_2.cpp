// 设计一个高效的算法，将顺序表l的所有元素逆置，要求算法的空间复杂度O1
#include<iostream>
using namespace std;
#define Max 50
struct Sqlist{
    int a[Max]={1,2,3,4,5,6,7};
    int length=7;
};
// 左右指针
void reverse(Sqlist &l){
    int left=0,right=l.length-1;
    while(left<=right){
        int temp=l.a[left];
        l.a[left]=l.a[right];
        l.a[right]=temp;
        left++;
        right--;
    }
}
// 数学计算
void reverse2(Sqlist &l){
    for(int i=0;i<l.length/2;i++){
        int temp=l.a[i];
        l.a[i]=l.a[l.length-i-1];
        l.a[l.length-i-1]=temp;
    }
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
    reverse2(l);
    disp(l);
    return 0;
}