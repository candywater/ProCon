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

using namespace std;

int main(int args, char *argc[]){
  int a,b,c;
  //price of A is a,
  //price of B is b;

  cin>>a>>b>>c;
  if(a>b)
    swap(a,b);
  int n=c/a;
  n+=(c%a)/b;

  cout<<n<<endl;
  return 0;
}
