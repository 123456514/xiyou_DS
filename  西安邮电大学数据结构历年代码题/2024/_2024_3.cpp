#include <stdio.h>
#include <stdlib.h>

// 假设图中最多有10个顶点，可根据实际情况调整
#define MAX 10

// 假设顶点数据类型为int，你可根据实际情况修改
typedef int VertexData;

// 边表节点结构体
typedef struct ArcNode {
    int adjvex;
    struct ArcNode *nextarc;
} ArcNode;

// 顶点表节点结构体
typedef struct node {
    VertexData data;
    ArcNode *firstarc;
} VertexNode;

// 图的邻接表结构体
typedef struct {
    VertexNode vertex[MAX];
} Adject;

// 标记顶点是否被访问过，初始化为false表示未访问
bool visited[MAX];

// 深度优先搜索函数，用于判断是否存在从start顶点到end顶点的路径
bool dfs(Adject graph, int start, int end) {
    // 如果当前顶点就是目标顶点，说明找到了路径，返回true
    if (start == end) return true;
    visited[start] = true;
    ArcNode *p = graph.vertex[start].firstarc;
    while (p!= NULL) {
        int adj_vertex = p->adjvex;
        if (!visited[adj_vertex]) {
            if (dfs(graph, adj_vertex, end)) return true;
        }
        p = p->nextarc;
    }
    return false;
}

// 判断图中顶点vi到顶点vj是否存在路径的函数
bool hasPath(Adject graph, int vi, int vj) {
    // 初始化访问标记数组为false
    for (int i = 0; i < MAX; i++) {
        visited[i] = false;
    }
    return dfs(graph, vi, vj);
}

// 简单构建一个示例图的函数，这里手动构建一个简单的连通图用于测试
void createSampleGraph(Adject *graph) {
    // 初始化顶点数据，这里简单赋值为顶点编号，实际可按需求设置
    for (int i = 0; i < 4; i++) {
        graph->vertex[i].data = i;
        graph->vertex[i].firstarc = NULL;
    }

    // 添加边，构建示例连通图
    ArcNode *node1 = (ArcNode *)malloc(sizeof(ArcNode));
    node1->adjvex = 1;
    node1->nextarc = graph->vertex[0].firstarc;
    graph->vertex[0].firstarc = node1;

    ArcNode *node2 = (ArcNode *)malloc(sizeof(ArcNode));
    node2->adjvex = 2;
    node2->nextarc = graph->vertex[0].firstarc;
    graph->vertex[0].firstarc = node2;

    ArcNode *node3 = (ArcNode *)malloc(sizeof(ArcNode));
    node3->adjvex = 0;
    node3->nextarc = graph->vertex[1].firstarc;
    graph->vertex[1].firstarc = node3;

    ArcNode *node4 = (ArcNode *)malloc(sizeof(ArcNode));
    node4->adjvex = 2;
    node4->nextarc = graph->vertex[1].firstarc;
    graph->vertex[1].firstarc = node4;

    ArcNode *node5 = (ArcNode *)malloc(sizeof(ArcNode));
    node5->adjvex = 0;
    node5->nextarc = graph->vertex[2].firstarc;
    graph->vertex[2].firstarc = node5;

    ArcNode *node6 = (ArcNode *)malloc(sizeof(ArcNode));
    node6->adjvex = 1;
    node6->nextarc = graph->vertex[2].firstarc;
    graph->vertex[2].firstarc = node6;

    ArcNode *node7 = (ArcNode *)malloc(sizeof(ArcNode));
    node7->adjvex = 3;
    node7->nextarc = graph->vertex[2].firstarc;
    graph->vertex[2].firstarc = node7;

    ArcNode *node8 = (ArcNode *)malloc(sizeof(ArcNode));
    node8->adjvex = 2;
    node8->nextarc = graph->vertex[3].firstarc;
    graph->vertex[3].firstarc = node8;
}

int main() {
    Adject graph;
    createSampleGraph(&graph);

    // 测试存在路径的情况
    int vi = 0;
    int vj = 3;
    if (hasPath(graph, vi, vj)) {
        printf("顶点 %d 到顶点 %d 存在路径\n", vi, vj);
    } else {
        printf("顶点 %d 到顶点 %d 不存在路径\n", vi, vj);
    }

    // 测试不存在路径的情况（修改顶点使其不存在路径，可根据实际图结构调整）
    vi = 0;
    vj = 5;
    if (hasPath(graph, vi, vj)) {
        printf("顶点 %d 到顶点 %d 存在路径\n", vi, vj);
    } else {
        printf("顶点 %d 到顶点 %d 不存在路径\n", vi, vj);
    }

    return 0;
}