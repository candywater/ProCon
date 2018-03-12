#include "iostream"
#include "string"

using namespace std;

class Solution {
public:
  int (string s) {
    int res = 0;
    for(int i = 0; i < s.size(); i++){
      res = res * 26 + (int)(s[i] - 'A' + 1);
    }
    return res;
  }
  string convertToTitle(int n) {
    string res;
    while(n > 26){
      res = (char)((n-1)%26 + 'A') + res;
      n = (n-1) / 26;
    }
    res = (char)((n-1)%26 + 'A') + res;
    return res;
  }
};


int main(int argc, char const *argv[]) {
  Solution a ;
  cout << a.titleToNumber("AAA") << endl;
  return 0;
}
