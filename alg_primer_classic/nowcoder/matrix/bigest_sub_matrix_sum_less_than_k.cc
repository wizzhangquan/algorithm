#include <iostream>
#include <vector>

/*
 * 给定一个无序矩阵，其中有正有负有0，再给定一个值k，
 * 求累加和小于等于k的最大子矩阵大小，矩阵的大小用其中的元素个数来表示
 */

using namespace std;

class FindSubMatrix {
public:


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
