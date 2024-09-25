// 将顺序表中的数据循环左移p位
#include<iostream>
using namespace std;
#define Max 10
struct Sqlist{
    int nums[Max]={1,2,3,4,5,6,7};
    int length=7;
};
// 1 2 3 4 5 6 7
// 5 6 7 1 2 3 4
void reverse(Sqlist &l,int left,int right){
    while(left<=right){
        int temp=l.nums[left];
        l.nums[left]=l.nums[right];
        l.nums[right]=temp;
        left++;
        right--;
    }
}
void removeLeftRecycle(Sqlist &l,int p){
    int n=l.length-1;
    reverse(l,0,n);
    reverse(l,0,p-1);
    reverse(l,p,n);
}
void disp(Sqlist &l){
    for(int i=0;i<l.length;i++){
        cout<<l.nums[i]<<" ";
    }
    cout<<endl;
}
int main(){
    Sqlist l;
    removeLeftRecycle(l,3);
    disp(l);
    return 0;
}