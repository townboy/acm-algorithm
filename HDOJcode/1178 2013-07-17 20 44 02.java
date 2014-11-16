******************************
    Author : townboy
    Submit time : 2013-07-17 20:44:02
    Judge Status : Accepted
    HDOJ Runid : 8622232
    Problem id : 1178
    Exe.time : 140MS
    Exe.memory : 3768K
    https://github.com/townboy
******************************


import java.io.*;
import java.math.*;
import java.util.Scanner;

class Main{
    public static void main(String[] args) {
        int n;
        String pr[] = new String[10];
        
        pr[1] = "1.00E0";
        pr[2] = "4.00E0";
        pr[3] = "1.00E1";
        pr[4] = "2.00E1";
        pr[5] = "3.50E1";
        pr[6] = "5.60E1";
        pr[7] = "8.40E1";
        
        
        Scanner cin = new Scanner(System.in);
        while(true) {
            n = cin.nextInt();
            if(0 == n) 
                return ;
            
            if(n <= 7) {
                System.out.println(pr[n]);
                continue;
            }
            
            BigDecimal ans = BigDecimal.valueOf(n);
            BigDecimal tem = BigDecimal.valueOf(n);
            tem = tem.multiply(BigDecimal.valueOf(2)).add(BigDecimal.ONE);
            ans = ans.multiply(ans.add(BigDecimal.ONE));
            ans = ans.multiply(tem);
            ans = ans.divide(BigDecimal.valueOf(12));
            tem = BigDecimal.valueOf(n);
            tem = tem.multiply(tem.add(BigDecimal.ONE));
            tem = tem.divide(BigDecimal.valueOf(4));
            ans = ans.add(tem);
            String A = ans.toString();
            if('.' == A.charAt(A.length()-2)) 
                A = A.substring(0, A.length()-2);
            int len = A.length()-1;
            
            while(ans.compareTo(BigDecimal.valueOf(10000)) >= 0)
                ans = ans.divide(BigDecimal.TEN, BigDecimal.ROUND_DOWN);
            if(ans.compareTo(BigDecimal.valueOf(1000)) >= 0)
                ans = ans.divide(BigDecimal.TEN, 0, BigDecimal.ROUND_HALF_UP);
            A = ans.toString();
            System.out.println(A.charAt(0) + "." + A.charAt(1) + A.charAt(2) + "E" + len);
        }
    }
}