#include <iostream>
#include <stack>

using namespace std;

struct Btnode {
    Btnode(int data_ = 0) : 
        data(data_), lchild(NULL), rchild(NULL) { }

    int data;
    Btnode *lchild;
    Btnode *rchild;
};

//约定 -1 为空结点
Btnode *initBinaryTree(const int elements[], const int size, int begin = 0) {
    if (begin < 0 || begin >= size || elements[begin] == -1)
        return NULL;

    Btnode *node = new Btnode(elements[begin]);
    node->lchild = initBinaryTree(elements, size, 2*begin+1);
    node->rchild = initBinaryTree(elements, size, 2*begin+2);
    cout << "node:" << node->data << " leftchild:"; 
    if (node->lchild != NULL)
        cout <<  node->lchild->data;
    else
        cout << " null";

    if (node->rchild != NULL) 
        cout << " rightchild:" << node->rchild->data << endl;
    else
        cout << " null" << endl;
    return node;
}

void postorderByRecursion(const Btnode *root) {
    if (root == NULL) return ;
    postorderByRecursion(root->lchild);
    postorderByRecursion(root->rchild);
    cout << root->data << " ";
}

void deleteBinaryTree(const Btnode *root) {
    if (root == NULL) return ;
    deleteBinaryTree(root->lchild);
    deleteBinaryTree(root->rchild);
    delete root;
}

/*
 * 后序遍历只用单个栈的思路：
 * 使用一个变量记录前一个遍历的结点
 * 然后每次沿着左子树压栈，当pre == stk.top->lchild 时，改压top右子树同样也沿着左边压栈
 * 当pre == stk.top->rchild时，遍历top，并pop
 */

void postorderByStack(const Btnode *root) {
    const Btnode *previous = NULL;
    const Btnode *pushnode = NULL;
    stack<const Btnode *> stk;
    
    pushnode = root;
    do {
        while(pushnode!=NULL) {
            stk.push(pushnode); 
            pushnode = pushnode->lchild;
        }
        const Btnode *node = stk.top();
        
        if (node->rchild == previous || (node->rchild == NULL && node->lchild == previous) || (!node->rchild && !node->lchild)) {
            cout << node->data << " ";
            stk.pop();
            previous = node;
            pushnode = NULL;
        }else if (node->lchild == previous) {
            pushnode = node->rchild;
            continue;
        }
    }while(!stk.empty());
}

int main() {
    int btArr[9] = {1, 2, 3, 4, -1, 6, 7, -1, 9};
    Btnode *root = initBinaryTree(btArr, 9);
    postorderByRecursion(root);
    cout << endl << "begin postorder by stack :" << endl;
    postorderByStack(root);
    cout << endl;
    deleteBinaryTree(root);
    return 0;
}
