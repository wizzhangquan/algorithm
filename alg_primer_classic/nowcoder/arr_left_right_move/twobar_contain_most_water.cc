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
 * eg: 1,1 => 1
 *     0,1,0,3,2,3,0 => 6
 *         |   |
 *         | | |
 *     _|__|_|_|_
 *     这里的bar没有宽度 和 前面2题不一样
 */

using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        if (height.empty()) return 0;

        int areamax = 0;
        int l = 0, r = height.size()-1;

        while (l <= r) {
            if (height[l] <= height[r]) {
                areamax = max(areamax,
                        height[l]*(r-l));
                ++l;
            }else {
                areamax = max(areamax,
                        height[r]*(r-l));
                --r;
            }    
        }
        return areamax;
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
