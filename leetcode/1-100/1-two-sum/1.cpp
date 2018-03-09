#include <iostream>
#include <unordered_map>
#include <vector>
#include <string>

using namespace std;

class Solution {
  public:
    vector<int> twoSum(vector<int>& nums, int target) {
      std::unordered_map<int, int> table;
      for(int i = 0; i < nums.size(); i++){
        if(table.find(target - nums[i]) != table.end())
          return vector<int>{table[target - nums[i]], i};
        else
          table.insert({nums[i], i});
        //std::cout << i << std::endl;
        //std::cout << target - nums[i] << std::endl;
        //std::cout << ( (table.find(target - nums[i]) != table.end()) == true ? "true" : "false" )<< std::endl;
      }
      return {};
    }
};

int main(){
  Solution a;
  vector<int> b = {3,2,4};
  a.twoSum (b, 6);
}

