******************************
    Author : townboy
    Submit time : 2013-08-03 01:10:37
    Judge Status : Accepted
    HDOJ Runid : 8811441
    Problem id : 2621
    Exe.time : 140MS
    Exe.memory : 3868K
    https://github.com/townboy
******************************


import java.io.*;
import java.util.*;
import java.math.*;

public class Main {
    public static void main(String[] args) {
        Scanner cin = new Scanner(System.in);
        
        BigInteger up,down ,a ,b;
        BigInteger minn, t;
        
        while(cin.hasNextBigInteger()) {
            a = cin.nextBigInteger();
            b = cin.nextBigInteger();
            if(a.equals(BigInteger.ZERO) == true && b.equals(BigInteger.ZERO) == true)
                break;
            up = BigInteger.ONE;
            down = BigInteger.ONE;
            
            minn = a.min(b);
            
            t = a.add(b).subtract(minn).add(BigInteger.ONE);
            while( t.equals(a.add(b).add(BigInteger.ONE)) == false ) {
                up = up.multiply(t);
                t = t.add(BigInteger.ONE);
            }
 
            t = BigInteger.ONE;
            while( t.equals(minn.add(BigInteger.ONE)) == false ) {
                down = down.multiply(t);
                t = t.add(BigInteger.ONE);
            }
            System.out.println(up.divide(down));
        }
    }
}