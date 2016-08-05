#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <limits>
/*
 * 给定一个无序矩阵，其中有正，有负，有0，求子矩阵的最大和
 *
 * 思路：
 * 将矩阵按连续列累加成数组，找出数组中最大连续累加和即可
 * O(width * width * 2length)
 */
using namespace std;

const int INTMIN = numeric_limits<int>::min();

class FindSubMatrix {
public:
    int getSubSumMax(const vector<vector<int>> &matrix) {
        if (matrix.empty()) return 0;

        vector<int> sumRow;
        int maxSum = INTMIN;
        //这里不能使用for (auto a:matrix) => 因为这里的a类型是vecto<int>
        // 而不是迭代器
        for (vector<vector<int>>::const_iterator headRow = matrix.begin();
                headRow != matrix.end(); ++headRow) {

            for(decltype(headRow) row_iter = headRow; 
                  row_iter != matrix.end(); ++row_iter) {
                decltype(*row_iter) row = *row_iter;

                if (row_iter == headRow)
                    sumRow.assign(row.cbegin(), row.cend());
                else {
                    for (int i=0; i!=row.size(); ++i)
                        sumRow[i] += row[i];
                }
                maxSum = max(maxSum, getContinuSubArrMaxSum(sumRow));
            }
        }
        return maxSum;
    }

    void testGetContinusSubArrMaxSum() {
        vector<int> arr;
        int sz, temp;
        cout << "please cin arr sz :";
        cin >> sz;
        for (int i=0; i<sz; ++i) {
            cin >> temp;
            arr.push_back(temp);
        } 
        cout << "continue subarr max sum: "
             << getContinuSubArrMaxSum(arr) << endl;
    }

private:
    int getContinuSubArrMaxSum(const vector<int> &arr) {
        if (arr.empty()) return 0;

        int sum = 0;
        int maxSum = sum;
        for (auto &n : arr) {
            if (sum <= 0)
                sum = n;
            else
                sum += n;
            //cout << "subsum : " << sum << " ";
            maxSum = max(maxSum, sum);
        }
        //cout << endl;
        //cout << "row arr: ";
        //for(auto &n : arr) cout << n << " ";
        
        //cout << " => subarr maxsum:" 
        //     << maxSum << endl;
        return maxSum;
    }

    

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
    InOutData data;
    data.in_data();
    cout << "print matrix:" << endl;
    data.print_matrix();

    FindSubMatrix m;
    cout << "max sum of sub matrix :"
         << m.getSubSumMax(data.getMatrix())
         << endl;
    return 0;
}
