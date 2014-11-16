******************************
    Author : townboy
    Submit time : 2013-11-05 21:14:20
    Judge Status : Accepted
    HDOJ Runid : 9508008
    Problem id : 1715
    Exe.time : 234MS
    Exe.memory : 5912K
    https://github.com/townboy
******************************



import java.util.*;
import java.math.*;

class Main {
    static BigInteger B[] = new BigInteger[1001];
    static void init() {
        B[1] = BigInteger.ONE;
        B[2] = BigInteger.ONE;
        for(int i = 3;i < 1001;i++)
            B[i] = B[i-1].add(B[i-2]);
    }
    public static void main(String[] args) {
        Scanner cin = new Scanner(System.in);
        int cas = cin.nextInt();
        init();
        for(int i = 0 ;i < cas;i++) {
            int p = cin.nextInt();
            System.out.println(B[p]);
        }
    }
}