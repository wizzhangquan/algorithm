#include <iostream>
#include <vector>
#include <algorithm>

/*
 * 给定一个无序矩阵，其中有正有负有0，再给定一个值k，
 * 求累加和小于等于k的最大子矩阵大小，矩阵的大小用其中的元素个数来表示
 */

using namespace std;

class FindSubMatrix {
public:
    int getBiggestSubMatrix(const vector<vector<int>> &matrix, int k) {
        if (matrix.empty()) return 0;
        
        k_ = k;
        vector<int> sumRow;
        for (int i=0; i<matrix.size(); ++i) {
            for (int j=i; j<matrix.size(); ++j) {
                const vector<int> &curRow = matrix[j];
                if (j == i)
                    sumRow.assign(curRow.begin(), curRow.end());
                else 
                    for (int ci=0; ci!=curRow.size(); ++ci) sumRow[ci] += curRow[ci];
                
            }
        }
    }

    void test_getLongestSubLess(void) {
        cout << "please cin arr elements:" << endl;
        int n;
        vector<int> arr;
        while (cin>>n) arr.push_back(n);
        cout << "please cin k:";
        cin >> k_;
        auto range = getLongestSubLess(arr);
        cout << "now show the subarr which sum <= " << k_
             << ":" << endl;
        for (int i=range.first; i!=range.second; ++i)
            cout << arr[i] << " ";
        cout << endl;
    }


private:
    //@return : longest lens of sub arr which sum less than k_
    pair<int, int> getLongestSubLess(const vector<int> &arr) {
        const int arrsz = arr.size();
        pair<int, int> range(0, 0);

        if (arrsz == 0) return range;

        if (arrsz == 1)
            if (arr[0] <= k_) return make_pair(0,1);
            else return range;
 
        vector<int> helpArr;//储存当前i的最大连续子序列和
        int sum = arr[0], diff, lens;
        helpArr.push_back(arr[0]);
        for (int i=1; i!=arrsz; ++i) {
            sum += arr[i];
            helpArr.push_back(max(helpArr.back(), sum));
            diff = sum - k_;
            auto first_i = find_if(begin(helpArr), end(helpArr), 
                    [diff](const int &n) -> bool {return n>=diff;});
            int first_site = first_i - helpArr.end();
            if (i+1-first_site > range.second-range.first) {
                range.first = first_site;
                range.second = i+1;
            }
        }
        return range;
    }

    pair<int, int> position;
    int length;
    int width;
    int k_;
};

class InOutData {
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

int main() {
    return 0;
}
