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

bool comp(char a, char b, char c){
  if(a == b) return true;
  if(a == c) return true;
  if(b == c) return true;
  return false;
}

int main(int argc, char *argv[]){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  
  int n;
  string a, b, c;
  cin >> n >> a >> b >> c; 
  
  int count = 0;
  for(int i = 0; i < n; i++){
    if(a[i] == b[i] && b[i] == c[i]) continue;
    if(comp(a[i], b[i], c[i])) count++;
    else count += 2;
  }
    
  cout << count << endl;
  

}
