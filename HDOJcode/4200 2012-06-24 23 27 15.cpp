******************************
    Author : townboy
    Submit time : 2012-06-24 23:27:15
    Judge Status : Accepted
    HDOJ Runid : 6096936
    Problem id : 4200
    Exe.time : 0MS
    Exe.memory : 348K
    https://github.com/townboy
******************************


#include<stdio.h>
#include<memory.h>

int zan[110][110];
int k,ans,save[110][110],n;

void swap(int &a,int &b)
{
    int tem=a;
    a=b;
    b=tem;
}

void debug()
{
    int i,f;
    for(i=0;i<n;i++)
    {
        for(f=0;f<=n;f++)
        {
            printf("%d ",save[i][f]);
        }
        printf("\n");
    }
    printf("\n");
}

void debug2()
{
    int i,f;
    for(i=0;i<n;i++)
    {
        for(f=0;f<=n;f++)
        {
            printf("%d ",zan[i][f]);
        }
        printf("\n");
    }
    printf("\n");
}

void fun()
{
    int i,f;
    for(f=0;f<n;f++)
    {
        for(i=f-k;i<=f+k;i++)
        {
            if(i<0 || i>=n)
            {
                continue;
            }
            save[i][f]=1;
        }
    }
}

int find(int row,int col)
{
    int i,f;
    for(f=col;f<n;f++)
    {
        for(i=row;i<n;i++)
        {
            if(0 != save[i][f])
            {
                return f;
            }
        }
    }
    return -1;
}

int gans()
{
    int i,f,ret=zan[n-1][n];
    for(i=n-2;i>=0;i--)
    {
        for(f=i+1;f<n;f++)
        {
            zan[i][n]^=(zan[i][f]&&zan[f][n]);
        }
        ret+=zan[i][n];
    }
//    debug2();
    return ret;
}

void dfs(int p,int k)
{
    int ret,i,f;
    if(p == k)
    {
        for(i=0;i<n;i++)        
        {
            for(f=0;f<=n;f++)
            {
                zan[i][f]=save[i][f];
            }
        }
        ret=gans();
        if(ret < ans)
        {
            ans=ret;
        }
        return ;
    }
    save[p][n]=0;
    dfs(p-1,k);
    save[p][n]=1;
    dfs(p-1,k);
}

int guass()
{
    int col,row,i,f,j;
    for(col=row=0;row<n&&col<n;row++,col++)
    {
        for(i=row;i<n;i++)
        {
            if(0 != save[i][col])
            {
                break;
            }
        }
        if(n == i)
        {
            j=find(row,col);
            if(-1 == j)
            {
                break;
            }
            for(i=0;i<n;i++)
            {
                swap(save[i][col],save[i][j]);
            }
            col--;
            row--;
            continue;
        }
        if(i != row)
        {
            for(f=col;f<=n;f++)
            {
                swap(save[i][f],save[row][f]);
            }
        }
        for(i=row+1;i<n;i++)
        {
            if(0 != save[i][col])
            {
                for(f=col;f<=n;f++)
                {
                    save[i][f]=save[i][f]^save[row][f];
                }
            }
        }
    }
    for(i=row;i<n;i++)
    {
        if(0 != save[i][n])
        {
            return -1;
        }
    }
//    debug();
    ans=10000;
    dfs(n-1,col-1);
    return ans;
}

void chu()
{
    memset(save,0,sizeof(save));
}

int main()
{
    int i,res,num,f;
//    freopen("D:\\in.txt","r",stdin);
    scanf("%d",&num);
    for(i=0;i<num;i++)
    {
        chu();
        scanf("%d%d",&n,&k);
        for(f=0;f<n;f++)
        {
            scanf("%d",&save[f][n]);
        }
        fun();
//        debug();
        res=guass();
//        debug();
        if(-1 == res)
        {
            printf("impossible\n");
        }
        else
        {
            printf("%d\n",res);
        }
    }
    return 0;
}