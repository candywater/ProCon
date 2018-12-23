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

#define max(a,b) (a>b)?a:b
using namespace std;

int main(int args, char *argc[]){
  int a,b,c,d;
  int q,w,e,r;
  cin>>a>>b>>c>>d;
  cin>>q>>w>>e>>r;
  int suma=a+b+c+d;
  int sumb=q+w+e+r;
  cout<<(max(suma,sumb))<<endl;
  return 0;
}
