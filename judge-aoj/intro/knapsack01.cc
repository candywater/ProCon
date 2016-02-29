#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <string>
#include <cstring>
#include <cmath>
#include <climits>

#define max(a,b) a>b?a:b
#define min(a,b) a<b?a:b
/*0-1 ナップザック問題

価値が vi 重さが wi であるような N 個の品物と、容量が W のナップザックがあります。次の条件を満たすように、品物を選んでナップザックに入れます：

    選んだ品物の価値の合計をできるだけ高くする。
    選んだ品物の重さの総和は W を超えない。

価値の合計の最大値を求めてください。
入力

１行目に２つの整数　N、W　が空白区切りで１行に与えられます。 続く N 行で i 番目の品物の価値 vi と重さ wi が空白区切りで与えられます。
出力

価値の合計の最大値を１行に出力してください。
制約

    1 ≤ N ≤ 100
    1 ≤ vi ≤ 1,000
    1 ≤ wi ≤ 1,000
    1 ≤ W ≤ 10,000

入出力例

入力例 1

4 5
4 2
5 2
2 1
8 3

出力例 1

13


入力例 2

2 20
5 9
4 10

出力例 2

9
*/

using namespace std;

int n,weight;
int testnum=0;
int w[100],v[100];
int table[10001][10001]={0};

int rec(int ix,int iw){
  //printf("testnum:%d ",++testnum);
  if(table[ix][iw]>0)
    return table[ix][iw];
  if(ix==n)
    return 0;
  if(iw<w[ix])
    return table[ix+1][iw];

  int res1=rec(ix+1,iw-w[ix])+v[ix];
  int res2=rec(ix+1,iw);
  int res=max(res1,res2);
  table[ix][iw]=res;
  //printf("table[%d][%d]:%d",ix,iw,table[ix][iw]);
  return res;
}

int main(int args, char *argc[]){

  cin>>n>>weight;
  for(int i=0;i<n;i++)
    cin>>v[i]>>w[i];

  rec(0,weight);
  //puts("\n");
  /*for(int i=0;i<n+1;i++){
    for(int ix=0;ix<weight+1;ix++)
      //printf("table[%d][%d]:%d ",i,ix,table[i][ix]);
      //puts("");
  }*/
  printf("%d\n",table[0][weight]);

  return 0;
}
