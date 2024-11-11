#include<iostream>
using namespace std;
//插入排序
// 该算法的时间复杂度为 On2
// 空间复杂度为 O1
// 稳定性 稳定
// 该算法适用于快已经有序的序列中
void insertSort(int arr[],int n){
    int temp;
    int j;
    for(int i=1;i<n;i++){
        // 如果前一个大于后一个，那么就记录后一个，然后从后i-1位置从后向前开始搜索，此时要确保界限和遍历到的元素如果大于temp，就把这个位上边的数向后移动。
        // 移动结束之后，那么此时的j就会变成-1，那么此时就把这个最小的元素，安排在最前面，temp[0]=temp
        if(arr[i-1]>arr[i]) {
            temp = arr[i];
            for (j = i - 1; j >= 0 && arr[j] > temp; j--) {
                arr[j + 1] = arr[j];
            }
            arr[j + 1] = temp;
        }
    }
}
void disp(int arr[]){
    for(int i=0;i<8;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}
//希尔排序 实际上就是使用了分组的直接插入排序
// 稳定性：不稳定
// 时间复杂度 O1.3-1.5
// 空间复杂度 O1
void shallSort(int arr[],int gap,int n){
    for(int i=gap;i<n;i++){
        int j=i-gap;
        int temp=arr[i];
        for(;j>=0&&arr[j]>temp;j-=gap){
            arr[j+gap]=arr[j];
        }
        arr[j+gap]=temp;
    }
}


void do_shallSort(int arr[],int n){
    int gap=n;
    while(gap>1){
        shallSort(arr,gap,n);
        gap=gap/2;
    }
    shallSort(arr,gap,n);
}
//快速排序
int getPart(int nums[],int left,int right){
    int temp=nums[left];
    while(left<right){
        while (left<right&&nums[right]>=temp){
            right--;
        }
        nums[left]=nums[right];
        while(left<right&&nums[left]<=temp){
            left++;
        }
        nums[right]=nums[left];
    }
    nums[left]=temp;
    return left;
}
void quicksort(int arr[],int left,int right){
    if(left>=right){
        return;
    }
    int part=getPart(arr,left,right);
    quicksort(arr,left,part-1);
    quicksort(arr,part+1,right);
}
//堆排序
//选择排序
//冒泡排序
//归并排序
void marge(int nums[],int left,int mid,int right){
    int p1=left;
    int p2=mid+1;
    int index=0;
    int temp[right-left+1];
    while(p1<=mid&&p2<=right){
        temp[index++]=nums[p1]<=nums[p2]?nums[p1++]:nums[p2++];
    }
    while(p1<=mid){
        temp[index++]=nums[p1++];
    }
    while(p2<=right){
        temp[index++]=nums[p2++];
    }
    for(int i=0;i<right-left+1;i++){
        nums[left+i]=temp[i];
    }
}
void margeSort(int nums[],int left,int right){
    if(left >=right){
        return;
    }
    int mid=(right+left)>>1;
    margeSort(nums,left,mid);
    margeSort(nums,mid+1,right);
    marge(nums,left,mid,right);
}
//基数排序
int main(){
    int arr[]={9,8,7,6,5,4,3,12};
    //insertSort(arr,8); //快速排序
    //do_shallSort(arr,8); // 希尔排序
    //margeSort(arr,0,7); // 归并排序
    quicksort(arr,0,7);
    disp(arr);
    return 0;
}