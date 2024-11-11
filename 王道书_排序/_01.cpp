#include<bits/stdc++.h>
using namespace std;
// 2016年统考408
// 现在有一个数组，其中要把这个数组分成两份，要求两份长度的之差为最小值，并且两份元素之和，之差的绝对值最大
// 算法思想：这里考虑到了使用快速排序的分治思想。
void seta(int a[],int n,int low,int high){
    int flag=1;
    int k=(high-low)/2;
    // 快排找 part
    while(flag){
        int i=low;
        int p=a[low];
        for(int j=low+1;j<=high;j++){ // 这里是从下标为1的位置开始进行检查的，此时的p 表示的是标志位，++i表示的是要在标志位的下一位
            if(a[j]<p){
                swap(a[++i],a[j]);
            }
        }
        swap(a[low],a[i]);
        if(i==k-1) flag=0; // 如果此时的 i是中间位，那么此时就是 中间位的左边和右边 此时都是一样的位数的
        else if(i<k-1) low=i+1;// 如果此时的 k-1也就是中间位在以排序标准位的右边，那么此时把 i 右边的位置进行标准化，此时左边的下标变化
        else high=i-1;
    }
    int s1=0,s2=0;
    cout<<"s1= ";
    for(int i=0;i<k;i++){
        s1+=a[i];
        cout<<a[i]<<" ";
    }
    cout<<endl;
    cout<<"s2= ";
    for(int i=k;i<n;i++){
        s2+=a[i];
        cout<<a[i]<<" ";
    }
    cout<<endl;
    cout<<abs(s1-s2)<<endl;
}
int main()
{
    int a[9]={0,-1,-2,0,-10,3,-4,1};
    seta(a,8,0,8);
    return 0;
}