#include <iostream>
#include <algorithm>
#include <iterator>
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

    //这里必须是static，不然传入sort会发生错误
    //如果是本类非static成员函数，会有一个隐藏的函数参数this
    static bool increment_compare(const env &a, const env &b) {
        //important
        if (a.first != b.first) //w升序
            return a.first < b.first;
        else //w相等情况下, h降序
            return a.second > b.second; 
    }

    void sort_envs() {
        sort(envelopes_.begin(), envelopes_.end(),
            Env_datas::increment_compare);
    }

private:
    vector<env > envelopes_;
};

//@UNIT_TEST : Env_datas sort
void test_envs(void) {
    while(true) { 
        Env_datas envs;
        envs.in_envs();
        envs.sort_envs();
        envs.show_envs();
    }
}

class Solution {
public:
    int maxEnvelopes(vector<pair<int, int> >& envelopes) {

    }
};

int main() {
    test_envs();
    return 0;
}
