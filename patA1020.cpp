#include <cstdio>
#include <queue>
#include <algorithm>
using namespace std;
const int maxn = 50;
struct node{
    int data;
    node* lChild;
    node* rChild;
};
int in[maxn];
int post[maxn];
int n;

node* create(int postL, int postR, int inL, int inR){
    if(postL > postR){
        return nullptr; //  后序序列长度小于0时返回
    }
    node* root = new node;  //创建一个新节点用来存放二叉树的根节点
    root -> data = post[postR]; //根节点的数据域为根节点的值
    int k;
    for(k = inL; k <= inR; k++){
        if(in[k] == post[postR]){
            break;
        }
    }
    int numLeft = k - inL; //左子树结点的个数
    root -> lChild = create(postL, postL + numLeft - 1, inL, k - 1);  //返回左子🌲的根结点地址
    root -> rChild = create(postL + numLeft, postR - 1, k + 1, inR);  //返回右子🌲的根结点地址
    return root;  //返回根节点地址

}


int num = 0; //已输出节点的个数
void BFS(node* root){
    queue<node*> q; //队列中存储的是地址
    q.push(root); //根结点地址入队
    while(!q.empty()){
        node* now = q.front(); //取出队首元素
        q.pop();
        printf("%d", now -> data);//访问队首元素
        num++;
        if(num < n) printf(" ");
        if(now -> lChild != nullptr)    q.push(now -> lChild);
        if(now -> rChild != nullptr)    q.push(now -> rChild);
    }
}
int main(){
    scanf("%d", &n);
    for(int i = 0; i < n; i++ ){
        scanf("%d", &post[i]);
    }
    for(int j = 0; j < n; j++){
        scanf("%d", &in[j]);
    }
    node* root = create(0, n - 1, 0, n - 1); //建树
    BFS(root);  //层序遍历
    return 0;
}
