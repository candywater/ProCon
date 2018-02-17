import java.util.*;

class Main{

  static Scanner sc = new Scanner(System.in);
  static int n,q;


  public static void main(String args[]){
    while(sc.hasNext()){
      n = sc.nextInt();
      q = sc.nextInt();
      if(n == 0 && q == 0)
        return;
      int res = solute();
      System.out.println(res);
    }
  }

  public static int solute(){
    int m;
    int table[] = new int[101];
    for(int i=0;i<n;i++){
      m = sc.nextInt();
      for(int im=0;im<m;im++){
        int t = sc.nextInt();
        table[t] += 1;
      }
    }

    int max = table[0];
    int data = 0;
    for(int i=0;i<101;i++){
      if(table[i] > max){
        max = table[i];
        data = i;
      }
    }
    if(max < q)
      return 0;
    else 
      return data;
  }

}
