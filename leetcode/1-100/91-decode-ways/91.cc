#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
  int numDecodings(string s) {
    if(s.length() < 1) return 0;
    vector<int> mem(s.length()+1, 1);
    dp(s, mem, 1);
    //show(mem);
    return mem[s.length()];
  }

  void dp(string& a, vector<int>& mem, int j){
    int i = j - 1;
    if(j > a.length()) return;
    if(check_posibility(i-1, j-1, a) && a[j-1] == '0') //10, 20 case 
      mem[j] = mem[j-2];
    else if(check_posibility(i-1, j-1, a)) //two digits case 
      mem[j] = mem[j-1] + mem[j-2];
    else if(a[j-1] == '0')//single 0 case 
      mem[j] = 0;
    else //other single digit case
      mem[j] = mem[j-1];
    dp(a, mem, j+1);
  }

  bool check_posibility(int m, int n, string& a){
    if(m < 0) return false;
    char i = a[m];
    char j = a[n];
    if(i == '1' ) return true;
    if(i == '2' && j < '7') return true;
    return false;
  }

  template<typename T>
  void show(T a){
    for(auto i : a){
      cout << i << " ";
    }
    cout << endl;
}

};

template<typename T>
void show(T a){
  for(auto i : a){

  }
  cout << endl;
}

int main(int argc, char *argv[]){
  Solution a;
  //cout << argc << argv[0] << endl;
  cout << a.numDecodings(argv[1]) << endl;
}