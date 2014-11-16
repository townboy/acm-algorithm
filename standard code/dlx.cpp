//精确覆盖
int L[maxn],R[maxn],U[maxn],D[maxn]; //左右上下
int C[maxn],H[maxn]; //节点属于哪一列  H[i]表示该行的头结点
int row[maxn]; //节点属于哪一行
int S[maxn]; //列链表中节点的总数
int O[maxn]; //记录答案
int head,num; //head, num为总节点数(即1的总个数)

void remove(int c) { //删除第c列
	L[R[c]]=L[c]; R[L[c]]=R[c];
	for(int i=D[c];i!=c;i=D[i]) { //删除对应c列有1的行
		for(int j=R[i];j!=i;j=R[j]) {
			U[D[j]]=U[j]; D[U[j]]=D[j];
			S[C[j]]--;
		}
	}
}

void resume(int c) { //恢复第c列
	for(int i=U[c];i!=c;i=U[i]) { //恢复c对应的有1的行
		for(int j=L[i];j!=i;j=L[j]) {
			U[D[j]]=j; D[U[j]]=j;
			S[C[j]]++;
		}
	}
	L[R[c]]=c; R[L[c]]=c;
}

bool dlx(int k)  {
	if(R[head]==head) { //全部填完
		//输出选择了哪些行
		cout << k ;
		for(int i=0;i<k ;i++) cout << " " << row[O[i]];
		cout << endl;
		return true;
	}
	int s=INF,c; //找1最少的列对应的第一个1的位置i
	for(int i=R[head];i!=head;i=R[i])
		if(S[i]<s) s=S[i],c=i;

	remove(c); //删除c对应的列
	for(int i=D[c];i!=c;i=D[i]) {
		O[k]=i;
		for(int j=R[i];j!=i;j=R[j]) remove(C[j]); //删除那一行有1的列
		if(dlx(k+1)) return true;
		for(int j=L[i];j!=i;j=L[j]) resume(C[j]); //恢复那一行有1的列
	}
	resume(c); //恢复c对应的列
	return false;
}

void addnode(int r,int c) {
	num++;
	U[num]=U[c]; D[U[c]]=num;  //老的最后行指向新的最后行
	U[c]=num; D[num]=c;   //新的最后行指向列首

	if(H[r]==-1) H[r]=L[num]=R[num]=num; //行的第一个1
	else { //插入到行列表中
		L[num]=L[H[r]]; R[num]=H[r];
		R[L[H[r]]]=num; L[H[r]]=num;
	}
	C[num]=c;   //列指针,表示num所在的列
	row[num]=r; //表示num所在的行
	S[c]++;     //相应的列1的个数+
}

void init(int m) {			//初始化列数
	head = 0;
	memset(H,-1,sizeof(H));
	for(int i=0;i<=m;i++) {
		U[i]=i; D[i]=i;
		L[i+1]=i; R[i]=i+1;
		S[i]=0; C[i]=i;
	}
	L[0]=m; R[m]=0;
	num=m;
}
//重复覆盖
/*
最少需要选择多少行才能覆盖掉所有的列。通过一个h()估价函数用来剪枝
具体实现有两种写法 第一种：直接对整棵搜索树进行暴搜，然后在搜索的过程中，通过已有的最优解去加上估价函数去剪枝
第二种，通过IDA*实现，这样子每次限制了深度之后，估价函数就起到了作用，可以减去在当前深度内不合法的情况。
*/

//一般求至少选择多少行,使得每一列至少有一个1.
int L[N],R[N],U[N],D[N]; //左右上下
int C[N],H[N]; //C[i],H[i]表示i对应的哪一列,哪一行
int S[N]; //列链表中节点的总数
int O[N]; //记录答案
int head,num,ans;    //head, num为总节点数(即1的总个数),ans为至少选择的行数
void remove(int c) {
    for(int i=D[c];i!=c;i=D[i]) {
        L[R[i]]=L[i]; R[L[i]]=R[i];
    }
}
void resume(int c) {
    for(int i=U[c];i!=c;i=U[i]) {
        R[L[i]]=i; L[R[i]]=i;
    }
}

bool use[N]; //大小为列数

int h() {
    memset(use,0,sizeof(use));
    int ret=0;
    for(int c=R[head];c!=head;c=R[c])
        if(!use[c]) {
            ret+=1;
            use[c]=1;
            for(int i=D[c];i!=c;i=D[i])
                for(int j=R[i];j!=i;j=R[j]) use[C[j]]=1;
        }
    return ret;
}

void dlx(int k) {
    if(k+h()>= ans) return;
    if(R[head]==head) {
        ans = min(ans,k);
        return;
    }

    int s=INF,c;
    for(int i=R[head];i!=head;i=R[i]){
        if(S[i]<s) s=S[i],c=i;
    }

    for(int i=D[c];i!=c;i=D[i]) {
        remove(i);
        for(int j=R[i];j!=i;j=R[j]) remove(j);
        dlx(k+1);
        for(int j=L[i];j!=i;j=L[j]) resume(j);
        resume(i);
    }
}

void addnode(int r,int c) {
    num++;
    U[num]=U[c]; D[U[c]]=num;  //老的最后行指向新的最后行
    U[c]=num; D[num]=c;   //新的最后行指向列首

    if(H[r]==-1) H[r]=L[num]=R[num]=num; //行的第一个1
    else { //插入到行列表中
        L[num]=L[H[r]]; R[num]=H[r];
        R[L[H[r]]]=num; L[H[r]]=num;
    }
    C[num]=c;   //列指针,表示num所在的列
    S[c]++;     //相应的列1的个数++
}

void init(int m) {
    head=0;
    memset(H,-1,sizeof(H));
    for(int i=0;i<=m;i++) {
        U[i]=i; D[i]=i;
        L[i+1]=i; R[i]=i+1;
        S[i]=0; C[i]=i;
    }
    L[0]=m; R[m]=0;
    num=m;
}



//数独转化
/*
对于一个 9*9 的数独，建立如下的矩阵。 
行： 
一共 9*9*9 = 729 行。一共 9*9 小格，每一格有种可能性 (1-9),每一种可能都对应着一行。 
列： 
一共（9+9+9）*9+81 = 324 种，前面三个分别代表着 9 行 9 列和 9 小 块。乘以 9 的意思是 9 种可能，因为每种可能只可以选择一个。 81 代表着81个小格，限制着每一个小格只可以放一个地方。 
     这样我们把矩阵建立起来，把行和列对应起来之后，行i可以放在列f上 就把 A[i][f] 设为 1 否则设为 0 。然后套用 Exact Cover Problem 的定义：选择一 些行，使得每一列有且仅有一个 1。哈哈，是不是对应着 sudoku 的一个解？ 
*/


int mul(int x,int y){					// 对于9*9数独
	return 9*x + y;
}

int getkuai(int x,int y){
	return (x/3)*3 + y/3;
}

void solve_sudoku(){
	int ji = 0;
	int m = 27*9 + 81;
	int sh = 1,ss = 82,sk = 163,sg = 244;		// 行 竖 块 
	init(m);
	for(int i = 0;i < 9;i++)
		for(int f = 0;f < 9;f++)
			for(int g = 0;g < 9;g++){
				to[ji][0] = i;
				to[ji][1] = f;
				to[ji][2] = g;
				
				if(-1==sudoku[i][f] || g==sudoku[i][f]){
					addnode(ji,sh+ mul(i,g));
					addnode(ji,ss+ mul(f,g));
					addnode(ji,sk+ mul( getkuai(i,f),g ));
					addnode(ji,sg+ mul(i,f));
				}
				ji++;
			}
	dlx(0);
}

