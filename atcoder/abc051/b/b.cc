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
  int k, s;
  cin >> k >> s;
  int count = 0;
  for(int i = 0; i <= k; i++){
    for(int j = 0; j <= k; j++){
      int tmp = s - i - j;
      count += tmp <= k && tmp >= 0 ? 1 : 0;
    }
  }
  cout << count << endl;
}
