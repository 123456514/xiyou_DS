// 完成最少时间在表中查找数值为x的元素，若找到则，将其后继圆度位置交换，若找不到，则将其插入表中并使元素仍让递增有序
// 算法思想： 边界条件 如果此时在顺序表中找到的是最大的一个元素，那么就没有后继元素，交换不了
#include<iostream>
using namespace std;
#define Max 10
struct Sqlist{
    int nums[Max]={1,2,2,4,5,6,7};
    int length=7;
};
void find(Sqlist &l,int x){
    int left=0,right=l.length-1,mid;
    while(left<=right){
        mid=(left+right)/2;
        if(l.nums[mid]==x){
            break;
        }else if(l.nums[mid]<x){
            left=mid+1;
        }else{
            right=mid-1;
        }
    }
    if(l.nums[mid]==x&&mid!=l.length-1){
        int temp=l.nums[mid];
        l.nums[mid]=l.nums[mid+1];
        l.nums[mid+1]=temp;
    }
    // 如果此时没有在数组中找到这个元素，但是此时已经找到了这个元素该在的位置，把对应的元素向后以后，然后x归位
    if(right<left){
        int i;
        for(i=l.length-1;i>right;i--){
            l.nums[i+1]=l.nums[i];
        }
        l.nums[i+1]=x;
        l.length++;
    }
}
void disp(Sqlist &l){
    for(int i=0;i<l.length;i++){
        cout<<l.nums[i]<<" ";
    }
    cout<<endl;
}
int main()
{
    Sqlist l;
    disp(l);
    find(l,3);
    disp(l);
    return 0;
}