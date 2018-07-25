#include <cstdio>
#include <vector>
#include <string>
#include <set>
#include <iostream>

using namespace std;
const vector<char> par = {
  '(', 
  ')'
};
class Solution {
  public:
    vector<string> generateParenthesis(int n) {
      set<string> res;
      backtrack(res, "", 2*n);
      return vector<string>(res.begin(), res.end());
    }

    bool isCorrect(string& str, int j){
      //cout << str << endl;
      int balance = 0;
      for(int i = 0; i < j; i++){
        balance += (str[i] == par[0] ? 1 : -1);
        if(balance < 0) 
          return false;
      }
      //cout << "true" << endl;
      return balance == 0;
    }

    void backtrack(set<string>& res, string str, int i){
      if(i == static_cast<int>(str.size())){
        if(isCorrect(str, i))
          res.insert(str);
        return;
      }
      for(int j = 0; j < 2; j++){
        string tmp = str;
        tmp.append(1, par[j]);
        backtrack(res, tmp, i);
      }
    }
};

template<typename T>
void show(vector<T> a){
  for(int i = 0; i < a.size(); i++){
    cout << a[i] << endl;
  }
}

int main(){
  Solution a;
  vector<string> b = a.generateParenthesis(4);
  show(b);

  return 0;
}
