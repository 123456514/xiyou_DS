// 两个带有头结点的非递增有序链表 合并成一个大的非递增有序链表 要求不能使用额外的空间
// 算法思路： 就是将一个链表中的所有结点，排序到另一个链表中，这里一定要注意指针的使用
#include <iostream>
using namespace std;
typedef struct lnode{
    int data;
    struct lnode *next;
}lnode,*linklist;
int a[5] = {5,4,3,3,2};
int b[3] = {3,2,1};
int n1 = 5;
int n2 = 3;
void buildlist(linklist &l,int num[],int n)
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
void disp(linklist &l)
{
    lnode *p = l->next;
    while(p)
    {
        cout<<p->data<<" ";
        p=p->next;
    }
    cout<<endl;
}
void  conbine(linklist &l1,linklist &l2){
    lnode *p1=l1->next,*p2=l2->next,*r=l1,*q,*s,*k;
    while(p1){
        if(p1->data>=l2->next->data){
           q=p1->next;
           p1->next=l2->next;
           l2->next=p1;
           r->next=q;
           p1=q;
        }else{
            q=l2;
            p2=l2->next;
            while(p2->data>p1->data){
                q=p2;
                p2=p2->next;
            }
            k=p1->next;
            p1->next=p2;
            q->next=p1;
            r->next=k;
            p1=k;
        }
    }
}
int main()
{
    linklist l1,l2;
    buildlist(l1,a,n1);
    buildlist(l2,b,n2);
    disp(l2);
    conbine(l1,l2);
    disp(l2);
}