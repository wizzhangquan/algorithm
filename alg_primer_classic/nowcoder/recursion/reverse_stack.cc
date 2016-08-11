#include <iostream>
#include <stack>
#include <stdexcept>

/*
 * 如何仅用递归函数和栈操作逆序一个栈
 *
 *
 * 【题目】
 *
 *
 * 一个栈依次压入1、2、3、4、5，那么从栈顶到栈底分别为5、4、3、2、1。
 * 将这个栈转置后，从栈顶到栈底为1、2、3、4、5，也就是实现栈中元素的逆序
 * ，但是只能用递归函数来实现，不能用其他数据结构。
 */

using namespace std;

template <typename T> class ReverStack {
public:

    void inStk() {
        cout << "please enter stack num:" << endl; 
        T n;
        while (cin >> n)
            stk_.push(n);
    }

    void test_getAndRemoveLast() {
        T last = getAndRemoveLast(stk_);
        cout << "the bottom of stack: "
             << last << endl;
        cout << "now the stack's top: "
             << stk_.top() << endl;
        cout << "print stack: ";
        printStack(stk_);
        cout << endl;
        cout << "print stack: ";
        printStack(stk_);
        cout << endl;
    }

    //打印stack，但不改变其
    void printStack(stack<T> &stk) {
        if (stk.empty())
            return ;
        T &curTop = stk.top();
        stk.pop();
        cout << curTop << "=> ";
        printStack(stk);
        stk.push(curTop);
        return ;
    }

    void ReverseStk(stack<T> &stk) {
        if (stk.empty() || stk.size() == 1) 
            return ;
        T bottom = getAndRemoveLast(stk);
        ReverseStk(stk);
        stk.push(bottom);
        return ;
    }

    //本函数利用递归将栈底元素移除并返回，
    //栈的其他部分元素次序不改变
    T getAndRemoveLast(stack<T> &stk) {
        if (stk.empty())
            throw out_of_range("stk is empty");
        T curTop = stk.top();
        stk.pop();
        if (stk.empty())
            return curTop;
        else {
            T ret = getAndRemoveLast(stk);
            stk.push(curTop);
            return ret;
        }
    }

private:
    stack<T> stk_;
};


int main() {
    ReverStack<int> rs;
    rs.inStk();
    rs.test_getAndRemoveLast();
    return 0;
}
