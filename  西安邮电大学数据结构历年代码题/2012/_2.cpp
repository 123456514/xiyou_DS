// 编写算法输出二叉树的按层遍历序列，同统计该二叉树中度为1的节点个数，要求给出二叉树的定义
#include <iostream>
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
int level_search(treenode * root){
    if(root == NULL) return 0;
    int count = 0;
    queue<treenode *> queueNode;
    queueNode.push(root);
    while(!queueNode.empty()){
        int size = queueNode.size();
        for(int i=0;i<size;i++){
            treenode *node = queueNode.front();
            cout << node->data << " ";
            if((node->left != NULL && node->right == NULL) || (node->left == NULL && node->right != NULL)){
                count++;
            }
            queueNode.pop();
            if(node->left) queueNode.push(node->left);
            if(node->right) queueNode.push(node->right);
        }
    }
    return count;
}
 int main(){
     tree t;
     buildtree(t);
     cout << level_search(t);
}