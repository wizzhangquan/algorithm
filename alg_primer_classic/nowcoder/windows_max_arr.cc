#include <iostream>
#include <vector>
#include <deque>

/*
 * 
 * rr和一个大小为w的窗口从数组的最左边滑到最右边，窗口每次向右边滑一个位置。
 * 例如，数组为[4,3,5,4,3,3,6,7]，窗口大小为3时：
 * [4 3 5] 4 3 3 6 7   窗口中最大值为5
 * 4 [3 5 4] 3 3 6 7   窗口中最大值为5
 * 4 3 [5 4 3] 3 6 7   窗口中最大值为5
 * 4 3 5 [4 3 3] 6 7   窗口中最大值为4
 * 4 3 5 4 [3 3 6] 7   窗口中最大值为6
 * 4 3 5 4 3 [3 6 7]   窗口中最大值为7
 *
 * 如果数组长度为n，窗口大小为w，则一共产生n-w+1个窗口的最大值。
 *
 * 请实现一个函数。
 * 输入：整型数组arr，窗口大小为w。
 * 输出：一个长度为n-w+1的数组res，res[i]表示每一种窗口状态下的最大值。
 * 以本题为例，结果应该返回{5,5,5,4,6,7}。
 */

using namespace std;

template <typename T> class WindowsArr {
public:
    void inArr() {
        int sz;
        cout << "Please enter arr sz:" << endl;
        cin >> sz;
        T num;
        cout << "Please enter arr elem:" << endl;
        for (int i=0; i<sz; ++i) {
            cin >> num;
            arr.push_back(num);
        }
    }
    
    vector<T> getMaxElemInEveryWindow(const int w) {
        vector<T> maxElemEveryWindow;
        if (arr.empty() || w > arr.size())
            return maxElemEveryWindow;

        deque<int> helpQue;//顺序存储当前窗口的值的从大到小排列
        int left=0, right=0;
        pushHelpDeque(helpQue, right);
        while (right < arr.size()) {
            if ((right-left) < w-1) {
                pushHelpDeque(helpQue, ++right);
            } else if ((right-left) == w-1) {
                maxElemEveryWindow.push_back(
                    arr[helpQue.front()]);
                pushHelpDeque(helpQue, ++right);
            } else {//right-left > w-1
                popHelpDeque(helpQue, left++);
            }
        }
        return maxElemEveryWindow;
    }

    void pushHelpDeque(deque<int> &helpQue, int pos) {
        if (pos == arr.size())
            return ;
        while (!helpQue.empty() && arr[helpQue.back()] <= arr[pos]) {
            helpQue.pop_back(); 
        }
        helpQue.push_back(pos);
    }
    void popHelpDeque(deque<int> &helpQue, int pos) {
        while (!helpQue.empty() && helpQue.front() <= pos)
            helpQue.pop_front();
    }

private:
    vector<T> arr;
};

void run() {
    WindowsArr<int> wa;
    wa.inArr();
    cout << "Please enter window sz: ";
    int window;
    cin >> window;
    vector<int> maxElemWins = 
        wa.getMaxElemInEveryWindow(window);

    cout << "The max window elem is :" << endl;
    for (auto n : maxElemWins)
        cout << n << " ";
    cout << endl;
}

int main() {
    run();
    return 0;
}
