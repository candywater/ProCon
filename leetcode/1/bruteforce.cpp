class Solution {
  public:
    vector<int> twoSum(vector<int>& nums, int target) {
      for ( int i = 0; i < nums.size() - 1; i++ ){
        //i don't know if input nums are positive numbers
        for( int j = i + 1; j < nums.size(); j++ )
          if ( nums[i] + nums[j] == target ) return vector<int>{i, j};
      }   
    }
};
