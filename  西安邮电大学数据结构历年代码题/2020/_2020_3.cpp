// 得到一颗二叉树的高度
#include<iostream>
using namespace std;
typedef struct treenode{
    char data;
    struct treenode *lchild,*rchild;
}treenode,*tree;
void buildtree(tree &t){
    char ch;
    ch=getchar();
    if(ch=='#') return;
    else{
        t=(treenode*) malloc(sizeof (treenode));
        t->data=ch;
        t->rchild=NULL;
        t->lchild=NULL;
        buildtree(t->lchild);
        buildtree(t->rchild);
    }
}
// 算法思想：其实就是左子树的高度和右子树的高度的最大值+1 递归的计算出左右子树的高度，然后最大值1
int get_height(tree &t){
    if(t==NULL) return 0;
    int l_height= get_height(t->lchild);
    int r_height= get_height(t->rchild);
    return max(l_height,r_height)+1;
}
int main(){
    tree t;
    buildtree(t);
    cout<<get_height(t);
}