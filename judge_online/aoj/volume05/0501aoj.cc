/*c++98*/
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <string>
#include <cstring>
#include <cmath>

using namespace std;

int main(int args, char *argc[]){
  int n;
  while(cin>>n){
    if(n==0) return 0;
    map<char,char> table;
    for(int i=0;i<n;i++){
      char a,b;
      cin>>a>>b;
      table.insert(make_pair(a,b));
    }

    cin>>n;
    for(int i=0;i<n;i++){
      char a;
      cin>>a;
      if(table.count(a)!=0)
        cout<<table[a];
      else
        cout<<a;
    }
    cout<<endl;
    }
  return 0;
}
