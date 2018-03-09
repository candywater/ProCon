class Solution {
public:
  bool isPalindrome(string s) {
    //if(s.size() == 0) return true;
    int endindex = 0;
    if(s.size() % 2 == 1) endindex = 1;
    for(size_t i = 0, j = s.size() - 1; i <= j - endindex; ){
      if(!isAlphabet(s[i])) i++;
      else if(!isAlphabet(s[j])) j++;
      else if(s[i++] == s[j++]) continue;
      else {
        cout << i << " " << j << endl;
        return false;
      }
    }
    return true;
  }

  bool isAlphabet(char a){
    if(a >= 'a' && a <= 'z')
      return true;
    if(a >= 'A' && a <= 'Z')
      return true;
    if(a >= '0' && a <= '9')
      return true;
    return false;
  }
};
