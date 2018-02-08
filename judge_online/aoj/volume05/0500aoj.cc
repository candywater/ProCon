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
    if(n==0)
      return 0;
    int a=0,b=0;
    for(int i=0;i<n;i++){
      int ia,ib;
      cin>>ia>>ib;
      if(ia==ib){
        a+=ia;
        b+=ib;
      }
      else if(ia<ib)
        b+=(ia+ib);
      else
        a+=(ia+ib);
    }
    printf("%d %d\n",a,b);
  }
  return 0;
}
