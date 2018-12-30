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

bool isMoreThanOnce(string& num){
  bool f3 = false;
  bool f5 = false;
  bool f7 = false;
  for(char& i : num){
    if(f3&&f5&&f7) return true;
    else if(i == '3') f3 = true;
    else if(i == '5') f5 = true;
    else if(i == '7') f7 = true;
  }
  if(f3&&f5&&f7) return true;
  else return false;
}

void dfs(int limitLen, int limitNum, string& num, int& count){
  if(num.size() > limitLen)
    return;
  int intnum = 0;
  if(num.size() > 0 && isMoreThanOnce(num)) {
    intnum = stoi(num);
    if(intnum <= limitNum){
      //cout << num << " " << intnum <<  endl;
      count += 1;
    }
  }
  
  num.push_back('3');
  dfs(limitLen, limitNum, num, count);
  num.pop_back();
  
  num.push_back('5');
  dfs(limitLen, limitNum, num, count);
  num.pop_back();
 
  num.push_back('7');
  dfs(limitLen, limitNum, num, count);
  num.pop_back();
  
}

int main(int argc, char *argv[]){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  
  int n;
  cin >> n;
  cout << endl;
  string n_str = to_string(n);
  string tmp = "";
  int count = 0;
  dfs(n_str.size(), n, tmp, count);
  cout << count << endl;
}
