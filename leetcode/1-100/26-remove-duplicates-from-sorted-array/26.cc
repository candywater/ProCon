#include "vector"

using namespace std;

class Solution {
public:
  int removeDuplicates(vector<int>& nums) {
    if(nums.size() == 0) return 0;
    int j = nums[0];
    int count = 1;
    for(size_t i = 1; i < nums.size(); i++){
      if(nums[i] == j) continue;
      j = nums[i];
      nums[count++] = nums[i];
    }
    return count;
  }
};

int main(int argc, char const *argv[]) {
  /* code */
  return 0;
}
