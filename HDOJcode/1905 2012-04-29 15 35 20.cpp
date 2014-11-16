******************************
    Author : townboy
    Submit time : 2012-04-29 15:35:20
    Judge Status : Accepted
    HDOJ Runid : 5867059
    Problem id : 1905
    Exe.time : 0MS
    Exe.memory : 256K
    https://github.com/townboy
******************************


#include<stdio.h>
#include<math.h>

int a,p;

int dfs(__int64 x,__int64 y,__int64 z)
{
    if( y == 1)
    {
        return (z*x)%p;
    }
    if( (y&1) == 1)
    {
        return dfs((x*x)%p,y/2,(z*x)%p);
    }
    else
    {
        return dfs((x*x)%p,y/2,z);
    }
}

int test(int x)
{
    int i;
    
    for(i=2;i<=sqrt(x);i++)
    {
        if(0 == x%i)
        {
            return 0;
        }
    }
    return 1;
}

int main()
{
    int yu;
    while(scanf("%d%d",&p,&a),!(0 == p && 0 == a))
    {
        if( 1 == test(p) )
        {
            printf("no\n");
            continue;
        }
        
        yu=dfs(a,p,1);

        if(a == yu)
        {
            printf("yes\n");
        }
        else
        {
            printf("no\n");
        }

    }
    return 0;
}