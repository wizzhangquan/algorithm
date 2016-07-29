#include <iostream>

/*
 * 未排序数组中累加和小于或等于给定值的最长子数组长度
 *
 * 【题目】
 * 给定一个无序数组arr，其中元素可正、可负、可0，给定一个整数k。求arr所有的子数组中累加和小于或等于k的最长子数组长度。
 * 例如：arr=[3,-2,-4,0,6]，k=-2，相加和小于或等于-2的最长子数组为{3,-2,-4,0}，所以结果返回4。
 * 【要求】
 * 时间复杂度(N*logN)
 *
 * 思想：
 * Sum1 - Sum2 <= k 
 * => Sum1 - k <= Sum2
 */

using namespace std;

int arr[100];
int lens = 0;
int maxr = 0;
int maxl = 0;

int getBigFirstPosition(int arr[], int sz, int num) {
    int l = 0;
    int r = sz-1;
    int mid, ret = -1;
    while (l <= r) {
        mid = (l + r) / 2;
        if (arr[mid] < num) {
            l = mid + 1;
        }else {
            ret = mid;
            r = mid-1; 
        }
    }
    return ret; 
}

int getLessSubarr(int arr[], int sz, int k) {
    const int help_sz = sz;
    int help[help_sz]; //记录当前i的子数组和最大值
    
    help[0] = arr[0];
    int r = 0, l = 0;
    int sum = 0;
    int diffsum = 0;
    ::lens = 0;
    while (r < sz) {
        sum += arr[r];
        diffsum = sum - k;
        if (sum <= k) {
            if (lens < r+1) {
                lens = r+1; maxl = 0; maxr = r+1;
            }
        }else {
            l = getBigFirstPosition(help, r, diffsum);
            if (l != -1 && ( lens < r-l )) { //== lens < r+1 - (l+1)
                lens = r-l; maxl = l+1; maxr = r+1;
            }
        }

        if (r > 0)
            help[r] = max(help[r-1], sum);
        ++r;
    } 

    return lens;
}
/*
void test_getBigFirstPosition() {
    int arrsz = -1;
    int k;
    cout << "please cin sz: ";
    while (cin >> arrsz && arrsz > 0) {
        cout << "please cin arr: " << endl;
        for (int i=0; i<arrsz; ++i) cin >> arr[i];
        cout << "please cin k: ";
        cin >> k;
        cout << "getLessFirstPosition < " 
             << k << " is " 
             << getBigFirstPosition(arr, arrsz, k)
             << endl << "------" << endl
             << "please cin sz: ";
    }
}
*/

void run() {
    int arrsz = -1;
    int k;
    cout << "please cin sz: ";
    while (cin >> arrsz && arrsz > 0) {
        cout << "please cin arr: " << endl;
        for (int i=0; i<arrsz; ++i) cin >> arr[i];
        cout << "please cin k: ";
        cin >> k;
        if (getLessSubarr(arr, arrsz, k) > 0) {
            cout << "get subarr len: " << lens << endl;
            for (int i = maxl; i < maxr; ++i)
                cout << arr[i] << " ";
        } else {
            cout << "cannot find subarr";
        }
        cout << endl << "------" << endl
             << "please cin sz: ";
    }
   
}

int main() {
    run();
    return 0;
}
