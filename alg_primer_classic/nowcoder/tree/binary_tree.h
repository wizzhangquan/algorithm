#ifndef __BINARY_TREE_H__
#define __BINARY_TREE_H__

#include <utility>
#include <cstddef>

template <typename Type>
class Btnode;

template <typename Type>
Btnode<Type> *initTree(const Type elements[], const int sz, int begin = 0);

template <typename Type>
void destoryTree(Btnode<Type> *root);

template <typename Type>
void preorder_traversal(const Btnode<Type> *root);

template <typename Type>
void midorder_traversal(const Btnode<Type> *root);

template <typename Type>
void postorder_traversal(const Btnode<Type> *root);

template <typename Type>
class Btnode {

    template <typename T, unsigned N>
    friend Btnode<T> *initBinaryTree(const T elements[N], int begin = 0);
    //这种方式为模板类的非约束模板友元函数
    //在类内部声明友元函数模板，可以创建非约束友元函数，
    //即每个函数具体化都是每个类具体化的友元
    //unsigned N cannot use in array[N]

    friend Btnode<Type> *initTree<Type>(const Type elements[], const int sz, int begin); 
    //模板类的约束模板友元函数 可以这样写，
    //但是需要前置声明该模板函数，并且不可以再使用非类型模板函数
    //eg:template <unsigned N>这种了 ==> error
    //另外，函数名后面的<Type>可以为<>，这是因为可以从函数参数推断出模板类型
    //并且这里，begin不能有默认参数，毕竟不是第一次声明

    friend void destoryTree<>(Btnode<Type> *root);
    friend void preorder_traversal<>(const Btnode<Type> *root);
    friend void midorder_traversal<>(const Btnode<Type> *root);
    friend void postorder_traversal<>(const Btnode<Type> *root);
public:
    Btnode(Type data = 0) : 
        data_(data), lchild(NULL), rchild(NULL) { 
    }

    //~Btnode() { lchild = rchild = NULL; }
//private:
    Type data_;
    Btnode *lchild;
    Btnode *rchild;
};

#endif
