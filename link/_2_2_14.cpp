// 找到两个有序数组中相同的元素，组成一个有序的链表
#include<iostream>
using namespace std;
typedef struct lnode{
    int data;
    struct lnode *next;
}lnode,*linklist;
linklist l3;
void buildnew(linklist &l1,linklist &l2)
{
    l3=(linklist) malloc(sizeof(lnode));
    lnode *p1=l1->next,*p2=l2->next,*s,*r;
    r=l3;
    while(p1&&p2)
    {
         if(p1->data<p2->data) p1=p1->next;
         else if(p2->data<p1->data) p2=p2->next;
         else{
             s=(lnode*) malloc(sizeof (lnode));
             s->data=p1->data;
             r->next=s;
             r=s;
             p1=p1->next;
             p2=p2->next;
         }
    }
    r->next=NULL;
}
