// 找到链表中的倒数第k个节点
#include<iostream>
using namespace std;
typedef struct lnode{
    int data;
    struct lnode * next;
}lnode,*linklist;
int a[5]={5,4,3,2,1};
int n =5;
void buildlist(linklist &l)
{
    l=(linklist)malloc(sizeof (lnode));
    lnode *r=l,*s;
    for(int i=0;i<n;i++)
    {
        s=(lnode*)malloc(sizeof(lnode));
        s->data=a[i];
        s->next=r->next;
        r->next=s;
        r=s;
    }
    r->next=NULL;
}
int findd(linklist &l,int k) {
    lnode *p = l->next, *q = l->next;
    int num = 0;
    while (p != NULL) {
        if (num < k) num++;
        else q = q->next;
        p = p->next;
    }
    if(num<k) return 0;
    else
    {
        cout<<"倒数第k个数为"<<q->data<<endl;
    }
    return q->data;
}
int main()
{
    linklist l;
    buildlist(l);
    cout<<findd(l,2)<<endl;
}