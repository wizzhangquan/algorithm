#include <iostream>

/*
 * 求两个子数组最大的累加和
 * 【题目】
 * 给定一个数组，其中当然有很多的子数组，在所有两个子数组的组合中，找到相加和最大的一组，要求两个子数组无重合的部分。最后返回累加和。
 * 【要求】
 * 时间复杂度达到O(N)
 *
 * 思路1：利用获得数组中最大累加和子数组的算法M
 * 将数组分为2个子数组，每个子数组做算法M求最大和 0(N*N)
 *
 * 思路2：先找出最大累加和sum1子数组及其位置 start,end
 * 然后在0-start ,end-arr_sz中再次找一个最大累加和子数组sum2
 * if (sum2 > 0) return sum1+sum2; 
 * else return sum1;
 */

using namespace std;

int getMaxSubarrSum(int *arr, int sz, int *start, int *end) {
    int sum = arr[0];
    int maxsum = sum;
    *start = 0;
    *end = 0;
    int l = 0, r = 0;
    for (int i=1; i<sz; ++i) {
        if (sum <= 0) {
            sum = arr[i];
            l = i;
        }
        else
            sum += arr[i];
        if (maxsum < sum) {
            *start = l;
            *end = i+1;
        }
    }
    return maxsum;
}

void test_getMSS() {
    int arr[100] = {0};
    int sz = -1, start, end;
    cout << "please cin arr sz: ";
    while (cin >> sz && sz > 0) {
        cout << "please cin arr:" << endl;
        for (int i=0; i<sz; ++i) cin >> arr[i];
        cout << "get the max subarr's sum : "
             << getMaxSubarrSum(arr, sz, &start, &end)
             << endl << "the subarr is: " << endl;
        for (int i=start; i<end; ++i) cout << arr[i] << " ";
        cout << endl;
        cout << "-------------" << endl
             << "please cin arr sz: ";
    }
}

int getMaxTwoSubarrSum(int arr[], int sz) {
    return 0;    
}

int main() {
    test_getMSS();
    return 0;
}
