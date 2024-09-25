// 设head为一个带头结点单链表的头指针，且给单链表的数据域是无序的，编写算法删除该单链表中值相同的多余节点。
#include<iostream>
using namespace std;
typedef struct lnode{
    int data;
    struct lnode *next;
}lnode,*linklist;
int a[6] = {1,1,-3,3,4,3};
int n=6;
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
    lnode *p=l->next,*q,*r;
    if(p!=NULL){
        while(p->next){
            q=p;
            while(q->next){
                if(q->next->data==p->data){
                    r=q->next;
                    q->next=r->next;
                    free(r);
                }else{
                    q=q->next;
                }
            }
            p=p->next;
        }
    }
}
int main()
{
    linklist l;
    buildlist(l);
    disp(l);
    remove_same(l);
    disp(l);
}