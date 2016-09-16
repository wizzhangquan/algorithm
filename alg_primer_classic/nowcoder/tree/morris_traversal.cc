#include <iostream>
#include "binary_tree.h"
#include "binary_tree.cc"

using namespace std;

/*
 * Mirros traversal
 * 非递归 不用stack 空间复杂度O(1) 时间复杂度O(2*n)
 * 利用叶子结点的空闲指针
 */

typedef Btnode<int> btnode;

inline void visit(const btnode *n) {
    cout << n->data_ << " ";
}

//发到当前结点的左子树的最右边的结点
const btnode *find_precursor(const btnode *node) {
    if (!node || !(node->lchild)) return NULL;

    const btnode *temp = node->lchild;
    while (temp->rchild != NULL && temp->rchild != node)
        temp = temp->rchild;
    return temp;
}

btnode *find_precursor(btnode *node) {
    const btnode *cnode = node;
    const btnode *retnode = find_precursor(cnode);
    return const_cast<btnode*>(retnode);
}

void preorder_morris(btnode *root) {
    if (!root) return ;

    btnode *node = root;
    btnode *precursor = NULL;
    while (node != NULL){
        precursor = find_precursor(node);
        if (precursor == NULL) {
            visit(node);
            node = node->rchild;
            continue; 
        }
        if (precursor->rchild == NULL) {
            precursor->rchild = node;
            visit(node);
            node = node->lchild;
        }else if (precursor->rchild == node){
            precursor->rchild = NULL;
            node = node->rchild;
        }else {
            cout << "ERROR" << endl;
            return ;
        }
    }//while
}//preorder_morris

int main() {
    int arr1[] = {1,2,3,4,5,6,7,8,9};
    Btnode<int> *root = initTree(arr1, 9);
    cout << "recursion preorder traversal:" << endl;
    preorder_traversal(root);
    cout << endl << "morris preorder traversal:" << endl;
    preorder_morris(root);
    cout << endl;
    return 0;
}
