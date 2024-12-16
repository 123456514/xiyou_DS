// 删除链表中值为x 的元素，x不唯一
//链表的重复元素删除
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
void delete_x(linklist &l,int x){
    lnode *p=l->next,*r=l,*s;
    while(p){
        if(p->data != x){
            r->next=p;
            r=p;
            p=p->next;
        }else{
            s=p;
            if(p->next==NULL){
                p->next=NULL;
            }else{
                p=p->next;
            }
            free(s);
        }
    }
}
int main(){
    linklist l;
    buildlist(l);
    disp(l);
    delete_x(l,7);
    disp(l);
}