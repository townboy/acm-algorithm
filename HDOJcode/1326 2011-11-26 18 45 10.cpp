******************************
    Author : townboy
    Submit time : 2011-11-26 18:45:10
    Judge Status : Accepted
    HDOJ Runid : 5060889
    Problem id : 1326
    Exe.time : 0MS
    Exe.memory : 272K
    https://github.com/townboy
******************************


#include<iostream>
using namespace std;
int main(void)
{
    int sum,sumi,i,num,a[100],ji;
    ji=1;
    while(cin>>num,num)
    {
        sum=0;
        for(i=0;i<num;i++)
        {
            scanf("%d",&a[i]);
            sum=sum+a[i];
        }
        sumi=0;
        for(i=0;i<num;i++)
        {
            if(a[i]>(sum/num))
            {
                sumi=sumi+(a[i]-(sum/num));
            }
        }
        cout<<"Set #"<<ji<<endl<<"The minimum number of moves is "<<sumi<<"."<<endl<<endl;
        ji++;
    
    }
return 0;
}