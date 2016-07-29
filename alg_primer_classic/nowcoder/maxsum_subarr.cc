#include <iostream>

/*
 * 求最大子数组和的值
 */

using namespace std;

//@return: max sum of subarrary
int getMaxSumSubarr(int arr[], int sz) {
    int sum, max_sum; 

    sum = max_sum = arr[0];
    int r = 1;
    while (r < sz) {
        if (sum < 0)
            sum = arr[r];
        else
            sum += arr[r];
        max_sum = max(sum, max_sum);
        ++r;
    }
    return max_sum;
}

void run() {
    int arr[100] = {0};
    int sz = 0;
    cout << "please cin arr sz: ";
    while (cin >> sz && sz > 0) {
        cout << "please cin arr:" << endl;
        for (int i=0; i<sz; ++i) cin >> arr[i];
        cout << "get the max subarr's sum : "
             << getMaxSumSubarr(arr, sz) << endl;
        cout << "-------------" << endl
             << "please cin arr sz: ";
    }
}

int main() {
    run();
    return 0;
}
