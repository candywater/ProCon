#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <utility>
#include <algorithm>
#include <set>

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

bool dfs(int before, int i, vector<vector<int>>& e, vector<bool>& v){
  //cout << "i:" << i << endl;
  if(v[i] == true) return false;
  v[i] = true;
  bool res = true;
  for(int j : e[i]){
    if(j == before) continue;
    bool tmp = dfs(i, j, e, v);
    res = tmp && res;
  }
  return res;
}

int main(int argc, char *argv[]){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  
  int n, m;
  cin >> n >> m;
  vector<bool> v(n, false);
  vector< vector<int> > e(n, vector<int>());
  for(int i = 0; i < m; i++){
    int a, b;
    cin >> a >> b;
    e[a-1].push_back(b-1);
    e[b-1].push_back(a-1);
  }
  for(int i = 0; i < n; i++){
    sort(e[i].begin(), e[i].end());
  }
  
  //show(v);
  //showmatrix(e);
  
  
  int count = 0;
  for(int i = 0; i < n; i++){
    count += (dfs(-1, i, e, v) == true ? 1 : 0);
    //cout << "count:" << count << endl;
    //show(v);
  }
  cout << count << endl;
}
