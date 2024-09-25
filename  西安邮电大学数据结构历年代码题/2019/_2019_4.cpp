// 现在二叉树有k层，此时要在这k层中找到第h层的节点、
#include<iostream>
using namespace std;
typedef struct treenode{
    char data;
    struct treenode *lchild,*rchild;
}treenode,*tree;
void buildtree(tree &t){
    char ch;
    ch=getchar();
    if(ch=='#') return;
    else{
        t=(treenode*) malloc(sizeof (treenode));
        t->data=ch;
        t->rchild=NULL;
        t->lchild=NULL;
        buildtree(t->lchild);
        buildtree(t->rchild);
    }
}
// 创建队列
// 入队
// 出队
// 得到队列中的元素个数
// 算法思想: 这里使用到 队列，就是首先在队列中添加一个节点，然后出这个节点，再把这个结点的左右孩子都入队，
// 并且要知道队列中有多少个节点，这里用于添加下一层二叉树节点，在一层都出队之后就把h-1，知道第h层，然后打印出第h层的节点
void get_h_nodes(tree &root,int h){

}
int main(){

}