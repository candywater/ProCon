#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <utility>

using namespace std;

vector<int> dx = {0, 1, 0, -1};
vector<int> dy = {1, 0, -1, 0};

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
//debug
void check(int i = 0){
  cout << "checkpoint:[" << i << "]" << endl;
}

int euclidean(int a, int b){
  if(a < b) swap(a, b);
  if(a == 0) return b;
  if(a == b || b == 0) return a;
  return euclidean(b, a%b);
}

int main(int argc, char *argv[]){
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  int n; cin >> n;
  vector<int> v(n);
  for(auto& i : v){
    cin >> i;
  }

  for(int i = 1; i < n; i++){
    v[i] = euclidean(v[i-1], v[i]);
  }

  cout << v[v.size()-1] << endl;
}
