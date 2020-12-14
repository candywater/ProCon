#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <utility>
#include <algorithm>

using namespace std;

class Solution {
public:

  void reverse(vector<int>& nums, int i, int j){
    while(i < j){
      int t = nums[i];
      nums[i] = nums[j];
      nums[j] = t;
      i++;
      j--;
    }
  }

  void nextPermutation(vector<int>& nums) {
    if(nums.size() <= 1) return;

    for(int i = nums.size() - 2; i >= 0; i--){
      if(i == 0 && nums[i] >= nums[i+1]){
        reverse(nums, 0, nums.size() - 1);
        return;
      }
      if(nums[i] >= nums[i+1]) continue;
      else{
        for(int j = i+1; j <= nums.size(); j++){
          if(j == nums.size()){
            int tmp = nums[j-1];
            nums[j-1] = nums[i];
            nums[i] = tmp;
            break;
          }
          else if(nums[j] > nums[i]) continue;
          else{
            int tmp = nums[j-1];
            nums[j-1] = nums[i];
            nums[i] = tmp;
            break;
          }
        }
        reverse(nums, i+1, nums.size()-1);
        return;
      }
    }
  }
};

int main(int argc, char *argv[]){
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  Solution s;
  // vector<int> nums = {1, 1, 1, 1, 5, 1, 1};
  // vector<int> nums = {1,5,8,0,7,6,5,3,1};
  vector<int> nums = {3,2,1};
  // vector<int> nums = {1, 2, 3};
  s.nextPermutation(nums);

  for(auto i : nums){ cout << i ; } cout << endl;

  return 0;

}
