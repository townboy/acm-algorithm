******************************
    Author : townboy
    Submit time : 2013-08-14 21:52:24
    Judge Status : Accepted
    HDOJ Runid : 8947761
    Problem id : 1041
    Exe.time : 218MS
    Exe.memory : 4204K
    https://github.com/townboy
******************************


import java.util.*;
import java.io.*;
import java.math.*;

class Main {
    public static void main(String[] args) {
        Scanner cin = new Scanner(System.in);
        BigInteger a[] = new BigInteger[1001];
        a[1] = BigInteger.ZERO;
        for(int i = 2 ;i < 1001; i++) {
            a[i] = a[i-1].multiply(BigInteger.valueOf(2));
            if(0 == i%2)
                a[i] = a[i].add(BigInteger.ONE);
            else
                a[i] = a[i].subtract(BigInteger.ONE);
        }
        
        while(true == cin.hasNextInt()) {
            int n = cin.nextInt();
            System.out.println(a[n]);
        }
    }
}