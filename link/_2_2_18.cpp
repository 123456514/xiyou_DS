// 8月25
// 循环单链表的拼接
#include<iostream>
using namespace std;
typedef struct lnode{
    int data;
    struct lnode *next;
}lnode,*linklist;
int a[]={1,2,3,4,5};
int b[]={6,7,8,9};
int a1=5;
int b1=4;
void buildlist(linklist &l,int n[],int num)
{
    l=(linklist)malloc(sizeof (lnode));
    lnode *r=l;
    for(int i=0;i<num;i++)
    {
        lnode *s=(lnode *)malloc(sizeof (lnode));
        s->data=n[i];
        r->next=s;
        r=r->next;
    }
    r->next=l;
}
void disp(linklist &l)
{
    lnode *p=l->next;
    while(p!=l)
    {
        cout<<p->data<<" ";
        p=p->next;
    }
    cout<<endl;
}
void combin(linklist &l1,linklist &l2)
{
    // 找到第一个和第二个链表的最后一个节点
    lnode *p1=l1->next,*p2=l2->next;
    while(p1->next!=l1)
    {
        p1=p1->next;
    }
    while(p2->next!=l2)
    {
        p2=p2->next;
    }
    p1->next=l2->next;
    p2->next=l1;
}
int main()
{
    linklist l1,l2;
    buildlist(l1,a,a1);
    buildlist(l2,b,b1);
    disp(l1);
    disp(l2);
    combin(l1,l2);
    disp(l1);
}