******************************
    Author : townboy
    Submit time : 2013-08-07 22:08:14
    Judge Status : Accepted
    HDOJ Runid : 8865315
    Problem id : 1212
    Exe.time : 125MS
    Exe.memory : 3612K
    https://github.com/townboy
******************************


import java.util.*;
import java.io.*;
import java.math.*;

class Main {
    public static void main(String[] args) {
        Scanner cin = new Scanner(System.in);
        BigInteger a ;
        int b;
        while(cin.hasNextBigInteger()) {
            a = cin.nextBigInteger();
            b = cin.nextInt();
            System.out.println(a.mod(BigInteger.valueOf(b)));
        }
     }
}