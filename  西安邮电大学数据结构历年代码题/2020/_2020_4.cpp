// 图 md文档
#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

// 定义图结构体（简单示意，根据实际情况完善）
struct Graph {
    int vexnum;  // 顶点个数
    vector<int> *adj;  // 邻接表
};

// 获取顶点v的第一个邻接顶点，返回顶点编号，若没有则返回 -1
int FirstAdjVertex(Graph g, int v) {
    if (g.adj[v].size() > 0) {
        return g.adj[v][0];
    }
    return -1;
}

// 获取顶点w在其邻接表中的下一个邻接顶点，返回顶点编号，若没有则返回 -1
int NextAdjVertex(Graph g, int w) {
    // 这里假设你有合适的方式获取下一个邻接顶点，示例中简单返回 -1
    return -1;
}
// 深度优先搜索函数
void dfs(Graph g, int v0, int &Vnum, int &Enum, int visited[]) {
    cout << "访问顶点: " << v0 << endl;  // 简单输出表示访问了该顶点，可根据需求改
    visited[v0] = true;  // 标记数组中 v0为true 表示该顶点已经被访问过了
    Vnum++;
    int w = FirstAdjVertex(g, v0);  // 在邻接表中访问此时v0所在的邻接表行数的下一个顶点的数值
    while (w!= -1) {
        if (w > v0) {  // 简单方式避免重复统计同一条边（无向图边会重复出现）
            Enum++;
        }
        if (!visited[w]) {  // 如果这个顶点没有被访问，那么就进行递归
            dfs(g, w, Vnum, Enum, visited);
        }
        w = NextAdjVertex(g, w);  // 进入这一行数据中的下一个顶点。
    }
}

// 判断图是否为树
int isTree(Graph &g) {
    int Vnum = 0;  // 表示的是顶点的个数
    int Enum = 0;  // 表示的是边的个数
    bool visited[g.vexnum];
    memset(visited, 0, sizeof(visited));
    // 选择顶点0作为起始顶点进行深度优先搜索，可根据实际调整
    dfs(g, 0, Vnum, Enum, visited);
    // 如果顶点数目相同并且边的条数等于顶点数 - 1
    if (Vnum == g.vexnum && Enum == g.vexnum - 1) {
        return 1;
    } else {
        return 0;
    }
}


int main() {
    Graph g;
    g.vexnum = 5;
    g.adj = new vector<int>[g.vexnum];
    // 这里假设手动添加一些边来构建图示例，实际根据需求完善边的添加逻辑
    g.adj[0].push_back(1);
    g.adj[0].push_back(2);
    g.adj[1].push_back(0);
    g.adj[1].push_back(3);
    g.adj[2].push_back(0);
    g.adj[2].push_back(4);
    g.adj[3].push_back(1);
    g.adj[4].push_back(2);

    int result = isTree(g);
    if (result == 1) {
        cout << "该图是一棵树" << endl;
    } else {
        cout << "该图不是一棵树" << endl;
    }

    delete[] g.adj;
    return 0;
}