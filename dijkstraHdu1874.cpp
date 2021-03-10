#include <iostream>
#include <cstdio>
#include <vector>
#include <cstring>
#include <queue>
#include <climits>

using namespace std;

const int MAXN = 200;
const int INF = INT_MAX;

struct Edge{
    int to;
    int length;
    Edge(int t, int l): to(t), length(l){}
};

vector<Edge> graph[MAXN];
int dis[MAXN];
bool visit[MAXN];

void Dijkstra(int start, int n){
    memset(visit, false, sizeof(visit));
    fill(dis, dis + n, INF);
    dis[start] = 0;
    for(int i = 0; i < n; ++i){ //需要n(vertex个数)次才能确定n个
        int u = -1;
        for(int j = 0; j < n; j++){ //找到最短路径已经确定的点
            if(visit[j]){
                continue;
            }
            if(u == -1 || dis[j] < dis[u]){
                u = j;
            }
        }
        for(int j = 0; j < graph[u].size(); ++j){   //基于新找到的结点u， 对以u为起点的其他结点依次进行松弛操作
            int vertex = graph[u][j].to;
            int distance = graph[u][j].length;
            if(dis[u] + distance < dis[vertex]){
                dis[vertex] = dis[u] + distance;
            }
        }
        visit[u] = true;    //点u放在心里已经确定最短路径的集合中
    }
    return;
}

int main(){
    int n, m;   //n个结点，m条边
    while(scanf("%d%d", &n, &m) != EOF){    //多组输入
        memset(graph, 0, sizeof(graph));
        while(m--){
            int from, to, length;
            scanf("%d%d%d", &from, &to, &length);
            graph[from].push_back(Edge(to, length));
            graph[to].push_back(Edge(from, length));
        }
        int start;
        int terminal;
        scanf("%d%d", &start, &terminal);
        Dijkstra(start, n);
        if(dis[terminal] == INF){
            dis[terminal] = -1;
        }
        printf("%d\n", dis[terminal]);
    }
}
