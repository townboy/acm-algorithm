// state指的就是之前的状态 然后记忆化搜索
#include<stdio.h>
#include<iostream>
#include<memory.h>

using namespace std;

typedef long long LL ;

int val[40];
LL dp[40][3];
/*
  0 代表前面没有出现过49 前一位是4
  1 代表前面没有出现过49 前一位不是4
  2 代表已经出现过49
*/
// 求解数字中出现49的个数
LL dfs(int pos,int state,bool limit) {
    if(false == limit && -1 != dp[pos][state])
        return dp[pos][state];
    if(0 == pos) {
        if(2 == state)
            return 1;
        return 0;
    }
    int end = 9;
    if(true == limit) 
        end = val[pos];
    LL ans = 0;
    for(int i = 0 ;i <= end;i++) {
        int newlimit = false;
        int newstate ;
        if(end==i && true==limit) 
            newlimit = true;
        if(2 == state)
            newstate = 2;
        else if(0 == state) {
            if(9 == i)
                newstate = 2;
            else if(4 == i) 
                newstate = 0;
            else 
                newstate = 1;
        }
        else {
            if(4 == i)
                newstate = 0;
            else 
                newstate = 1;
        }
        ans += dfs(pos-1, newstate, newlimit);
    }
    if(false == limit)
        dp[pos][state] = ans;
    return ans;
}

LL solve(LL x) {	// 求解0-x中的所有满足条件数字的个数
    int pos = 0;
    while(0 != x) {
        pos ++;
        val[pos] = x%10;
        x /= 10;
    }
    return dfs(pos,1,true);
}
