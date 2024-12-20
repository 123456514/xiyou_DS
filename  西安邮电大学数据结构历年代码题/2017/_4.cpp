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
int count = 0;
// 统计二叉树中叶子节点值等于x的节点数目
int get_node_count_x(treenode *root,char x){
    if(root == NULL) return 0;
    if(root->right==NULL && root->left==NULL && root->data==x) return count+=1;
    get_node_count_x(root->left,x);
    get_node_count_x(root->right,x);
    return 0;
}
int main(){
    tree t;
    buildtree(t);
     cout <<get_node_count_x(t,'B');
    return 0;
}
