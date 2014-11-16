******************************
    Author : townboy
    Submit time : 2012-03-28 21:09:47
    Judge Status : Accepted
    HDOJ Runid : 5658986
    Problem id : 1217
    Exe.time : 15MS
    Exe.memory : 228K
    https://github.com/townboy
******************************


#include<stdio.h>
#include<string.h>

int n;
double map[50][50];
char s[10050],e[100],ch[50][100];

double maxx(double a,double b)
{
    return a>b?a:b;
}

void chu()
{
    int i,f;
    for(i=0;i<n;i++)
    {
        for(f=0;f<n;f++)
        {
            map[i][f]=-1;
        }
    }
}

int finds()
{
    int i;
    for(i=0;i<n;i++)
    {
        if(0==strcmp(ch[i],s))
        {
            return i;
        }
    }
    return -1;
}

int finde()
{
    int i;
    for(i=0;i<n;i++)
    {
        if(0==strcmp(ch[i],e))
        {
            return i;
        }
    }
    return -1;
}

int main()
{
    double x;
    int ji,i,f,k,m,xe,xs,flag;
    ji=0;
    while(scanf("%d",&n),n)
    { 
        ji++;
        getchar();
        chu();
        for(i=0;i<n;i++)
        {
            gets(ch[i]);
        }
        scanf("%d",&m);
        getchar();
        for(i=0;i<m;i++)
        {
            scanf("%s%lf%s",s,&x,e);
            xs=finds();
            xe=finde();
            if(-1==map[xs][xe]||x>map[xs][xe])
            {
                map[xs][xe]=x;
            }
        } 
        for(k=0;k<n;k++)
        {
            for(i=0;i<n;i++)
            {
                for(f=0;f<n;f++)
                {
                    if(-1!=map[i][k]&&-1!=map[k][f])
                    {
                        map[i][f]=maxx(map[i][f],map[i][k]*map[k][f]);
                    }
                }
            }
        }
        flag=0; 

        for(i=0;i<n;i++)
        {
            if(1<map[i][i])
            {
                flag=1;
                break;
            }
        }
        if(1==flag)
        {
            printf("Case %d: Yes\n",ji);
        }
        else
        {
            printf("Case %d: No\n",ji);
        }
    }
    return 0;
}