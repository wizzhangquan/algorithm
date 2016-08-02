#include <iostream>
#include <vector>

/*
 * 插水坑问题
 * 按照a[i]的值形成其值高度的，1为宽度的柱子，形成一个容器
 * 求容器最大蓄水值
 *
 * eg: 0,1,0,3,2,1,0,1,2 => 5
 */

//这里不再需要辅助数组了
//而是需要4个变量来双向移动比较
//这里可以参考快排的方法
//
//因为这里的算法思想是
//在i处
//知道i左边数组元素最大值leftmax_i
//    i右边数组元素最大值rightmax_i
//那么我们就可以知道在i处可以蓄水： min(leftmax_i, right_i) - arr[i]
//所以在算法container_water_ust_helparr.cc中使用了辅助数组
//来帮助我们存储left/rigth遍历的最大值
//
//但是，我们可以思考如下：
//在从指向两端的指针left, right处时，
//令 less = min(left_max, right_max)
//就可以确定less+1 / -1处的水量
//并且可以将left   / right移动
//下面上代码
//
//
//经过测试完全正确
//I wanner use C++11

using namespace std;

class Solution {
public:
    int maxArea(vector<int> &height) {
        if (height.empty()) return 0;

        int l = 1, r = height.size() - 2;
        int leftmax = height[0];
        int rightmax = height[height.size() - 1];
        int water = 0;
        while (l <= r) {
            if (leftmax <= rightmax) {
                leftmax = max(leftmax, height[l]);
                water += leftmax - height[l];
                ++l;
            }else {
                rightmax = max(rightmax, height[r]);
                water += rightmax - height[r];
                --r;
            }
        }
        return water;
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
