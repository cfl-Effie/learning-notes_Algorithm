/*
在蒜头君的国度里有N个城市,这N个城市间只有N-1条路把这个N个城市连接起来。现在,蒜头君在第S号城市,他有张该国地图,他想知道如果自己要去参观第
T号城市,必须经过的前一个城市是几号城市(假设你不走重复的路)。
输入格式
  第一行输入一个整数M表示测试数据共有M(1≤M≤5)组。
  每组测试数据的第一行输入一个正整数N(1≤N≤100000)和一个正整数S(1≤S≤N),N表示城市的总个数,S表示蒜头君所在城市的编号。
  随后的N-1行,每行有两个正整数a,b(1≤a,b≤N),表示第a号城市和第b号城市之间有一条路连通。
输出格式
  每组测试数据输N个正整数,其中,第i个数表示从S走到i号城市,必须要经过的上一个城市的编号。(其中i=S时,请输出-1)。
eg:
  in:
    1
    10 1
    1 9
    1 8
    8 10
    10 3
    8 6
    1 2
    10 4
    9 5
    3 7
  out:
    -1 1 10 10 9 8 3 1 1 8
  */
#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;

const int MAXN = 100005;

vector<int> graph[MAXN];
int parent[MAXN];

void bfs(int start, int n) {
    memset(parent, 0, sizeof(parent));
    queue<int> q;
    q.push(start);
    parent[start] = -1;  // 起点的父节点设为-1
    
    while (!q.empty()) {
        int current = q.front();
        q.pop();
        
        for (int neighbor : graph[current]) {
            if (parent[neighbor] == 0) {  // 未访问过
                parent[neighbor] = current;
                q.push(neighbor);
            }
        }
    }
}

int main() {
    int M;
    cin >> M;
    
    while (M--) {
        int N, S;
        cin >> N >> S;
        
        // 清空图
        for (int i = 1; i <= N; i++) {
            graph[i].clear();
        }
        
        // 构建图
        for (int i = 0; i < N - 1; i++) {
            int a, b;
            cin >> a >> b;
            graph[a].push_back(b);
            graph[b].push_back(a);
        }
        
        // BFS遍历
        bfs(S, N);
        
        // 输出结果
        for (int i = 1; i <= N; i++) {
            cout << parent[i];
            if (i < N) cout << " ";
        }
        cout << endl;
    }
    
    return 0;
}
