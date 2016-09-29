#include <iostream>
#include <map>
#include "binary_tree.h"
#include "binary_tree.cc"

using namespace std;

/*
 * 在二叉树中找到累加和为指定值的最长路径长度
 */
class TreeLongestPathSum {
public:
    explicit TreeLongestPathSum(const btnode *root) :
        firstSumLevelMap_(), sum_(0), root_(root) {
    }

    int findLongestPathSum(const int sum) {
        initSumLevelMap();
        sum_ = sum;
        return preorderAdd(root_);
    }

private:
    int preorderAdd(const btnode *node, int accumulation = 0, int level = 1);
    void initSumLevelMap() {
        if (__builtin_expect(firstSumLevelMap_.empty(), false))
            firstSumLevelMap_.clear();
        firstSumLevelMap_.insert(make_pair(0, 0));
    }

    map<int, int> firstSumLevelMap_;
    int sum_;
    const btnode *root_;
};//TreelongestPathSum

int TreeLongestPathSum::
preorderAdd(const btnode *node, int accumulation, int level) {
    if (node == NULL) return 0;
    accumulation += node->data_;

    if (firstSumLevelMap_.count(accumulation) == 0) {
        firstSumLevelMap_.insert(make_pair(accumulation, level));
    }

    int accuChildLevel = max(preorderAdd(node->lchild, accumulation, level+1), 
                        preorderAdd(node->rchild, accumulation, level+1) );
    if (firstSumLevelMap_.count(accumulation - sum_)) {
        int retLevel = level - firstSumLevelMap_[accumulation - sum_];
        return max(retLevel, accuChildLevel);
    }else
        return accuChildLevel;
}

int main() {
    int treeArr[9] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    btnode *root = initTree<int>(treeArr, 9);
    TreeLongestPathSum sumPath(root);
    int sum;
    cout << "please enter sum which u want find:";
    while (cin>>sum)
        cout << "find longest path sum = " << sum
             << "'s path is " << sumPath.findLongestPathSum(sum) << endl;
    return 0;
}
