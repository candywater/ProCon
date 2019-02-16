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


int main(int argc, char *argv[]){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  
  int n, m;
  cin >> n >> m;
  vector<int> v(m, 0);
  int tmp;
  for(int i = 0; i < n; i++){
    cin >> tmp;
    for(int j = 0; j < tmp; j++){
      int t;
      cin >> t;
      v[t-1]++;
    }
  }
  int count = 0;
  for(int i = 0; i < m; i++){
    if(v[i] == n) count++;
  }
  //show(v);
  cout << count << endl;

}
