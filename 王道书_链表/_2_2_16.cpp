#include <iostream>
using namespace std;
typedef struct lnode{
    int data;
    struct lnode *next;
}lnode,*linklist;
int a[5]={1,2,3,4,5};
int b[3] ={2,3,6};
int n1 = 5;
int n2 = 3;
void buildlist(linklist &l,int aa[],int n)
{
    l=(linklist ) malloc(sizeof(lnode));
    lnode *r = l;
    for(int i=0;i<n;i++)
    {
        lnode *s = (lnode *) malloc(sizeof (lnode));
        s->data=aa[i];
        r->next=s;
        r=r->next;
    }
    r->next=NULL;
}
void disp(linklist &l)
{
    lnode *r = l->next;
    while(r)
    {
        cout<<r->data<<" ";
        r=r->next;
    }
}
// 链表中的模式匹配 这里使用的是暴力算法
bool isok(linklist &l1,linklist &l2) {
    lnode *p1 = l1->next, *p2 = l2->next, *r = l1->next;
    while (p1&&p2)
    {
        // 这里的r指针表示的是第一个主串的遍历位置
        if(p1->data != p2->data)
        {
            r=r->next;
            p1=r;
            p2=l2->next;
        }
        else
        {
            p1=p1->next;
            p2=p2->next;
        }
    }
    if(p2) return false;
    else return true;
}
int main()
{
    linklist l1,l2;
    buildlist(l1,a,n1);
    buildlist(l2,b,n2);
    bool ok = isok(l1,l2);
    cout << ok;
}