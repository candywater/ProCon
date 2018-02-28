#include "iostream"
#include "stack"
#include "string"
#include "unordered_map"

using namespace std;

class Solution {
public:

  bool isValid(string s) {
    unordered_map<int, int> m1 = {
      {')', '('},
      {'}', '{'},
      {']', '['}
    };

    stack<char> st;
    st.push(s[0]);

    for(size_t i = 1; i < s.size(); i++){
      if(st.size() == 0) st.push(s[i]);
      else if(m1[(s[i])] != st.top()) st.push(s[i]);
      else st.pop();
    }

    return st.size() == 0;
  }
};

int main(){
  Solution a ;
  cout << a.isValid("[") << endl;


  stack<char> st;
  unordered_map<int, int> m1;
  int i = m1[0];

  cout << i << endl;

  return 0;
}
