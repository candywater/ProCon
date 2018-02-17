//created by candywater 2017-Oct-21
import java.util.*;
public class PrimeNum{
  public ArrayList<Integer> primeNums= new ArrayList<Integer>();
  public static void main(String args[]){
    PrimeNum a = new PrimeNum();
    Scanner sc = new Scanner(System.in);
    int in = sc.nextInt();
    while(in != -1){
      a.process(in);
      in = sc.nextInt();
    }
  }

  public boolean process(int in){
    int index = checkIndex(in);
    calc(index, in);
    outputExist(primeNums.size()); 
    return true;
  }

  //calc start index
  public int checkIndex(int in){
    for(int i = primeNums.size() - 1; i >= 0; --i){
      if( primeNums.get(i) < in )
        return primeNums.get(i);
    }
    return 1;
  }

  //calculate numbers in range
  public boolean calc(int start, int end){
    for(int i = start; i <= end - 2; ++i){
      if( isPrime(i) && isPrime(i + 2) ){
        primeNums.add(i);
      }
    }
    return true;
  }

  //
  public boolean outputExist(int length){
    if(length > primeNums.size() || length < 0)
      return false;
    for(int i = 0; i < length; ++i){
      System.out.print( "(" + primeNums.get(i) + "," + (primeNums.get(i)+2) + ")" );
      if(i % 2 == 1)
        System.out.println();
    }
    return true;
  }

  public boolean isPrime(int num){
    if( num == 1 ) 
      return false;
    int half = num / 2 + 1;
    for(int i = 2; i <= half; ++i){
     if ( num % i == 0 ) 
       return false;
    }
    return true;
  }


  //DEBUG
  public void log(String str){
    System.out.println(str);
  }
  /*
   * used log
   *
   *
    log("PRIME:" + num);
   *
    a.log("read end");
      a.log("process end");
    log("calc before");
    log("calc end");
    log("output exist end");
   *
   */
}
