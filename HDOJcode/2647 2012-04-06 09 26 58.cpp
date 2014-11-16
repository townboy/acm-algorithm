******************************
    Author : townboy
    Submit time : 2012-04-06 09:26:58
    Judge Status : Accepted
    HDOJ Runid : 5715400
    Problem id : 2647
    Exe.time : 93MS
    Exe.memory : 600K
    https://github.com/townboy
******************************


#include<stdio.h>
#include<memory.h>

int ru[11000],val[11000],u[21000],v[21000],first[11000],next[21000];

int maxx(int a,int b)
{
    return a>b?a:b;
}

void chu(int n)
{
    int i;
    memset(ru,0,sizeof(ru));
    for(i=1;i<=n;i++)
    {
        first[i]=-1;
        val[i]=888;
    }
}

int main()
{
    int n,k,i,f,aim,ji,sum,e,s,j;
//    freopen("D:\\in.txt","r",stdin);
    while(scanf("%d%d",&n,&k)!=EOF)
    {
        chu(n);

        for(i=0;i<k;i++)
        {
            scanf("%d%d",&e,&s);

            j=first[s];
            while(-1!=j)
            {
                if(v[j]==e)
                {
                    break;
                }
                j=next[j];
            }
            if(-1!=j)
            {
                continue;
            }

            u[i]=s;
            v[i]=e;
            next[i]=first[u[i]];
            first[u[i]]=i;

            ru[v[i]]++;
        }

        sum=0;
        for(ji=0;;ji++)
        {
            aim=-1;
            for(f=1;f<=n;f++)
            {
                if(0==ru[f])
                {
                    aim=f;
                    break;
                }
            }
            if(-1==aim)
            {
                break;
            }
        
            sum+=val[aim];
            ru[aim]=-1;

            e=first[aim];
            while(-1!=e)
            {
                val[v[e]]=maxx(val[aim]+1,val[v[e]]);
                ru[v[e]]--;
                e=next[e];
            }
        }
        if(ji==n)
        {
            printf("%d\n",sum);
        }
        else
        {
            printf("-1\n");
        }
    }
    return 0;
}