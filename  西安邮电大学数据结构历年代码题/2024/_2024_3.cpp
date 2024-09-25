//  若连通图以邻接表方式进行存储，请设计算法判断在该图中定点v1到vj之间是否存在一条路径
#include<iostream>
using namespace std;
#define MAX 10;
typedef struct ArcNode{
    int adjvex;
    struct ArcNode *nextarc;
}ArcNode;
typedef struct node{
    int data;
    ArcNode *firstarc;
}VertexNode;
typedef struct{
    VertexNode vertex[MAX];
}AdjList;
int main(){
    return 0;
}