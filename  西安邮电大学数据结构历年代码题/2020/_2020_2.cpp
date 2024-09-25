// 已知两个带头结点的非递减有序的单链表A和B，设la是单链表a的头结点，lb是单链表b的头结点指针，编写算法
// 将这两个单链表合并成一个非递增有序链表c,要求单链表c仍然使用原来两个链表的存储空间。
#include<iostream>
using namespace std;
typedef struct lnode{
    int data;
    struct lnode *next;
}lnode,*linklist;
int a[5]={5,6,7,8,9};
int b[5]={6,9,10,11,12};
int n=5;
void buildlist(linklist &l,int num[])
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
// 这里考虑使用到头插法
linklist combine(linklist &l1,linklist &l2){
    lnode *p=l1->next,*r,*f;
    while(p){
        r=p->next;
        f=l2;
        while(f->next!=NULL && f->next->data<p->data){
            f=f->next;
        }
        p->next=f->next;
        f->next=p;
        p=r;
    }
    return l2;
}
void print(linklist l){
    lnode* p=l->next;
    while(p){
        cout<<p->data<<" ";
        p=p->next;
    }
    cout<<endl;
}
int main()
{
    linklist l1;
    linklist l2;
    buildlist(l1,a);
    buildlist(l2,b);
    print(l1);
    print(l2);
    combine(l1,l2);
    print(l2);
}
