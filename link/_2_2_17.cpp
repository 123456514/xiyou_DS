// 8月25
// 判断一个循环链表是否是一个回文链表
#include<iostream>
using namespace std;
typedef struct lnode{
    int data;
    struct lnode * next;
    struct lnode * prior;
}lnode,*linklist;
int a[5]={1,2,3,2,1};
int n = 5;
void buildlist(linklist &l,int n)
{
    l=(linklist)malloc(sizeof (lnode));
    l->next=l;
    l->prior=l;
    lnode *r=l;
    for(int i =0;i < n;i++)
    {
        lnode *s=(lnode *)malloc(sizeof (lnode));
        s->data=a[i];
        s->next=r->next;
        r->next->prior=s;
        s->prior=r;
        r->next=s;
        r=s;
    }
}
void disp(linklist l)
{
    lnode *r=l->next;
    while(r!=l)
    {
        cout<<r->data<<" ";
        r=r->next;
    }
    cout<<endl;
}
// 这里使用了双链表的特定，使用了两个指针相向遍历，如果链表中节点的个数为奇数 p!q   如果链表中的结点的个数为偶数 那么此时当链表遍历到中间两个相同节点的时候，在让指针遍历一次，那么此时就是
// q.next != p 即跳出规则为 q.next != p
// 1 2 3 3 2 1
//     p q
//     q p
bool isok(linklist &l)
{
    lnode *p=l->next;
    lnode *q=l->prior;
    while(p!=q&&q->next!=p)
    {
        if(p->data==q->data)
        {
            p=p->next;
            q=q->prior;
        }
        else
        {
            return false;
        }
    }
    return true;
}
int main()
{
    linklist l;
    buildlist(l,n);
    disp(l);
    cout <<isok(l);
}