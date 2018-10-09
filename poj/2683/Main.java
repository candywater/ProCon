import java.util.*;
import java.math.*;

public class Main{

  static int m;
  static Scanner sc = new Scanner(System.in);
  static int year,n;

  static BigDecimal money;
  static int mod;//0 as simple; 1 as compound
  static BigDecimal stack;
  static BigDecimal rate;
  static BigDecimal charge;

  public static void main(String args[]){
    m = sc.nextInt();
    for(int i=0;i<m;i++)
      solute();
  }
  public static void solute(){
    money = new BigDecimal(sc.nextDouble());
    BigDecimal money_bak = money;
    year = sc.nextInt();
    n = sc.nextInt();
    BigDecimal[] itr = new BigDecimal[n];

    for(int i=0;i<n;i++){
      money = money_bak;
      mod = sc.nextInt();
      rate = new BigDecimal(sc.nextDouble());
      charge = new BigDecimal(sc.nextLong());
      stack = new BigDecimal("0");

      if(mod == 0)
        simpleMod(year);
      else 
        compoundMod(year);
      money = money.add(stack);
      money = new BigDecimal(money.longValue());
      itr[i] = money;
      //System.out.println("--money--" + money);
    }
    BigDecimal a = itr[0];
    for(int i = 1; i<itr.length;i++)
      if(a.compareTo(itr[i]) < 0 )
        a = itr[i];

    System.out.println(a);
  }
  public static void compoundMod(int year){
    for(int i = 0; i < year; i++){
      BigDecimal a = money.multiply(rate);
      money = money.add(a);
      money = new BigDecimal(money.longValue());
      money = money.subtract(charge);
    }
    //System.out.println("--com--" + money);
    //System.out.println("stack:" + stack);
  }
  public static void simpleMod(int year){
    for(int i=0;i<year;i++){
      try {
        if(stack == null)
          stack = money.multiply(rate);
        else 
          stack = stack.add(money.multiply(rate));
        stack = new BigDecimal(stack.longValue());
      }
      catch (NullPointerException e){
        System.out.println("= =|||");
      }
      money = money.subtract(charge);
    }
    //System.out.println("--sim--" + money);
    //System.out.println("stack:" + stack);
  }
}
