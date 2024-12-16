#include<iostream>
using namespace std;
int n1 = 6;
int n2 = 6;
int a[6] = {1,2,3,4,5,6};
int b[6] = {10,9,3,4,5,11};
// 创建链表
typedef struct lnode{
    int data;
    struct lnode *next;
}lnode,*linklist;
// 创建链表
void buildlist(linklist &l,int n,int nums[]){
    l=(linklist)malloc(sizeof (lnode));
    lnode *r = l;
    for(int i =0;i < n;i++){
        lnode *s=(lnode*) malloc(sizeof(lnode));
        s->data=nums[i];
        r->next=s;
        r=r->next;
    }
    r->next = NULL;
}
// 打印链表
void disp(linklist &l){
    lnode *r = l->next;
    while(r){
        cout<<r->data<<" ";
        r=r->next;
    }
    cout<<endl;
}
void linkNode_same(linklist &la,linklist &lb){
    lnode *pa=la->next,*pb=lb->next;
    lnode *lc=(lnode *)malloc(sizeof(lnode));
    lc->next=NULL;
    lnode *r;
    while(pa){
        pb=lb->next;
        while(pb){
            if(pb->data == pa->data){
                lc->next=pb;
                break;
            }
            pb=pb->next;
        }
        while(pb != NULL && pb->data==pa->data){
            r=pb;
            pb=pb->next;
            pa=pa->next;
        }
        pa=pa->next;
    }
    r->next=NULL;
    disp(lc);
}
int main(){
    linklist la;
    linklist lb;
    buildlist(la,n1,a);
    buildlist(lb,n2,b);
    linkNode_same(la,lb);
}