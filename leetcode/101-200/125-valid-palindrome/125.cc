#include "iostream"

using namespace std;

class Solution {
public:
  bool isPalindrome(string s) {
    //if(s.size() == 0) return true;
    trans_to_lower_case(s);
    //cout << "check point" << endl;
    int endindex = 0;
    if(s.size() % 2 == 1) endindex = 1;
    for(int i = 0, j = s.size() - 1; i <= j - endindex; ){
      if(!isAlphabet(s[i])) i++;
      else if(!isAlphabet(s[j])) j--;
      else if(s[i++] == s[j--]) continue;
      else {
        cout << "[" << i-1 << "]:" << s[i-1] << " "
        << "[" << j+1 << "]:" << s[j+1] << endl;
        return false;
      }
    }
    return true;
  }

  bool isAlphabet(char a){
    if(a >= 'a' && a <= 'z')
      return true;
    //if(a >= 'A' && a <= 'Z') return true;
    if(a >= '0' && a <= '9')
      return true;
    return false;
  }
  void trans_to_lower_case(string& s){
    int diff = 'A' - 'a';
    for(size_t i = 0; i < s.size(); i++){
      if(s[i] >= 'A' && s[i] <= 'Z') s[i] = s[i] - diff;
    }
  }
};

int main(int argc, char const *argv[]) {
  Solution a ;
  //a.isPalindrome("A man, a plan, a canal: Panama");
  //a.isPalindrome("race a car");
  a.isPalindrome("");
  return 0;
}
