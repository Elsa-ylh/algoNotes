//二叉树的四种遍历方法
//二叉树的先序遍历
void preOrder(node* root){
    if(root == nullptr){
        return;
    }
    printf("%d\n", root -> data);
    preOrder(root -> lChild);
    preOrder(root -> rChild);
}
//二叉树的中序遍历
void inOrder(node* root){
    if(root == nullptr){
        return;
    }
    inOrder(root -> lChild);
    printf("%d\n", root -> data);
    inOrder(root -> rChild);
}
//二叉树的后序遍历
void postOrder(node* root){
    if(root == nullptr){
        return;
    }
    postOrder(root -> lChild);
    postOrder(root -> rChild);
    printf("%d\n", root -> data);
}
//二叉树的层次遍历
void layerOrder(node* root){
    queue<node*> q;
    q.push(root);
    while(!q.empty()){
        node* now = q.front();
        q.pop();
        printf("%d\n", now -> data);
        if(now -> lChild != nullptr)    q.push(now -> lChild);
        if(now -> rChild != nullptr)    q.push(now -> rChild);
    }

}

//层次遍历时要求计算每个结点所处于的层次
struct nodes{
    int data;
    int layer;
    nodes* lChild;
    nodes* rChild;
};
void layerOrderWithLayer(nodes* root){
    queue<nodes*> q;
    root -> layer = 1;
    q.push(root);
    while(!q.empty()){
        nodes* now = q.front();
        q.pop();
        printf("%d\n", now -> data);
        if(now -> lChild != nullptr){
            now -> lChild -> layer = now -> layer + 1;
            q.push(now -> lChild);
        }
        if(now -> rChild != nullptr){
            now -> rChild ->layer = now -> layer + 1;
            q.push(now -> rChild);
        }
    }
}
//先序序列与中序序列构建二叉树
//当前先序序列区间为【preL, preR], 中序序列区间为【inL, inR]，返回根节点地址
int pre[10] = {0};
int in[10] = {0};
node* create(int preL, int preR, int inL, int inR){
    if(preL > preR){
        return nullptr;
    }   //先序序列长度小于0时，直接返回
    node* root = new node;
    root -> data = pre[preL];
    int k;
    for(k = inL; k < inR; k++){
        if(in[k] == pre[preL]){
            break;
        }
    }
    int numLeft = k - inL;
    root -> lChild = create(preL + 1, preL   + numLeft, inL, k - 1);
    root -> rChild = create(preL + numLeft + 1, preR, k + 1, inR );
    return root;
}
