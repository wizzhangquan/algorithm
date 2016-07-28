#include <iostream>
#include <map>

/*
 * 给定一个无序数组arr,其中元素可正，可负，可0，给定一个整数k。
 *  求arr所有的子数组中累加和为k的最长子数组长度。
 */

using namespace std;

const int MAXSZ = 100;

int lens = 0;
int maxr = 0;
int maxl = 0;

//C++03版
//@return : len
int get_max_subarrlen(int arr[], int arr_sz, int k) {
    map<int, int> subsum_map; //key:subsum value:r
    subsum_map.insert(make_pair(0, -1)); /* imporant */
    
    lens = 0;
    int l = 0, r = 0, sum = 0;
    while (r < arr_sz) {
        sum += arr[r];
        if ( subsum_map.find(sum) == subsum_map.end())
            subsum_map.insert(make_pair(sum, r));
        ++r;
        int sum_diff = sum - k;
        if ( subsum_map.find(sum_diff) != subsum_map.end()) {
            //如果当前数组和 与 k的差值被发现在map
            l = subsum_map[sum_diff] + 1;
            if (lens < r-l) {
                lens = r-l; maxr = r; maxl = l;
            } 
        }
    }
    return lens;
}

int main() {
    cout << "please cin arr_sz: ";
    int arr[MAXSZ] = {0}, k;
    int arr_sz;

    while (cin >> arr_sz && arr_sz > 0) {
        for (int i = 0; i < arr_sz; ++i) cin >> arr[i];
        cout << "please cin k: ";
        cin >> k;
        if (get_max_subarrlen(arr, arr_sz, k) > 0) {
            cout << "subarr lens: " 
                 << lens << endl << "subarr: ";
            for (int i = maxl; i < maxr; ++i)
                cout << arr[i] << " ";
            cout << endl; 
        } else
            cout << "cannot find subarr's sum == " 
                 << k << endl;
        
        cout << "please cin arr_sz: ";
    }
    return 0;
}
