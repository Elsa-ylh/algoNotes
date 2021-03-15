#include <cstdio>
#include <queue>
using namespace std;

struct node{
    int x, y;
}Node;  //结点的横纵坐标

const int maxn = 100;
int matrix[maxn][maxn]; //1 0 矩阵
bool inQueue[maxn][maxn] = {false}; //标记某点是否入过队

int n, m; //n代表行数， m代表列数
int X[4] = {1, -1, 0, 0};
int Y[4] = {0, 0, 1, -1};   //便于坐标偏移

bool judge(int x, int y){
    if(x < 0 || x >= n || y < 0 || y >= m)  //下标不合法时return false
        return false;
    if(matrix[x][y] == 0 || inQueue[x][y])  //值为0的点不访问， 已经入队的不访问
        return false;
    return true;
}

void BFS(int x, int y){
    queue<node> Q;
    Node.x = x, Node.y = y;
    Q.push(Node);
    inQueue[x][y] = true;
    while(!Q.empty()){
        node top = Q.front();
        Q.pop();
        for(int i = 0;i < 4; i++){  //试探上下左右的坐标是否需要访问
//            int inX = x + X[i];
//            int inY = y + Y[i];   //第一个错误：坐标偏移是针对队头元素， 不是针对传进来的x和y
            int newX = top.x + X[i];
            int newY = top.y + Y[i];
//            Node.x = inX, Node.y = inY;
//            Q.push(Node);
//            inQueue[inX][inY] = true; //第二个错误：对于得到的偏移结点，首先检查其是否有访问的必要
            if(judge(newX, newY)){  //如果可以访问就入队
                Node.x = newX, Node.y = newY;
                Q.push(Node);
                inQueue[newX][newY] = true;
            }
        }
    }
}
int main(){
    int ans = 0; //1的块数
    scanf("%d%d", &n, &m);
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            scanf("%d", &matrix[i][j]);
        }
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(matrix[i][j] == 1 && !inQueue[i][j]){    //只对值为1的点和尚未入队的点进行BFS
                ans++;  //1块数加一
                BFS(i, j);
            }
        }
    }
    printf("%d\n", ans);
    return 0;
}
