#include <iostream>
#include <limits>
/*
 *求两个子数组最大的累加和
 * 【题目】
 *  给定一个数组，其中当然有很多的子数组，在所有两个子数组的组合中，找到相加和最大的一组，要求两个子数组无重合的部分。最后返回累加和。
 * 【要求】
 *  时间复杂度达到O(N)
 *
 *  先建立数组arr1保存每次到i的子数组最大累加和
 *  然后再从末尾开始建立数组arr2，也是保存从end到i的子数组最大累加和
 *  然后比较每次 arr1[i-1] + arr2[i]的和的最大值
 *  即为所求的值
 */

using namespace std;

const int int_min = numeric_limits<int>::min();

int getTwoSubarrMaxSum(int arr[], int sz) {
    int maxsubarr[sz]; 
    int sum = arr[0];

    maxsubarr[0] = sum;
    for (int r=1; r<sz; ++r) {
        if (sum < 0)
            sum = arr[r];
        else
            sum += arr[r];
        maxsubarr[r] = max(sum, maxsubarr[r-1]); 
    }

    sum = arr[sz-1];
    maxsubarr[sz-1] = sum;
    int twosub_sum = int_min;
    for (int l=sz-2; l>0; --l) {
        twosub_sum = max(twosub_sum,
            maxsubarr[l+1] + maxsubarr[l]);
        
        if (sum < 0) 
            sum = arr[l];
        else 
            sum += arr[l];

        maxsubarr[l] = max(sum,
            maxsubarr[l+1]);
    }
    return twosub_sum;
}

void run() {
    int arr[100] = {0};
    int sz = -1;
    cout << "please cin arr sz: ";
    
    while (cin >> sz && sz > 0) {
        cout << "please cin arr:" << endl;
        for (int i=0; i<sz; ++i) cin >> arr[i];
        cout << "get two subarr max sum: "
             << getTwoSubarrMaxSum(arr, sz)
             << endl << "-------------"
             << endl;
        cout << "please cin arr sz: "; 
    }
}

int main() {
    run();
    return 0;
}
