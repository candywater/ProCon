class Solution {
  const vector<string> table = {
    ".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--",
    "--.."
  };
public:
  int uniqueMorseRepresentations(vector<string>& words) {
    set<string> res;
    for(int i = 0; i < static_cast<int>(words.size()); i++){
      string temp = "";
      for(int j = 0; j < static_cast<int>(words[i].size()); j++){
        temp += table[words[i][j] - 'a'];//cause only lower case
      }
      res.insert(temp);
      //cout << temp << endl;
    }
    return static_cast<int>(res.size());
  }
};
