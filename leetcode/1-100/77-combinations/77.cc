class Solution {
public:
  vector<vector<int>> combine(int n, int k) {
    vector<vector<int>> res;
    vector<int> temp;
    combine(res, temp, 1, n, k);
    return res;
  }
  void combine(
    vector<vector<int>>& res, vector<int>& temp, int index, int n, int k){
      if(temp.size() > k) return;
      if(temp.size() == k){
        res.push_back(temp);
      }
      for(int i = index; i <= n; i++){
        temp.push_back(i);
        combine(res, temp, i+1, n, k);
        temp.pop_back();
      }
  }
};
