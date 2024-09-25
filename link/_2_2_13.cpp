//链表的重复元素删除
#include<iostream>
using namespace std;
typedef struct lnode{
    int data;
    struct lnode *next;
}lnode,*linklist;
void merge(linklist &l1,linklist &l2)
{
    lnode *p1=l1->next,*p2=l2->next,*r;
    l1->next=NULL;
    while(p1&&p2)
    {
        if(l1->data <= l2->data)
        {
            r=p1->next;
            p1->next=l1->next;
            l1->next=p1;
            p1=r;
        }
        else
        {
            r=p2->next;
            p2->next=l1->next;
            l1->next=p2;
            p2=r;
        }
    }
    if(p1) p2=p1;
    while(p2)
    {
        r=p2->next;
        p2->next=l1->next;
        l1->next=p2;
        p2=r;
    }
}
//int main()
//{
//
//}