#include <iostream>
#include <algorithm>
#include <vector>

/*
 * leetcode 11
 * Container With Most Water
 *
 * Given n non-negative integers a1, a2, ..., an,
 * where each represents a point at coordinate (i, ai). 
 * n vertical lines are drawn such that the two 
 * endpoints of line i is at (i, ai) and (i, 0). 
 * Find two lines, which together with x-axis forms 
 * a container, such that the container contains the most water.
 *
 * eg: 0,1,0,3,2,1,0,1,2 => 5
 */

//i wanner use C++11

using namespace std;

class Solution {
public:
    int maxArea(vector<int> &height) {
        vector<int> left_max_arr;
        vector<int> right_max_arr;

        int biggest = -1;

        for_each(height.begin(), height.end(),
            [&biggest, &left_max_arr](const int &n) -> void 
            { biggest = max(biggest, n);
              left_max_arr.push_back(biggest); });

        cout << "show the lefte_max_arr: ";
        show_arr(left_max_arr);
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
        cout << "please cin num(>=0) : ";
        int num;
        while (cin >> num && num >= 0) {
            data.push_back(num);
            cout << "please cin num(>=0) : ";
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
        s.maxArea(iotest.get_data());
    }
}

int main() {
    run();
    return 0;
}
