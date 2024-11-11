// 8月25
// 从循环链表中依次删除链表中的最小值，并且依次打印每个节点的值
// 使用四个指针，分别是 工作指针 p 工作指针前驱r  最小值指针min 最小值指针rmin   rmin.next = min.next;
#include<iostream>
using namespace std;
int a[]={2,1,3,4,5};
int n=5;
typedef struct lnode{
    int data;
    struct lnode *next;
}lnode,*linklist;
void buildlist(linklist &l,int n)
{
    l=(linklist)malloc(sizeof (lnode));
    lnode *r=l;
    for(int i=0;i<n;i++)
    {
        lnode *s=(lnode *)malloc(sizeof (lnode));
        s->data=a[i];
        r->next=s;
        r=r->next;
    }
    r->next=l;
}
void disp(linklist &l)
{
    lnode *p=l->next;
    while(p!=l)
    {
        cout<<p->data<<" ";
        p=p->next;
    }
    cout<<endl;
}
void findmin(linklist &l)
{
    lnode *min,*rmin,*r,*p;
    while(l->next!=l)
    {
        r=l,p=l->next,min=p,rmin=r;
        while(p!=l)
        {
            if(p->data<min->data)
            {
                min=p;
                rmin=r;
            }
            else
            {
                r=p;
                p=p->next;
            }
        }
        cout<<min->data<<" ";
        rmin->next=min->next;
        free(min);
    }
    //删除链表l
    free(l);
}
int main()
{
    linklist l;
    buildlist(l,n);
    findmin(l);
}