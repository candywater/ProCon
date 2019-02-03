#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <utility>

using namespace std;

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


int main(int argc, char *argv[]){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  int n;
  cin >> n;
  vector<int> v(n);
  int sum = 0;
  for(auto& i : v){
    cin >> i;
    sum += i;
  }
  for(auto i : v){
    if(sum - i <= i){
      cout << "No" << endl;
      return 0;
    }
  }
  cout << "Yes" << endl;
}
