******************************
    Author : townboy
    Submit time : 2013-07-11 01:12:58
    Judge Status : Accepted
    HDOJ Runid : 8563209
    Problem id : 1002
    Exe.time : 156MS
    Exe.memory : 3996K
    https://github.com/townboy
******************************


import java.io.*;
import java.util.*;
import java.math.*;

public class Main {
    public static void main(String[] args) {
        Scanner cin = new Scanner(System.in);
        int cas = cin.nextInt();
        for(int i = 0 ;i < cas;i++) {
            if(0 != i)
                System.out.println("");
            BigInteger a = cin.nextBigInteger();            
            BigInteger b = cin.nextBigInteger();
            System.out.println("Case " +(i+1)+ ":");
            System.out.println(a + " + " + b + " = " + a.add(b) );
        }
    }
}
