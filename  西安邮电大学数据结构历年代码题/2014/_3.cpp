// 求二叉树高度
#include<iostream>
#include <stack>

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
// 算法思想：其实就是左子树的高度和右子树的高度的最大值+1 递归的计算出左右子树的高度，然后最大值1
int get_height(tree &t){
    if(t==NULL) return 0;
    int l_height= get_height(t->left);
    int r_height= get_height(t->right);
    return max(l_height,r_height)+1;
}