#include "iostream"
#include "unordered_set"
#include "vector"

using namespace std;

class Solution {
public:
  vector<int> singleNumber(vector<int>& nums) {
    unordered_multiset<int> table;
    for (size_t i = 0; i < nums.size(); i++) {
      if(table.count(nums[i]) > 0) table.erase(nums[i]);
      else table.insert(nums[i]);
    }
    std::vector<int> res = {
      *table.begin(), *++table.begin()
    };
    return res;
  }

  void show(unordered_multiset<int>& t){
    for(auto i : t)
      cout << i << " ";
    cout << endl;
  }

};

int main(int argc, char const *argv[]) {
  /* code */
  return 0;
}
