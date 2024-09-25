// 编写算法 统计带头结点的单链表l的实际元素个数
// 这里的实际元素个数 其实指的是 除了头结点以外的节点个数
#include<iostream>
using namespace std;
typedef struct lnode{
    int data;
    struct lnode *next;
}lnode,*linklist;
//尾插法创建带有头结点的链表
int a[5] = {5,4,3,3,2};
int n1 = 5;
void buildlist(linklist &l,int num[],int n)
{
    l=(linklist) malloc(sizeof (lnode));
    lnode *r = l;
    for(int i = 0;i<n;i++)
    {
        lnode *s=(lnode*)malloc(sizeof(lnode));
        s->data=num[i];
        r->next=s;
        r=r->next;
    }
    r->next=NULL;
}
int get_sum(linklist &l){
    if(l==NULL) return 0;
    int count = 0;
    lnode *p=l->next;
    while(p){
        count++;
        p=p->next;
    }
    return count;
}
int main(){
    linklist l;
    buildlist(l,a,n1);
    cout<< get_sum(l);
    return 0;
}