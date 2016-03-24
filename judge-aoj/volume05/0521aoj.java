/*java 1.8*/
import java.util.*;

class Main{
  public static void main(String args[]){
    Scanner scan=new Scanner(System.in);
    while(scan.hasNext()){
      int money=scan.nextInt();
      if(money==0)
        break;
      money=1000-money;

      /*500,100,50,10,5,1*/
      int a=money/500;
      money%=500;

      a+=money/100;
      money%=100;

      a+=money/50;
      money%=50;

      a+=money/10;
      money%=10;

      a+=money/5;
      money%=5;

      a+=money;

      System.out.println(a);
    }
  }
}
