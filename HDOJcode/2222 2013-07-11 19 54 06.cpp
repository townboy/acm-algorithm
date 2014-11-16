******************************
    Author : townboy
    Submit time : 2013-07-11 19:54:06
    Judge Status : Accepted
    HDOJ Runid : 8568719
    Problem id : 2222
    Exe.time : 484MS
    Exe.memory : 27580K
    https://github.com/townboy
******************************


#include <cstdio>
#include <cstdlib>
#include <string>
#include <climits>
#include <iostream>
#include <vector>
#include <set>
#include <cmath>
#include <cctype>
#include <algorithm>
#include <sstream>
#include <map>
#include <cstring>
#include <queue>
using namespace std;

const int MAX_NODE = 500100;

const int CHILD_NUM = 26;

struct ACAutomaton {
    int chd[MAX_NODE][CHILD_NUM];
    int val[MAX_NODE];
    int fail[MAX_NODE];

    int Q[MAX_NODE];

    int ID[128];

    int sz;
    
    void Initialize() {
        fail[0] = 0;
        for (int i = 0 ; i < CHILD_NUM ; i ++) {
            ID[i+'a'] = i;
        }
    }

    void Reset() {
        memset(chd[0] , 0 , sizeof(chd[0]));
        sz = 1;
    }
    
    void Insert(char *a) {
        int p = 0;
        for ( ; *a ; a ++) {
            int c = ID[*a];
            if (!chd[p][c]) {
                memset(chd[sz] , 0 , sizeof(chd[sz]));
                val[sz] = 0;
                chd[p][c] = sz ++;
            }
            p = chd[p][c];
        }
        val[p] ++;
    }

    void Construct() {
        int *s = Q , *e = Q;
        for (int i = 0 ; i < CHILD_NUM ; i ++) {
            if (chd[0][i]) {
                fail[ chd[0][i] ] = 0;
                *e ++ = chd[0][i];
            }
        }
        while (s != e) {
            int u = *s++;
            for (int i = 0 ; i < CHILD_NUM ; i ++) {
                int &v = chd[u][i];
                if (v) {
                    *e ++ = v;
                    fail[v] = chd[ fail[u] ][i];
                } else {
                    v = chd[ fail[u] ][i];
                }
            }
        }
    }
    
    int work(char wen[]) {
        int ans = 0;
        for(int i = 0,f = 0 ; wen[i] ; i++) {
            int c = ID[wen[i]];
            f = chd[f][c];
            int tem = f;
            while(tem){
                if(0 != val[tem]){
                    ans += val[tem];
                    val[tem] = 0;
                }
                tem = fail[tem];
            }
        }
        return ans;
    }
}AC;

char tem[55];
char wen[1100000];

int main() {
    int cas;
    AC.Initialize();
    cin >> cas;
    for(int i = 0 ;i < cas;i++){
        int n;
        AC.Reset();
        cin >> n;
        for(int f = 0; f < n;f++){
            scanf("%s",tem);
            AC.Insert(tem);
        }
        AC.Construct();
        scanf("%s",wen);
        cout << AC.work(wen) << endl;
    }
    return 0;
}
