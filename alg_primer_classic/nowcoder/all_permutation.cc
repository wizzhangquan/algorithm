#include <iostream>
#include <algorithm>
#include <utility>

using namespace std;

//全排列

void all_permutation(int arr[], int from, int to) {
    if (to <= 1) return ;
    if (from == to) {
        for (int i = 0; i<=to; ++i)
            cout << arr[i];
        cout << endl;
    }else {
        for (int i = from; i <= to; ++i) {
            swap(arr[i], arr[from]);
            all_permutation(arr, from+1, to);
            swap(arr[i], arr[from]);
        }

    }
}

int main() {
    int a[] = {1,2,3,4};
    all_permutation(a, 0, 3);
    return 0;
}
