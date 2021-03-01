
//二叉链表的定义
struct node{
    int data;
    node* lChild;
    node* rChild;
};

//初始化
node* root = nullptr;

//新建结点
node* newNode(int v){
    node* Node = new node;
    Node -> data = v;
    Node -> lChild = Node -> rChild = nullptr;
    return Node;
}

//查找并修改数据
void search(node* root, int x, int newData){
    if(root == nullptr){
        return;
    }
    if(root -> data == x){
        root -> data = newData;
    }
    search(root -> lChild, x, newData);
    search(root -> rChild, x, newData);
}

//二叉树结点的插入
void insert(node* &root, int x){
    if(root == NULL){
        root = newNode(x);
        return;
    }
    if(按二叉树的性质应该插在左子树){
        insert(root -> lChild, x);
    }else{
        insert(root -> rChild, x);
    }
}
//二叉树的创建
node* Create(int data[], int n){
    node* root = nullptr;
    for(int i = 0; i < n; i++){
       insert(root, data[i]); 
    }
    return root;
}
