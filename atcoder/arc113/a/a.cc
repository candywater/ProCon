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


int main(int argc, char *argv[]){
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  int k ;
  cin >> k;

  long long count = 0;

  for(int i = 1; i <= k; i++){
    for(int j = 1; j <= k; j++){
      if(i*j > k) break;
      for(int m = 1; m <= k; m++){
        if(i*j*m <= k){
          count++;
        }
        else{
          break;
        }
      }
    }
  }

  cout << count << endl;

  return 0;
}
