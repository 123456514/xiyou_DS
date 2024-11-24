// ͼ md�ĵ�
#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

// ����ͼ�ṹ�壨��ʾ�⣬����ʵ��������ƣ�
struct Graph {
    int vexnum;  // �������
    vector<int> *adj;  // �ڽӱ�
};

// ��ȡ����v�ĵ�һ���ڽӶ��㣬���ض����ţ���û���򷵻� -1
int FirstAdjVertex(Graph g, int v) {
    if (g.adj[v].size() > 0) {
        return g.adj[v][0];
    }
    return -1;
}

// ��ȡ����w�����ڽӱ��е���һ���ڽӶ��㣬���ض����ţ���û���򷵻� -1
int NextAdjVertex(Graph g, int w) {
    // ����������к��ʵķ�ʽ��ȡ��һ���ڽӶ��㣬ʾ���м򵥷��� -1
    return -1;
}
// ���������������
void dfs(Graph g, int v0, int &Vnum, int &Enum, int visited[]) {
    cout << "���ʶ���: " << v0 << endl;  // �������ʾ�����˸ö��㣬�ɸ��������
    visited[v0] = true;  // ��������� v0Ϊtrue ��ʾ�ö����Ѿ������ʹ���
    Vnum++;
    int w = FirstAdjVertex(g, v0);  // ���ڽӱ��з��ʴ�ʱv0���ڵ��ڽӱ���������һ���������ֵ
    while (w!= -1) {
        if (w > v0) {  // �򵥷�ʽ�����ظ�ͳ��ͬһ���ߣ�����ͼ�߻��ظ����֣�
            Enum++;
        }
        if (!visited[w]) {  // ����������û�б����ʣ���ô�ͽ��еݹ�
            dfs(g, w, Vnum, Enum, visited);
        }
        w = NextAdjVertex(g, w);  // ������һ�������е���һ�����㡣
    }
}

// �ж�ͼ�Ƿ�Ϊ��
int isTree(Graph &g) {
    int Vnum = 0;  // ��ʾ���Ƕ���ĸ���
    int Enum = 0;  // ��ʾ���Ǳߵĸ���
    bool visited[g.vexnum];
    memset(visited, 0, sizeof(visited));
    // ѡ�񶥵�0��Ϊ��ʼ���������������������ɸ���ʵ�ʵ���
    dfs(g, 0, Vnum, Enum, visited);
    // ���������Ŀ��ͬ���ұߵ��������ڶ����� - 1
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
    // ��������ֶ����һЩ��������ͼʾ����ʵ�ʸ����������Ʊߵ�����߼�
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
        cout << "��ͼ��һ����" << endl;
    } else {
        cout << "��ͼ����һ����" << endl;
    }

    delete[] g.adj;
    return 0;
}