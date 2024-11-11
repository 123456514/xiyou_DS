// 双向冒泡排序
// 从左向右 使用冒泡排序，那么最后一位就已经排好了，那么此时的high-- ,在待排数组中删除最后一个
// 然后从右向左，使用冒泡排序，那么经过一趟排序之后，此时的数组中的第一位已经是排序好的，那么就把第一个从待排数组中删除 low++
// 然后依次类推
#include<bits/stdc++.h>
using namespace std;
void bubble(int a[],int n){
    int low=0,high=n-1;
    bool flag=true;
    while(low<high&&flag){
        flag=false; // 如果数组中的元素，有序，那么就标志位就一直位false 那么就直接退出了循环。
        for(int i=low;i<high;i++){ // 从左向右
            if(a[i]>a[i+1]) {
                flag= true;
                swap(a[i],a[i+1]);
            }
        }
        high--; // a[high] 已经排好了
        for(int i=high;i>low;i--){ // 从右向左
            if(a[i]<a[i-1]) {
                flag= true;
                swap(a[i],a[i-1]);
            }
        }
        low++;  // a[low] 已经排好了
    }
}
void disp(int a[],int n){
    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
    }
}
int main()
{
    int a[10]={9,8,7,6,5,4,3,21,1,0};
    bubble(a,10);
    disp(a,10);
    return 0;
}