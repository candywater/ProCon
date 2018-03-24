
class Solution {
public:
  int threeSumClosest(vector<int>& nums, int target) {
    //similar problem to 15-3sum
    set<vector<int>> res;
    sort(nums.begin(), nums.end());
    int diff = INT_MAX;
    int result = 0;

    for(int k = 0; k != static_cast<int>(nums.size()); k++){
      int i = k + 1, j = static_cast<int>(nums.size()) - 1;
      for( ; i < j; ){
        int sum = nums[i] + nums[j];
        if(sum+nums[k] == target)
          return target;
        else if(sum+nums[k] < target)
          i++;
        else if(sum+nums[k] > target)
          j--;
        int temp = sum + nums[k] - target;
        temp = temp > 0 ? temp : -temp;
        if(temp < diff){
          diff = temp;
          result = sum + nums[k];
        }
      }
    }
    return result;
  }

};
