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

int main() {
    int btArr[9] = {1, 2, 3, 4, -1, 5, 6, -1, 7};
    Btnode *root = initBinaryTree(btArr, 9);
    return 0;
}
