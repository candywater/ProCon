#include "iostream"
#include "unordered_set"
#include "vector"

using namespace std;

class Solution {
public:
  int singleNumber(vector<int>& nums) {
    unordered_set<int> table;
    for (size_t i = 0; i < nums.size(); i++) {
      if(table.count(nums[i]) > 0) table.erase(nums[i]);
      else table.insert(nums[i]);
    }
    return *table.begin();
  }
};

int main(int argc, char const *argv[]) {
  /* code */
  return 0;
}
