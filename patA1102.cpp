#include <cstdio>
#include <queue>
#include <algorithm>
using namespace std;
const int maxn = 50;

struct node{
    int lChild, rChild;
}Node[maxn];


bool notRoot[maxn] = {false};
int n; // 结点个数

int strToNum(char c){ //实现两个功能，一是字符转数字
    if(c == '-')
        return -1;
    else{
        notRoot[c - '0'] = true;  //二是将输入过的数字在notRoot[]里标记为true表示不是root
        return c - '0';
    }

}

int findRoot(){ //经过strToNum(), 输入的n个结点出了root都被标记为true
    for(int i = 0; i < n; i++){
        if(!notRoot[i]){
            return i;
        }
    }
}

int num;
void print(int now){
    printf("%d", now);
    num++;
    if(num < n)
        printf(" ");
    else
        printf("\n");
}


void BST(int root){
    queue<int> q;
    q.push(root);
    num = 0;
    while(!q.empty()){
        int now = q.front();
        q.pop();
        print(now);
        if(Node[now].lChild != -1) q.push(Node[now].lChild);
        if(Node[now].rChild != -1) q.push(Node[now].rChild);
    }
}
void inOrder(int root){
    if(root == -1){
        return;
    }
    inOrder(Node[root].lChild);
    num = 0;
    print(root);
    inOrder(Node[root].rChild);
}

void invertByPostOrder(int root){
    if(root == -1){
        return;
    }
    invertByPostOrder(Node[root].lChild);
    invertByPostOrder(Node[root].rChild);
    swap(Node[root].lChild, Node[root].rChild);
}

int main(){
    scanf("%d", &n);
    char lChild, rChild;
    for(int i = 0; i < n; i++){ //根据输入数据构建二叉树，第一份数据储存在Node[0]里，依此类推
        scanf("%*c%c %c", &lChild, &rChild);
        Node[i].lChild = strToNum(lChild);
        Node[i].rChild = strToNum(rChild);
    }

    int root = findRoot();      //找到根结点
    invertByPostOrder(root);    //通过后序遍历反转二叉树
    BST(root);                  //层序遍历
    inOrder(root);              //中序遍历
    return 0;
}
