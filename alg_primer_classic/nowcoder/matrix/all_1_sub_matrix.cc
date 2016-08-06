#include <iostream>
#include <vector>

/*
 * 给定一个无序矩阵，其中只有1和0两种值。
 * 求只含有1的最大的子矩阵大小，矩阵的大小用其中的元素个数来表示
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
    return 0;
}
