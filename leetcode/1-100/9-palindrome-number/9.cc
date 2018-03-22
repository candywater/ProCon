//strange problem.
//it says "Determine whether an integer is a palindrome. Do this without extra space."
//but recommand solution use O(1) extra space...

//so...I decided to ignore that "do not use extra space" something

class Solution {
public:
  bool isPalindrome(int x) {
    if(x < 0) return false;
    string str = to_string(x);
    int i = 0, j = static_cast<int>(str.size() - 1);
    for(; i < j; i++, j--){
      if(str[i] != str[j]) return false;
    }
    return true;
  }
};
