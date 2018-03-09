class Solution {
public:
  vector<vector<int>> generate(int numRows) {
    vector<vector<int>> res;
    if(numRows == 0) return res;
    res.push_back(std::vector<int>(1, 1));
    for(size_t i = 1; i < numRows; i++){
      res.push_back(vector<int>());
      res[i].push_back(1);
      for(size_t j = 1; j < res[i - 1].size(); j++){
        res[i].push_back(res[i-1][j-1] + res[i-1][j]);
      }
      res[i].push_back(1);
    }
    return res;
  }
};
