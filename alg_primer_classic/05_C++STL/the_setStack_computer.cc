#include <iostream>
#include <stdio.h>
#include <string>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <stack>
#include <iterator>

using namespace std;

//poj.org/problem?id=3121

typedef set<int> setInt;
map<setInt, int> idCache;
vector<setInt> setCache;

int getId(const setInt &s) {
    if (idCache.count(s))
        return idCache[s];
    int sId = setCache.size();
    setCache.push_back(s);
    idCache[s] = sId;
    return sId;
}

int main() {
    int enterCnt;
    int operCnt;
    //string oper;
    char oper[15] = {0};
    scanf("%d", &enterCnt);
    if (enterCnt <= 0) return 1;

    for (int enteri = 0; enteri != enterCnt; ++enteri) {
        scanf("%d", &operCnt);
        stack<int> stk;
        //idCache.clear();
        //setCache.clear();

        for (int operi = 0; operi != operCnt; ++operi) {
            //cin >> oper;
            scanf("%s", oper);
            if (oper[0] == 'P') {
                stk.push(getId(setInt()));
                //cout << "stk's top:" << stk.top() << endl;
            }else if (oper[0] == 'D')
                stk.push(stk.top());
            else {
                setInt s1 = setCache[stk.top()]; stk.pop();
                setInt s2 = setCache[stk.top()]; stk.pop();
                setInt s;
                if (oper[0] == 'U') { //UNION
                    set_union(s1.begin(), s1.end(), s2.begin(), s2.end(), inserter(s, s.begin()));
                } else if (oper[0] == 'I') { //INTERSECT
                    set_intersection(s1.begin(), s1.end(), s2.begin(), s2.end(), inserter(s, s.begin()));
                } else { //ADD
                    s = s1;
                    s.insert(getId(s2));
                }
                stk.push(getId(s));
            }
            printf("%d\n", setCache[stk.top()].size());
        }
        printf("***\n");
    }
    return 0;
}
