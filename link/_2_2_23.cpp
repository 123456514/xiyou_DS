// 找到公共后缀的起始点
#include<iostream>
using namespace std;
typedef struct lnode{
    char data;
    struct lnode *next;
}lnode,*linklist;
char a[7]{'l','o','a','d','i','n','g'};
char b[5]={'b','e','i','n','g'};
void buildlist(linklist &l,char aa[],int n)
{
    l=(linklist)malloc(sizeof(lnode));
    lnode *s,*r=l;
    for(int i=0;i<n;i++)
    {
        s=(lnode*)malloc(sizeof (lnode));
        s->data=aa[i];
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
int length(linklist &l)
{
    int count=0;
    lnode *p=l->next;
    while(p)
    {
        count++;
        p=p->next;
    }
    return count;
}
linklist get_ans(linklist l1,linklist l2)
{
    int len1=length(l1),len2=length(l2);
    int k= abs(len1-len2);
    lnode *p=l1->next,*q=l2->next;
    if(len1>=len2)
    {
        while(k--)
        {
            p=p->next;
        }
    }
    if(len2>=len1)
    {
        while(k--)
        {
            q=q->next;
        }
    }
    while(p->data!=q->data)
    {
        p=p->next;
        q=q->next;
    }
    return p;
}
int main()
{
    linklist l1,l2;
    buildlist(l1,a,7);
    buildlist(l2,b,5);
    disp(l1);
    disp(l2);
    linklist ans = get_ans(l1,l2);
    cout<<ans->data<<endl;
    return 0;
}