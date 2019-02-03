#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <utility>
#include <algorithm>
#include <cmath>

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
  int n, m;
  cin >> n >> m;
  vector<int> v(m);
  if(m <= 1) {cout << "0" << endl; return 0;}
  if(n >= m) {cout << "0" << endl; return 0;}
  for(int& i : v){
    cin >> i;
  }
  sort(v.begin(), v.end());
  int start = *v.begin();
  int end = *v.rbegin();
  int length = end - start;
  
  vector<int> lenlist;
  for(int i = 1; i < m; i++){
    lenlist.push_back(v[i]-v[i-1]);
  }
  sort(lenlist.begin(), lenlist.end());
  
  for(int i = m-1; i >=m-n; i--){
    length -= lenlist[i];
  }
  cout << length << endl;

}
