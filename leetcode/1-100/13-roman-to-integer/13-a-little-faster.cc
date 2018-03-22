#include "iostream"
#include "unordered_map"
#include "string"
#include "vector"
#include "climits"

using namespace std;

class Solution {
  //I, V, X, L, C, D, M
  //1, 5, 10, 50, 100, 500, 1000
  /*const vector<int> nums = {
    1,5,10,50,100,500,1000
  };
  const vector<char> alphabet = {
    'I', 'V', 'X', 'L', 'C', 'D', 'M'
  };*/
  const unordered_map<char, int> table = {
    {'I', 1},
    {'V', 5},
    {'X', 10},
    {'L', 50},
    {'C', 100},
    {'D', 500},
    {'M', 1000}
  };
public:
  int romanToInt(string s) {
    int res = 0;
    int tmp = 0;
    int next = INT_MIN;
    for(int i = 0; i < static_cast<int>(s.size()); i++){
    //don't know why, but this way is a little faster
      tmp = table.find(s[i])->second;
      next = i < static_cast<int>(s.size()) - 1
              ? table.find(s[i+1])->second
              : INT_MIN;
      res += next > tmp ? -tmp : tmp;
      //cout << res << " " << next << endl;
    }
    return res;
  }
};

int main(int argc, char const *argv[]) {
  Solution a;
  a.romanToInt("DCXXI");
  a.romanToInt("MCMXCVI");
  return 0;
}
