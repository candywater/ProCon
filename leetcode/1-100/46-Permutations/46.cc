//similar problem to 77.

class Solution {
public:
  vector<vector<int>> permute(vector<int>& nums) {
    vector<vector<int>> res;
    vector<int> temp(nums.size(), 0);
    vector<bool> table(nums.size(), false);
    sort(nums.begin(), nums.end());
    combine(res, temp, 0, nums, table);
    return res;
  }
  void combine(
    vector<vector<int>>& res, vector<int>& temp,
    int index,
    const vector<int>& nums, vector<bool>& table){
      if(index >= nums.size()){
        res.push_back(temp);
        return;
      }
      for(int i = 0; i < nums.size(); i++){
        if(table[i] == true) continue;
        temp[index] = nums[i];
        table[i] = true;
        combine(res, temp, index+1, nums, table);
        table[i] = false;
      }
  }
};
