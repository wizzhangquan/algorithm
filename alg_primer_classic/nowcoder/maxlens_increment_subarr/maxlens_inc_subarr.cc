#include <iostream>

using namespace std;

//最长递增子序列
// [2,0,1,4,6,5,3] => [0,1,4,5]

const int maxsz = 100;

int search_bigger_p(int arr[], int sz, int search_num);

void copy_arr(int a[], int b[], int sz) {
    for (int i=0; i<sz; ++i) a[i] = b[i];
}

//@return: maxlen subarr's len
//subarr[] is in/out param
int get_longest_increment_subarr(int arr[], 
            int sz, int subarr[]) {
    
    int r = 0;
    int bigger_pointer = 0;
    int longest = 1; 
    int help[sz];
    help[0] = arr[0];
    for (int i = 1; i < sz; ++i) {
        bigger_pointer = search_bigger_p(help, longest, arr[i]);
        /*
        cout << "in arr[" << i << "]:" << arr[i]
             << " ==> p:" << bigger_pointer
             << endl << "    subarr:";
        for (int j=0; j<=bigger_pointer; ++j) 
            cout << help[j] << " ";
        cout << endl; 
        */
        
        longest = max(longest, bigger_pointer+1);
        help[bigger_pointer] = arr[i];
        if (bigger_pointer+1 == longest)
            copy_arr(subarr, help, longest); //拷贝当前最长子序列，但是不准确，还是会有错误例子上的就是
    }
    return longest;
}


int search_bigger_p(int arr[], int sz, int num) {
    int begin = 0;
    int end = sz-1;
    int mid;

    while (begin <= end) {
        mid = (begin + end) / 2;
        if (arr[mid] == num)
            return mid;
        if (arr[mid] > num) {
            end = mid - 1;
        } else 
            begin = mid + 1;
    }
    return begin;
}

void test_search_p(void) {
    int arr[maxsz] = {0}; //but here is can initialize
    int sz = 0;
    cout << "please cin sz : ";
    cin >> sz;
    cout << "please cin arr : " << endl;
    for (int i=0; i<sz; ++i) cin >> arr[i];

    cout << "please cin which num u want search : ";
    int search, position;
    while (cin >> search && search != -1) {
        position = search_bigger_p(arr, sz, search);
        cout << "find the " << search << "'s position : "
             << position << " and num is: " 
             << arr[position] << endl;

        cout << "please cin which num u want search : ";
    }
}

void run(void) {
    int arr[maxsz] = {0};
    int subarr[maxsz] = {0};
    int sz = 0;

    cout << "please cin sz : ";
    while (cin >> sz && sz > 0) {
        cout << "please cin arr : " << endl;
        for (int i=0; i<sz; ++i) cin >> arr[i];
        int longest_len =
            get_longest_increment_subarr(arr, sz, subarr);
        cout << "the longest subarr's len : " 
             << longest_len << endl
             << " the arr : " << endl;
        for (int i=0; i<longest_len; ++i) 
            cout << subarr[i] << " "; 
        cout << endl;
        cout << "please cin sz : "; 
    }
}

int main() {
    //test_search_p();
    run();
    return 0;
}
