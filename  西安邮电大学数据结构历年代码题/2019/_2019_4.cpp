// 现在二叉树有k层，此时要在这k层中找到第h层的节点、
#include<iostream>
#include<queue>
using namespace std;
typedef struct treenode{
    char data;
    struct treenode *left,*right;
}treenode,*tree;
void buildtree(tree &t){
    char ch;
    ch=getchar();
    if(ch=='#') return;
    else{
        t=(treenode*) malloc(sizeof (treenode));
        t->data=ch;
        t->left=NULL;
        t->right=NULL;
        buildtree(t->left);
        buildtree(t->right);
    }
}
int find_node_data_level_count(treenode * root,int h){
    if(root == NULL) return 0;
    queue<treenode *> nodeQueue;
    nodeQueue.push(root);
    while(!nodeQueue.empty()){
        int size = nodeQueue.size();
        h--;
        if(h==0){
            return size;
        }
        for(int i=0;i<size;i++){
            treenode * node = nodeQueue.front();
            nodeQueue.pop();
            if(node->left) nodeQueue.push(node->left);
            if(node->right) nodeQueue.push(node->right);
        }
    }
    return -1;
}
int main(){

}