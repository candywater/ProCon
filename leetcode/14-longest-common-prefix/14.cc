class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
      if(strs.size() < 1)
        return "";
      if(strs.size() < 2)
        return strs[0];
      string common = strs[0];
      size_t index = common.size();
      for(size_t i = 1; i < strs.size(); i++){
        index = longestindex(common, strs[i], index);
      }
      return common.substr(0, index);
    }
  size_t longestindex(const string& common, const string& tar, const size_t& index){
    size_t minlen = tar.size() < index ? tar.size() : index;
    for(size_t i = 0; i < minlen; i++){
      if(common[i] != tar[i]) return i;
    }
    return minlen;
  }
};
