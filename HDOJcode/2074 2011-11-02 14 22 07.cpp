******************************
    Author : townboy
    Submit time : 2011-11-02 14:22:07
    Judge Status : Accepted
    HDOJ Runid : 4880477
    Problem id : 2074
    Exe.time : 15MS
    Exe.memory : 244K
    https://github.com/townboy
******************************


#include<stdio.h>
int main(void)
{
    int b[90][90],num,i,f,g,ji;
    char a[2],c[90][90];
    ji=0;
    while(scanf("%d %c %c",&num,&a[0],&a[1])!=EOF)
    {
        ji++;
        if(ji!=1)
            printf("\n");
        if(num==1)
        {
            printf("%c\n",a[0]);
        }
        else
        {
        for(f=0;f<num;f++)
        { 
            for(g=0;g<num;g++)
            {
                b[f][g]=1;
            }
        }

        for(i=0;i<(num+1)/2;i++)
        {
            for(f=(num+1)/2-i-1;f<=(num+1)/2+i-1;f++)
            {
                for(g=(num+1)/2-i-1;g<=(num+1)/2+i-1;g++)
                {
                    if(b[f][g]==1)
                    {
                        c[f][g]=a[i%2];
                        b[f][g]=0;
                    }
                }
            }    
        }
        c[0][0]=c[0][num-1]=c[num-1][0]=c[num-1][num-1]=' ';
        
        
        for(f=0;f<num;f++)
        { 
            for(g=0;g<num;g++)
            {
                printf("%c",c[f][g]);
            }
            printf("\n");
        }
        }

    
    
    }


    return 0;
}