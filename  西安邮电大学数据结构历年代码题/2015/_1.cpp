//删除单链表中节点中数值域为奇数的节点
// 两个有序链表 得到两个链表中的共同元素 在A链表中
#include <iostream>
using namespace std;
typedef struct lnode{
    int data;
    struct lnode *next;
}lnode,*linklist;
// 创建带头结点的链表
int a[11] = {1,2,3,3,4,5,6,7,8,9,10};
int n = 11;
void buildlist(linklist &l,int aa[]){
    l=(linklist) malloc(sizeof (lnode));
    lnode *s,*r=l;
    for(int i=0;i<n;i++){
        s=(lnode*) malloc(sizeof (lnode));
        s->data=aa[i];
        r->next=s;
        r=r->next;
    }
    r->next=NULL;
}
void disp(linklist l)
{
    lnode *s=l->next;
    while(s)
    {
        cout<<s->data<<" ";
        s=s->next;
    }
    cout<<endl;
}
void delete_ji_num(linklist &l){
    lnode *p,*r;
    p=l;
    if(p->next != NULL){
        while(p->next){
            if(p->next->data % 2 != 0){ // 如果是奇数，此处的r就相当于一个替罪羊，记录删除节点位置的指针，然后free
                r=p->next;
                p->next=r->next;
                free(r);
            }else{
                p=p->next;
            }
        }
    }
}
int main(){
    linklist l;
    buildlist(l,a);
    return 0;
}