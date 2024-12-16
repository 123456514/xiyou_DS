// 编写算法，在以二叉链表存储的二叉树中，已知某结点数据元素值为x，求该节点的双亲节点
#include<iostream>
using namespace std;
typedef struct treenode{
    char data;
    struct treenode *left,*right;
}treenode,*tree;
void buildtree(tree &t)
{
    char ch;
    ch=getchar();
    if(ch=='#') t=NULL;
    else
    {
        t=(treenode *)malloc(sizeof(treenode));
        t->data=ch;
        t->left=NULL;
        t->right=NULL;
        buildtree(t->left);
        buildtree(t->right);
    }
}
treenode* findParent(treenode* T,int x){
    if(T == NULL){
        return NULL;
    }
    if((T->left !=NULL && T->left->data ==x)||(T->right != NULL && T->right->data == x)) {
        return T;
    }
    treenode *parent =findParent(T->left, x);
    if(parent != NULL) {
        return parent;
    }
    parent = findParent(T->right, x);
    return parent;
}
int main(){
    tree t;
    buildtree(t);
    cout << findParent(t,'E')->data;
}


