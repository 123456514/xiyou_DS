// 已知两个带有头结点的单向循环链表ra和rb，ra，rb分别为链表的尾结点，编写算法，将表ra连接到ra后，是他们合并成一个单向循环链表
#include<iostream>
using namespace std;
typedef struct node{
    int data;
    struct node *next;
}node,*linklist;
// 创建链表
int a[5]={1,2,3,4,5};
int b[5]={6,7,8,9,10};
int n=5;
void buildlist(linklist &l,int nums[]){
    l=(node*)malloc(sizeof (node));
    node *s;
    node *r=l;
    for(int i=0;i<n;i++){
        s=(node*)malloc(sizeof (node));
        s->data=nums[i];
        s->next=r->next;
        r->next=s;
        r=s;
    }
    r->next=l; //循环
}
// 找到尾指针
node* findNode(linklist &l){
    node *p=l->next;
    while(p->next!=l){
        p=p->next;
    }
    return p;
}
void disp(linklist &l)
{
    node *p=l->next;
    while(p!=l)
    {
        cout << p->data<<" ";
        p=p->next;
    }
    cout<<endl;
}
void combine(linklist &l1,linklist &l2){
    node *ra= findNode(l1);
    node *rb= findNode(l2);
    rb->next=NULL;
    ra->next=l2->next;
    rb->next=l1;
    disp(l1);
}

int main(){
    linklist l1;
    linklist l2;
    buildlist(l1,a);
    buildlist(l2,b);
    combine(l1,l2);
    return 0;
}








