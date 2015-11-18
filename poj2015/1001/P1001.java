import java.util.*;
import java.math.*;

public class P1001{
    public static void main (String args[]){
        Scanner in =new Scanner (System.in);    
        while(in.hasNext()){
            BigDecimal r=in.nextBigDecimal();
            int n=in.nextInt();
            r=r.pow(n);
            r=r.stripTrailingZeros();
            String str=r.toPlainString();
            int index=str.indexOf(".");
            BigDecimal a=new BigDecimal(1);
            if(a.compareTo(r)>0){
                System.out.println(str.substring(index));
            }
            else 
                System.out.println(str);

        }
    }
}

