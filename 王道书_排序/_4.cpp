// 快排版本 1
#include<bits/stdc++.h>
using namespace std;
int func(int a[],int low,int high){
    int index=low+rand()%(high-low+1);
    swap(a[low],a[index]); // 随机交换
    int i=low;
    int p=a[low];
    // 这里是挨个从一个方向开始遍历的
    for(int j=low+1;j<=high;j++){
        if(a[j]<p){
            swap(a[++i],a[j]);
        }
    }
    swap(a[low],a[i]);
    return i;
}
int getPart_2(int a[],int low,int high){
    int index=low+rand()%(high-low+1);
    swap(a[index],a[low]);
    int temp=a[low];
    while(low<high){
        while(low<high && temp<=a[high]) {
            high--;
        }
        while(low<high && temp>=a[low]){
            low++;
        }
        if(low<high){
            swap(a[low],a[high]);
        }
    }
    swap(temp,a[low]);
    return low;
}
void quick_sort(int a[],int low,int high){
    if(low<high){
        int index = getPart_2(a,low,high);
        quick_sort(a,low,index-1);
        quick_sort(a,index+1,high);
    }
}
void disp(int a[],int n){
    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
    }
}

int main(){
    int a[10]={9,8,7,6,5,4,3,2,1,0};
    quick_sort(a,0, 9);
    disp(a,10);
}