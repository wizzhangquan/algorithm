#include <queue>
#include <iostream>
#include <stdio.h>
#include <map>
#include <string>

using namespace std;

//poj.org/problem?id=2259

static const int MAXQUECNT = 1005;

int main() {
    int teamcnt;
    char oper[10] = {0};
    int testnum = 0;
    while(scanf("%d", &teamcnt) && teamcnt > 0) {
        int elecnt, element;
        map<int, int> team;
        queue<int> teamq;
        queue<int> elemq[MAXQUECNT];

        printf("Scenario #%d\n", ++testnum);
        for (int teami = 0; teami != teamcnt; ++teami) {
            scanf("%d", &elecnt);
            for (int elei = 0; elei != elecnt; ++elei) {
                scanf("%d", &element);
                team[element] = teami;
            }
        }
        for (;;) { 
            scanf("%s", oper);
            if (oper[0] == 'S') break;
            if (oper[0] == 'D') {
                int teami = teamq.front();
                while(elemq[teami].empty()) {
                    teamq.pop();
                    teami = teamq.front();
                }
                int top = elemq[teami].front();
                elemq[teami].pop();
                printf("%d\n", top);
            }else { //ENQUEUE
                scanf("%d", &element);
                int teami = team[element];
                if (elemq[teami].empty())
                    teamq.push(teami);
                elemq[teami].push(element);
            }
        }
        printf("\n");
    }
    return 0;
}
