#include<iostream>
#include<queue>
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
// 假设二叉树以二叉链表作为存储结构，设计算法求解非空二叉树中值x的阶段所在的层次
int find_x_level(treenode * root,char x){
    if(root == NULL) return -1;
    queue<treenode *> nodeQueue;
    nodeQueue.push(root);
    int count = 0;
    while(!nodeQueue.empty()){
        int size = nodeQueue.size();
        count++;
        for(int i=0;i<size;i++){
            treenode * node = nodeQueue.front();
            nodeQueue.pop();
            if(node->data == x){
                return count;
            }
            if(node->left) nodeQueue.push(node->left);
            if(node->right) nodeQueue.push(node->right);
        }
    }
    return -1;
}