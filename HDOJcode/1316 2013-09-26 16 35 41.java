******************************
    Author : townboy
    Submit time : 2013-09-26 16:35:41
    Judge Status : Accepted
    HDOJ Runid : 9231646
    Problem id : 1316
    Exe.time : 171MS
    Exe.memory : 5676K
    https://github.com/townboy
******************************


import java.io.*;
import java.util.*;
import java.math.*;

public class Main {
    public static void main(String[] args) {
        BigInteger res[] = new BigInteger[500];
        res[0] = BigInteger.ONE;
        res[1] = BigInteger.valueOf(2);
        
        BigInteger end = BigInteger.TEN;
        for(int i = 0;i < 99;i++)
            end = end.multiply(BigInteger.TEN);
        
        for(int i = 2; ;i++) {
            res[i] = res[i-1].add(res[i-2]);
            if(0 < res[i].compareTo(end))
                break;
        }
        
        Scanner cin = new Scanner(System.in);
        while(true) {
            BigInteger a = cin.nextBigInteger();
            BigInteger b = cin.nextBigInteger();
            if(0 == a.add(b).compareTo(BigInteger.ZERO)  ) 
                break;
            int aa ,bb;
            for(aa = 0; ; aa++) 
                if(0 <= res[aa].compareTo(a))
                    break;
            
            for(bb = 0; ; bb++) 
                if(0 < res[bb].compareTo(b))
                    break;
                
            System.out.println(bb - aa);
        }
    }
}