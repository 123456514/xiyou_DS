// 在链表中的结点中存在一个访问次数域，访问一次这个域的值就会增加一位，并且把这个结点插入到链表的前面，根据访问次数排列
#include<iostream>
using namespace std;
typedef struct lnode{
    int data;
    int f;
    struct lnode *prior;
    struct lnode *next;
}lnode,*linklist;
// 创建非循环双链表
int a[5]={1,2,3,4,5};
int n=5;
void buildlist(linklist &l)
{
    l=(linklist)malloc(sizeof (lnode));
    lnode *s,*r=l;
    l->prior=NULL;
    l->next=l;
    for(int i =0;i<n;i++)
    {
        s=(lnode *)malloc(sizeof (lnode));
        s->data=a[i];
        s->f=0;
        s->next= r->next;
        r->next->prior=s;
        r->next=s;
        s->prior=r;
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
linklist Locate(linklist &l,int x)
{
    lnode *p=l->next,*q;
    while(p&&p->data!=x) p=p->next;
    if(!p) cout<<"没有找到等于x的这个结点"<<endl;
    else
    {
        p->f++;
        // 如果此时这里的p的 结点的下一个节点为null 那么这个为空的节点的前驱就不能指向p的前驱
        if(p->next!=NULL) p->next->prior=p->prior;
        p->prior->next=p->next;
        q=p->prior;
        while(q!=l&&q->f<=p->f) q=q->prior;
        p->next=q->next;
        q->next->prior=p;
        p->prior=q;
        q->next=p;
    }
    return p;
}
int main()
{
    linklist l;
    buildlist(l);
    disp(l);
    Locate(l,5);
    Locate(l,4);
    disp(l);
}