******************************
    Author : townboy
    Submit time : 2013-05-28 16:17:50
    Judge Status : Accepted
    HDOJ Runid : 8396025
    Problem id : 4294
    Exe.time : 250MS
    Exe.memory : 364K
    https://github.com/townboy
******************************


#include<stdio.h>
#include<iostream>
#include<string>
#include<queue>
#include<memory.h>

using namespace std;

char dig[12]="0123456789";
int n,c;
int m,use[2];
char state[10010];
int pre[10010];

void init(){
    memset(state,0,sizeof(state));
    memset(pre,-1,sizeof(pre));
}

string makestring(int x){
    string ans="";
    char tem;
    while(-1 != pre[x]){
        ans+=state[x];
        x=pre[x];
    }
    for(int i=0;i<ans.length()/2;i++){
        tem=ans[i];
        ans[i]=ans[ans.length()-i-1];
        ans[ans.length()-i-1]=tem;
    }
    return ans;
}

string bfs()
{
    int S,i,nS;
    queue<int>q;
    q.push(0);
    init();
    while(!q.empty())
    {
        S=q.front();q.pop();
        for(i=0;i<m;i++)
        {
            if(use[i]==0 && S==0)    continue;
            nS=(S*c+use[i])%n;
            if(0 == nS){
                return makestring(S)+dig[use[i]];
            }
            if(0 != state[nS])    continue;
            pre[nS]=S;
            state[nS]=dig[use[i]];
            q.push(nS);
        }
    }
    return "-1";
}

int check(string res,string ans){
    if(res.length() < ans.length())
        return 1;
    if(res.length() > ans.length())
        return 0;
    if(res < ans)    return 1;
    return 0;
}

void update(string &ans,string res){
    if("-1" == ans){
        ans =  res;
        return;
    }
    if("-1" == res)    return ;
    if(1 == check(res,ans))
        ans = res;
}

int main()
{
    int i,f;
    string ans,res;
    while(scanf("%d%d",&n,&c)!=EOF)
    {
        ans="-1";
        for(i=1;i<c;i++)
        {
            m=1;
            use[0]=i;
            update(ans,bfs());
        }
        if(ans != "-1"){
            cout << ans << endl;
            continue;
        }
        for(i=0;i<c;i++)
            for(f=i+1;f<c;f++)
            {
                m=2;
                use[0]=i;
                use[1]=f;
                update(ans,bfs());
            }
        cout << ans << endl;
    }
    return 0;
}