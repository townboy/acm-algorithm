//[ 同余枚举自由元 ]
#include<stdio.h>
#include<memory.h>

int zan[110][110];
int ans,save[110][110],n;

void swap(int &a,int &b)
{
    int tem=a;
    a=b;
    b=tem;
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
            return -1;		// 无解
        }
    }
    ans=10000;		// 一解或者多解
    dfs(n-1,col-1);
    return ans;		// 最小开关数量
	return n-row    // 自由元数量
}

//[ 普通高斯 ]

void gauss()
{
	int i,f,col,row;
	for(col=row=0;row<n&&col<m;col++,row++)
	{
		for(i=row;i<n;i++)
		{
			if(0 != save[i][col])
			{
				break;
			}
		}
		if(i != n)
		{
			r--;
			continue;
		}
		if(i != row)
		{
			for(f=col;f<=m;f++)
			{
				swap(save[i][f],swap[row][f]);
			}
		}
		for(i=r+1;i<n;i++)
		{
			if(0 != save[i][col])
			{
				double tem=save[i][col]/save[row][col];
				for(f=col;f<=m;f++)
				{
					save[i][f]-=tem*save[row][f];
				}
			}
		}
	}
	for(i=n-1;i>=0;i--)
	{
		save[i][m]/=save[i][i];
		save[i][i]=1;
		for(f=i-1;f>=0;f--)
		{
			save[f][m]-=save[i][m]*save[f][i];
		}
	}
}

