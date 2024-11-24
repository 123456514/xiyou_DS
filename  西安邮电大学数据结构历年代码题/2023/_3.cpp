// 设计算法判断一个无向图是否为连通图，并打印其连通分量个数，可以调用的dfs，bfs
// void dfs(Graph g,int v) 在无向图g中深度优先遍历v所有的连通子图
// void bfs(Graph g,int v) 在无向图g中广度优先遍历v所在的连通子图
#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

// 假设这里有Graph结构体定义以及dfs、bfs函数声明如下（实际中需要根据具体情况完善其定义）
// struct Graph{
//     int V;  // 顶点数量
//     vector<int> *adj;  // 邻接表
// };
// void dfs(Graph g, int v);
// void bfs(Graph g, int v);

// 判断无向图是否连通，并返回连通分量个数
int isConnected(Graph g) {
    int count = 0;
    int visited[g.V];
    memset(visited, 0, sizeof(visited));

    for (int v = 0; v < g.V; v++) {
        if (!visited[v]) {
            // 每调用一次dfs或者bfs代表从一个新的未访问过的连通分量中的节点开始遍历
            // 这里选择调用dfs，也可以调用bfs，逻辑类似
            dfs(g, v);
            // bfs(g, v);
            count++;
        }
    }
    return count;
}
int main() {
    // 这里假设你已经正确构建好了一个无向图g，例如
    // Graph g;
    // g.V = 5;
    // g.adj = new vector<int>[g.V];
    // 进行相应的边的添加等初始化操作
    int componentCount = isConnected(g);
    if (componentCount == 1) {
        cout << "该无向图是连通图" << endl;
    } else {
        cout << "该无向图不是连通图，连通分量个数为: " << componentCount << endl;
    }
    return 0;
}