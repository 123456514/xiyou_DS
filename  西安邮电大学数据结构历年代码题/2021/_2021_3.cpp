// 判断一颗二叉树是否是二叉排序树
#include<iostream>
using namespace std;
// 创建二叉树
#define Max 10;
bool isBST=true;
char temp='A';
typedef struct treenode{
    char data;
    struct treenode *lchild,*rchild;
}treenode,*tree;
// 创建二叉树
void buildtree(tree &t)
{
    char ch;
    ch=getchar();
    if(ch=='#') t=NULL;
    else
    {
        t=(treenode *)malloc(sizeof(treenode));
        t->data=ch;
        t->lchild=NULL;
        t->rchild=NULL;
        buildtree(t->lchild);
        buildtree(t->rchild);
    }
}
// 判断一棵树是否是二叉排序树
void is_BST(tree &t){
    if(t==NULL) return;
    //中序遍历二叉树，并且在遍历的过程中保证是依次上升的
    is_BST(t->lchild);
    if(t->data>=temp){
        temp=t->data;
    }else{
        isBST=false;
    }
    is_BST(t->rchild);
}
int main(){
    tree t;
    buildtree(t);
    is_BST(t);
    cout << isBST<<endl;
}