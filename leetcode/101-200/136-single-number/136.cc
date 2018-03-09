class Solution {
public:
  int singleNumber(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    for (size_t i = 1; i < nums.size() - 1; i++) {
      if(nums[i] != nums[i - 1] && nums[i] != nums[i+1]) return nums[i];
    }
    if(nums.size() > 1)
      if(nums[nums.size()-1] != nums[nums.size()-2])
        return nums[nums.size()-1];
    return nums[0];
  }
};

int main(int argc, char const *argv[]) {
  /* code */
  return 0;
}
