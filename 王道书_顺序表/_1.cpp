// 从顺序表中伤处具有最小值的元素 假设唯一 并由函数返回被删除元素的值
// 空出的位置由最后一个元素填补，若顺序表为空，则显示出错信息，并返回运行
#include<iostream>
using namespace std;
#define max 50
struct sqlist{
    int data[max]={2,3,4,5,9,0,78};
    int length=7;
};
int target=0;
bool delete_min(sqlist &s,int &ele){
    if(s.length==0) return false;
    int min=s.data[0];
    int flag=0;
    for(int i=1;i<s.length;i++){
        if(min>s.data[i]){
            min=s.data[i];
            flag=i;
        }
    }
    target=min;
    ele=s.data[flag];
    s.data[flag]=s.data[s.length-1];
    return true;
}
void print(sqlist &s)
{
    for(int i=0;i<s.length;i++){
        cout<<s.data[i]<<" ";
    }
    cout<<endl;
}
int main(){
    sqlist l;
    int k=0;
    print(l);
    cout<<delete_min(l,k);
    cout<<endl;
    cout<<k;
    cout<<endl;
    print(l);
    cout<<target;
}