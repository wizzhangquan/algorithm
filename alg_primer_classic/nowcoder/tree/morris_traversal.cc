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

void midorder_morris(btnode *root) {
    if (!root) return ;

    btnode *node = root;
    btnode *precursor = NULL;
    while (node != NULL) {
        precursor = find_precursor(node);
        if (precursor == NULL) {
            visit(node);
            node = node->rchild;
        }else if (precursor->rchild == NULL) {
            precursor->rchild = node;
            node = node->lchild;
        }else if (precursor->rchild == node) {
            visit(node);
            precursor->rchild = NULL;
            node = node->rchild;
        }else {
            cout << "ERROR" << endl;
            return ;
        }
    }//while
}//midorder_morris

//逆序当前结点的右边界，并返回右边界的最后结点
//end_rchild标识右边界最后结点的rchild的指针
btnode *reverse_right_boundary(btnode *node, btnode *end_rchild = NULL) {
    btnode *before = NULL, *current = node, *after = NULL;
    while (current != NULL && current != end_rchild) {
        after = current->rchild;
        current->rchild = before;
        before = current;
        current = after;
    }
    return before; 
}

inline void visit_right_boundary(btnode *node) {
    while (node) {
        visit(node);
        node = node->rchild;
    }
}

void reverse_visit_rboundary(btnode *node, btnode *end_rchild = NULL) {
    btnode *reversed_head = reverse_right_boundary(node, end_rchild);
    visit_right_boundary(reversed_head);
    reverse_right_boundary(reversed_head);
}

void postorder_morris(btnode *root) {
    if (!root) return ;
    
    btnode *node = root;
    btnode *precursor = NULL;
    while (node != NULL) {
        precursor = find_precursor(node);
        if (precursor == NULL) {
            node = node->rchild;
        }else if (precursor->rchild == NULL) {
            precursor->rchild = node;
            node = node->lchild;
        }else if (precursor->rchild == node) {
            //在这种状态下，逆序打印当前结点的左子树的
            //右边界
            //为了使空间复杂度为O(1)，我们先将右边界逆序
            //打印完后再逆序回来
            reverse_visit_rboundary(node->lchild, node);            
            node = node->rchild;
        }
    }
    reverse_visit_rboundary(root, NULL);
}

//测试逆序函数是否成功
/*
void test_rboundary(btnode *node) {
    btnode *rboundary_head = reverse_right_boundary(node);
    cout << "visit reverse right boundary:" << endl;
    visit_right_boundary(rboundary_head);
    cout << endl << "reverse to original tree" << endl;
    reverse_right_boundary(rboundary_head);
    cout << "now test preorder all tree:" << endl;
    preorder_traversal(node);
    cout << endl;
}
*/

int main() {
    int arr1[] = {1,2,3,4,-1,6,-1,-1,9};
    Btnode<int> *root = initTree(arr1, 9);

    cout << "recursion preorder traversal:" << endl;
    preorder_traversal(root);
    cout << endl << "morris preorder traversal:" << endl;
    preorder_morris(root);

    cout << endl << "recursion midorder traversal:" << endl;
    midorder_traversal(root);
    cout << endl << "morris midorder traversal:" << endl;
    midorder_morris(root);

    cout << endl << "recursion postorder traversal:" << endl;
    postorder_traversal(root);
    cout << endl << "morris postorder traversal:" << endl;
    postorder_morris(root);
    cout << endl;

    destoryTree(root);
    return 0;
}
