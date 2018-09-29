/*java 1.8*/
import java.util.*;

class Main{
  public static void main(String args[]){
    Scanner scan=new Scanner(System.in);
    while(scan.hasNext()){
      int na=scan.nextInt();
      int nb=scan.nextInt();
      int nc=scan.nextInt();
      if(na*nb*nc==0)
        return;
      int n=scan.nextInt();
      int a[]=new int [na];
      int b[]=new int [nb];
      int c[]=new int [nc];
      Arrays.fill(a,2);
      Arrays.fill(b,2);
      Arrays.fill(c,2);
      //ok=1; not ok=0; dont know=2

      int ta,tb,tc;
      int res;

      int table[][]=new int [n][4];
      for(int ix=0;ix<n;ix++)
        for(int iy=0;iy<4;iy++)
          table[ix][iy]=-1;

      for(int i=0;i<n;i++){
        ta=scan.nextInt();
        ta-=1;
        tb=scan.nextInt();
        tb-=(na+1);
        tc=scan.nextInt();
        tc-=(na+nb+1);
        res=scan.nextInt();

        if(res==1){
          a[ta]=1;b[tb]=1;c[tc]=1;
        }
        if(res==0){
          table[i][0]=ta;
          table[i][1]=tb;
          table[i][2]=tc;
          table[i][3]=res;
        }
      }
      for(int i=0;i<n;i++){
        if(table[i][3]==0)
          twoOfThree(table[i][0],table[i][1],table[i][2],
              a,b,c);
      }


      for(int i=0;i<na;i++)
        System.out.println(a[i]);
      for(int i=0;i<nb;i++)
        System.out.println(b[i]);
      for(int i=0;i<nc;i++)
        System.out.println(c[i]);

    }
  }//main
  static void twoOfThree(int ta,int tb,int tc,int []a,int []b,int []c){
    if(a[ta]==1&&b[tb]==1){
      c[tc]=0;return;
    }
    else if(a[ta]==1&&c[tc]==1){
      b[tb]=0;return;
    }
    else if(b[tb]==1&&c[tc]==1){
      a[ta]=0;return;
    }

  }

}
