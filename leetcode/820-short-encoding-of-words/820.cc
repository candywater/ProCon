#include "iostream"
#include "set"
#include "string"
#include "vector"

using namespace std;


struct cmp{
  bool operator ()(const string& a, const string& b)const {
    //cout << "a: " << a << " b: " << b << " " << endl;
    for(int i = a.size() - 1, j = b.size() - 1; i >= 0 && j >= 0; i--, j--){
      //cout << a[i] << " " << b[j] << " ";
      if(a[i] != b[j]) return a[i] < b[j];
    }
    //cout << "TRUE" << endl;
    return false;
  }
};

struct lencmp{
  bool operator () (const string& a, const string& b) const {
    return a.size() > b.size();
  }
} lencmpins;


class Solution {
public:
  int minimumLengthEncoding(vector<string>& words) {
    sort(words.begin(), words.end(), lencmpins);
    //show(words);cout << endl;
    set<string, cmp> table;
    for(auto i : words){
      table.insert(i);
    }
    //debug
    //show(table);
    int len = 0;
    for(auto i : table){
      len += i.size() + 1;
    }

    return len;

  }

  template<typename T>
  void show(T a){
    for(auto i : a){
      cout << " " << i ;
    }
    cout << endl;
  }


};



int main(int argc, char const *argv[]) {
  Solution a ;
  vector<string> b = {
    "time",
    "me",
    "you",
    "youyou",
    "man"
  };
  int res = a.minimumLengthEncoding(b);
  cout << "res: " << res << endl;
  return 0;
}
