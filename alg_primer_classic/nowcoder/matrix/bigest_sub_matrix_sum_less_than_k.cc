#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>

/*
 * 给定一个无序矩阵，其中有正有负有0，再给定一个值k，
 * 求累加和小于等于k的最大子矩阵大小，矩阵的大小用其中的元素个数来表示
 */

using namespace std;

const int INTMIN = numeric_limits<int>::min();

struct subMatrixArea {
    subMatrixArea() : 
        topLeft(0,0), length(0), width(0), maxarea(0) { } 

    pair<int, int> topLeft;
    int length;
    int width;
    int maxarea;

    
    void showSubMatrix(const vector<vector<int>> &originalMatrix) {
        cout << "maxarea:" << maxarea
             << " topLeft:[" << topLeft.first << ","
             << topLeft.second << "]  "
             << "length:" << length
             << " width:" << width
             << endl;
        
        for (int vert = topLeft.second; 
                vert!=topLeft.second+width; ++vert) {
            const vector<int> &curRow = originalMatrix[vert];
            for (int horizon = topLeft.first;
                horizon != topLeft.first+length; ++horizon)
                cout << curRow[horizon] << " ";
            cout << endl;
        }
       
    }
    
};

class FindSubMatrix {
public:

    subMatrixArea getBiggestSubMatrix(const vector<vector<int>> &matrix, int k) {
        subMatrixArea retArea;
        if (matrix.empty()) return retArea;
        
        k_ = k;
        vector<int> sumRow;
        int maxarea = 0;
        for (int i=0; i<matrix.size(); ++i) {
            for (int j=i; j<matrix.size(); ++j) {
                const vector<int> &curRow = matrix[j];
                if (j == i)
                    sumRow.assign(curRow.begin(), curRow.end());
                else 
                    for (int ci=0; ci!=curRow.size(); ++ci) 
                        sumRow[ci] += curRow[ci];
                auto range = getLongestSubLess(sumRow);
                int area = (range.second - range.first)*(j+1-i);
                if (area > maxarea) {
                    maxarea = area;
                    retArea.topLeft.first = range.first;
                    retArea.topLeft.second = i;
                    retArea.length = range.second - range.first;
                    retArea.width = j+1-i;
                    retArea.maxarea = maxarea;
                }
            }
        }
        return retArea;
    }

    void test_getLongestSubLess(void) {
        int sz;
        cout << "please cin sz: ";
        cin >> sz;
        cout << "please cin arr elements:" << endl;
        vector<int> arr;
        int n;
        for (int i=0; i<sz; ++i) {
            cin >> n; arr.push_back(n);
        } 
        cout << "please cin k:";
        cin >> k_;
        auto range = getLongestSubLess(arr);
        cout << "now show the subarr which sum <= " << k_
             << ":" << endl;
        cout << "range: (" << range.first
             << ", " << range.second << ")" << endl;
        for (int i=range.first; i!=range.second; ++i)
            cout << arr[i] << " ";
        cout << endl;
    }


private:
    //@return : longest lens of sub arr which sum less than k_
    pair<int, int> getLongestSubLess(const vector<int> &arr) {
        pair<int, int> range(0,0);
        if (arr.empty()) return range;
        
        vector<int> helpArr;
        int diff, sum = 0;
 
        for (int r = 0; r != arr.size(); ++r) {
            sum += arr[r];
            if (sum <= k_) {
                range.first = 0; range.second = r+1;
            }else {
                diff = sum - k_;
                auto first_site = 
                    find_if(helpArr.begin(), helpArr.end(),
                    [diff] (const int &n) { return n>=diff; });
                int first_position = first_site - helpArr.begin();
                if (r-first_position > range.second-range.first) {
                    range.first = first_position+1; //important
                    range.second = r+1;
                }
            }
            if (helpArr.empty())
                helpArr.push_back(sum);
            else helpArr.push_back(max(helpArr.back(), sum));
        }
        return range;
    }


    //pair<int, int> position;
    //int length;
    //int width;
    int k_;
};

class InOutMatrix {
public:
    void in_data() {
        cout << "please enter length: ";
        cin >> length;
        cout << "please enter width: ";
        cin >> width;
        cout << "please enter the matrix" << endl;
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

    const vector<vector<int>>& getMatrix() const{
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

void run() {
    InOutMatrix iom;
    int k;    
    iom.in_data();
    cout << "please cin the k:";
    cin >> k;
    FindSubMatrix fsm;
    auto subm = fsm.getBiggestSubMatrix(iom.getMatrix(), k);
    cout << "let us show show the max sub matrix which sum less " 
         << k << ":" << endl;
    subm.showSubMatrix(iom.getMatrix());
}

int main() {
    run();
    return 0;
}
