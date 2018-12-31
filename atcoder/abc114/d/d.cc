#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <climits>
#include <algorithm>
#include <cmath>

using namespace std;

template<typename T> 
void show(T a){
  for(auto i : a){ cout << i << " "; }
  cout << endl;
}
/*
//https://www.geeksforgeeks.org/find-divisors-natural-number-set-1/
int countDivisors(int n, vector<int>& list){
  int count = 1;
  for(int i = 1; i <= sqrt(n); i++){
    if(n % i != 0) continue;
    if(n/i == i){
      count++;
    }
    else{
      count += 2;
    }
  }
  list[n] = count;
}

int pow(int i, int j){
  for(int k = 0; k < j; k++)
    i *= k + 1;
  return i;
}
*/

vector<int> list(101, 0);
// 使われた回数がx以上の素数の数を探す
int findmorethan(int x){
  int count = 0;
  for(int i : list){
    if(i >= x) count++;
  }
  return count;
}

int main(int argc, char *argv[]){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  
  // https://img.atcoder.jp/abc114/editorial.pdf
  // dp の実装は難しい。なぜなら、約数100と約数10が、重複する部分があるので、これを避ける実装が難しい。
  int count = 0;
  int n;
  cin >> n;
  
  // https://img.atcoder.jp/abc114/editorial.pdf
  // 1-100までのすべての素の約数が、何回使われたのかを記載
  for(int i = 2; i <= n; i++){
    int num = i;
    for(int j = 2; j <= num; j++){
      while(num % j == 0){
        list[j] += 1;
        num = num / j;
      }
    }
  }
  
  //show(list);
  
 
  // 75 = 75 = 3 x 25 = 3 x 5 x 5 = 5 x 15
  int res = 0;
  // 75 = 75
  res += findmorethan(74);
  res += (findmorethan(2)-1) * findmorethan(24);
  res += (findmorethan(2)-2) * (findmorethan(4)-1) * findmorethan(4) / 2;
  res += (findmorethan(4)-1) * findmorethan(14);
  
  //cout << findmorethan(4) << endl;
  //cout << findmorethan(2) << endl;
  
  cout << res << endl;
  
}
