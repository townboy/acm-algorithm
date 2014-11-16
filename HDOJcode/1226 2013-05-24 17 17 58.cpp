******************************
    Author : townboy
    Submit time : 2013-05-24 17:17:58
    Judge Status : Accepted
    HDOJ Runid : 8373398
    Problem id : 1226
    Exe.time : 125MS
    Exe.memory : 1468K
    https://github.com/townboy
******************************


#include<stdio.h>
#include<iostream>
#include<queue>
#include<memory.h>
#include<string>
#include<algorithm>

using namespace std;

char dig[10];
int n,c,m;
int allow[16];
string state[5100],d="0123456789ABCDEF";

int turn(){
    if(dig[0]>='0' && dig[0]<='9')
        return dig[0]-'0';
    return dig[0]-'A'+10;
}

void init(){
    for(int i=0;i<n;i++)
        state[i]="";
}

string bfs(){
    int i,S,nS;
    string path;
    queue<int>q;
    q.push(0);
    while(!q.empty())
    {
        S=q.front();q.pop();
        if(state[S].length() == 500)    continue;
        for(i=0;i<m;i++)
        {
            nS=(S*c+allow[i])%n;
            path=state[S]+d[allow[i]];
            if(0==S && 0==allow[i])    continue;
            if(0 == nS)
                return path;
            if("" == state[nS]){
                state[nS]=path;
                q.push(nS);
            }
        }
    }
    return "give me the bomb please";
}

int main()
{
    int cas,i,f;
    scanf("%d",&cas);
    for(i=0;i<cas;i++)
    {
        scanf("%d%d",&n,&c);
        scanf("%d",&m);
        init();
        for(f=0;f<m;f++)
        {
            scanf("%s",dig);
            allow[f]=turn();
        }
        sort(allow,allow+m);
        if(0 == n){
            puts(0==allow[0]?"0":"give me the bomb please");
            continue;
        }
        cout<<bfs()<<endl;
    }
    return 0;
}