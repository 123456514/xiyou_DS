// 两个有序链表 得到两个链表中的共同元素 在A链表中
#include <iostream>
using namespace std;
typedef struct lnode{
    int data;
    struct lnode *next;
}lnode,*linklist;
// 创建带头结点的链表
int a[5] = {2,4,5,7,9};
int b[5] = {1,2,5,9,10};
int n = 5;
void buildlist(linklist &l,int aa[])
{
    l=(linklist) malloc(sizeof (lnode));
    lnode *s,*r=l;
    for(int i=0;i<n;i++)
    {
        s=(lnode*) malloc(sizeof (lnode));
        s->data=aa[i];
        r->next=s;
        r=r->next;
    }
    r->next=NULL;
}
void disp(linklist l)
{
    lnode *s=l->next;
    while(s)
    {
        cout<<s->data<<" ";
        s=s->next;
    }
    cout<<endl;
}
 void deletelist(linklist &l1,linklist &l2)
 {
    lnode *p1=l1->next,*p2=l2->next,*r=l1,*q;
    while(p1&&p2)
    {
        if(p1->data<p2->data)
        {
            q=p1;
            p1=p1->next;
            free(q);
        }
        else if(p1->data>p2->data)
        {
            q=p2;
            p2=p2->next;
            free(q);
        }
        else
        {
            r->next=p1;
            r=p1;
            p1=p1->next;
            q=p2;
            p2=p2->next;
            free(q);
        }
    }
    // 将p指针之后的节点全部删除
    while(p1)
    {
        q=p1;
        p1=p1->next;
        free(q);
    }
     while(p2)
     {
         q=p2;
         p2=p2->next;
         free(q);
     }
     r->next=NULL;
 }
int main()
{
    linklist l1,l2;
    buildlist(l1,a);
    buildlist(l2,b);
    deletelist(l1,l2);
    disp(l1);
}