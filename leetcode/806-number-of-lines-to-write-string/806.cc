#include "vector"
#include "iostream"
#include "string"

using namespace std;

class Solution {
public:
  vector<int> numberOfLines(vector<int>& widths, string S) {
    int res = 0;
    int count = 0;
    for(int i = 0; i < static_cast<int>(S.size()); i++){
      //cause only lower case
      res += widths[S[i] - 'a'];
      //cout << res << endl;
      if(res > 100){
        res -= widths[S[i] - 'a'];
        count++;
        res = 0;
        res += widths[S[i] - 'a'];
      }
    }
    if(res != 100)
      return {count + 1, res%100};
    else
      return {count, 100};
  }
};

int main(int argc, char const *argv[]) {
  Solution a;
  vector<int> q = {4,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10};
  string m = "bbbcccdddaaa";
  vector<int> v = a.numberOfLines(
    q,
    m
  );
  cout << v[0] << " " << v[1] << endl;
  return 0;
}
