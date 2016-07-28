#include <iostream>
#include <map>

/*
 * 给定一个无序数组arr, 其中元素可正可负可0.
 * 求arr所有的子数组中正数与负数个数相等的最长子数组长度
 */

using namespace std;

const int MAXSZ = 100;

int lens = 0;
int maxr = 0;
int maxl = 0;

class neg_pos_trans {
public:
    int operator()(const int num) {
        if (num>0) return 1;
        if (num<0) return -1;
        return 0;
    }
};

int get_pn_equal_subarr(int arr[], int arr_sz) { //p: positive  n:negative
    //if num > 0: sum+=1; < 0: sum-=1
    map<int, int> summap; //key:position value:sum 
    summap.insert(make_pair(0, -1));

    ::lens = 0;
    int sum = 0;
    int l = 0, r = 0;
    int reverse_sum = 0;
    neg_pos_trans trans;

    while (r < arr_sz) {
        sum += trans(arr[r]);
        if (summap.find(sum) == summap.end())
            summap.insert(make_pair(sum, r));
        ++r;
        reverse_sum = sum - 0; // important
        if (summap.find(reverse_sum) != summap.end()) {
            l = summap[reverse_sum] + 1;
            if (lens < r - l) {
                lens = r-l; maxl = l; maxr = r;
            }
        }
    }
    return lens;
}

int main() {
    cout << "please cin arr_sz: ";
    int arr[MAXSZ] = {0};
    int arr_sz;

    while (cin >> arr_sz && arr_sz > 0) {
        for (int i = 0; i < arr_sz; ++i) cin >> arr[i];
        if (get_pn_equal_subarr(arr, arr_sz) > 0) {
            cout << "subarr lens: " 
                 << lens << endl << "subarr: ";
            for (int i = maxl; i < maxr; ++i)
                cout << arr[i] << " ";
            cout << endl; 
        } else
            cout << "cannot find negative/positive equal subarr" << endl;
        
        cout << "please cin arr_sz: ";
    }
    return 0;
}
