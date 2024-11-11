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
// 2012 二叉树层序遍历，同时统计二叉树中度为1的节点

// 2013 统计二叉树中度为1节点 改变条件
// if((root->right!=NULL&&root->left==NULL) || (root->right!=NULL && root->left!=NULL)) return count+=1;
int get_node_count_one(treenode *root){
    if(root == NULL) return 0;
    if((root->right!=NULL && root->left==NULL) || (root->right==NULL && root->left!=NULL)) return count+=1;
    get_node_count_one(root->left);
    get_node_count_one(root->right);
    return 0;
}
// 2014 得到二叉树的高度
// 算法思想：其实就是左子树的高度和右子树的高度的最大值+1 递归的计算出左右子树的高度，然后最大值1
int get_height(tree &t){
    if(t==NULL) return 0;
    int l_height= get_height(t->left);
    int r_height= get_height(t->right);
    return max(l_height,r_height)+1;
}
// 2015 输出二叉树后序遍历的逆序序列
void behand_order_reverse(treenode *root){
    if(root==NULL) return;
    behand_order_reverse(root->right);
    behand_order_reverse(root->left);
    cout<<root->data;
}
// 2016 统计二叉树中度为2的节点个数，其实就是非空节点 判断条件变一下
// if(root->right!=NULL && root->left!=NULL) return count+=1;
int get_node_count_two(treenode *root){
    if(root == NULL) return 0;
    if(root->right!=NULL && root->left!=NULL) return count+=1;
    get_node_count_two(root->left);
    get_node_count_two(root->right);
    return 0;
}
// 2017 统计二叉树中叶子节点是x的节点数目，其实就是加一个root.val==x而已
int get_node_count_x(treenode *root,char x){
    if(root == NULL) return 0;
    if(root->right==NULL && root->left==NULL && root->data==x) return count+=1;
    get_node_count_x(root->left,x);
    get_node_count_x(root->right,x);
    return 0;
}
// 2018 二叉树叶子节点  重复

// 2019 得到二叉树中第k层节点的个数
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
// 2020 二叉树高度 重复 2014

// 2021 判断二叉树是否是二叉排序树

// 2022 得到二叉树中一个数值为x的节点的双亲节点
// 方法一: 不使用递归的方法，第一步把二叉树中的节点放到一个数组中，但是这里开辟多大的数组空间这里是不知道的
treenode *find_parent_node_1(treenode * root,int x){
    treenode* temp[11]={0};
    int index = 0;
    queue<treenode *> nodeQueue;
    nodeQueue.push(root);
    while(!nodeQueue.empty()){
        int size = nodeQueue.size();
        for(int i=0;i<size;i++){
            treenode *node=nodeQueue.front();
            temp[index]=node;
            index++;
            nodeQueue.pop();
            if(node) nodeQueue.push(node->left);
            if(node) nodeQueue.push(node->right);
        }
    }
    // 在数组中找到x这个结点
    int j=0;
    for(int i=0;i<11;i++){
        if(temp[i] != NULL && temp[i]->data == x){
            j=i;
            break;
        }
    }
    if(j%2==0) return temp[j/2-1];
    else return temp[j/2];
}
// 方法二: 使用递归的方法
treenode* find_parent_node(treenode * root,int x){
    if(root == NULL) return NULL;
    if((root->right != NULL && root->data == x) || (root->left != NULL && root->data == x)){
        return root;
    }
    treenode* parent = find_parent_node(root->left,x);
    if(parent != NULL){
        return parent;
    }
    parent = find_parent_node(root->right,x);
    return parent;
 }
// 2023 得到二叉树中第k层的所有节点  重复 2019
// 得到第h 层的所有节点数据
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
// 2024 得到二叉树中值为x的节点所在的层数
// 层序遍历版本
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
// 得到二叉树中第k层的节点  层序遍历

int getnodecount(treenode *root){
    if(root == NULL) return 0;
    if(root->right==NULL && root->left==NULL) return count+=1;
    getnodecount(root->left);
    getnodecount(root->right);
    return 0;
}
// 二叉树递归先序遍历
void front_order(treenode *root){
    if(root==NULL) return;
    cout<<root->data;
    front_order(root->left);
    front_order(root->right);
}
// 二叉树递归中序遍历
void middle_order(treenode *root){
    if(root==NULL) return;
    middle_order(root->left);
    cout<<root->data;
    middle_order(root->right);
}
// 二叉树递归后序遍历
void behand_order(treenode *root){
    if(root==NULL) return;
    behand_order(root->left);
    behand_order(root->right);
    cout<<root->data;
}
// 二叉树层序遍历
void levelOrderIterative(treenode * root){
    if(root == NULL) return;
    queue<treenode *> nodequeue;
    nodequeue.push(root);
    while(!nodequeue.empty()){
        int size = nodequeue.size();
        for(int i=0;i<size;i++){
            treenode * node = nodequeue.front();
            cout <<node->data;
            nodequeue.pop();
            if(node->left != NULL) nodequeue.push(node->left);
            if(node->right != NULL) nodequeue.push(node->right);
        }
    }
}
// 二叉树非递归先序遍历
// 这里使用到栈
void preOrderIterative(treenode * root){
    if(root == NULL) return;
    stack<treenode *> nodestack;
    nodestack.push(root);
    while(!nodestack.empty()){
        treenode *node =nodestack.top();
        cout<<node->data;
        nodestack.pop();
        if(node->right != NULL) nodestack.push(node->right);
        if(node->left != NULL) nodestack.push(node->left);
    }
}
// 二叉树非递归中序遍历
void inOrderIterative(treenode *root){
    if(root == NULL) return;
    stack<treenode *> nodeStack;
    treenode *currentNode = root; // 表示的是记录的是当前节点
    while(currentNode || !nodeStack.empty()){
        // 把一棵树的左子树全部入栈
        while(currentNode){
            nodeStack.push(currentNode);
            currentNode = currentNode->left;
        }
        // 某个节点的左子树为空，那么此时的当前节点就是栈顶元素，输出栈顶元素
        // 并且把该元素从栈移除，接着遍历这个结点的右子树
        currentNode = nodeStack.top();
        cout << currentNode->data;
        nodeStack.pop();
        currentNode = currentNode->right;
    }
}
// 二叉树非递归后序遍历
void postOrderIterative(treenode * root){
    if(root == NULL) return;
    stack<treenode *> nodeStack;
    treenode *currentNode = root; // 维护一个当前节点指针
    treenode *visitedNode = root; // 保存上一次访问的节点，初始化为root
    while(currentNode || !nodeStack.empty()){
        while(currentNode){
            nodeStack.push(currentNode);
            currentNode=currentNode->left;
        }
        currentNode = nodeStack.top();
        // 如果此时当前节点的有孩子不为空，并且是没有被访问过的
        if(currentNode->right && currentNode->right != visitedNode){
            currentNode = currentNode->right;
        }else{
            // 如果此时的节点没有右孩子，或者右孩子已经被访问过了，那么此时就打印出该节点的数值，并且记录此时的当前节点为访问过的节点，记录当前节点为NULL，防止出现循环，把该节点移除栈
            cout << currentNode->data;
            visitedNode = currentNode;
            currentNode = NULL;
            nodeStack.pop();
        }
    }
}


// dfs版本
int main(){
    tree t;
    buildtree(t);
    cout << find_node_data_level_count(t,2);
    // cout <<find_x_level(t,'B');
    // cout<<get_node_count_x(t,'E');
    return 0;
}

