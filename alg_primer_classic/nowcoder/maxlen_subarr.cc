#include <iostream>
/*
 * 未排序正数数组中累加和为给定值的最长子数组长度
 *
 * <item>
 * 给定一个数组arr,该数组无序，但每个值为正数，再给定一个正数k。
 * 求arr的所有子数组中所有元素相加和为k的最长子数组长度
 *
 * eg: arr=[1,2,1,1,1], k=3
 * 累加和为3的最长子数组为[1,1,1] ,lens=3
 * 时间复杂度O(N), 额外空间复杂度O(1)
 */

using namespace std;

const int maxsz = 100;

int lens = 0; //if len after the get_subarr == 0 ,its means donot occur the subarr'sum == sum
int maxl = 0;
int maxr = 0;

//@return : max sub arr len
int get_subarr(int *arr, int arr_sz, int sum) {
    int l = 0, r = 0; 
    int sub_sum = 0; //sub_sum = arr [l - (r-1)]

    while (r <= arr_sz) {
        if (sub_sum == sum) {
            if (r-l > lens) {
                lens = r-l;
                maxl = l;
                maxr = r;
            }
            sub_sum -= arr[l++]; 
        }else if (sub_sum < sum) {
            sub_sum += arr[r++];
        }else {
            sub_sum -= arr[l++];
        } 
    }
    return lens;
}

int main(void) {
    int arr[maxsz] = {0};
    int arr_sz = 0;
    int sum = 0;

    while (cin >> arr_sz && arr_sz > 0) {
        for (int i=0; i < arr_sz; ++i)
            cin >> arr[i];
        cin >> sum;
        get_subarr(arr, arr_sz, sum);
        cout << "max subarray : len:" << lens << endl;
        for (int i=maxl; i < maxr; ++i )
            cout << arr[i] << " ";
        cout << endl;
    }

    return 0;
}
