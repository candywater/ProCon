#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <utility>
#include <algorithm>

using namespace std;

//vector<int> dx = {0, 1, 0, -1};
//vector<int> dy = {1, 0, -1, 0};

template<typename T> 
void show(T a){
  for(auto i : a){ cout << i << " "; }
  cout << endl;
}
template<typename T> 
void showmatrix(T a){
  for(auto j: a){for(auto i : j){ cout << i; }cout << endl;}
  cout << endl;
}
void check(int i = 0){
  cout << "checkpoint:[" << i << "]" << endl;
}


/*
  1:9
  2:4
  3:4
  4:2
  5:1
  6:1
  7:4
  8:2
  9:2
*/
int getNum(long a, long b){
  if(b == 0) return 1;
  int ia = a%10;
  if(ia == 0 || ia == 5 || ia ==6) return ia;
  int c;
  if(ia == 1){
    c = 9;
  }
  if(ia == 2 || ia ==3 || ia==7){
    c = 4;
  }
  if(ia ==4 ||ia==8 ||ia==9){
    c = 2;
  }
  c = (b-1) % c;
  int res = ia;
  for(int i = 0; i < c; i++){
    res = res * ia;
    res = res % 10;
  // cout << "res:" << res <<endl;
  }
  return res % 10;
}

int main(int argc, char *argv[]){
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  // cout << getNum(7, 1) << endl;
  // cout << getNum(7, 2) << endl;
  // cout << getNum(7, 3) << endl;
  // cout << getNum(7, 4) << endl;
  // cout << getNum(7, 5) << endl;

  int a, b, c;
  cin >> a >> b>> c;
  if( c == 0)
    b = 1;

  int r = getNum(a, b);

  cout << r <<endl;

}
