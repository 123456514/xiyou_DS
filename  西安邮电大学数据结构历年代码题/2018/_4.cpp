// 已知二叉树以二叉链表方式存储，编写算法统计叶子结点的个数
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
int count;
int getnodecount(treenode *root){
    if(root == NULL) return 0;
    if(root->right==NULL && root->left==NULL) return count+=1;
    getnodecount(root->left);
    getnodecount(root->right);
    return 0;
}
int main(){
    tree t;
    buildtree(t);
    getnodecount(t);
    cout<<count;
    return 0;
}
