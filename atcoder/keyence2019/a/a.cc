#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

template<typename T> 
void show(T a){
  for(auto i : a){ cout << i << " "; }
  cout << endl;
}


int main(int argc, char *argv[]){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  unordered_map<int, int> map;
  map[1] = 0;
  map[7] = 0;
  map[4] = 0;
  map[9] = 0;
  vector<int> a(4);
  for(int& i : a){
    cin >> i;
  }
  for(int& i : a){
    if(map.count(i) <= 0) {
      cout << "NO" << endl;
      return 0;
    }
    map[i] = map[i]+1;
  }
  
  for(int& i : a){
    if(map[i] != 1){
      cout << "NO" << endl;
      return 0;
    }
  }
  cout << "YES" << endl;
}
