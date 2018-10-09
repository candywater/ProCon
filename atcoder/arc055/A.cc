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

static int n;

int main(int args, char *argc[]){

  cin >> n;

  if(n != 0)
    cout << "1";
  n--;
  while(n != 0)
    n--,
      cout << "0";
  cout<< "7" << endl;

  return 0;
}
