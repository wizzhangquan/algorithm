#include <iostream>
#include <algorithm>
#include <vector>

/*
 * 插水坑问题
 * 按照a[i]的值形成其值高度的，1为宽度的柱子，形成一个容器
 * 求容器最大蓄水值
 *
 * eg: 0,1,0,3,2,1,0,1,2 => 5
 */
//I wanner use C++11

using namespace std;

class Solution {
public:
    //更好解法可以不使用辅助数组
    int maxArea(vector<int> &height) {
        vector<int> left_max_arr;
        vector<int> right_max_arr;

        int biggest = -1;

        for_each(height.cbegin(), height.cend(),
            [&biggest, &left_max_arr](const int &n) -> void 
            { biggest = max(biggest, n);
              left_max_arr.push_back(biggest); 
        });

        cout << "show the left_max_arr: ";
        show_arr(left_max_arr);

        //这里将使用反向迭代器
        biggest = -1;
        for_each(height.crbegin(), height.crend(),
            [&biggest, &right_max_arr] (const int &n) -> void 
            { biggest = max(biggest, n);
              right_max_arr.push_back(biggest); 
              //vector donnt has push_front
        });
        
        cout << "show the right_max_arr: ";
        show_arr(right_max_arr);

        int area = 0;
        int less_height = 0;
        auto left_iter = left_max_arr.cbegin();
        auto right_iter = right_max_arr.crbegin();
        for (const auto height_iter : height) {
            less_height = min(*left_iter++, *right_iter++);
            area += less_height - height_iter;
        }
        return area;
    }

private:
    //just unit_test
    void show_arr(vector<int> arr) {
        for(auto &n : arr)
            cout << n << " ";
        cout << endl;
    }
};

class in_out_data {
public:
    in_out_data() = default;

    void in_data() {
        cout << "please cin num(>=0) (-1 means end)" 
             << endl << "=> ";
        int num;
        while (cin >> num && num >= 0) {
            data.push_back(num);
            //cout << "please cin num(>=0) : ";
        }
    }

    vector<int> &get_data() {
        return data;
    }

private:
    vector<int> data;
};

void run(void) {
    Solution s;

    while (true) {
        in_out_data iotest;
        iotest.in_data();
        cout << "get max area is: "
             << s.maxArea(iotest.get_data())
             << endl;
    }
}

int main() {
    run();
    return 0;
}
