#include <cstdio>
#include <string>
#include <stack>
#include <algorithm>

using namespace std;
const int maxn = 30;
int pre[maxn];
int post[maxn];
int in[maxn];
int n; //结点总个数

struct node{
    int data;
    node* lChild;
    node* rChild;
};

node* create(int preL, int preR, int inL, int inR){
    if(preL > preR){
        return nullptr;
    }
    node* root = new node;
    root -> data = pre[preL];
    int k;
    //遍历中序序列数组，找到域当前根结点点数据域相等的结点
    for(k = inL; k <= inR; k++){
        if(root -> data == in[k])
            break;
    }
    int numLeft = k - inL; //当前结点左子树结点个数
    root -> lChild = create(preL + 1, preL + numLeft, inL, k - 1);
    root -> rChild = create(preL + numLeft + 1, preR, k + 1, inR);
    return root;
}

int num = 0;
void postOrder(node* root){
    if(root == nullptr)
        return;

    postOrder(root -> lChild);
    postOrder(root -> rChild);
    printf("%d", root -> data);
    num++;
    if(num != n)
        printf(" ");
}

int main(){

    stack<int> st;
    int x, preIndex = 0, inIndex = 0; //入栈元素, 先序序列位置， 中序序列位置
    char str[5]; //用来存放输入的
    scanf("%d", &n);
    //出栈入栈次数共2n次
    for(int i = 0; i < 2 * n; i++){
        scanf("%s", str);
        if(strcmp(str, "Push") == 0){
            scanf("%d", &x);
            st.push(x);
            pre[preIndex++] = x;
        }
        else{
            in[inIndex++] = st.top();
            st.pop();
        }
    }
    node* root = create(0, n - 1, 0, n - 1);
    postOrder(root);
    return 0;
}
