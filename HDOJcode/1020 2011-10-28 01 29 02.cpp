******************************
    Author : townboy
    Submit time : 2011-10-28 01:29:02
    Judge Status : Accepted
    HDOJ Runid : 4838527
    Problem id : 1020
    Exe.time : 0MS
    Exe.memory : 280K
    https://github.com/townboy
******************************


#include<stdio.h>
#include<string.h>
int main(void)
{
    int num,i,su[12000],len,flag,f,g;
    char x[12000],zi[12000];
    scanf("%d",&num);
    getchar();
    for(i=0;i<num;i++)
    {
        scanf("%s",x);
        getchar();
        len=strlen(x);
        flag=1;
        f=0;
        for(g=1;g<len;g++)
        {
            if(x[g]==x[g-1])
            {
            flag++;
            }    
            else
            {
            su[f]=flag;
            zi[f]=x[g-1];
            flag=1;
            f++;
            }
        }
        su[f]=flag;
        zi[f]=x[g-1];

        

        for(g=0;g<f+1;g++)
        {
            if(su[g]!=1)
                printf("%d",su[g]);
                printf("%c",zi[g]);
        
        }
        printf("\n");
    }
  return 0;
}

