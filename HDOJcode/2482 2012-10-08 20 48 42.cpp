******************************
    Author : townboy
    Submit time : 2012-10-08 20:48:42
    Judge Status : Accepted
    HDOJ Runid : 6889524
    Problem id : 2482
    Exe.time : 93MS
    Exe.memory : 548K
    https://github.com/townboy
******************************


#include<stdio.h>
#include<string.h>
#include<string>
#include<iostream>
#include<vector>
#include<map>
#include<queue> 
#include<math.h> 
#include<memory.h>
#define INF 0x7fffffff 
using namespace std; 

int sx,sy,ex,ey,zan;
char ch1[110],ch2[110]; 
int loc[5100][2]; 
vector<int>belong[5100]; 
map<string,int>mp; 
int bus[110][40]; 
int busnum[110],bussum; 
int s,t,n,path[110][110]; 
int dis[110],hash[110]; 

void chu()
{
    int i;
    for(i=1;i<=5000;i++)
    {    
        belong[i].clear(); 
    }
    memset(path,-1,sizeof(path));
    for(i=1;i<=n;i++)
    {
        dis[i]=INF; 
    }
    memset(hash,0,sizeof(hash)); 
} 

void turn()
{
    int i,up,down,left,right;
    up=right=10240;
    down=left=0; 
    for(i=0;i<8;i++) 
    {
        if('1' < ch1[i]) 
        {
            down=(down+up)/2;    
        }
        else
        {
            up=(down+up)/2;                
        } 
        if(0 == (ch1[i]-'0')%2)
        {
            right=(right+left)/2;    
        }
        else
        {
            left=(right+left)/2; 
        } 
    }
    sx+=down;     
    sy+=left; 
    up=right=10240;
    down=left=0; 
    for(i=0;i<8;i++) 
    {
        if('1' < ch2[i]) 
        {
            down=(down+up)/2;    
        }
        else
        {
            up=(down+up)/2;                
        } 
        if(0 == (ch2[i]-'0')%2)
        {
            right=(right+left)/2;    
        }
        else
        {
            left=(right+left)/2; 
        } 
    }
    ex+=down;     
    ey+=left; 
}
 
void check(int x)
{
    int f,v,size,i,sum,u;
    sum=(sx-loc[x][0])*(sx-loc[x][0])+(sy-loc[x][1])*(sy-loc[x][1]); 
    
    size=belong[x].size(); 
    if(sqrt((double)sum) <= 1000)
    {
        for(i=0;i<size;i++)
        {
            v=belong[x][i]; 
            path[s][v]=1; 
        } 
    } 
    sum=(ex-loc[x][0])*(ex-loc[x][0])+(ey-loc[x][1])*(ey-loc[x][1]); 
    if(sqrt((double)sum) <= 1000)
    {
        for(i=0;i<size;i++)
        {
            v=belong[x][i]; 
            path[v][t]=0; 
        } 
    } 
    
    
    for(i=0;i<size;i++)
    {
        for(f=i+1;f<size;f++)
        {
            u=belong[x][i]; 
            v=belong[x][f]; 
            path[u][v]=1; 
            path[v][u]=1; 
        } 
    } 
}

void spfa()
{
    int v,i,tem;
    queue<int>q;
    q.push(s); 
    dis[s]=0; 
    while(!q.empty())
    {
        tem=q.front();
        q.pop();
        hash[tem]=0; 
        for(i=1;i<=n;i++)
        {
            if(-1 == path[tem][i])
            {    
                continue; 
            } 
            if(dis[tem]+path[tem][i] < dis[i]) 
            {
                dis[i]=dis[tem]+path[tem][i];    
                if(0 == hash[i])
                {
                    hash[i];
                    q.push(i); 
                } 
            }                
        }     
    } 
} 
 

int main()
{
    string ch; 
    int k,g,i,num,f,sum;
    scanf("%d",&num);
    for(i=0;i<num;i++)
    {
        scanf("%s%d%d",ch1,&sx,&sy);
        scanf("%s%d%d",ch2,&ex,&ey);
        turn();         
        scanf("%d",&zan); 
//        printf("%d %d \n%d %d \n",sx,sy,ex,ey); 

        mp.clear(); 
        for(f=1;f<=zan;f++)
        {
            cin>>ch; 
            mp[ch]=f; 
            scanf("%d%d",&loc[f][0],&loc[f][1]); 
        }
        
        scanf("%d",&bussum); 
        n=bussum+2;
        s=n-1;
        t=n; 
        chu();
        for(f=1;f<=bussum;f++) 
        {
            scanf("%d",&busnum[f]);
            for(g=0;g<busnum[f];g++)
            {
                cin>>ch;
                k=mp[ch]; 
                belong[k].push_back(f); 
            } 
        } 

        for(f=1;f<=zan;f++)
        {
            check(f); 
        } 
            
        sum=(sx-ex)*(sx-ex)+(sy-ey)*(sy-ey); 
        if(sqrt((double)sum) <= 2000)
        {
            printf("walk there\n"); 
            continue; 
        } 

         spfa(); 
         if(INF == dis[t]) 
         {
             printf("take a taxi\n");    
         } 
         else
         {
            printf("%d\n",dis[t]); 
         } 
    } 
    return 0;
}