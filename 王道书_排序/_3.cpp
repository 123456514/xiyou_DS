// 把一个数组中的奇数都移到偶数之前
// 算法思想： 设置两个指针，一个指针从左边扫描，一个指针从右边扫描
// 第一个指针如果此时遍历到偶数停止，如果第二个指针遍历到奇数停止，然后交换两个元素，并依次类推，那么奇数就是在偶数之前的。
#include<bits/stdc++.h>
using namespace std;
void func(int a[],int n){
    int i=0,j=n-1;
    while(i<j){
       while(i<j&&a[i]%2==1) i++;
       while(i<j&&a[j]%2==0) j--;
       if(i<j){
           swap(a[i],a[j]);
           i++; // 指针向内聚拢
           j--;
       }
    }
}
void disp(int a[],int n){
    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
    }
}
int main()
{
    int a[10]={0,1,2,3,4,5,6,7,8,9};
    func(a,10);
    disp(a,10);
    return 0;
}