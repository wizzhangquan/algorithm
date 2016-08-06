#include <iostream>
#include <vector>
#include <stack>
#include <deque>
#include <utility>

/*
 * 给定一个无序矩阵，其中只有1和0两种值。
 * 求只含有1的最大的子矩阵大小，矩阵的大小用其中的元素个数来表示
 *
 * 这里将其转换为数组，将i行以上所有的数子按照同列累加
 * 但i行上位置为0的位置累加数组里依然是0，然后可以转换为[1,2,0,3,4]之类的累加数组
 * 然后求其连续围成的最大矩形面积
 *
 * eg:
 * 0 1 0 1  => [0 1 0 1]                      => max: 1
 * 1 1 1 1  => [1 2 1 2] [1 1 1 1]            => max: 4 4 
 * 0 1 1 1  => [1 3 2 3] [1 2 2 2] [0 1 1 1]  => max: 6 6 3
 * so subMaxAll1 area : 6
 */

using namespace std;

struct subMatrixArea {
    subMatrixArea() : 
        topLeft(0,0), length(0), width(0), maxarea(0) { } 

    pair<int, int> topLeft;
    int length;
    int width;
    int maxarea;
};

class FindSubMatrix {
public:
    subMatrixArea getAllOneSubMatrix(const vector<vector<int>> &matrix) {
    
    }
    void test_getContinueMaxSubArea() {
        vector<int> arr;
        int n;
        cout << "please enter arr(-1 means end):" << endl;
        while (cin >> n && n >= 0)
            arr.push_back(n);
        
        pair<int, int> range;
        cout << "max area sub arr's area:"
             << getContinueMaxSubArea(arr, range)
             << endl;
        cout << "sub arr:";
        for (int i=range.first; i<range.second; ++i)
            cout << arr[i] << " ";
        cout << endl;
    }
    
private:
    //use stack
    //返回能围成最大矩阵的面积
    //stack中是按照从小到大排列的
    //当当前num>stack.top时，就开始清算stack.top元素的面积
    //猜想：蓄水池那个问题也可以用stack
    //但是本题目却不可以使用其两端指针移动的方法
    //因为中途会断层
    int getContinueMaxSubArea(const vector<int> &arr, 
                        pair<int, int>& range) {
        range.first = range.second = 0;
        if (arr.empty()) return 0;

        stack<int, deque<int>> helpStack;
        int maxarea = 0, area;
        helpStack.push(-1);
        const int sz = arr.size();
        for (int r=0; r!=sz; ++r) {
            if (helpStack.top() < 0 || 
                arr[helpStack.top()] < arr[r]) {
                helpStack.push(r);
                continue;
            }
            while (helpStack.top() >= 0 && arr[helpStack.top()] >= arr[r]) {
                int topNum = arr[helpStack.top()];
                helpStack.pop();
                int lIndex = helpStack.top();
                area = topNum*(r-lIndex-1);
                if (area > maxarea) {
                    range.first = lIndex+1;
                    range.second = r;
                    maxarea = area;
                }
            }
            helpStack.push(r);
        }

        while (helpStack.top() >= 0) {
            int topNum = arr[helpStack.top()];
            helpStack.pop();
            int lIndex = helpStack.top();
            area = topNum*(sz-lIndex-1);
            if (area > maxarea) {
                range.first = lIndex+1;
                range.second = sz;
                maxarea = area;
            }
        }
        return maxarea;
    }
};

class InOutMatrix {
public:
    void in_data() {
        cout << "please enter length: ";
        cin >> length;
        cout << "please enter width: ";
        cin >> width;
        cout << "please enter the matrix(element:0/1)" << endl;
        int temp;
        for (int i=0; i<width; ++i) {
            vector<int> row;
            for (int j=0; j<length; ++j) {
                cin >> temp;
                row.push_back(temp);
            }
            matrix.push_back(row);
        }
    }

    const vector<vector<int>>& getMatrix() const {
        return matrix;
    }

    void print_matrix() {
        for (auto &row_iter : matrix) {
            for (auto &num_iter : row_iter)
                cout << num_iter << " ";
            cout << endl;
        }
    }
    
private:
    int length;
    int width;
    vector<vector<int>> matrix;
};

int main() {
    FindSubMatrix fsm;
    fsm.test_getContinueMaxSubArea();
    return 0;
}
