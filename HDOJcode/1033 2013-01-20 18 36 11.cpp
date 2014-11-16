******************************
    Author : townboy
    Submit time : 2013-01-20 18:36:11
    Judge Status : Accepted
    HDOJ Runid : 7521472
    Problem id : 1033
    Exe.time : 15MS
    Exe.memory : 272K
    https://github.com/townboy
******************************


#include<stdio.h>
#include<string.h>

char ch[210];
int n,m,k;
int dira[4][3]={{0,-10,3},{10,0,0},{0,10,1},{-10,0,2}};
int dirv[4][3]={{0,10,1},{-10,0,2},{0,-10,3},{10,0,0}};

int main()
{
    int len;
    int i,last;
    int px,py;

    while(gets(ch)!=NULL)
    {
        len=strlen(ch);
        printf("300 420 moveto\n310 420 lineto\n");
        last=0;
        px=310;
        py=420;
        for(i=0;i<len;i++)
        {
            if('A' == ch[i])
            {
                px+=dira[last][0];
                py+=dira[last][1];
                last=dira[last][2];
                printf("%d %d lineto\n",px,py);
            }
            else
            {
                px+=dirv[last][0];
                py+=dirv[last][1];
                last=dirv[last][2];
                printf("%d %d lineto\n",px,py);
            }    
        }
        printf("stroke\nshowpage\n");
    }
    return 0;    
}