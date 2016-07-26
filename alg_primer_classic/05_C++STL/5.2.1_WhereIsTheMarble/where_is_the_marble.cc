#include <cstdio>
#include <algorithm>

using namespace std;

const int maxn = 10000;
/*
 * 这个题目不详述了
 *
 * 但cin/cout过于慢，故而这里不使用
 * 同样的还有string
 */
int main() {
    int num, query_cnt, kase = 0, arr[maxn], query;
    while (scanf("%d%d", &num, &query_cnt) == 2 && num) {
        printf("CASE# %d:\n", ++kase);
        for (int i=0; i<num; ++i) scanf("%d", &arr[i]);
        sort(arr, arr+num);
        while (query_cnt--) {
            scanf("%d", &query);
            int exist_position = lower_bound(arr, arr+num, query) - arr;
            if (arr[exist_position] == query) 
                printf("%d found at %d\n", query, exist_position);
            else
                printf("%d not found\n", query);
        }
    }
    return 0;
}
