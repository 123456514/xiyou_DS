// 在一维数组中存在两个线性表，将两个顺序表位置互换
// 算法思想：就是将例如 123 456
// 翻转全部的元素 654321
// 翻转 456123  两次局部翻转
// 翻转成为 456 123
#include<iostream>
using namespace std;
#define Max 10
struct Sqlist{
    int nums[Max]={1,2,3,4,5,6,7};
    int length=7;
};
void reverse(Sqlist &l,int left,int right){
    while(left<=right){
        int temp=l.nums[left];
        l.nums[left]=l.nums[right];
        l.nums[right]=temp;
        left++;
        right--;
    }
}
// 此处的m表示的是第一个顺序表的长度，n 表示的是第二个顺序表的长度
void change(Sqlist &l,int m,int n){
    reverse(l,0,n+m-1);
    reverse(l,0,n-1);
    reverse(l,n,n+m-1);
}
void disp(Sqlist &l){
    for(int i=0;i<l.length;i++){
        cout<<l.nums[i]<<" ";
    }
    cout<<endl;
}
int main(){
    Sqlist l;
    disp(l);
    change(l,3,4);
    disp(l);
    return 0;
}