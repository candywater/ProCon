class Solution {
public:
  void rotate(vector<int>& nums, int k) {
    if(k >= nums.size()) k = k%nums.size();
    rotate1(nums, k);
  }

  void rotate1(vector<int>& nums, int k){
    vector<int> res(nums.begin()+(nums.size()-k), nums.end());
    res.insert(res.end(), nums.begin(), nums.begin()+(nums.size()-k));
    nums = res;
  }


};
