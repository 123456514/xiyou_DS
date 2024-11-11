//删除链表中绝对值元素相同的结点
#include<iostream>
using namespace std;
typedef struct lnode{
    int data;
    struct lnode *next;
}lnode,*linklist;
int a[5] = {1,1,3,-3,4};
int n=5;
void buildlist(linklist &l)
{
    l=(linklist)malloc(sizeof (lnode));
    lnode *s,*r=l;
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
        cout << p->data<<" ";
        p=p->next;
    }
    cout<<endl;
}
void remove_same(linklist &l)
{
    lnode *p=l,*f;
    int *q;
    int s;
    q=(int *)malloc(sizeof (int)*n+1);
    for(int i=0;i<n+1;i++) *(q+i)=0;
    while(p->next!=NULL)
    {
        s=abs(p->next->data);
        if(*(q+s)==0)
        {
            *(q+s)+=1;
            p=p->next;
        }
        else
        {
            f=p->next;
            p->next=f->next;
            free(f);
        }
    }
    free(q);
}
int main()
{
    linklist l;
    buildlist(l);
    disp(l);
    remove_same(l);
    disp(l);
}