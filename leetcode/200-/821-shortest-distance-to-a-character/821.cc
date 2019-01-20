#include "iostream"
#include "vector"
#include "string"

using namespace std;

class Solution {
public:
  vector<int> shortestToChar(string S, char C) {
    vector<int> table;
    vector<int> res;
    for(int i = 0; i < S.size(); i++){
      if(S[i] == C) table.push_back(i);
    }
    int j = 0;
    int k = j + 1;
    for(int i = 0; i < S.size(); i++){
      if(j + 1 < table.size()) {
        if(i > table[j+1]) j++;
        k = j + 1;
      }
      if(k >= table.size()) k = j;//assume that at least there is a char C in string S
      int tmp1 = abs(table[j] - i);
      int tmp2 = abs(table[k] - i);
      int tmp = tmp1 < tmp2 ? tmp1 : tmp2;
      //cout << tmp1 << " " << tmp2 << endl;
      res.push_back(tmp);
    }
    return res;
  }

  int abs(int j){
    return j > 0 ? j : -j;
  }


};

template<typename T>
void show(T a){
  for(auto i : a)
    cout << i << " ";
  cout << endl;
}

int main(int argc, char const *argv[]) {
  Solution a;
  show(a.shortestToChar("loveleetcode", 'e'));
  show(a.shortestToChar("aaab", 'b'));
  return 0;
}
