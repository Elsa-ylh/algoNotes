#include <cstdio>
#include <algorithm>
#include <climits>


using namespace std;
//PAT1030 Travel Plan dijkstra + DFS implementing with matrix


const int MAXN = 510;   //the highest limit of index number
const int INF = INT_MAX; //infinity integer

//n is number of vertex, m is number of edge
//st: start  ed: end
//G[][] is matrix of distance, cost[][] is matrix of cost
//d[] is the record of the shortest distance and c[] is the record of the lowest cost
int n, m, st, ed, G[MAXN][MAXN], cost[MAXN][MAXN];
int d[MAXN], c[MAXN], pre[MAXN];

bool vis[MAXN] = {false};   //"vis[i] == true" means vertex i has been visited

void Dijkstra(int s){   //"s" is where the path is from
    fill(d, d + MAXN, INF);
    fill(c, c + MAXN, INF);
    for(int i = 0; i < n; i++) {
        pre[i] = i;
    }
    d[s] = 0;   //the distance from vertex s to vertex x is 0
    c[s] = 0;   //the cost from vertex s to vertex x is 0
    for(int i  = 0; i < n; i++){    //everytime find a shortest path from st to vertex i
        int u = -1, MIN = INF;  //d[u] is the lowest number of array d[], u is the index and MIN records d[u]
        for(int j = 0; j < n; j++){ //find a MIN from those vertexes that haven't been visited
            if(!vis[j] && d[j] < MIN){
                u = j;
                MIN = d[j];
            }
        }
        if(u == -1) return;
        vis[u] = true;
        for(int v = 0; v < n; ++v){
            if((!vis[u]) && (G[u][v] != INF)){  //update the shortest path and the lowest cost
                if(d[u] + G[u][v] < d[v]){
                    d[v] = d[u] + G[u][v];
                    c[v] = c[u] + cost[u][v];
                    pre[v] = u;
                }else if(d[u] + G[u][v] == d[v]){   //if there are two paths with the same distance
                    if(c[u] + cost[u][v] < c[v]){   //choose the one that cost less
                        c[v] = c[u] + cost[u][v];
                        pre[v] = u;
                    }
                }
            }
        }
    }
}

void DFS(int v){    //print path with the shortest distance and the lowest cost
    if(v == st){
        printf("%d", v);
        return;
    }
    DFS(pre[v]);
    printf("%d", v);
}

int main(){
    //n is number of vertex, m is number of edge, st: start  ed: end
    scanf("%d%d%d%d", &n, &m, &st, &ed);
    int u, v;   //u: from  v: to
    fill(G[0], G[0] + MAXN * MAXN, INF);    //initialize the value of Graph, assume the distance is INF at the beginning
    fill(cost[0], cost[0] + MAXN * MAXN, INF);  //initialize the value of cost, same as above
    for(int i = 0; i < m; i++){
        scanf("%d%d", &u, &v);  //input where the current edge from(u) and to(v)
        scanf("%d%d", &G[u][v], &cost[u][v]);   //input the distance from u and v, and cost from u and v
        G[v][u] = G[u][v];
        cost[v][u] = cost[u][v];
    }
    Dijkstra(st);
    DFS(ed);
    printf("%d%d\n",d[ed], c[ed]);  //print the shortest distance and the lowest cost
    return 0;
}
