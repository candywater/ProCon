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
  char a;
  while(cin>>a&&a!='\n')
    if(a<='C')
      printf("%c",('Z'+a-'A'-2));
    else
      printf("%c",a-3);
  cout<<endl;
  return 0;
}
