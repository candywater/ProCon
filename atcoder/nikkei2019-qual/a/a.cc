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


int main(int argc, char *argv[]){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  int a, b, n;
  cin >> n >> a >> b;
  cout << min(a, b) << endl;
  int res = a+b-n;
  cout << (res > 0 ? res : 0) << endl;
}
