#include "iostream"
#include "string"

using namespace std;

class Solution {
public:
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
  cout << a.convertToTitle(26*26) << endl;
  return 0;
}
