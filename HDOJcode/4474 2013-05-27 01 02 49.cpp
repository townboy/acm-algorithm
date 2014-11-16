******************************
    Author : townboy
    Submit time : 2013-05-27 01:02:49
    Judge Status : Accepted
    HDOJ Runid : 8388096
    Problem id : 4474
    Exe.time : 2031MS
    Exe.memory : 61084K
    https://github.com/townboy
******************************


#include<stdio.h>
#include<memory.h>
#include<iostream>
#include<string>
#include<queue>

using namespace std;

string state[10010];
int allow[10];
int n;
string dig="0123456789";

void init(){
    memset(allow,-1,sizeof(allow));
    for(int i=0;i<n;i++)
        state[i] = "";
}

string bfs(){
    int S,i,nS;
    queue<int>q;
    q.push(0);
    while(!q.empty())
    {
        S=q.front();q.pop();
        for(i=0;i<10;i++)
        {
            if(0 == allow[i])    continue;
            if(0==i && ""==state[S])    continue;
            nS=(S*10+i)%n;
            if(0 == nS)    return state[S]+dig[i];
            if("" != state[nS])    continue;
            state[nS]=state[S]+dig[i];
            q.push(nS);
        }
    }
    return "-1";
}

int main()
{
    int tem,m;
    int cas=0,i;
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        cas++;
        init();
        for(i=0;i<m;i++){
            scanf("%d",&tem);
            allow[tem]=0;
        }
        printf("Case %d: ",cas);
        cout<<bfs()<<endl;
    }
    return 0;
}