class Solution {
  const vector<string> keyboard = {
    "",
    "", "abc", "def",
    "ghi", "jkl", "mno",
    "pqrs", "tuv", "wxyz"
  };
  vector<int> three;
  vector<int> four;
public:
  vector<string> letterCombinations(string digits) {
    vector<string> res;
    string str(digits.size(), '0');
    backtrack(res, digits, 0, str);

    return res;
  }

  void backtrack(
    vector<string>& res, const string& digits, int index, string& str){
    if(index == digits.size()){
      if(!str.empty())
        res.push_back(str);
    }
    int k = digits[index] - '0';
    for(int i = 0; i < keyboard[k].size(); i++){
      str[index] = keyboard[k][i];
      backtrack(res, digits, index+1, str);
    }
  }
};
