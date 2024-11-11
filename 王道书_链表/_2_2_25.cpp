// 找到链表的中间节点 然后断开前半个链表，逆置后半段链表
#include<iostream>
using namespace std;
typedef struct lnode{
    int data;
    struct lnode *next;
}lnode,*linklist;
int a[10]={1,2,3,4,5,6,7,8,9,10};
int n=10;
void buildlist(linklist &l)
{
    l=(linklist)malloc(sizeof (lnode));
    lnode *r=l,*s;
    for(int i=0;i<n;i++)
    {
        s=(lnode*)malloc(sizeof (lnode));
        s->data=a[i];
        s->next=r->next;
        r->next=s;
        r=s;
    }
    r->next=NULL;
}
void disp(linklist &l)
{
    lnode *p=l->next;
    while(p)
    {
        cout<<p->data<<" ";
        p=p->next;
    }
    cout<<endl;
}
void newlist(linklist &L)
{
    lnode *p,*q,*r,*l;
    p=L,q=L;
    while(q->next!=NULL)
    {
        p=p->next;
        q=q->next;
        if(q->next!=NULL) q=q->next;
    }
    q=p->next;
    p->next=NULL; //断开前半部分链表
    // 逆置后半部分链表,这里使用的是头插法
    while(q)
    {
        r=q->next;
        q->next=p->next;
        p->next=q;
        q=r;
    }
    l=L->next;
    q=p->next;
    p->next=NULL;
    while(q)
    {
        r=q->next;
        q->next=l->next;
        l->next=q;
        l=q->next;
        q=r;
    }
}
int main()
{
    linklist l;
    buildlist(l);
    disp(l);
    newlist(l);
    disp(l);
}