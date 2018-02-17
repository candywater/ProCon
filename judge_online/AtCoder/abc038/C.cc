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

static long long int sum = 0;

long long int calc(long long int a){
  return ((a + 1) * a / 2);
}

void solve(long long int a){
  //cout<<"======"<<a<<"=======\n";
  sum += calc(a);
}

int main(int args, char *argc[]){
  int n;
  long long int a;
  long long int front;
  long long int count_num = 1;
  cin >> n;
  cin >> front;

  for(int i = 1;i < n;i++){
    scanf("%d", &a);
    if(front < a)
      count_num++;
    else{
      solve(count_num);
      count_num = 1;
    }
    front = a;
  }

  if(count_num != 0)
    solve(count_num);
  
  cout << sum << endl;

  return 0;
}
