******************************
    Author : townboy
    Submit time : 2012-07-04 15:48:30
    Judge Status : Accepted
    HDOJ Runid : 6127974
    Problem id : 1195
    Exe.time : 265MS
    Exe.memory : 1108K
    https://github.com/townboy
******************************


#include<stdio.h>
#include<queue>
#include<memory.h> 
using namespace std; 

char aim[10],inti[10]; 
int hash[10][10][10][10]; 
int dir[3][2]={{1,8},{-1,-8},{1,-1}}; 
int turn[3][2]={{0,1},{1,2},{2,3}}; 

struct node 
{
    int que[4]; 
    int t; 
}; 
struct node ru,tem; 

int bfs()
{
    int i,flag,f; 
    queue<node>q;
    for(i=0;i<4;i++)
    {
        ru.que[i]=inti[i]-'0'; 
    }
    ru.t=0; 
    q.push(ru);
    while(!q.empty())
    {
        tem=q.front();
        q.pop();
        flag=1;
        for(i=0;i<4;i++)
        {
            if(aim[i]-'0' != tem.que[i])
            {
                flag=0;
                break; 
            }    
        }
        if(1 == flag)
        {
            return tem.t; 
        } 
        if(1 == hash[tem.que[0]][tem.que[1]][tem.que[2]][tem.que[3]])
        {
            continue; 
        }     
        hash[tem.que[0]][tem.que[1]][tem.que[2]][tem.que[3]]=1; 
        for(i=0;i<4;i++)
        {
            if(1 == tem.que[i])
            {
                for(f=0;f<2;f++)
                {
                    ru=tem;
                    ru.que[i]+=dir[0][f];
                    ru.t++;
                    q.push(ru);                
                }
                continue; 
            }
            if(9 == tem.que[i])
            {
                for(f=0;f<2;f++)
                {
                    ru=tem;
                    ru.que[i]+=dir[1][f];
                    ru.t++;
                    q.push(ru);                
                }    
                continue; 
            } 
            for(f=0;f<2;f++)
            {
                ru=tem;
                ru.que[i]+=dir[2][f];
                ru.t++;
                q.push(ru);                
            }
        } 
        
        for(i=0;i<3;i++)
        {
            ru=tem;
            ru.que[turn[i][0]]=tem.que[turn[i][1]]; 
            ru.que[turn[i][1]]=tem.que[turn[i][0]];
            ru.t++;
            q.push(ru); 
        } 
    }        
    return -1; 
} 

void chu()
{
    memset(hash,0,sizeof(hash)); 
} 

int main()
{
    int num,i,ans; 
    scanf("%d",&num);
    for(i=0;i<num;i++)
    {
        chu();
        getchar(); 
        scanf("%s",inti);
        scanf("%s",aim); 
        ans=bfs();
        printf("%d\n",ans); 
    }
    return 0;
}