#include <iostream>
#include <stack>
#include <stdexcept>

/*
 * 如何仅用递归函数和栈操作逆序一个栈
 *
 * 【题目】
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

    void test_ReverseStk() {
        cout << "now stack which before reverse: ";
        printStack(stk_);
        cout << endl;
        cout << "Reverse stack" << endl;
        ReverseStk(stk_);
        cout << "print the Reversed stack: ";
        printStack(stk_);
        cout << endl;
    }

    void test_getAndRemoveLast() {
        T &last = getAndRemoveLast(stk_);
        cout << "the bottom of stack: "
             << last << endl;
        cout << "now the stack's top: "
             << stk_.top() << endl;
        cout << "print stack: ";
        printStack(stk_);
        cout << endl;
        last = 999;
        cout << "change ret, print stack: ";
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
        //T &curTop = stk.top();
        //这里不能使用引用
        //因为是指向stk的栈中的某位置的
        //如果返回后，到递归第二层之后，结果就不是原来的栈底
        //而变成了之前的栈底之上的那个元素
        //
        //@localhost recursion]# ./a.out
        //please enter stack num:
        //5 4 3 2 1
        //
        //1 2 3 4 5 stk.empty ret:5
        //ret last : 5
        //ret last : 4
        //ret last : 4
        //ret last : 4
        //the bottom of stack: 4
        //now the stack's top: 1
        //print stack: 1=> 2=> 3=> 4=>
        //change ret to 999, print stack: 1=> 2=> 3=> 999=>
        //
        cout << curTop << " ";
        stk.pop();
        if (stk.empty()) {
            cout << "stk.empty ret:" << curTop<< endl;
            return curTop;
        }
        else {
            T ret = getAndRemoveLast(stk);
            cout << "ret last : " << ret << endl;
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
    rs.test_ReverseStk();
    return 0;
}
