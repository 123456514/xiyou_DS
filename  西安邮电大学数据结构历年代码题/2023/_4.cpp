#include<iostream>
using namespace std;
int n = 5;
int a[5] = {1,2,3,4,5};
// 创建链表
typedef struct lnode{
    int data;
    struct lnode *next;
}lnode,*linklist;
// 创建链表
void buildlist(linklist &l,int n){
    l=(linklist)malloc(sizeof (lnode));
    lnode *r = l;
    for(int i =0;i < n;i++){
        lnode *s=(lnode*) malloc(sizeof(lnode));
        s->data=a[i];
        r->next=s;
        r=r->next;
    }
    r->next = NULL;
}
// 链表逆置
void reverse(linklist &l){
    lnode *pre = NULL;
    lnode *cur = l->next;
    l->next = NULL;
    while(cur){
        lnode *curNext = cur->next;
        cur->next = pre;
        pre = cur;
        cur=curNext;
    }
    l->next=pre;
}
void disp(linklist &l){
    lnode *p=l->next;
    while(p){
        cout << p->data << " ";
        p=p->next;
    }
}
int main(){
    linklist l;
    buildlist(l,5);
    reverse(l);
    disp(l);
}