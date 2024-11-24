#include <stdio.h>
#include <stdlib.h>

// ����ͼ�������10�����㣬�ɸ���ʵ���������
#define MAX 10

// ���趥����������Ϊint����ɸ���ʵ������޸�
typedef int VertexData;

// �߱�ڵ�ṹ��
typedef struct ArcNode {
    int adjvex;
    struct ArcNode *nextarc;
} ArcNode;

// �����ڵ�ṹ��
typedef struct node {
    VertexData data;
    ArcNode *firstarc;
} VertexNode;

// ͼ���ڽӱ�ṹ��
typedef struct {
    VertexNode vertex[MAX];
} Adject;

// ��Ƕ����Ƿ񱻷��ʹ�����ʼ��Ϊfalse��ʾδ����
bool visited[MAX];

// ����������������������ж��Ƿ���ڴ�start���㵽end�����·��
bool dfs(Adject graph, int start, int end) {
    // �����ǰ�������Ŀ�궥�㣬˵���ҵ���·��������true
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

// �ж�ͼ�ж���vi������vj�Ƿ����·���ĺ���
bool hasPath(Adject graph, int vi, int vj) {
    // ��ʼ�����ʱ������Ϊfalse
    for (int i = 0; i < MAX; i++) {
        visited[i] = false;
    }
    return dfs(graph, vi, vj);
}

// �򵥹���һ��ʾ��ͼ�ĺ����������ֶ�����һ���򵥵���ͨͼ���ڲ���
void createSampleGraph(Adject *graph) {
    // ��ʼ���������ݣ�����򵥸�ֵΪ�����ţ�ʵ�ʿɰ���������
    for (int i = 0; i < 4; i++) {
        graph->vertex[i].data = i;
        graph->vertex[i].firstarc = NULL;
    }

    // ��ӱߣ�����ʾ����ͨͼ
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

    // ���Դ���·�������
    int vi = 0;
    int vj = 3;
    if (hasPath(graph, vi, vj)) {
        printf("���� %d ������ %d ����·��\n", vi, vj);
    } else {
        printf("���� %d ������ %d ������·��\n", vi, vj);
    }

    // ���Բ�����·����������޸Ķ���ʹ�䲻����·�����ɸ���ʵ��ͼ�ṹ������
    vi = 0;
    vj = 5;
    if (hasPath(graph, vi, vj)) {
        printf("���� %d ������ %d ����·��\n", vi, vj);
    } else {
        printf("���� %d ������ %d ������·��\n", vi, vj);
    }

    return 0;
}