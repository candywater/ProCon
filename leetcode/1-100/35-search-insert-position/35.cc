class Solution {
public:
  int searchInsert(vector<int>& nums, int target) {
    size_t i = 0;
    for( ; i < nums.size(); i++){
      if(target <= nums[i])
        return (int)i;
    }
    return (int)i;
  }
};
