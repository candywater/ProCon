#include <iostream>
#include <string>
#include <climits>

using namespace std;

template<typename T> 
void show(T a){
  for(auto i : a){ cout << i << " "; }
  cout << endl;
}


int main(int argc, char *argv[]){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  
  string s;
  cin >> s;
  
  int res = INT_MAX;
  for(int i = 0; i < s.size()-2; i++){
    int tmp = stoi(s.substr(i, 3));
    tmp = 753 - tmp;
    tmp = tmp > 0 ? tmp : -tmp;
    if(tmp < res) res = tmp;
  }
  cout << res << endl;

}
