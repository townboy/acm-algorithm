******************************
    Author : townboy
    Submit time : 2013-11-17 18:56:18
    Judge Status : Accepted
    HDOJ Runid : 9608091
    Problem id : 4781
    Exe.time : 15MS
    Exe.memory : 356K
    https://github.com/townboy
******************************


    #include <stdio.h>  
    #include <algorithm>  
    #include <iostream>  
    #include <memory.h>  
    #include <vector>  
      
    using namespace std;  
      
    typedef pair<int,int> PII;  
      
    int n ,m;  
    #define maxn 85  
      
    bool use[maxn][maxn];  
    int ret[maxn][maxn];  
    vector<int> edge[3];  
    int sum[maxn];  
      
    void add(int u,int v,int w) {  
        if(v > n) {  
            ret[u][1] = w;  
            use[u][1] = use[1][u] = true;  
        }  
        else {  
            use[u][v] = use[v][u] = true;  
            sum[v] = sum[v-1] + w;  
            ret[u][v] = w;  
        }  
    }  
      
    void debug() {  
        for(int i = 1;i <= n;i++) {  
            for(int f = 1;f <= n;f++)  
                cout << use[i][f] << " " ;  
            cout << endl;  
        }  
        cout << endl;  
    }  
      
    bool seek(int val) {  
        for(int i = 1 ;i <= n;i++)   
            for(int f = 1;f <= n;f++) {  
                if(i == f)  
                    continue;  
                if(use[i][f] == true)  
                    continue;  
                int tt = 0;  
                if(f > i) {  
                    tt = sum[f] - sum[i];  
                    tt %= 3;  
                }  
                else {  
                    tt = sum[i] - sum[f];  
                    tt %= 3;  
                    tt = 3 - tt;  
                }  
                if(tt == (val % 3)) {  
                    use[i][f] = use[f][i] = true;  
                    ret[i][f] = val;  
                    return true;  
                }  
            }  
        return false;  
    }  
      
    void ans() {  
        for(int i = 1 ;i <= n;i++)  
            for(int f = 0 ;f <= n;f++)  
                if(0 != ret[i][f])  
                    printf("%d %d %d\n",i ,f, ret[i][f]);  
    }  
      
      
    bool solve() {  
        int minn = min(edge[1].size() , edge[2].size());  
        minn = min(minn , n / 2);  
        int le = n - 2 * minn;  
        if(le > edge[0].size())  
            return false;  
        for(int i = 0 ;i < minn;i ++) {  
            add(i + 1, i + 2, *(edge[1].end()-1));  
            edge[1].pop_back();  
        }  
        for(int i = 0 ;i < minn;i ++) {  
            add(minn + i + 1,minn + i + 2,  *(edge[2].end()-1));  
            edge[2].pop_back();  
        }  
        for(int i = 0;i < le ;i++) {  
            add(2 * minn + i + 1,2 * minn + i + 2, *(edge[0].end()-1) );  
            edge[0].pop_back();  
        }  
        for(int i = 0 ;i < 3;i++) {  
            int size = edge[i].size();  
            for(int f = 0 ;f < size;f++)  
                if(false == seek(edge[i][f]))  
                    return false;  
        }  
        return true;  
    }  
      
    void init() {  
        memset(use, false, sizeof(use));  
        memset(ret, 0, sizeof(ret));  
        edge[0].clear();  
        edge[1].clear();  
        edge[2].clear();  
      
        memset(sum ,0, sizeof(sum));  
        for(int i = 1;i <= m;i++)  
            edge[i%3].push_back(i);  
    }  
      
    int main() {  
        int cas;  
        cin >> cas;  
        for(int i = 0 ;i < cas;i++) {  
            cin >> n >> m;  
            printf("Case #%d:\n",i + 1);  
            init();  
            if(true == solve())  
                ans();  
            else  
                cout << "-1" << endl;  
        }  
        return 0;  
    }  