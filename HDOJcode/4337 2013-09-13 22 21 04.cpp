******************************
    Author : townboy
    Submit time : 2013-09-13 22:21:04
    Judge Status : Accepted
    HDOJ Runid : 9166463
    Problem id : 4337
    Exe.time : 0MS
    Exe.memory : 320K
    https://github.com/townboy
******************************


 /*1007 King Arthur's Knights
    ÖÐµÈÌâ£¬¹¹ÔìÒ»¸öÌØÊâÍ¼µÄHamilton»ØÂ·¡£Ê×ÏÈËæ»úµÃµ½Ò»¸ö»·ÐòÁÐa1, a2, ..., an, Èç¹ûa(i)->a(i+1)ÔÚÍ¼ÖÐÃ»ÓÐ±ß£¬ÒòÎªÃ¿¸öµãÖÁÉÙºÍÒ»°ëµÄµãÓÐ±ßÏàÁ¬£¬ÓÚÊÇÒ»¶¨¿ÉÒÔÕÒµ½ÁíÒ»¸öµãj£¬Âú×ãa(i)-a(j)ÓÐ±ß£¬a(i+1)-a(j+1)ÓÐ±ß¡£È»ºó·´×ª»·ÖÐa(i+1)µ½a(j)ÕâÒ»¶ÎÐòÁÐ£¬¼´¿ÉÁî»·ÉÏ´æÔÚµÄ±ßÊýÔö¼Ó1»ò2£¨È¡¾öÓÚÔ­À´µÄ»·ÉÏa(j)->a(j+1)ÊÇ·ñÓÐ±ß£©¡£¼ÌÐø´Ë¹ý³ÌÖ±µ½»·ÉÏËùÓÐµÄ±ß¶¼´æÔÚ.
*/

#include <stdio.h>
#include <iostream>
#include <memory.h>
#include <algorithm>
#include <memory.h>
#include <vector>

using namespace std;

#define maxn 155

int n ,m;
bool G[maxn][maxn];
int q[maxn];

void read() {
    int u ,v;
    memset(G, false, sizeof(G));
    for(int i = 0 ;i < m;i++) {
        scanf("%d%d",&u,&v);
        G[u][v] = G[v][u] = true;
    }
}

void solve() {
    for(int i = 0 ; i < n;i++)
        q[i] = i+1;
    for(int i = 0 ;i < n;i++) {
        int I = q[i] , _I = q[(i+1)%n];
        if(true == G[I][_I])
            continue;
        for(int f = 0;f < n; f++) {
            int F = q[f] , _F = q[(f+1)%n];
            if(true == G[I][F] && true == G[_I][_F]) {
                int st = (i+1)%n ,ed = (f+1)%n;
                if(st < ed)
                    reverse(q + st,q + ed);
                else
                    reverse(q + ed,q + st);
                break;
            }
        }
    }
}

void ans() {
    for(int i = 0 ;i < n-1;i++)
        cout << q[i] << " ";
    cout << q[n-1] << endl;
}

int main() {
    while(cin >> n >> m) {
        read();
        solve();
        ans();
    }
    return 0;
}
