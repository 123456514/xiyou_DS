// 两个单向循环链表合并为一个大的单向循环链表 la lb 为链表的头指针
//链表的重复元素删除
#include<iostream>
using namespace std;
typedef struct lnode{
    int data;
    struct lnode *next;
}lnode,*linklist;
int a[10]={1,2,3,5,6,6,7,7,9,10};
int n=10;
void buildlist(linklist &l)
{
    l=(linklist)malloc(sizeof(lnode));
    lnode *s,*r=l;
    for(int i=0;i<n;i++)
    {
        s=(lnode *)malloc(sizeof(lnode));
        s->data=a[i];
        r->next=s;
        r=r->next;
    }
    r->next=l;
}
lnode * find_tail_node(linklist &l){
    lnode * node = l->next;
    while(node->next != l){
        node=node->next;
    }
    return node;
}
lnode* combine(linklist &la,linklist &lb){
    // 合并两个循环链表
    lnode *node_a= find_tail_node(la);
    node_a->next=lb->next;
    lnode *node_b= find_tail_node(lb);
    node_b->next=la;
    return la;
}
int main(){
    linklist la;
    linklist lb;
    buildlist(la);
    buildlist(lb);
    lnode * node = combine(la,lb);
    return 0;
}