#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <utility>
#include <algorithm>

using namespace std;

template<typename T> 
void show(T a){
  for(auto i : a){ cout << i << " "; }
  cout << endl;
}


int main(int argc, char *argv[]){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  
  int n;
  cin >> n;
  vector<int> a(n);
  for(int& i : a){
    cin >> i;
  }
  
  int maxn = a[0];
  for(int i = 0; i < n; i++){
    maxn = max(maxn, a[i]);
  }
  
  // n x n
  int count = 0;
  for(int i = 0; i < maxn; i++){
    for(int j = 0; j < n; j++){
      if(a[j] > 0){
        count++;
        while(++j < n){
          if(a[j] <= 0) break;
        }
      }
    }
    for(int j = 0; j < n; j++) a[j] -= 1;
  }
  
  //show(a);
  
  cout << count << endl;
}
