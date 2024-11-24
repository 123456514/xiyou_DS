// 假设某非空二叉树以二叉链表作为存储结构，请设计算法打印该二叉树中第k层上的所有结点
#include<iostream>
#include <stack>
#include <queue>

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
void find_node_data_level(treenode * root,int h){
    if(root == NULL) return;
    queue<treenode *> nodeQueue;
    nodeQueue.push(root);
    while(!nodeQueue.empty()){
        int size = nodeQueue.size();
        h--;
        if(h==0 && !nodeQueue.empty()){
            for(int i=0;i<size;i++){
                cout << nodeQueue.front()->data;
                nodeQueue.pop();
            }
            return;
        }
        for(int i=0;i<size;i++){
            treenode * node = nodeQueue.front();
            nodeQueue.pop();
            if(node->left) nodeQueue.push(node->left);
            if(node->right) nodeQueue.push(node->right);
        }
    }
}