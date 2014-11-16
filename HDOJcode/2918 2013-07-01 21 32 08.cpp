******************************
    Author : townboy
    Submit time : 2013-07-01 21:32:08
    Judge Status : Accepted
    HDOJ Runid : 8514199
    Problem id : 2918
    Exe.time : 750MS
    Exe.memory : 14500K
    https://github.com/townboy
******************************


#include<stdio.h>
#include<memory.h>
#include<iostream>
#include<algorithm>
#include<queue>

using namespace std;

int deep;
int ans[400000];
int fac[] = {40320,5040,720,120,24,6,2,1,1};

struct node{
    int s[9];
    int state;
};
node tem;

int conto(node tem){
    int ans=0,exist[10],num;
    memset(exist,0,sizeof(exist));
    for(int i = 0;i<9;i++){
        num=0;
        for(int f = 1;f<tem.s[i];f++)
            if(0 == exist[f])
                num++;
        ans += fac[i] * num;
        exist[tem.s[i]] = 1;
    }
    return ans;
}

int read(){
    char ch[20];
    scanf("%s",ch);
    deep = ch[0] - '0';
    int flag = deep;
    for(int i=1;i<10;i++){
        tem.s[i-1] = ch[i] - '0';
        if(tem.s[i-1] != 0)
            flag = 1;
    }
    return 0==flag?0:1;
}

queue<node>q;
int pos[] = {0,1,3,4};

void debug(node tem){
    for(int i=0;i<9;i++){
        if(0 == i%3)
            cout << endl;
        cout << " " << tem.s[i];
    }
    cout << endl;
}

void ni(node tem,int pos){
    int zan = tem.s[pos];
    tem.s[pos] = tem.s[pos+1];
    tem.s[pos+1] = tem.s[pos+4];
    tem.s[pos+4] = tem.s[pos+3];
    tem.s[pos+3] = zan;
    
    int state = conto(tem);
    if(-1 != ans[state])
        return ;
    ans[state] = ans[tem.state]+1;
    tem.state = state;
    q.push(tem);
}

void shun(node tem,int pos){
    int zan = tem.s[pos];
    tem.s[pos] = tem.s[pos+3];
    tem.s[pos+3] = tem.s[pos+4];
    tem.s[pos+4] = tem.s[pos+1];
    tem.s[pos+1] = zan;

    int state = conto(tem);
    if(-1 != ans[state])
        return ;
    ans[state] = ans[tem.state]+1;
    tem.state = state;
    q.push(tem);
}

void bfs(){
    node tem;
    while(!q.empty()){
        tem = q.front();
        q.pop();
        for(int i=0;i<4;i++){
            shun(tem,pos[i]);
            ni(tem,pos[i]);
        }
    }
}

int main()
{
    int cas = 0;
    memset(ans,-1,sizeof(ans));
    
    for(int i=0;i<9;i++)
        tem.s[i] = i+1;
    tem.state = 0;
    ans[0] = 0;
    q.push(tem);
    bfs();
    while(1 == read()){
        int state = conto(tem);
        cas++;
        cout << cas << ". " ;
        if(ans[state] > deep)
            cout << "-1" << endl;
        else
            cout << ans[state] << endl;
    }
    return 0;
}