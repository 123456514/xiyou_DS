//找到链表的入环节点 快慢指针
#include<iostream>
using namespace std;
typedef struct lnode{
    int data;
    struct lnode *next;
}lnode;
int a[15]={1,2,3,4,5,6,7,8,9,4,5,6,7,8,9};
int n=15;
void buildlist(lnode *l)
{
    lnode *s,*r=l;
    r->data=a[0];
    for(int i=1;i<n;i++)
    {
        s=(lnode*)malloc(sizeof(lnode));
        s->data=a[i];
        r->next=s;
        r=r->next;
    }
    r->next=NULL;
}
void disp(lnode *l)
{
    lnode *p=l;
    while(p)
    {
        cout<<p->data<<" ";
        p=p->next;
    }
    cout<<endl;
}
lnode* find_cycle_node(lnode *l)
{
    lnode *s=l,*f=s;
    while(s!=NULL&&f->next!=NULL)
    {
        s=s->next;
        f=f->next->next;
        if(s->data==f->data) break;
    }
    if(s==NULL||f->next==NULL) return NULL;
    lnode *p=l,*q=s;
    while(p->data!=q->data)
    {
        p=p->next;
        q=q->next;
    }
    return p;
}
int main()
{
    lnode list;
    lnode *l=&list;
    buildlist(l);
    // disp(l);
    cout<<find_cycle_node(l)->data;
}