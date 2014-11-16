******************************
    Author : townboy
    Submit time : 2013-08-16 21:20:37
    Judge Status : Accepted
    HDOJ Runid : 8969889
    Problem id : 4681
    Exe.time : 359MS
    Exe.memory : 9784K
    https://github.com/townboy
******************************


#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<memory.h>
#include<string.h>

using namespace std;

#define maxn 1100

char a[maxn], b[maxn], c[maxn];
int lena, lenb, lenc;

void read() {
    scanf("%s%s%s",a,b,c);
    lena = strlen(a);
    lenb = strlen(b);
    lenc = strlen(c);
}

int dpl[maxn][maxn];
int dpr[maxn][maxn];

void init() {
    memset(dpl,0,sizeof(dpl));
    memset(dpr,0,sizeof(dpr));
    
    for(int i = 1 ;i <= lena;i++) {
        for(int f = 1; f <= lenb; f++)
            if(a[i-1] == b[f-1])
                dpl[i][f] = dpl[i-1][f-1] + 1;
            else
                dpl[i][f] = max(dpl[i-1][f],dpl[i][f-1]);
    }

    for(int i = lena; i >= 1; i--) {
        for(int f = lenb;f >= 1; f--)
            if(a[i-1] == b[f-1])
                dpr[i][f] = dpr[i+1][f+1] + 1;
            else
                dpr[i][f] = max(dpr[i+1][f],dpr[i][f+1]);
    }
}

int enda[maxn], endb[maxn];

void debug() {
    for(int i = 0; i < lena;i ++) 
        cout << enda[i] << " " ;
    cout << endl;
}

int solve() {
    int i ,f;
    memset(enda,-1,sizeof(enda));
    memset(endb,-1,sizeof(endb));

    for(i = 0; i < lena;i ++) {
        if(c[0] != a[i])
            continue;
        int t = 0;
        for(f = i;f < lena;f++) {
            if(c[t] == a[f])
                t ++;
            if(t == lenc)
                break;
        }
        if(f == lena)
            break;
        enda[i] = f;
    }

    for(i = 0; i < lenb;i ++) {
        if(c[0] != b[i])
            continue;
        int t = 0;
        for(f = i;f < lenb;f++) {
            if(c[t] == b[f])
                t ++;
            if(t == lenc)
                break;
        }
        if(f == lenb)
            break;
        endb[i] = f;
    }
    
    init();
    int ans = 0;
    for(int i = 0 ;i < lena;i ++)
        for(int f = 0 ;f < lenb ;f ++)
            if(-1 != enda[i] && -1 != endb[f])
                ans = max(ans,lenc+dpl[i][f]+dpr[enda[i]+2][endb[f]+2]);
    return ans;
}

int main() {
    int cas;
    cin >> cas;
    for(int i = 0;i < cas; i++) {
        read();
        printf("Case #%d: ",i+1);
        cout << solve() << endl;
    }
    return 0;
}