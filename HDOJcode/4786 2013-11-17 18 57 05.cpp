******************************
    Author : townboy
    Submit time : 2013-11-17 18:57:05
    Judge Status : Accepted
    HDOJ Runid : 9608096
    Problem id : 4786
    Exe.time : 328MS
    Exe.memory : 2544K
    https://github.com/townboy
******************************


    #include <stdio.h>  
    #include <iostream>  
    #include <memory.h>  
    #include <queue>  
      
    using namespace std;  
      
    typedef pair<int,int> PII;  
    #define maxn 110000  
      
    PII b[maxn];  
    PII w[maxn];  
    int jb, jw;  
    int n ,m;  
      
    bool isfib[maxn];  
    int set[maxn];  
      
    int find(int x) {  
        return set[x] == x ? x : set[x] = find(set[x]);  
    }  
      
    bool solve() {  
        int minn = 0 ,maxx = 0;  
        for(int i = 1;i <= n;i++)  
            set[i] = i;      
      
        for(int i = 0;i < jb ;i++) {  
            int u = b[i].first;  
            int v = b[i].second;  
            u = find(u);  
            v = find(v);  
            if(u != v)  
                set[u] = v;  
        }  
      
        for(int i = 0;i < jw ;i++) {  
            int u = w[i].first;  
            int v = w[i].second;  
            u = find(u);  
            v = find(v);  
            if(u != v) {  
                set[u] = v;  
                minn ++;  
            }  
        }  
      
        int head = 0;  
        for(int i = 1;i <= n; i++)  
            if(set[i] == i)  
                head ++;  
        if(1 != head)  
            return false;  
      
        for(int i = 1;i <= n;i++)  
            set[i] = i;      
      
        for(int i = 0;i < jw ;i++) {  
            int u = w[i].first;  
            int v = w[i].second;  
            u = find(u);  
            v = find(v);  
            if(u != v) {  
                set[u] = v;  
                maxx ++;  
            }  
        }  
        for(int i = minn;i <= maxx;i++)  
            if(true == isfib[i])  
                return true;  
        return false;  
    }  
      
    void init() {  
        int a = 1, b = 2;   
        memset(isfib , false ,sizeof(isfib));  
        isfib[a] = true;  
        while(b < maxn) {  
            isfib[b] = true;  
            int c = a + b;  
            a = b;  
            b = c;  
        }  
    }  
      
    int main() {  
        int cas;  
        cin >> cas;  
        int u ,v, t;  
      
        init();  
      
        for(int i = 0 ;i < cas;i++) {  
            cin >> n >> m;  
            jb = jw = 0;  
            for(int f = 0 ;f < m;f++) {  
                scanf("%d%d%d",&u, &v, &t);  
                if(1 == t)  
                    w[jw ++ ] = make_pair(u,v);  
                else  
                    b[jb ++ ] = make_pair(u,v);  
            }  
            bool ret = solve();  
            printf("Case #%d: ", i + 1);  
            if(true == ret)  
                cout << "Yes" << endl;  
            else  
                cout << "No" << endl;  
        }  
        return 0;  
    }  