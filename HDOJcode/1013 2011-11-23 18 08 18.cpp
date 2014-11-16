******************************
    Author : townboy
    Submit time : 2011-11-23 18:08:18
    Judge Status : Accepted
    HDOJ Runid : 5039844
    Problem id : 1013
    Exe.time : 0MS
    Exe.memory : 180K
    https://github.com/townboy
******************************


#include<stdio.h>
#include<string.h>
int me(int x)
{
    int sum=0;
    while(x!=0)
    {
        sum=sum+x%10;
        x=x/10;
    }
    return sum;

}
int main(void)
{
    int sum,i,len;
    char num[10000];
    while(scanf("%s",num),num[0]!='0')
    {
        len=strlen(num);
        sum=0;
        for(i=0;i<len;i++)
        {
            sum=sum+(num[i]-'0');
        }
        while(sum>9)
        {
            sum=me(sum);
        }
        printf("%d\n",sum);
    
    }

return 0;
}