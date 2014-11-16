******************************
    Author : townboy
    Submit time : 2013-07-02 14:54:51
    Judge Status : Accepted
    HDOJ Runid : 8516206
    Problem id : 1813
    Exe.time : 265MS
    Exe.memory : 312K
    https://github.com/townboy
******************************


#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<memory.h>
#include<string>
#include<queue>
#define INF 0x3f3f3f3f

using namespace std;

int n;
char map[10][10];
int dir[4][2] = {0,1,-1,0,1,0,0,-1};
int deep;
string pr[4];
int path[100];

void ans(){
    for(int i=0;i<deep;i++)
        cout << pr[path[i]] << endl;
}

struct S{
    int pos[100][2];
    int left;
};
S lz;

int pos[200][2],now;
int dis[10][10];

int h(){
    int ans = 0;
    for(int i=0;i<lz.left;i++)
        ans = max(ans,dis[ lz.pos[i][0] ][ lz.pos[i][1] ]);
    return ans;
}

bool check(int x,int y){
    if(x<0 || x>=n || y<0 || y>=n)
        return false;
    if('1' == map[x][y])
        return false;
    return true;
}

bool handle(int now){
    bool flag = false;
    for(int i = 0; i < lz.left ;i++){
        int nx = lz.pos[i][0] + dir[now][0];
        int ny = lz.pos[i][1] + dir[now][1];
        if('0' == map[nx][ny]){
            flag = true;
            if(0==nx || n-1==nx || 0==ny || n-1==ny){
                lz.pos[i][0] = lz.pos[lz.left-1][0]; 
                lz.pos[i][1] = lz.pos[lz.left-1][1]; 
                lz.left --;
                i--;
            }
            else{
                lz.pos[i][0] = nx;
                lz.pos[i][1] = ny;
            }
        }
    }
    return flag;
}

void debug(){
    cout << "Begin" << endl;
    for(int i = 0;i < lz.left;i++)
        cout << lz.pos[i][0] << " " << lz.pos[i][1] << endl;
    cout << "End " << endl;
}

bool ID(int d){
    int state = h();
    if(0 == state){
        return true;
    }
    if(d + state > deep)
        return false;
    S tem = lz;
    for(int i = 0;i < 4;i++){
        bool flag = handle(i);
        if(false == flag){
            lz = tem;
            continue;
        }
        path[d] = i;
        if(true == ID(d+1))
            return true;
        lz = tem;
    }
}

int hash[10][10];

void bfs(int sx,int sy){
    queue<int>q;
    memset(hash,0x3f,sizeof(hash));
    q.push(sx);
    q.push(sy);
    hash[sx][sy] = 0;
    while(!q.empty()){
        int x = q.front();q.pop();
        int y = q.front();q.pop();
        
        dis[x][y] = min(hash[x][y],dis[x][y]);
        for(int i = 0;i < 4;i++){
            int nx = x + dir[i][0];
            int ny = y + dir[i][1];
            if(false == check(nx,ny))
                continue;
            if(INF != hash[nx][ny])
                continue;
            hash[nx][ny] = hash[x][y] + 1;
            q.push(nx);
            q.push(ny);
        }
    }
}

void init(){
    memset(dis,0x3f,sizeof(dis));
    lz.left = 0;
    for(int i = 0 ;i < n;i++)
        for(int f = 0;f < n;f++)
        {
            if('1' == map[i][f])
                continue;
            if(i!=0 && n-1!=i && 0!=f && n-1!=f){
                lz.pos[lz.left][0] = i;
                lz.pos[lz.left][1] = f;
                lz.left ++;
            }
            else
                bfs(i,f);
        }
}

void map_debug(){
    for(int i = 0;i < n;i++)
        cout << map[i] << endl;
    cout << endl;
}

int main()
{
    int cas = 0;
    
    pr[0] = "east";
    pr[1] = "north";
    pr[2] = "south";
    pr[3] = "west";
    
    while(scanf("%d",&n) != EOF){
        getchar();
        for(int i=0;i<n;i++)
            gets(map[i]);
        init();
        for(deep = 0;;deep++){
            if(true == ID(0))
                break;
        }
        cas ++;
        if(1 != cas)
            cout << endl;
        ans();
    }
    return 0;
}