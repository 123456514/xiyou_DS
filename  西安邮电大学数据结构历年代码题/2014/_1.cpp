// 某学校实验室有一批计算机，按其价格从低到高的次序构成了一个单链表存放，链表中每个节点指出同样价格的若干台
// 现在又新增n台价格为h元的计算机，编程实现在实验室计算机单链表中添加计算机的算法
#include<iostream>
using namespace std;
typedef struct lnode{
    int count;
    int price;
    struct lnode *next;
}lnode,*linklist;
int counts[5]={5,6,7,8,9};
int prices[5]={6,9,10,11,12};
int n=5;
void buildlist(linklist &l,int counts[],int prices[])
{
    l=(linklist) malloc(sizeof (lnode));
    lnode *r = l;
    for(int i = 0;i<n;i++)
    {
        lnode *s=(lnode*)malloc(sizeof(lnode));
        s->count=counts[i];
        s->price=prices[i];
        r->next=s;
        r=r->next;
    }
    r->next=NULL;
}
void add_computers(linklist &l,int count,int price){
    // 按照单个计算机的价格升序排列
    lnode *p=l,*r=l; // 标记r指针，为指针p的前驱指针
    while(p != NULL){
        if(p->next != NULL && p->next->price>price){
            break;
        }
        r=p;
        p=p->next;
    }
    lnode *s=(lnode *) malloc(sizeof(lnode));
    s->price=price;
    s->count=count;
    if(p != NULL){
        lnode *f=p->next;
        p->next=s;
        s->next=f;
    }else{
       // 如果此时在price中是最大的，那么就把节点添加在最后一个上
        r->next=s;
        s->next=NULL;
    }
}
void disp(linklist &l)
{
    lnode *p=l->next;
    while(p!=l)
    {
        cout << p->price<<" ";
        p=p->next;
    }
    cout<<endl;
}
int main(){
    linklist l;
    buildlist(l,counts,prices);
    add_computers(l,9,18);
    disp(l);
    return 0;
}