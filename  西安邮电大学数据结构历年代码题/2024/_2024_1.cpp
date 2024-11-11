// 设计算法实现将单链表l中的第i个节点开始的len 个节点删除
#include<iostream>
using namespace std;
int n = 5;
int a[5] = {1,2,3,4,5};
// 创建链表
typedef struct lnode{
    int data;
    struct lnode *next;
}lnode,*linklist;
// 创建链表
void buildlist(linklist &l,int n)
{
    l=(linklist)malloc(sizeof (lnode));
    lnode *r = l;
    for(int i =0;i < n;i++)
    {
        lnode *s=(lnode*) malloc(sizeof(lnode));
        s->data=a[i];
        r->next=s;
        r=r->next;
    }
    r->next = NULL;
}
// 打印链表
void disp(linklist &l)
{
    lnode *r = l->next;
    while(r)
    {
        cout<<r->data<<" ";
        r=r->next;
    }
    cout<<endl;
}
int get_count(linklist &l)
{
    lnode *p = l->next;
    int k=0;
    while(p)
    {
        k++;
        p=p->next;
    }
    return k;
}
void delete_list(linklist &l,int i,int len)
{
    // 链表长度 length
    // 1. i > length
    // 2. 从i开始删除len个结点，如果此时的len大于 length - i - 1
    // 1-2-3-4-5
    // 从第2个节点删除2个节点
    // 1-4-5
    int length = get_count(l);
    if(length < i || i + len - 1 > length)
    {
        cout<<"删除失败"<<endl;
    }
    lnode *r = l,*q,*p=l->next;
    while(p){
        for(int k = 1;k<i;k++){
            r=p;
            p=p->next;
        }
        while(len != 0){
            q=p;
            p=p->next;
            free(q);
            len--;
        }
        r->next=p;
        break;
    }
}
int main()
{
    linklist l;
    buildlist(l,5);
    disp(l);
    delete_list(l,5,4);
    disp(l);
}