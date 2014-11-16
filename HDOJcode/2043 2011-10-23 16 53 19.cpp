******************************
    Author : townboy
    Submit time : 2011-10-23 16:53:19
    Judge Status : Accepted
    HDOJ Runid : 4809093
    Problem id : 2043
    Exe.time : 0MS
    Exe.memory : 192K
    https://github.com/townboy
******************************


#include<stdio.h>
#include<string.h>
int main(void)
{


    int num,i,s1,s2,s3,s4,f,len;
    char    ch[100];
  scanf("%d",&num);
  getchar();
  for(i=0;i<num;i++)
  {
      s1=s2=s3=s4=0;
  gets(ch);
  len=strlen(ch);
  if(len>=8&&len<=16)
  {    for(f=0;f<len;f++)
    {
  if(ch[f]>=65&&ch[f]<=90)
      s1=1;
  else if(ch[f]>=48&&ch[f]<=57)
      s2=1;
  else if ((ch[f]>=35&&ch[f]<=37)||ch[f]==64||ch[f]==33||ch[f]==94||ch[f]==126)
      s3=1;
  else if(ch[f]>=97&&ch[f]<=122)
      s4=1;

  
  
  
    }
    if(s1+s2+s3+s4>=3)
        printf("YES\n");
    else
        printf("NO\n");
  }
   else
       printf("NO\n");



  }



return 0;

}