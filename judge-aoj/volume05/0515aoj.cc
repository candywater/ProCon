#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>

using namespace std;

static int x,y;
vector<vector<int> > trap;
vector<vector<int> > table;

void solve (){
//  cout<<"entered solve",printf(" x:%d,y:%d\n",x,y);
  for(int ix=1;ix<=x;ix++){
 //   cout<<" enter first for";
    for(int iy=1;iy<=y;iy++){
      if(trap[ix][iy]==1) continue;
      if(ix==1&&iy==1) continue;
  //    printf(" ix:%d,iy:%d\n",ix,iy);

   //   printf("table[%d][%d]=table[%d][%d]+table[%d][%d] ",ix,iy,ix-1,iy,ix,iy-1);
      table[ix][iy]=table[ix-1][iy]+table[ix][iy-1];
      //table[ix*(y+1)+iy]=table[ix*(y)+iy]+table[ix*(y+1)+iy-1];
    }
  }

}
int main(void){
  while(cin>>x>>y,x&&y){
    int n;
    cin>>n;
  
    trap.clear();
    trap.resize(x+1, vector<int>(y+1,0));
    //int trap[x+1][y+1];
    //memset(trap,0,sizeof(trap));
    int tx,ty;
    for(int i=0;i<n;i++){
      cin>>tx>>ty;
      trap[tx][ty]=1;
    }

    //int table[x+1][y+1];
    //memset(table,0,sizeof(table));
    table.clear();
    table.resize(x+1,vector<int>(y+1,0));
    table[1][1]=1;

    //cout<<"before solve\n";
    solve();
    cout<<table[x][y]<<endl;

  }
  return 0;
}


/*import java.util.*;

  class Aoj0515{
  static int x,y;
  static public void main(String args[]){
  Scanner scan=new Scanner(System.in);
  while(scan.hasNext()){
  x=scan.nextInt();
  y=scan.nextInt();
  if(x==0&&y==0)
  return;
  int n;
  n=scan.nextInt();
  int trap[][]=new int [x+2][y+2];
  int tmpx,tmpy;
  for(int i=0;i<n;i++){
  tmpx=scan.nextInt();
  tmpy=scan.nextInt();
  trap[tmpx][tmpy]=1;
  }

  int table[][]=new int [x+2][y+2];
  table[1][1]=1;
  solve(trap,table);
//      print(table);
System.out.println(table[x][y]);
}
return;
}
static public void print(int table[][]){
for(int iy=1;iy<=y;iy++){
for(int ix=1;ix<=x;ix++){
System.out.printf("%d ",table[ix][iy]);
}
System.out.println();
}
}
static public void solve(int trap[][],int table[][]){

//    System.out.println("table[1][1]="+table[1][1]);

for(int ix=1;ix<=x;ix++){
int iy=1;
for(;iy<=y;iy++){
if(trap[ix][iy]==1) continue;
if(ix==1&&iy==1) continue;
if(trap[ix][iy]==1) continue;
//        System.out.printf("table[%d][%d]=table[%d][%d]+table[%d][%d] ",ix,iy,ix-1,iy,ix,iy-1);
table[ix][iy]=table[ix-1][iy]+table[ix][iy-1];
//       System.out.printf("[%d]=[%d]+[%d]\n",table[ix][iy],table[ix-1][iy],table[ix][iy-1]);
}
}
}
static public void solve(int a,int j,int trap[][]){
if(a==x && j==y){
res++;
return;
}
if(a<x) 
if(trap[a+1][j]!=1)
solve(a+1,j,trap);
if(j<y)
if(trap[a][j+1]!=1)
solve(a,j+1,trap);
}
}
 */

