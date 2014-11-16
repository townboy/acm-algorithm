//[ 一维树状数组 ]

int lowbit(int t)
{
	return t&(-t);
}

int sum(int end)
{
	int sum=0;
	while(end > 0)
	{
		sum+=in[end];
		end-=lowbit(end);
	}
	return sum;
}

void plus(int pos,int num)
{
	while(pos<=n)
	{
		in[pos]+=num;
		pos+=lowibt(pos);
	}
}
//[ 二维树状数组 ]
int maxm,maxn;

int lowbit(int t) {
	return t&(-t);
}

int sum(int n,int m) {
	int sum=0;
	int _m = m;
	while(n > 0) {
		m = _m;
		while(m > 0) {
			sum += in[n][m];
			m -= lowbit(m);
		}
		n -= lowbit(n);
	}
	return sum;
}

void plus(int n ,int m,int v) {
	int _m = m;
	while(n <= maxn) {
		m = _m;
		while(m <= maxm) {
			in[n][m] += v;
			m += lowbit(m);
		}
		n += lowbit(n);
	}	
}

int getsum(int n0,int m0,int n1,int m1) {
	return sum(n0,m0) - sum(n0,m1-1) - sum(n1-1,m0) + sum(n1-1,m1-1);
}

//[ 三维树状数组 ]

int sum(int x,int y,int z) {
	int sum=0; 
	for(int i=x;i>0;i-=lowbit(i))
		for(int f=y;f>0;f-=lowbit(f))
			for(int g=z;g>0;g-=lowbit(g))
				sum += in[i][f][g]; 
	return sum; 
}

int getsum(int x1,int y1,int z1,int x2,int y2,int z2) {
	Return sum(x2,y2,z2)-sum(x1-1,y2,z2)-sum(x2,y1-1,z2)-sum(x2,y2,z1-1)+sum(x2,y1-1,z1-1)+sum(x2,y1-1,z1-1)+sum(x1-1,y2,z1-1)+sum(x1-1,y1-1,z1-1); 
} 

void plus(int x,int y,int z,int v) {
	for(int i=x;i<=100;i+=lowbit(i))
		for(int f=y;f<=100;f+=lowbit(f))
			for(int g=z;g<=100;g+=lowbit(g))
				in[i][f][g]+=v; 
} 
//[ 树状数组求K大 ]
//当然也可以二分写,这个非常高效

int find_kth(int k)
{
	int sum=0,pos=0;
	for(i=20;i>=0;i--)
	{
		pos+=(1<<i);
		if(pos > MAX || sum+in[pos]>=k)
		{
			pos-=(1<<i);
		}
		else
		{
			sum+=in[pos];
		}
	}
	return pos+1;
}


