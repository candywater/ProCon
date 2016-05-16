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

static int alpha[26];
static int a = 0, b = 0;

int main(int args, char *argc[]){
  char tmp;
  int count = 0;
  for(int i = 0;i<26;i++)
    alpha[i] = 0;

  while(cin >> tmp)
    alpha[tmp-'a']++,
      count++;

  for(int i = 0;i<26;i++){
    if(alpha[i] % 2 != 0)
      b++;
    a+=alpha[i]/2;
  }

  if(b == 0){
    cout<<count<<endl;
    return 0;
  }

  cout<<(a/b*2 + 1) <<endl;
  
  return 0;
}
