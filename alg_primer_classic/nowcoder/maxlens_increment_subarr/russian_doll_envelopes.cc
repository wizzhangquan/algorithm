#include <iostream>
#include <algorithm>
#include <iterator>
#include <numeric>
#include <vector>

/*
 * 俄罗斯沙皇问题
 * https://leetcode.com/problems/russian-doll-envelopes/
 * leetcode 354
 * (w, h) 数组中 必须 w1<h1, w2<h2才能(w1, h1) < (w2, h2)
 * 求最多能摞多少个
 *
 *
 * 思路:
 * 按照w值递增来排序数组，如果w值相同则按照h值递减顺序来排序数组
 * 然后按照求最长递增子序列的方式来求得其中数据
 */

using namespace std;


//如果需要提交，只需要将此类的代码提交上去即可
class Solution {
public:
    Solution() = default;

    int maxEnvelopes(vector<pair<int, int> >& envelopes) {
        if (envelopes.empty()) return 0;

        sort(envelopes.begin(), envelopes.end(),
            Solution::increment_compare);

        vector<int> help_arr;
        int longest = 1;
        help_arr.push_back(envelopes.begin()->second);
        for (vector<pair<int, int> >::iterator iter = envelopes.begin();
            iter != envelopes.end(); ++iter) {
            int h = iter->second;
            vector<int>::iterator bigger_iter =
                find_if(help_arr.begin(), help_arr.end(), 
                    [h](int &n) -> bool { return n>=h; });

            int position = bigger_iter - help_arr.begin();
            cout << "find bigger help_arr[" 
                 << position
                 << "]:" << *bigger_iter << endl;
            
            if (bigger_iter == help_arr.end())
                help_arr.push_back(h);
            else
                *bigger_iter = h;
            
            longest = max(longest, position + 1);
        }
        return longest;

    }
    //这里必须是static，不然传入sort会发生错误
    //如果是本类非static成员函数，会有一个隐藏的函数参数this
    static bool increment_compare(const pair<int, int> &a, 
        const pair<int, int> &b) {
        //important
        if (a.first != b.first) //w升序
            return a.first < b.first;
        else //w相等情况下, h降序
            return a.second > b.second; 
    }
};

class Env_datas {
    
public:
    typedef pair<int, int> env;
    
    Env_datas() { };
    
    void in_envs(void) {
        int w, h;
        cout << "please cin <w,h> : ";
        while (cin >> w && w != -1 && cin >> h) {
            envelopes_.push_back(make_pair(w, h));
            cout << "please cin <w,h> : ";
        }
    }

    vector<env >& get_data() {
        return envelopes_;
    }
    
    void show_envs() {
        cout << "show the sorted envs: " << ends;
        for(vector<pair<int, int> >::iterator wh = envelopes_.begin();
                wh != envelopes_.end(); ++wh) {
            cout << "[" << wh->first
                 << ", " << wh->second << "]  ";
            if (wh+1 != envelopes_.end())
            cout << "=>  ";
        }
        cout << endl;
    }

    void sort_envs() {
        sort(envelopes_.begin(), envelopes_.end(),
            Solution::increment_compare);
    }

private:
    vector<env > envelopes_;
};


//@UNIT_TEST : Env_datas Solution
void test_envs(void) {
    Solution s;
    while(true) { 
        Env_datas envs;
        envs.in_envs();

        cout << "get the max Envs's lens: "
             << s.maxEnvelopes(envs.get_data())
             << "-----------------" << endl;
    }
}

int main() {
    test_envs();
    return 0;
}
