******************************
    Author : townboy
    Submit time : 2012-06-24 16:05:22
    Judge Status : Accepted
    HDOJ Runid : 6095902
    Problem id : 3915
    Exe.time : 0MS
    Exe.memory : 272K
    https://github.com/townboy
******************************


#include<stdio.h>
#include<memory.h>

int m,save[40][110];

void swap(int &a,int &b)
{
    int tem=a;
    a=b;
    b=tem;
}

void fen(int f,int x)
{
    int j=0;
    while(0 != x)
    {
        save[j][f]=(1&x);
        x>>=1;
        j++;
    }
}

void debug()
{
    int i,f;
    for(i=0;i<31;i++)
    {
        for(f=0;f<=m;f++)
        {
            printf("%d ",save[i][f]);
        }
        printf("\n");
    }
    printf("\n");
}

int gauss()
{
    int col,row,i,f,ans;
    for(col=row=0;row<31&&col<m;row++,col++)
    {
        for(i=row;i<31;i++)
        {
            if(0 != save[i][col])
            {
                break;
            }
        }
        if(i == 31)
        {
            row--;
            continue;
        }
        if(i != row)
        {
            for(f=col;f<m;f++)
            {
                swap(save[i][f],save[row][f]);
            }
        }
        for(i=row+1;i<31;i++)
        {
            if(0 != save[i][col])
            {
                for(f=col;f<m;f++)
                {
                    save[i][f]=(save[i][f]^save[row][f]);
                }
            }
        }
    }
    for(i=row;i<31;i++)
    {
        if(0 != save[i][m])
        {
            return -1;
        }
    }
    ans=1;
    for(i=0;i<m-row;i++)
    {
        ans=(ans*2)%1000007;
    }
    return ans;
}

void chu()
{
    memset(save,0,sizeof(save));
}

int main()
{
    int i,f,num,x;
//    freopen("D:\\in.txt","r",stdin);
    scanf("%d",&num);
    for(i=0;i<num;i++)
    {
        chu();
        scanf("%d",&m);
        for(f=0;f<m;f++)
        {
            scanf("%d",&x);
            fen(f,x);
        }
        printf("%d\n",gauss());
    }
    return 0;
}