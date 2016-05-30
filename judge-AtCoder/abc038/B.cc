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

  int a[2] = {0};
  int b[2] = {0};

  cin >> a[0] >> a[1];
  cin >> b[0] >> b[1];

  for(int i = 0;i < 2;i++)
    for(int j = 0;j < 2;j++)
      if(a[i] == b[j]){
        cout << "YES\n";
        return 0;
      }

  cout<<"NO\n";
  return 0;
}
