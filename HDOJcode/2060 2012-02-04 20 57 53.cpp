******************************
    Author : townboy
    Submit time : 2012-02-04 20:57:53
    Judge Status : Accepted
    HDOJ Runid : 5315110
    Problem id : 2060
    Exe.time : 15MS
    Exe.memory : 220K
    https://github.com/townboy
******************************


#include<iostream>
using namespace std;
int main()
{
    int x,me,i,you,val[30],num;
    val[0]=0;
    val[1]=7;
    for(i=2;i<=6;i++)
    {
        val[i]=val[i-1]+(8-i);
    }
    for(i=7;i<=21;i++)
    {
        val[i]=val[i-1]+8;
    }
    cin>>num;
    for(i=0;i<num;i++)
    {
        cin>>x>>me>>you;
        if(val[x]>=you-me)
        {
            cout<<"Yes"<<endl;
        }
        else
        {
            cout<<"No"<<endl;
        }
    }
    return 0;
}