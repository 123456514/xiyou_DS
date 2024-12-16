#include<iostream>
using namespace std;
typedef struct lnode{
    int data;
    struct lnode *next;
}lnode,*linklist;
int a[5]={1,3,3,4,7};
int n=5;
void buildlist(linklist &L){
    L=(linklist)malloc(sizeof(lnode));
    lnode *s,*r=L;
    for(int i=0;i<n;i++){
        s=(lnode *)malloc(sizeof(lnode));
        s->data=a[i];
        r->next=s;
        r=r->next;
    }
    r->next=NULL;
}
void disp(linklist L){
    lnode *s=L->next;
    while(s){
        cout<<s->data<<" ";
        s=s->next;
    }
    cout<<endl;
}
void divide_list(linklist &l){
    lnode *l1=(lnode*)malloc(sizeof(lnode));
    lnode *l2=(lnode*)malloc(sizeof(lnode));
    lnode *p=l->next,*cur1=l1,*cur2=l2;
    while(p) {
        if (p->data % 2 == 0) {
            cur2->next = p;
            cur2 = cur2->next;
        } else {
            cur1->next = p;
            cur1 = cur1->next;
        }
        p = p->next;
    }
    cur1->next=NULL;
    cur2->next=NULL;
    disp(l1);
    disp(l2);
}
int main(){
    linklist l;
    buildlist(l);
    divide_list(l);
}