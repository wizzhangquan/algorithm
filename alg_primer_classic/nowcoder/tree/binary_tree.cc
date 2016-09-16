#include "binary_tree.h"
#include <iostream>

using namespace std;

template <typename T, unsigned N>
Btnode<T> *initBinaryTree(const T elements[N], int begin = 0) {
    if (begin<0 || begin>=N || elements[begin]==-1)
        return NULL;
    Btnode<T> *node = new Btnode<T>(elements[begin]);
    node->lchild = initBinaryTree(elements, 2*begin+1);
    node->rchild = initBinaryTree(elements, 2*begin+2);
    return node;
}

template <typename Type>
Btnode<Type> *initTree(const Type elements[], const int sz, int begin = 0) {
    if (begin<0 || begin>=sz || elements[begin]==-1)
        return NULL;
    Btnode<Type> *node = new Btnode<Type>(elements[begin]);
    node->lchild = initTree(elements, sz, 2*begin+1);
    node->rchild = initTree(elements, sz, 2*begin+2);
    /*
    cout << "init node ,data:" << node->data_;
    if (node->lchild == NULL)
        cout << " left:NULL";
    else 
        cout << " left:" << node->lchild->data_;

    if (node->rchild == NULL)
        cout << " right:NULL";
    else 
        cout << " right:" << node->lchild->data_;
    cout << endl;
    */
    return node;
}

template <typename Type>
void destoryTree(Btnode<Type> *root) {
    if (root == NULL) return ;
    destoryTree(root->lchild);
    destoryTree(root->rchild);
    delete root;
}

template <typename Type>
void preorder_traversal(const Btnode<Type> *root) {
    if (root == NULL) return ;
    cout << root->data_ << " ";
    preorder_traversal(root->lchild);
    preorder_traversal(root->rchild);
}

template <typename Type>
void midorder_traversal(const Btnode<Type> *root) {
    if (root == NULL) return ;
    midorder_traversal(root->lchild);
    cout << root->data_ << " ";
    midorder_traversal(root->rchild);
}

/*
int main() {
    int arr[9] = {1, 2, 3, 4, -1, 6, 7, -1, 9};

    Btnode<int> *root = initTree<int>(arr, 9);

    cout << "begin midorder traversal" << endl;
    midorder_traversal(root);
    cout << endl;
    destoryTree(root);
    return 0;
}*/
