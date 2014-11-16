******************************
    Author : townboy
    Submit time : 2013-06-30 20:43:38
    Judge Status : Accepted
    HDOJ Runid : 8511439
    Problem id : 1043
    Exe.time : 484MS
    Exe.memory : 21568K
    https://github.com/townboy
******************************


#include<stdio.h>
#include<iostream>
#include<string>
#include<memory.h>
#include<queue>

using namespace std;

string path[400000];
int hash[400000];
int fac[]={40320,5040,720,120,24,6,2,1,1};

struct node{
    int s[9];
    int pos,state;
};

queue<node>q;
    
int conto(node tem){
    int ans=0,exist[10],num;
    memset(exist,0,sizeof(exist));
    for(int i=0;i<9;i++){
        num = 0;
        for(int f=1;f<tem.s[i];f++){
            if(0 ==  exist[f])
                num++;
        }
        exist[tem.s[i]] = 1;
        ans += num*fac[i];
    }
    return ans;
}
    
void debug(node tem){
    for(int i=0;i<9;i++){
        if(0 == i%3)
            puts("");
        printf("%d ",tem.s[i]);
    }
    puts("");
}
    
void fun(node tem,int pos,string PATH){
    node to;
    to = tem;
    to.pos = pos;
    to.s[tem.pos] = tem.s[to.pos];
    to.s[to.pos] = tem.s[tem.pos];
    to.state = conto(to);
    if(1 == hash[to.state])    return ;
    hash[to.state] = 1;
    path[to.state] = PATH;
    q.push(to);
}
    
void bfs()
{
    node tem,to;
    while(!q.empty()){
        tem = q.front();
        q.pop();
        // debug(tem);
        if(tem.pos > 2)
            fun(tem,tem.pos-3,"d"+path[tem.state]);
        if(tem.pos < 6)
            fun(tem,tem.pos+3,"u"+path[tem.state]);
        if(0 != tem.pos%3)
            fun(tem,tem.pos-1,"r"+path[tem.state]);
        if(0 != (tem.pos+1)%3)
            fun(tem,tem.pos+1,"l"+path[tem.state]);
    }
}

int main()
{
    char ch[4];
    int i;
    node tem;
    for(i=0;i<9;i++)
        tem.s[i] = i+1;
    tem.pos = 8;
    tem.state = 0;
    hash[0] = 1;
    path[0] = "";
    q.push(tem);
    bfs();

        
    while(scanf("%s",ch)!=EOF){
        tem.s[0] = ('x'==ch[0] ? 9:ch[0]-'0');
        for(i=1;i<9;i++){
            scanf("%s",ch);
            tem.s[i] = ('x'==ch[0] ? 9:ch[0]-'0');
        }
        int state = conto(tem);
        if(0 != state && path[state] == "")
            cout << "unsolvable" << endl;
        else     
            cout << path[state] << endl;
    }
    return 0;
}