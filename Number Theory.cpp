int gcd(int a,int b)
{	
	int tem;
	if(a < b)		// 保证 a大 b小
	{
		tem=b;
		b=a;
		a=tem;
	}
	while(0 != b)
	{
		tem=a%b;
		a=b;
		b=tem;
	}
	return a;
}

int lcm(int a,int b)
{
	return a/gcd(a,b)*b;
}


//欧拉函数
/*
从1到 n的数中与 n互质的个数。
通式 φ(x)=x(1-1/p1)(1-1/p2)(1-1/p3)(1-1/p4)…..(1-1/pn)，其中p1, p2……pn为x的所有质因数。
通式也可以写为 φ(x)=x*((p1-1)/p1)*((p2-1)/p2)*((p3-1)/p3)…..((pn-1)/pn)
*/
// 逆元
typedef __int64 LL;
#define mod 1000000007

LL quickpow(LL m,LL n){
	LL ans=1;
	while(n){
		if(n&1) 
			ans=(ans*m)%mod;
		n = n>>1;
		m =  (m*m)%mod;
	}
	return ans;
}
LL Inv(LL x){			// 根据费马小定理
	return quickpow(x,mod-2);
}

//6.4 线性筛素数
const int N=1000000;
int pr[N],p[N/10],lp;

void gp(){
    for(int i=2;i<N;i++){
        if(!pr[i])p[lp++]=pr[i]=i;
        for(int j=0;j<lp && i*p[j]<N;j++){
            pr[i*p[j]]=p[j];
            if(i%p[j]==0)break;
        }
    }
}
//pr[] 记录的是这个数字的最小素因子

