// 顺序表中的数据平均值
#include<iostream>
using namespace std;
#define Max 50
struct Sqlist{
    int a[Max]={1,2,3,4,5,6,7,8,9,10};
    int length=10;
};
int get_average_num(Sqlist &l){
    int sum = 0;
    for(int i=0;i<l.length;i++){
        sum += l.a[i];
    }
    return sum / l.length;
}
int main(){
    Sqlist l;
    cout << get_average_num(l);
    return 0;
}