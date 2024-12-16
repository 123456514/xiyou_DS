#include<stdio.h>
#include"string.h"
bool is_reverse(char nums[]){
    if(strlen(nums) % 2 == 0){
        return false;
    }
    int left = 0,right=strlen(nums) - 1;
    while(left != right){
        if(nums[left] == nums[right]){
            right--;
            left++;
        }else{
            return false;
        }
    }
    return true;
}
int main(){
    char nums[6]={'1','1','4','&','2','1'};
    printf("%d",is_reverse(nums));
    return 0;
}