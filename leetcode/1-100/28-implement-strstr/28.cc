class Solution {
public:
  int strStr(string haystack, string needle) {
    if(needle.size() == 0) return 0;
    if(haystack.size() == 0) return -1;
    for(size_t i = 0; i < haystack.size(); i++){
      if(haystack[i] != needle[0]) continue;
      bool flg = true;
      for(size_t j = 0; j < needle.size(); j++){
        if(haystack[i+j] != needle[j]) {
          flg = false;
          break;
        }
      }
      if(flg) return i;
    }
    return -1;
  }
};
