// 在二叉树中找到节点 x 并且输出x 的所有孩子节点
#include<iostream>
#include <stack>
#include <queue>

using namespace std;
typedef struct treenode{
    char data;
    struct treenode *left,*right;
}treenode,*tree;
// 创建二叉树
void buildtree(tree &t){
    char ch;
    ch=getchar();
    if(ch=='#') t=NULL;
    else{
        t=(treenode *)malloc(sizeof(treenode));
        t->data=ch;
        t->left=NULL;
        t->right=NULL;
        buildtree(t->left);
        buildtree(t->right);
    }
}
treenode * find_x_tree(treenode *root,char ch){
    queue<treenode *> nodeQueue;
    nodeQueue.push(root);
    while(!nodeQueue.empty()){
        int size = nodeQueue.size();
        for(int i = 0;i < size;i++){
            treenode *node = nodeQueue.front();
            if(node->data == ch){
                return node;
            }
            nodeQueue.pop();
            if(node->left) nodeQueue.push(node->left);
            if(node->right) nodeQueue.push(node->right);
        }
    }
    return NULL;
}
void func(treenode *root){
    if(root == NULL) return;
    cout << root->data << " ";
    func(root->left);
    func(root->right);
}
int main(){
    tree t;
    buildtree(t);
    treenode * node = find_x_tree(t,'C');
    func(node);
}