******************************
    Author : townboy
    Submit time : 2012-05-08 16:02:39
    Judge Status : Accepted
    HDOJ Runid : 5914881
    Problem id : 1079
    Exe.time : 0MS
    Exe.memory : 468K
    https://github.com/townboy
******************************


#include<stdio.h>

int np[2020][15][35];
int r[15]={0,31,29,31,30,31,30,31,31,30,31,30,31};
int fr[15]={0,31,28,31,30,31,30,31,31,30,31,30,31};

int check(int x)
{
    if(0 == x%100)
    {
        if(0==x%400)
        {
            return 1;
        }
        return 0;
    }
    else if(0==x%4)
    {
        return 1;
    }
    return 0;
}

int main()
{ 
    int y,d,m,ly,ld,lm,i,num;

//    freopen("D:\\in.txt","r",stdin);
    np[2001][11][4]=0;
    for(i=5;i<=31;i++)
    {
        np[2001][11][i]=1;
    }
    for(i=1;i<=10;i++)
    {
        np[2001][12][i]=1;
    }


    y=2001;
    m=11;
    d=3;
    ly=2001;
    lm=11;
    ld=4;

    while(1)
    {
        if(0==np[ly][lm][ld])
        {
            np[y][m][d]=1;
        }
        else
        {
            if(12==m)
            {
                if(1==np[y+1][1][d])
                {
                    np[y][m][d]=0;    
                }
                else
                {
                    np[y][m][d]=1;
                }
            }
            else
            {
                if(1== check(y))
                {
                    if(d > r[m+1])
                    {
                        np[y][m][d]=0;
                    }
                    else
                    {
                        if(1==np[y][m+1][d])
                        {
                            np[y][m][d]=0;    
                        }
                        else
                        {
                            np[y][m][d]=1;
                        }    
                    }
                }
                else
                {
                    if(d > fr[m+1])
                    {
                        np[y][m][d]=0;
                    }
                    else
                    {
                        if(1==np[y][m+1][d])
                        {
                            np[y][m][d]=0;    
                        }
                        else
                        {
                            np[y][m][d]=1;
                        }    
                    }
                }
            }
        }
        
        ly=y;
        lm=m;
        ld=d;
        if(1==m&&1==d)
        {
            y--;
            m=12;
            d=31;
        }
        else if(1==d)
        {
            if(1==check(y))
            {
                m--;
                d=r[m];
            }
            else
            {
                m--;
                d=fr[m];
            }
        }
        else
        {
            d--;
        }

        if(y==1899)
        {
            break;
        }

    }
    
    scanf("%d",&num);

    for(i=0;i<num;i++)
    {
        scanf("%d%d%d",&y,&m,&d);
        if(1 == np[y][m][d])
        {
            printf("YES\n");
        }
        else
        {
            printf("NO\n");
        }
    }
    return 0;
}