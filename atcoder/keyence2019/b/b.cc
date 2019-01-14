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
  
  string str;
  cin >> str;
  string key = "keyence";
  
  if(str.size() < key.size()){
    cout << "No" <<endl;
    return 0;
  }
  
  int i = 0;
  for(; i < key.size(); i++){
    if(str[i] != key[i]) break;
  }
  int j = 0;
  for(; j < key.size(); j++){
    if(str[str.size()-j-1] != key[key.size()-j-1]) break;
  }
  
  //cout << i << " " << j << endl;
  if(i + j >= key.size())
    cout << "YES" << endl;
  else  
    cout << "NO" << endl;

}
