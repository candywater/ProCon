/*java 1.8*/
import java.util.*;
import java.math.*;

class Main{
  public static void main(String args[]){
    Scanner scan=new Scanner(System.in);
    while(scan.hasNext()){
      int n = scan.nextInt();
      int k = scan.nextInt();
      if(n*k==0) return;

      //0th~k-1st, make sum of them is 0
      //then look k-th num, record 0 - 0th + kth, compare 0 and new value
      //then look (k+1)th num, record (old value - 1st + (k+1)th), compare maxium value and new value
      int table[]=new int [n];
      for(int i=0;i<n;i++){
        table[i]=scan.nextInt();
      }

      int res=0;
      int max=0;
      int imax=0;
      for(int i=k;i<n;i++){
        res=res+table[i]-table[i-k];
        if(res>max){
          //System.out.printf("max changed,imax=%d,imaxEnd=%d\n",i-k+1,i);
          max=res;
          imax=i-k+1;
        }
      }

      long out=0;
      for(int i=imax;i<imax+k;i++){
        out+=table[i];
      }
      //System.out.printf("imax:%d\n",imax);
      System.out.println(out);

    }
  }//main
}
