const int maxn = 30;
//二叉树的静态实现
struct node{
    int data;
    int lChild;
    int rChild;
}Node[maxn];

int nodeIndex = 0;
int newNode(int v){
    Node[nodeIndex].data = v;
    Node[nodeIndex].lChild = -1;
    Node[nodeIndex].rChild = -1;
    return nodeIndex++;
}

void search(int root, int x, int newData){
    if(root == -1){ //root为根节点在数组中的下标
        return;
    }
    if(Node[root].data == x)
    {
        Node[root].data = newData;
    }
    search(Node[root].lChild, x, newData);
    search(Node[root].rChild, x, newData);
}

void insert(int &root, int x){
    if(root == -1){
        root = newNode(x);
        return;
    }
    if(根据性质应该插在左子树){
        insert(Node[root].lChild, x);
    }else{
        insert(Node[root].rChild, x);
    }
}
//二叉树的建立， 函数返回根结点root的下标
int Creat(int data[], int n) {
    int root = -1;
    for (int i = 0; i < n; i++) {
        insert(root, data[i]);
    }
    return root;    //返回二叉树的根节点下标
}

//先序遍历
void preOrder(int root){
    if(root == -1){
        return;
    }
    printf("%d\n", Node[root].data);
    preOrder(Node[root].lChild);
    preOrder(Node[root].rChild);
}
//中序遍历
void inOrder(int root){
    if(root == -1){
        return;
    }
    inOrder(Node[root].lChild);
    printf("%d\n", Node[root].data);
    inOrder(Node[root].rChild);
}
//后序遍历
void postOrder(int root){
    if(root == -1){
        return;
    }
    postOrder(Node[root].lChild);
    postOrder(Node[root].rChild);
    printf("%d\n", Node[root].data);
}
//层序遍历
void layerOrder(int root){
    queue<int> q;
    q.push(root); //根节点地址入队
    while(!q.empty()){
        int now = q.front();
        q.pop();
        printf("%d ", Node[now].data);
        if(Node[now].lChild != -1) q.push(Node[now].lChild);
        if(Node[now].rChild != -1) q.push(Node[now].rChild);
    }
}
