#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <bitset>
#include <stack>

using namespace std;

template<typename T> 
void show(T a){
  for(auto i : a){ cout << i << " "; }
  cout << endl;
}

long long sum = 0;
long long count = 0;

void add_num(string& s, bitset<12>&b ){
  int j = 0;
  for(int i = 0; i < s.size()-1; i++){
    if(b[i] == 1) {
      string num = s.substr(j, i-j+1);
      sum += stoll(num);
      j = i + 1;
    }
  }
  string num = s.substr(j, s.size()-j);
  sum += stoll(num);
}

void dfs(int pos, string& s, bitset<12>& b){
  if(pos >= s.size()) return;
  if(pos == s.size()-1){
    add_num(s, b);
  }
  b[pos] = 1;
  dfs(pos+1, s, b);
  b[pos] = 0;
  dfs(pos+1, s, b);
}

int main(int argc, char *argv[]){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  string s;
  long long num;
  cin >> num;
  s = to_string(num);
  bitset<12> b(0);
  dfs(0, s, b);
  cout << sum << endl;
}
