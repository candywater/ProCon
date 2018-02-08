/*c++11*/
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

using namespace std;

int main(int args, char *argc[]){
  int n,q;
  cin>>n>>q;

  vector<int> table;
  table.resize(n+1,0);

  for(int i=0;i<q;i++){
    int a,b,c;
    cin>>a>>b>>c;
    for(int iy=a;iy<=b;iy++)
      table[iy]=c;
    //table[a]+=c;
    //table[b]-=c;
  }

  for(auto ix=(++table.begin());ix!=table.end();ix++)
    cout<<*ix<<endl;

  /*int tmp=0;
  for(auto ix=(++table.begin());ix!=table.end();ix++){
    tmp+=(*ix);
    cout<<tmp<<endl;
  }*/
  return 0;
}
