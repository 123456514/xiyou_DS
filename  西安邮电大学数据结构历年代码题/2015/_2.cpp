// 将非0元素前移到顺序表的前方
#include<iostream>
using namespace std;
#define max 10
struct sqlist{
    int data[max]={0,0,4,5,9,0,78};
    int length=7;
};
void remove_no_zero_front_num(sqlist &l){
    int k=0;
    for(int i=0;i<l.length;i++){
        if(l.data[i] == 0){
            k++;
        }else{
            l.data[i-k] = l.data[i];
            l.data[i]=0;
        }
    }
}
void disp(sqlist &l){
    for(int i=0;i<l.length;i++){
        cout << l.data[i] << " ";
    }
}
int main(){
    sqlist l;
    remove_no_zero_front_num(l);
    disp(l);
    return 0;
}