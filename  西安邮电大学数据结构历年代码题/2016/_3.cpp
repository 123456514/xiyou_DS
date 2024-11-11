// 判断回文
#include<iostream>
#include <cstring>
using namespace std;
bool judge_reverse(char nums[]){
    int l=0;
    int r=strlen(nums) -1;
    while(l<=r){
        if(nums[l] != nums[r]){
            return false;
        }
        l++;
        r--;
    }
    return true;
}
int main(){
    if(judge_reverse("aba")){
        cout << "ok";
    }else{
        cout << "no";
    }
    return 0;
}