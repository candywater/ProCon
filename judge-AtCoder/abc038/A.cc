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
  char t = 'T';
  string a;

  cin>>a;

  if(*(--a.end()) == t)
    cout<<"YES\n";
  else
    cout<<"NO\n";

  return 0;
}
