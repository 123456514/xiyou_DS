// 二叉树 统计度为2的节点
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
int get_node_count_two(treenode *root){
    if(root == NULL) return 0;
    if(root->right!=NULL && root->left!=NULL) return count+=1;
    get_node_count_two(root->left);
    get_node_count_two(root->right);
    return 0;
}
int main(){
    tree t;
    buildtree(t);
    cout<<get_node_count_two(t);
    return 0;
}