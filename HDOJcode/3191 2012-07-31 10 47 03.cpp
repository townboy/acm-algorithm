******************************
    Author : townboy
    Submit time : 2012-07-31 10:47:03
    Judge Status : Accepted
    HDOJ Runid : 6382582
    Problem id : 3191
    Exe.time : 15MS
    Exe.memory : 272K
    https://github.com/townboy
******************************


#include<stdio.h>
#include<memory.h>
#define INF 0x7fffffff

int n;
int s,e,hash[60][2],val[60][2],cnt[60][2],map[60][60];

void chu()
{
    int i;
    memset(map,-1,sizeof(map));
    memset(cnt,0,sizeof(cnt));
    memset(hash,0,sizeof(hash));
    for(i=0;i<n;i++)
    {
        val[i][0]=val[i][1]=INF;    
    }
}

void dij()
{
    int minn,aim,i,xin,flag;
    val[s][0]=0;
    cnt[s][0]=1;
    while(1)
    {
        minn=INF;
        aim=-1;
        for(i=0;i<n;i++)
        {
            if(0 == hash[i][0] && val[i][0] < minn)
            {
                minn=val[i][0];
                flag=0;
                aim=i;            
            }
            if(0 == hash[i][1] && val[i][1] < minn)
            {
                minn=val[i][1];
                flag=1;
                aim=i;                        
            }
        }
        if(-1 == aim)
        {
            break; 
        }
        hash[aim][flag]=1; 
        for(i=0;i<n;i++)
        {
            if(-1 == map[aim][i])
            {
                continue;
            }
            xin=val[aim][flag]+map[aim][i];    
            if(xin < val[i][0])
            {
                val[i][1]=val[i][0];
                cnt[i][1]=cnt[i][0];
                val[i][0]=xin;
                cnt[i][0]=cnt[aim][flag];
            } 
            else if(xin == val[i][0])
            {
                cnt[i][0]+=cnt[aim][flag];    
            }
            else if(xin < val[i][1])
            {
                val[i][1]=xin;
                cnt[i][1]=cnt[aim][flag];
            }
            else if(xin == val[i][1])
            {
                cnt[i][1]+=cnt[aim][flag];    
            }
        } 
    } 
}

int main()
{
    int u,v,len,m,i;
    while(scanf("%d%d%d%d",&n,&m,&s,&e)!=EOF)
    {
        chu();
        for(i=0;i<m;i++)
        {    
            scanf("%d%d%d",&u,&v,&len);
            map[u][v]=len;
        }    
        dij();
        printf("%d %d\n",val[e][1],cnt[e][1]);
    }
    return 0;
}