#include <iostream>
#include <limits>


//本算法错误
//原因见下面思路2分析, 因为在最大累加和中可以拆分掉负数，然后
//两个子数组最大累加和会出现在此间
//
//正确版本: 
//accumulate_sum_questions/tow_subarr_max_sum.cc

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
 * 思路2： 错误思路
 * 先找出最大累加和sum1子数组及其位置 start,end
 * 然后在0-start ,end-arr_sz中再次找一个最大累加和子数组sum2
 * if (sum2 > 0) return sum1+sum2; 
 * else return sum1;
 *
 * 思路3：
 * 构造sum数组，从左至右构造 再从右至左构造
 * 那么 得到arr[0---i] 与 arr[i+1---end]的最大值即可
 */

using namespace std;

#define INT_MIN numeric_limits<int>::min()

/*
int getMaxSubarrSum(int *arr, int sz, int *start, int *end) {
    int sum = arr[0];
    int maxsum = sum;
    int m_start = 0, m_end = 0;
    int l = 0, r = 0;

    for (int i=1; i<sz; ++i) {
        if (sum <= 0) {
            sum = arr[i];
            l = i;
        }
        else
            sum += arr[i];
        if (maxsum < sum) {
            maxsum = sum;
            m_start = l;
            m_end = i+1;
        }
    }
    if (start != NULL) *start = m_start;
    if (end != NULL) *end = m_end;
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
*/
/*  ERROR
int getMaxTwoSubarrSum(int arr[], int sz) {
*
 * ERROR
 * [1, -1, 0, -2, 3, 5, -2, 8, 7, -4]
 * 两个子数组： [3, 5] [8, 7]
 * 但是使用此算法 为 [1], [3, 5, -2, 8, 7]
 * 故而是错误
 *
    if (sz < 2) return INT_MIN;
    if (sz == 2) return arr[0] + arr[1];

    int start, end;
    int sum_max = 
        getMaxSubarrSum(arr, sz, &start, &end);

    int sum_less = INT_MIN;
    if (start > 0) {
        sum_less = 
            getMaxSubarrSum(arr, start, NULL, NULL); 
    }

    if (end < sz) {
        int sum_less_end =
            getMaxSubarrSum(arr+end, sz-end, NULL, NULL);
        sum_less = 
            sum_less > sum_less_end ? sum_less : sum_less_end;
    }
     
    cout << endl;
    cout << "First max sum: " << sum_max
         << "   Second max sum: " << sum_less << endl; 
    
    if (sum_less < 0 && (end - start != 1))
        return sum_max;
    else
        return sum_max + sum_less;
}
*/


void run() {
    int arr[100] = {0};
    int sz = -1;
    cout << "please cin arr sz: ";
    while (cin >> sz && sz > 0) {
        cout << "please cin arr:" << endl;
        for (int i=0; i<sz; ++i) cin >> arr[i];
        cout << "get the two max subarr's sum : "
             << getMaxTwoSubarrSum(arr, sz) 
             << endl
             << "-------------" << endl
             << "please cin arr sz: ";
    }   
}

int main() {
    run();
    return 0;
}
