// 后序遍历逆序序列
#include<iostream>
using namespace std;
typedef struct treenode{
    char data;
    struct treenode *left,*right;
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
        t->left=NULL;
        t->right=NULL;
        buildtree(t->left);
        buildtree(t->right);
    }
}
void behand_order_reverse(treenode *root){
    if(root==NULL) return;
    behand_order_reverse(root->right);
    behand_order_reverse(root->left);
    cout<<root->data;
}
int main(){
    tree t;
    buildtree(t);
    behand_order_reverse(t);
    return 0;
}

